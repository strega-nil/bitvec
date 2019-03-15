#ifndef RS_BITVEC_FFI_BITVEC_HPP
#define RS_BITVEC_FFI_BITVEC_HPP

#include <cstddef>
#include <cstdint>
#include <array>

#include <bitslice.hpp>
#include <bitvec.h>

namespace rust {
namespace bitvec {

namespace func {
namespace bv {

//  JUMP TABLES
//
//  These tables are used to multiplex template-class method instantiations to
//  the correct C-API boundary function. These tables cannot be observed or used
//  outside this module, and are removed from the compiled output.

using ctor_t = void(BitVec *);
static auto const ctor = std::array<ctor_t *, 8>{{
	reinterpret_cast<ctor_t *>(rs_bitvec_bv_b08_new),
	reinterpret_cast<ctor_t *>(rs_bitvec_bv_l08_new),
	reinterpret_cast<ctor_t *>(rs_bitvec_bv_b16_new),
	reinterpret_cast<ctor_t *>(rs_bitvec_bv_l16_new),
	reinterpret_cast<ctor_t *>(rs_bitvec_bv_b32_new),
	reinterpret_cast<ctor_t *>(rs_bitvec_bv_l32_new),
	reinterpret_cast<ctor_t *>(rs_bitvec_bv_b64_new),
	reinterpret_cast<ctor_t *>(rs_bitvec_bv_l64_new),
}};

using dtor_t = void(BitVec *);
static auto const dtor = std::array<dtor_t *, 8>{{
	reinterpret_cast<dtor_t *>(rs_bitvec_bv_b08_drop),
	reinterpret_cast<dtor_t *>(rs_bitvec_bv_l08_drop),
	reinterpret_cast<dtor_t *>(rs_bitvec_bv_b16_drop),
	reinterpret_cast<dtor_t *>(rs_bitvec_bv_l16_drop),
	reinterpret_cast<dtor_t *>(rs_bitvec_bv_b32_drop),
	reinterpret_cast<dtor_t *>(rs_bitvec_bv_l32_drop),
	reinterpret_cast<dtor_t *>(rs_bitvec_bv_b64_drop),
	reinterpret_cast<dtor_t *>(rs_bitvec_bv_l64_drop),
}};

} // namespace bv
} // namespace func

template <Cursor C, class T>
class BitVector;

namespace impl {

template <Cursor C, class T>
static BitVec * make_bitvec(BitVector<C, T> * bv) {
	return reinterpret_cast<BitVec *>(bv);
}

template <Cursor C, class T>
static BitVec const * make_bitvec(BitVector<C, T> const * bv) {
	return reinterpret_cast<BitVec const *>(bv);
}

}

template <Cursor C, class T>
class BitVector : BitSliceHandle {
public:
	explicit BitVector(void) : BitSliceHandle(void), capacity{0} {
		impl::mux<C, T>(func::bv::ctor, impl::make_bitvec(this));
	}
	~BitVector(void) const {
		impl::mux<C, T>(func::bv::dtor, impl::make_bitvec(this));
	}
private:
	std::size_t capacity;
};

} // namespace bitvec
} // namespace rust

#endif//RS_BITVEC_FFI_BITVEC_HPP
