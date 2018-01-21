/* This file is part of the dynarmic project.
 * Copyright (c) 2018 MerryMage
 * This software may be used and distributed according to the terms of the GNU
 * General Public License version 2 or any later version.
 */

#include "frontend/A64/translate/impl/impl.h"

namespace Dynarmic {
namespace A64 {

bool TranslatorVisitor::CSEL(bool sf, Reg Rm, Cond cond, Reg Rn, Reg Rd) {
    size_t datasize = sf ? 64 : 32;

    IR::U32U64 operand1 = X(datasize, Rn);
    IR::U32U64 operand2 = X(datasize, Rm);

    IR::U32U64 result = ir.ConditionalSelect(cond, operand1, operand2);

    X(datasize, Rd, result);

    return true;
}

} // namespace A64
} // namespace Dynarmic