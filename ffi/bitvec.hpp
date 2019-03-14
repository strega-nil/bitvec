#ifndef RS_BITVEC_FFI_BITVEC_HPP
#define RS_BITVEC_FFI_BITVEC_HPP

#include <cstddef>

#include "./bitslice.h"
#include "./bitvec.h"

#include "./bitslice.hpp"

template <typename T>
class BitVecBe;

template <>
class BitVecBe<unsigned char> : public HBitSliceBe<unsigned char>
{};

#endif//RS_BITVEC_FFI_BITVEC_HPP
