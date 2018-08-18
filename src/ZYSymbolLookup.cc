/* vim:set et ts=4 sts=4:
 *
 * ibus-libzhuyin - New Zhuyin engine based on libzhuyin for IBus
 *
 * Copyright (c) 2014 Peng Wu <alexepico@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "ZYSymbolLookup.h"
#include <stdio.h>
#include <string.h>

namespace ZY {

gboolean
SymbolLookup::loadFromFile(const char * filename)
{
    FILE * symbolfile = fopen (filename, "r");
    if (NULL == symbolfile)
        return FALSE;

    char* linebuf = NULL; size_t size = 0; ssize_t read;
    while ((read = getline (&linebuf, &size, symbolfile)) != -1) {
        if (0 == strlen (linebuf))
            continue;

        if ( '\n' == linebuf[strlen (linebuf) - 1] ) {
            linebuf[strlen (linebuf) - 1] = '\0';
        }

        gchar ** items = g_strsplit_set (linebuf, " =", 2);
        guint len = g_strv_length (items);

        if (0 == len)
            continue;

        String index = items[0];
        /* for symbols.dat, copy display label from symbol. */
        String symbol = index;
        if (2 == len)
            symbol = items[1];

        /* just append. */
        m_indexes.push_back (index);
        m_symbols.push_back (symbol);

        g_strfreev (items);
    }

    return TRUE;
}

String
SymbolLookup::find (const String index)
{
    gboolean found = FALSE;

    size_t i;
    for(i = 0; i < m_indexes.size (); ++i) {
        if (index == m_indexes[i]) {
            found = TRUE;
            break;
        }
    }

    if (found)
        return m_symbols[i];

    return "";
}

void
SymbolLookup::dumpInfo ()
{
    size_t i;
    for (i = 0; i < m_indexes.size (); ++i)
        printf ("%s %s\n", m_indexes[i].c_str (), m_symbols[i].c_str ());
}

};
