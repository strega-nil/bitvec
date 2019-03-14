#ifndef RS_BITVEC_FFI_BITSLICE_HPP
#define RS_BITVEC_FFI_BITSLICE_HPP

#include <cstddef>
#include <cstdint>
#include <array>

#include <bitslice.h>

namespace rust {
namespace bitvec {

namespace func {

//  JUMP TABLES
//
//  These tables are used to multiplex template-class method instantiations to
//  the correct C-API boundary function. These tables cannot be observed or used
//  outside this module, and are removed from the compiled output.

using from_span_t = auto(BitPtrImmut *, void const *, std::size_t) -> bool;
static auto const from_span = std::array<from_span_t *, 8>{{
	reinterpret_cast<from_span_t *>(rs_bitvec_bs_b08_from_span),
	reinterpret_cast<from_span_t *>(rs_bitvec_bs_l08_from_span),
	reinterpret_cast<from_span_t *>(rs_bitvec_bs_b16_from_span),
	reinterpret_cast<from_span_t *>(rs_bitvec_bs_l16_from_span),
	reinterpret_cast<from_span_t *>(rs_bitvec_bs_b32_from_span),
	reinterpret_cast<from_span_t *>(rs_bitvec_bs_l32_from_span),
	reinterpret_cast<from_span_t *>(rs_bitvec_bs_b64_from_span),
	reinterpret_cast<from_span_t *>(rs_bitvec_bs_l64_from_span),
}};

using from_span_partial_t = auto(BitPtrImmut *, void const *, std::size_t, std::uint8_t, std::uint8_t) -> bool;
static auto const from_span_partial = std::array<from_span_partial_t *, 8>{{
	reinterpret_cast<from_span_partial_t *>(rs_bitvec_bs_b08_from_span_partial),
	reinterpret_cast<from_span_partial_t *>(rs_bitvec_bs_l08_from_span_partial),
	reinterpret_cast<from_span_partial_t *>(rs_bitvec_bs_b16_from_span_partial),
	reinterpret_cast<from_span_partial_t *>(rs_bitvec_bs_l16_from_span_partial),
	reinterpret_cast<from_span_partial_t *>(rs_bitvec_bs_b32_from_span_partial),
	reinterpret_cast<from_span_partial_t *>(rs_bitvec_bs_l32_from_span_partial),
	reinterpret_cast<from_span_partial_t *>(rs_bitvec_bs_b64_from_span_partial),
	reinterpret_cast<from_span_partial_t *>(rs_bitvec_bs_l64_from_span_partial),
}};

using empty_t = void(BitPtrImmut *);
static auto const empty = std::array<empty_t *, 8>{{
	reinterpret_cast<empty_t *>(rs_bitvec_bs_b08_empty),
	reinterpret_cast<empty_t *>(rs_bitvec_bs_l08_empty),
	reinterpret_cast<empty_t *>(rs_bitvec_bs_b16_empty),
	reinterpret_cast<empty_t *>(rs_bitvec_bs_l16_empty),
	reinterpret_cast<empty_t *>(rs_bitvec_bs_b32_empty),
	reinterpret_cast<empty_t *>(rs_bitvec_bs_l32_empty),
	reinterpret_cast<empty_t *>(rs_bitvec_bs_b64_empty),
	reinterpret_cast<empty_t *>(rs_bitvec_bs_l64_empty),
}};

using len_t = auto(BitPtrImmut const *) -> std::size_t;
static auto const len = std::array<len_t *, 8> {{
	reinterpret_cast<len_t *>(rs_bitvec_bs_b08_len),
	reinterpret_cast<len_t *>(rs_bitvec_bs_l08_len),
	reinterpret_cast<len_t *>(rs_bitvec_bs_b16_len),
	reinterpret_cast<len_t *>(rs_bitvec_bs_l16_len),
	reinterpret_cast<len_t *>(rs_bitvec_bs_b32_len),
	reinterpret_cast<len_t *>(rs_bitvec_bs_l32_len),
	reinterpret_cast<len_t *>(rs_bitvec_bs_b64_len),
	reinterpret_cast<len_t *>(rs_bitvec_bs_l64_len),
}};

using is_empty_t = auto(BitPtrImmut const *) -> Tristate;
static auto const is_empty = std::array<is_empty_t *, 8>{{
	reinterpret_cast<is_empty_t *>(rs_bitvec_bs_b08_is_empty),
	reinterpret_cast<is_empty_t *>(rs_bitvec_bs_l08_is_empty),
	reinterpret_cast<is_empty_t *>(rs_bitvec_bs_b16_is_empty),
	reinterpret_cast<is_empty_t *>(rs_bitvec_bs_l16_is_empty),
	reinterpret_cast<is_empty_t *>(rs_bitvec_bs_b32_is_empty),
	reinterpret_cast<is_empty_t *>(rs_bitvec_bs_l32_is_empty),
	reinterpret_cast<is_empty_t *>(rs_bitvec_bs_b64_is_empty),
	reinterpret_cast<is_empty_t *>(rs_bitvec_bs_l64_is_empty),
}};

using first_t = auto(BitPtrImmut const *) -> Tristate;
static auto const first = std::array<first_t *, 8>{{
	reinterpret_cast<first_t *>(rs_bitvec_bs_b08_first),
	reinterpret_cast<first_t *>(rs_bitvec_bs_l08_first),
	reinterpret_cast<first_t *>(rs_bitvec_bs_b16_first),
	reinterpret_cast<first_t *>(rs_bitvec_bs_l16_first),
	reinterpret_cast<first_t *>(rs_bitvec_bs_b32_first),
	reinterpret_cast<first_t *>(rs_bitvec_bs_l32_first),
	reinterpret_cast<first_t *>(rs_bitvec_bs_b64_first),
	reinterpret_cast<first_t *>(rs_bitvec_bs_l64_first),
}};

using split_first_t = auto(BitPtrImmut *) -> Tristate;
static auto const split_first = std::array<split_first_t *, 8>{{
	reinterpret_cast<split_first_t *>(rs_bitvec_bs_b08_split_first),
	reinterpret_cast<split_first_t *>(rs_bitvec_bs_l08_split_first),
	reinterpret_cast<split_first_t *>(rs_bitvec_bs_b16_split_first),
	reinterpret_cast<split_first_t *>(rs_bitvec_bs_l16_split_first),
	reinterpret_cast<split_first_t *>(rs_bitvec_bs_b32_split_first),
	reinterpret_cast<split_first_t *>(rs_bitvec_bs_l32_split_first),
	reinterpret_cast<split_first_t *>(rs_bitvec_bs_b64_split_first),
	reinterpret_cast<split_first_t *>(rs_bitvec_bs_l64_split_first),
}};

using split_first_mut_t = auto(BitPtrMut *) -> Tristate;
static auto const split_first_mut = std::array<split_first_mut_t *, 8>{{
	reinterpret_cast<split_first_mut_t *>(rs_bitvec_bs_b08_split_first_mut),
	reinterpret_cast<split_first_mut_t *>(rs_bitvec_bs_l08_split_first_mut),
	reinterpret_cast<split_first_mut_t *>(rs_bitvec_bs_b16_split_first_mut),
	reinterpret_cast<split_first_mut_t *>(rs_bitvec_bs_l16_split_first_mut),
	reinterpret_cast<split_first_mut_t *>(rs_bitvec_bs_b32_split_first_mut),
	reinterpret_cast<split_first_mut_t *>(rs_bitvec_bs_l32_split_first_mut),
	reinterpret_cast<split_first_mut_t *>(rs_bitvec_bs_b64_split_first_mut),
	reinterpret_cast<split_first_mut_t *>(rs_bitvec_bs_l64_split_first_mut),
}};

using split_last_t = auto(BitPtrImmut *) -> Tristate;
static auto const split_last = std::array<split_last_t *, 8>{{
	reinterpret_cast<split_last_t *>(rs_bitvec_bs_b08_split_last),
	reinterpret_cast<split_last_t *>(rs_bitvec_bs_l08_split_last),
	reinterpret_cast<split_last_t *>(rs_bitvec_bs_b16_split_last),
	reinterpret_cast<split_last_t *>(rs_bitvec_bs_l16_split_last),
	reinterpret_cast<split_last_t *>(rs_bitvec_bs_b32_split_last),
	reinterpret_cast<split_last_t *>(rs_bitvec_bs_l32_split_last),
	reinterpret_cast<split_last_t *>(rs_bitvec_bs_b64_split_last),
	reinterpret_cast<split_last_t *>(rs_bitvec_bs_l64_split_last),
}};

using split_last_mut_t = auto(BitPtrMut *) -> Tristate;
static auto const split_last_mut = std::array<split_last_mut_t *, 8>{{
	reinterpret_cast<split_last_mut_t *>(rs_bitvec_bs_b08_split_last_mut),
	reinterpret_cast<split_last_mut_t *>(rs_bitvec_bs_l08_split_last_mut),
	reinterpret_cast<split_last_mut_t *>(rs_bitvec_bs_b16_split_last_mut),
	reinterpret_cast<split_last_mut_t *>(rs_bitvec_bs_l16_split_last_mut),
	reinterpret_cast<split_last_mut_t *>(rs_bitvec_bs_b32_split_last_mut),
	reinterpret_cast<split_last_mut_t *>(rs_bitvec_bs_l32_split_last_mut),
	reinterpret_cast<split_last_mut_t *>(rs_bitvec_bs_b64_split_last_mut),
	reinterpret_cast<split_last_mut_t *>(rs_bitvec_bs_l64_split_last_mut),
}};

using last_t = auto(BitPtrImmut *) -> Tristate;
static auto const last = std::array<last_t *, 8>{{
	reinterpret_cast<last_t *>(rs_bitvec_bs_b08_last),
	reinterpret_cast<last_t *>(rs_bitvec_bs_l08_last),
	reinterpret_cast<last_t *>(rs_bitvec_bs_b16_last),
	reinterpret_cast<last_t *>(rs_bitvec_bs_l16_last),
	reinterpret_cast<last_t *>(rs_bitvec_bs_b32_last),
	reinterpret_cast<last_t *>(rs_bitvec_bs_l32_last),
	reinterpret_cast<last_t *>(rs_bitvec_bs_b64_last),
	reinterpret_cast<last_t *>(rs_bitvec_bs_l64_last),
}};

using get_t = auto(BitPtrImmut *, std::size_t) -> Tristate;
static auto const get = std::array<get_t *, 8>{{
	reinterpret_cast<get_t *>(rs_bitvec_bs_b08_get),
	reinterpret_cast<get_t *>(rs_bitvec_bs_l08_get),
	reinterpret_cast<get_t *>(rs_bitvec_bs_b16_get),
	reinterpret_cast<get_t *>(rs_bitvec_bs_l16_get),
	reinterpret_cast<get_t *>(rs_bitvec_bs_b32_get),
	reinterpret_cast<get_t *>(rs_bitvec_bs_l32_get),
	reinterpret_cast<get_t *>(rs_bitvec_bs_b64_get),
	reinterpret_cast<get_t *>(rs_bitvec_bs_l64_get),
}};

using set_t = void(BitPtrMut *, std::size_t, bool);
static auto const set = std::array<set_t *, 8>{{
	reinterpret_cast<set_t *>(rs_bitvec_bs_b08_set),
	reinterpret_cast<set_t *>(rs_bitvec_bs_l08_set),
	reinterpret_cast<set_t *>(rs_bitvec_bs_b16_set),
	reinterpret_cast<set_t *>(rs_bitvec_bs_l16_set),
	reinterpret_cast<set_t *>(rs_bitvec_bs_b32_set),
	reinterpret_cast<set_t *>(rs_bitvec_bs_l32_set),
	reinterpret_cast<set_t *>(rs_bitvec_bs_b64_set),
	reinterpret_cast<set_t *>(rs_bitvec_bs_l64_set),
}};

using as_ptr_t = auto(BitPtrImmut *) -> void const *;
static auto const as_ptr = std::array<as_ptr_t *, 8>{{
	reinterpret_cast<as_ptr_t *>(rs_bitvec_bs_b08_as_ptr),
	reinterpret_cast<as_ptr_t *>(rs_bitvec_bs_l08_as_ptr),
	reinterpret_cast<as_ptr_t *>(rs_bitvec_bs_b16_as_ptr),
	reinterpret_cast<as_ptr_t *>(rs_bitvec_bs_l16_as_ptr),
	reinterpret_cast<as_ptr_t *>(rs_bitvec_bs_b32_as_ptr),
	reinterpret_cast<as_ptr_t *>(rs_bitvec_bs_l32_as_ptr),
	reinterpret_cast<as_ptr_t *>(rs_bitvec_bs_b64_as_ptr),
	reinterpret_cast<as_ptr_t *>(rs_bitvec_bs_l64_as_ptr),
}};

using as_mut_ptr_t = auto(BitPtrMut *) -> void const *;
static auto const as_mut_ptr = std::array<as_mut_ptr_t *, 8>{{
	reinterpret_cast<as_mut_ptr_t *>(rs_bitvec_bs_b08_as_mut_ptr),
	reinterpret_cast<as_mut_ptr_t *>(rs_bitvec_bs_l08_as_mut_ptr),
	reinterpret_cast<as_mut_ptr_t *>(rs_bitvec_bs_b16_as_mut_ptr),
	reinterpret_cast<as_mut_ptr_t *>(rs_bitvec_bs_l16_as_mut_ptr),
	reinterpret_cast<as_mut_ptr_t *>(rs_bitvec_bs_b32_as_mut_ptr),
	reinterpret_cast<as_mut_ptr_t *>(rs_bitvec_bs_l32_as_mut_ptr),
	reinterpret_cast<as_mut_ptr_t *>(rs_bitvec_bs_b64_as_mut_ptr),
	reinterpret_cast<as_mut_ptr_t *>(rs_bitvec_bs_l64_as_mut_ptr),
}};

using swap_t = void(BitPtrMut *, std::size_t, std::size_t);
static auto const swap = std::array<swap_t *, 8>{{
	reinterpret_cast<swap_t *>(rs_bitvec_bs_b08_swap),
	reinterpret_cast<swap_t *>(rs_bitvec_bs_l08_swap),
	reinterpret_cast<swap_t *>(rs_bitvec_bs_b16_swap),
	reinterpret_cast<swap_t *>(rs_bitvec_bs_l16_swap),
	reinterpret_cast<swap_t *>(rs_bitvec_bs_b32_swap),
	reinterpret_cast<swap_t *>(rs_bitvec_bs_l32_swap),
	reinterpret_cast<swap_t *>(rs_bitvec_bs_b64_swap),
	reinterpret_cast<swap_t *>(rs_bitvec_bs_l64_swap),
}};

using reverse_t = void(BitPtrMut *);
static auto const reverse = std::array<reverse_t *, 8>{{
	reinterpret_cast<reverse_t *>(rs_bitvec_bs_b08_reverse),
	reinterpret_cast<reverse_t *>(rs_bitvec_bs_l08_reverse),
	reinterpret_cast<reverse_t *>(rs_bitvec_bs_b16_reverse),
	reinterpret_cast<reverse_t *>(rs_bitvec_bs_l16_reverse),
	reinterpret_cast<reverse_t *>(rs_bitvec_bs_b32_reverse),
	reinterpret_cast<reverse_t *>(rs_bitvec_bs_l32_reverse),
	reinterpret_cast<reverse_t *>(rs_bitvec_bs_b64_reverse),
	reinterpret_cast<reverse_t *>(rs_bitvec_bs_l64_reverse),
}};

using split_at_t = auto(BitPtrImmut *, BitPtrImmut *, std::size_t) -> bool;
static auto const split_at = std::array<split_at_t *, 8>{{
	reinterpret_cast<split_at_t *>(rs_bitvec_bs_b08_split_at),
	reinterpret_cast<split_at_t *>(rs_bitvec_bs_l08_split_at),
	reinterpret_cast<split_at_t *>(rs_bitvec_bs_b16_split_at),
	reinterpret_cast<split_at_t *>(rs_bitvec_bs_l16_split_at),
	reinterpret_cast<split_at_t *>(rs_bitvec_bs_b32_split_at),
	reinterpret_cast<split_at_t *>(rs_bitvec_bs_l32_split_at),
	reinterpret_cast<split_at_t *>(rs_bitvec_bs_b64_split_at),
	reinterpret_cast<split_at_t *>(rs_bitvec_bs_l64_split_at),
}};

using split_at_mut_t = auto(BitPtrMut *, BitPtrMut *, std::size_t) -> bool;
static auto const split_at_mut = std::array<split_at_mut_t *, 8>{{
	reinterpret_cast<split_at_mut_t *>(rs_bitvec_bs_b08_split_at_mut),
	reinterpret_cast<split_at_mut_t *>(rs_bitvec_bs_l08_split_at_mut),
	reinterpret_cast<split_at_mut_t *>(rs_bitvec_bs_b16_split_at_mut),
	reinterpret_cast<split_at_mut_t *>(rs_bitvec_bs_l16_split_at_mut),
	reinterpret_cast<split_at_mut_t *>(rs_bitvec_bs_b32_split_at_mut),
	reinterpret_cast<split_at_mut_t *>(rs_bitvec_bs_l32_split_at_mut),
	reinterpret_cast<split_at_mut_t *>(rs_bitvec_bs_b64_split_at_mut),
	reinterpret_cast<split_at_mut_t *>(rs_bitvec_bs_l64_split_at_mut),
}};

using rotate_left_t = void(BitPtrMut *, std::size_t);
static auto const rotate_left = std::array<rotate_left_t *, 8>{{
	reinterpret_cast<rotate_left_t *>(rs_bitvec_bs_b08_rotate_left),
	reinterpret_cast<rotate_left_t *>(rs_bitvec_bs_l08_rotate_left),
	reinterpret_cast<rotate_left_t *>(rs_bitvec_bs_b16_rotate_left),
	reinterpret_cast<rotate_left_t *>(rs_bitvec_bs_l16_rotate_left),
	reinterpret_cast<rotate_left_t *>(rs_bitvec_bs_b32_rotate_left),
	reinterpret_cast<rotate_left_t *>(rs_bitvec_bs_l32_rotate_left),
	reinterpret_cast<rotate_left_t *>(rs_bitvec_bs_b64_rotate_left),
	reinterpret_cast<rotate_left_t *>(rs_bitvec_bs_l64_rotate_left),
}};

using rotate_right_t = void(BitPtrMut *, std::size_t);
static auto const rotate_right = std::array<rotate_right_t *, 8>{{
	reinterpret_cast<rotate_right_t *>(rs_bitvec_bs_b08_rotate_right),
	reinterpret_cast<rotate_right_t *>(rs_bitvec_bs_l08_rotate_right),
	reinterpret_cast<rotate_right_t *>(rs_bitvec_bs_b16_rotate_right),
	reinterpret_cast<rotate_right_t *>(rs_bitvec_bs_l16_rotate_right),
	reinterpret_cast<rotate_right_t *>(rs_bitvec_bs_b32_rotate_right),
	reinterpret_cast<rotate_right_t *>(rs_bitvec_bs_l32_rotate_right),
	reinterpret_cast<rotate_right_t *>(rs_bitvec_bs_b64_rotate_right),
	reinterpret_cast<rotate_right_t *>(rs_bitvec_bs_l64_rotate_right),
}};

using all_t = auto(BitPtrImmut *) -> bool;
static auto const all = std::array<all_t *, 8>{{
	reinterpret_cast<all_t *>(rs_bitvec_bs_b08_all),
	reinterpret_cast<all_t *>(rs_bitvec_bs_l08_all),
	reinterpret_cast<all_t *>(rs_bitvec_bs_b16_all),
	reinterpret_cast<all_t *>(rs_bitvec_bs_l16_all),
	reinterpret_cast<all_t *>(rs_bitvec_bs_b32_all),
	reinterpret_cast<all_t *>(rs_bitvec_bs_l32_all),
	reinterpret_cast<all_t *>(rs_bitvec_bs_b64_all),
	reinterpret_cast<all_t *>(rs_bitvec_bs_l64_all),
}};

using any_t = auto(BitPtrImmut *) -> bool;
static auto const any = std::array<any_t *, 8>{{
	reinterpret_cast<any_t *>(rs_bitvec_bs_b08_any),
	reinterpret_cast<any_t *>(rs_bitvec_bs_l08_any),
	reinterpret_cast<any_t *>(rs_bitvec_bs_b16_any),
	reinterpret_cast<any_t *>(rs_bitvec_bs_l16_any),
	reinterpret_cast<any_t *>(rs_bitvec_bs_b32_any),
	reinterpret_cast<any_t *>(rs_bitvec_bs_l32_any),
	reinterpret_cast<any_t *>(rs_bitvec_bs_b64_any),
	reinterpret_cast<any_t *>(rs_bitvec_bs_l64_any),
}};

using not_all_t = auto(BitPtrImmut *) -> bool;
static auto const not_all = std::array<not_all_t *, 8>{{
	reinterpret_cast<not_all_t *>(rs_bitvec_bs_b08_not_all),
	reinterpret_cast<not_all_t *>(rs_bitvec_bs_l08_not_all),
	reinterpret_cast<not_all_t *>(rs_bitvec_bs_b16_not_all),
	reinterpret_cast<not_all_t *>(rs_bitvec_bs_l16_not_all),
	reinterpret_cast<not_all_t *>(rs_bitvec_bs_b32_not_all),
	reinterpret_cast<not_all_t *>(rs_bitvec_bs_l32_not_all),
	reinterpret_cast<not_all_t *>(rs_bitvec_bs_b64_not_all),
	reinterpret_cast<not_all_t *>(rs_bitvec_bs_l64_not_all),
}};

using not_any_t = auto(BitPtrImmut *) -> bool;
static auto const not_any = std::array<not_any_t *, 8>{{
	reinterpret_cast<not_any_t *>(rs_bitvec_bs_b08_not_any),
	reinterpret_cast<not_any_t *>(rs_bitvec_bs_l08_not_any),
	reinterpret_cast<not_any_t *>(rs_bitvec_bs_b16_not_any),
	reinterpret_cast<not_any_t *>(rs_bitvec_bs_l16_not_any),
	reinterpret_cast<not_any_t *>(rs_bitvec_bs_b32_not_any),
	reinterpret_cast<not_any_t *>(rs_bitvec_bs_l32_not_any),
	reinterpret_cast<not_any_t *>(rs_bitvec_bs_b64_not_any),
	reinterpret_cast<not_any_t *>(rs_bitvec_bs_l64_not_any),
}};

using some_t = auto(BitPtrImmut *) -> bool;
static auto const some = std::array<some_t *, 8>{{
	reinterpret_cast<some_t *>(rs_bitvec_bs_b08_some),
	reinterpret_cast<some_t *>(rs_bitvec_bs_l08_some),
	reinterpret_cast<some_t *>(rs_bitvec_bs_b16_some),
	reinterpret_cast<some_t *>(rs_bitvec_bs_l16_some),
	reinterpret_cast<some_t *>(rs_bitvec_bs_b32_some),
	reinterpret_cast<some_t *>(rs_bitvec_bs_l32_some),
	reinterpret_cast<some_t *>(rs_bitvec_bs_b64_some),
	reinterpret_cast<some_t *>(rs_bitvec_bs_l64_some),
}};

using count_ones_t = auto(BitPtrImmut *) -> std::size_t;
static auto const count_ones = std::array<count_ones_t *, 8>{{
	reinterpret_cast<count_ones_t *>(rs_bitvec_bs_b08_count_ones),
	reinterpret_cast<count_ones_t *>(rs_bitvec_bs_l08_count_ones),
	reinterpret_cast<count_ones_t *>(rs_bitvec_bs_b16_count_ones),
	reinterpret_cast<count_ones_t *>(rs_bitvec_bs_l16_count_ones),
	reinterpret_cast<count_ones_t *>(rs_bitvec_bs_b32_count_ones),
	reinterpret_cast<count_ones_t *>(rs_bitvec_bs_l32_count_ones),
	reinterpret_cast<count_ones_t *>(rs_bitvec_bs_b64_count_ones),
	reinterpret_cast<count_ones_t *>(rs_bitvec_bs_l64_count_ones),
}};

using count_zeros_t = auto(BitPtrImmut *) -> std::size_t;
static auto const count_zeros = std::array<count_zeros_t *, 8>{{
	reinterpret_cast<count_zeros_t *>(rs_bitvec_bs_b08_count_zeros),
	reinterpret_cast<count_zeros_t *>(rs_bitvec_bs_l08_count_zeros),
	reinterpret_cast<count_zeros_t *>(rs_bitvec_bs_b16_count_zeros),
	reinterpret_cast<count_zeros_t *>(rs_bitvec_bs_l16_count_zeros),
	reinterpret_cast<count_zeros_t *>(rs_bitvec_bs_b32_count_zeros),
	reinterpret_cast<count_zeros_t *>(rs_bitvec_bs_l32_count_zeros),
	reinterpret_cast<count_zeros_t *>(rs_bitvec_bs_b64_count_zeros),
	reinterpret_cast<count_zeros_t *>(rs_bitvec_bs_l64_count_zeros),
}};

using set_all_t = void(BitPtrMut *, bool);
static auto const set_all = std::array<set_all_t *, 8>{{
	reinterpret_cast<set_all_t *>(rs_bitvec_bs_b08_set_all),
	reinterpret_cast<set_all_t *>(rs_bitvec_bs_l08_set_all),
	reinterpret_cast<set_all_t *>(rs_bitvec_bs_b16_set_all),
	reinterpret_cast<set_all_t *>(rs_bitvec_bs_l16_set_all),
	reinterpret_cast<set_all_t *>(rs_bitvec_bs_b32_set_all),
	reinterpret_cast<set_all_t *>(rs_bitvec_bs_l32_set_all),
	reinterpret_cast<set_all_t *>(rs_bitvec_bs_b64_set_all),
	reinterpret_cast<set_all_t *>(rs_bitvec_bs_l64_set_all),
}};

} // namespace func

enum class Endian : std::size_t {
	Big = 0,
	Little = 1,
};

namespace impl {

template <class T, Endian N, class Ret, class... Args, class... Ts>
auto mux(
	std::array<auto (*)(Args...) noexcept -> Ret, 8> const& funcs,
	Ts&&... ts
) noexcept -> Ret {
	constexpr auto index =
		(static_cast<std::size_t>(__builtin_ctzll(sizeof(T))) << 1)
		| static_cast<std::size_t>(N);
	return funcs[index](std::forward<Ts>(ts)...);
}

static BitPtrImmut const * make_immut(BitPtrMut const * bp) {
	return reinterpret_cast<BitPtrImmut const *>(bp);
}

static BitPtrImmut const * make_immut(BitPtrImmut const * bp) {
	return bp;
}

static BitPtrImmut * make_immut(BitPtrMut * bp) {
	return reinterpret_cast<BitPtrImmut *>(bp);
}

static BitPtrImmut * make_immut(BitPtrImmut * bp) {
	return bp;
}

} // namespace impl

template <typename T, Endian N>
class BitSliceHandle :
	std::conditional<std::is_const<T>::value, BitPtrImmut, BitPtrMut>::type {
public:
	explicit BitSliceHandle(void) noexcept {
		impl::mux<T, N>(func::empty, impl::make_immut(this));
	}
	BitSliceHandle(const T * ptr, const std::size_t len) noexcept {
		if (not impl::mux<T, N>(
			func::from_span, impl::make_immut(this), ptr, len)
		) {
			*this = BitSliceHandle();
		}
	}
	BitSliceHandle(      T * ptr, const std::size_t len) noexcept {
		if (not impl::mux<T, N>(
			func::from_span, impl::make_immut(this), ptr, len)
		) {
			*this = BitSliceHandle();
		}
	}
	BitSliceHandle(const T * ptr, const std::size_t len, const std::uint8_t head, const std::uint8_t tail) noexcept {
		if (not impl::mux<T, N>(
			func::from_span_partial, impl::make_immut(this), ptr, len, head, tail)
		) {
			*this = BitSliceHandle(ptr, len);
		}
	}
	BitSliceHandle(      T * ptr, const std::size_t len, const std::uint8_t head, const std::uint8_t tail) noexcept {
		if (not impl::mux<T, N>(
			func::from_span_partial, impl::make_immut(this), ptr, len, head, tail)
		) {
			*this = BitSliceHandle(ptr, len);
		}
	}

	size_t size(void) const noexcept {
		return impl::mux<T, N>(func::len, impl::make_immut(this));
	}

	bool is_empty(void) const noexcept {
		return 0 != mux(func::is_empty, impl::make_immut(this));
	}

	Tristate first(void) const noexcept {
		return impl::mux<T, N>(func::first, impl::make_immut(this));
	}

	Tristate split_first(void) noexcept {
		return impl::mux<T, N>(func::split_first, make_immut(this));
	}

	Tristate split_first_mut(void) noexcept {
		return impl::mux<T, N>(func::split_first_mut, this);
	}

	Tristate split_last(void) noexcept {
		return impl::mux<T, N>(func::split_last, make_immut(this));
	}

	Tristate split_last_mut(void) noexcept {
		return impl::mux<T, N>(func::split_last_mut, this);
	}

	Tristate last(void) const noexcept {
		return impl::mux<T, N>(func::last, impl::make_immut(this));
	}

	Tristate get(const std::size_t index) const noexcept {
		return impl::mux<T, N>(func::get, impl::make_immut(this), index);
	}

	void set(const std::size_t index, const bool value) const noexcept {
		mux(func::set, this, index, value);
	}

	const T *const as_ptr(void) const noexcept {
		return static_cast<const T *const>(mux(func::as_ptr, impl::make_immut(this)));
	}

	T *const as_mut_ptr(void) const noexcept {
		return static_cast<T *const>(mux(func::as_mut_ptr, this));
	}

	void swap(const std::size_t a, const std::size_t b) const noexcept {
		mux(func::swap, this, a, b);
	}

	void reverse(void) const noexcept {
		mux(func::reverse, this);
	}

	BitSliceHandle<T const, N> split_at(const std::size_t mid) noexcept {
		BitSliceHandle<T const, N> out;
		mux(func::split_at, make_immut(this), make_immut(this), mid);
		return out;
	}

	BitSliceHandle<T, N> split_last_mut(const std::size_t mid) noexcept {
		BitSliceHandle<T, N> out;
		mux(func::split_at_mut, this, out, mid);
		return out;
	}

	void rotate_left(const std::size_t by) const noexcept {
		mux(func::rotate_left, this, by);
	}

	void rotate_right(const std::size_t by) const noexcept {
		mux(func::rotate_right, this, by);
	}

	bool all(void) const noexcept {
		return impl::mux<T, N>(func::all, impl::make_immut(this));
	}

	bool any(void) const noexcept {
		return impl::mux<T, N>(func::any, impl::make_immut(this));
	}

	bool not_all(void) const noexcept {
		return impl::mux<T, N>(func::not_all, impl::make_immut(this));
	}

	bool not_any(void) const noexcept {
		return impl::mux<T, N>(func::not_any, impl::make_immut(this));
	}

	bool some(void) const noexcept {
		return impl::mux<T, N>(func::some, impl::make_immut(this));
	}

	size_t count_ones(void) const noexcept {
		return impl::mux<T, N>(func::count_ones, impl::make_immut(this));
	}

	size_t count_zeros(void) const noexcept {
		return impl::mux<T, N>(func::count_zeros, impl::make_immut(this));
	}

	void set_all(const bool value) const noexcept {
		mux(func::set_all, this, value);
	}
};

}; // namespace bitvec
}; // namespace rust

#endif//RS_BITVEC_FFI_BITSLICE_HPP
