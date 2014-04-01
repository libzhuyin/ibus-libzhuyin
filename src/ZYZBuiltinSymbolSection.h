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

#ifndef __ZY_LIB_ZHUYIN_BUILTIN_SYMBOL_SECTION_H_
#define __ZY_LIB_ZHUYIN_BUILTIN_SYMBOL_SECTION_H_

#include "ZYZSymbolSection.h"

namespace ZY {

class BuiltinSymbolSection : public SymbolSection {
public:
    BuiltinSymbolSection (PhoneticEditor & editor);
    virtual ~BuiltinSymbolSection ();

public:
    virtual bool initCandidates (const String & lookup);
    virtual bool populateCandidates ();
    virtual bool selectCandidate (guint index);

};

};

#endif