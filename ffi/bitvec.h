#ifndef RS_BITVEC_FFI_BITVEC_H
#define RS_BITVEC_FFI_BITVEC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>
#include "./bitslice.h"

/**
 * @struct BitVecB08
 *
 * @brief Stack handle for an owned, managed, bit vector.
 *
 * The bits are in big-endian order, chunked in one-byte intervals.
 */
struct BitVecB08 {
    /// @brief Handle to the owned slice.
    struct HBitSliceB08M ptr;
    /// @brief Size of the allocated region, in bytes.
    size_t capacity;
};

/**
 * @struct BitVecL08
 *
 * @brief Stack handle for an owned, managed, bit vector.
 *
 * The bits are in little-endian order, chunked in one-byte intervals.
 */
struct BitVecL08 {
    /// @brief Handle to the owned slice.
    struct HBitSliceL08M ptr;
    /// @brief Size of the allocated region, in bytes
    size_t capacity;
};

/**
 * @struct BitVecB16
 *
 * @brief Stack handle for an owned, managed, bit vector.
 *
 * The bits are in big-endian order, chunked in two-byte intervals.
 */
struct BitVecB16 {
    /// @brief Handle to the owned slice.
    struct HBitSliceB16M ptr;
    /// @brief Size of the allocated region, in two-byte chunks.
    size_t capacity;
};

/**
 * @struct BitVecL16
 *
 * @brief Stack handle for an owned, managed, bit vector.
 *
 * The bits are in little-endian order, chunked in two-byte intervals.
 */
struct BitVecL16 {
    /// @brief Handle to the owned slice.
    struct HBitSliceL16M ptr;
    /// @brief Size of the allocated region, in two-byte chunks.
    size_t capacity;
};

/**
 * @struct BitVecB32
 *
 * @brief Stack handle for an owned, managed, bit vector.
 *
 * The bits are in big-endian order, chunked in four-byte intervals.
 */
struct BitVecB32 {
    /// @brief Handle to the owned slice.
    struct HBitSliceB32M ptr;
    /// @brief Size of the allocated region, in four-byte chunks.
    size_t capacity;
};

/**
 * @struct BitVecL32
 *
 * @brief Stack handle for an owned, managed, bit vector.
 *
 * The bits are in little-endian order, chunked in four-byte intervals.
 */
struct BitVecL32 {
    /// @brief Handle to the owned slice.
    struct HBitSliceL32M ptr;
    /// @brief Size of the allocated region, in four-byte chunks.
    size_t capacity;
};

/**
 * @struct BitVecB64
 *
 * @brief Stack handle for an owned, managed, bit vector.
 *
 * The bits are in big-endian order, chunked in eight-byte intervals.
 */
struct BitVecB64 {
    /// @brief Handle to the owned slice.
    struct HBitSliceB64M ptr;
    /// @brief Size of the allocated region, in eight-byte chunks.
    size_t capacity;
};

/**
 * @struct BitVecL64
 *
 * @brief Stack handle for an owned, managed, bit vector.
 *
 * The bits are in little-endian order, chunked in eight-byte intervals.
 */
struct BitVecL64 {
    /// @brief Handle to the owned slice.
    struct HBitSliceL64M ptr;
    /// @brief Size of the allocated region, in eight-byte chunks.
    size_t capacity;
};

#define RS_BITVEC_DEREF(cls) \
/** @brief Downcasts a `BitVec` to a `BitSlice` handle. */ \
/** @param self Pointer to a `BitVec` handle. */ \
/** @return Pointer to a `BitSlice` handle. */ \
/** @retval `self` */ \
struct HBitSlice ## cls ## M *const BV ## cls ## _deref(struct BitVec ## cls *const self) { \
    return &(self->ptr); \
}

RS_BITVEC_DEREF(B08)
RS_BITVEC_DEREF(L08)
RS_BITVEC_DEREF(B16)
RS_BITVEC_DEREF(L16)
RS_BITVEC_DEREF(B32)
RS_BITVEC_DEREF(L32)
RS_BITVEC_DEREF(B64)
RS_BITVEC_DEREF(L64)

#undef RS_BITVEC_DEREF

/**
 * @brief Creates a new `BitVec` handle.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 */
extern void rs_bitvec_bv_b08_new(struct BitVecB08 *const self);
/**
 * @brief Creates a new `BitVec` handle.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 */
extern void rs_bitvec_bv_l08_new(struct BitVecL08 *const self);
/**
 * @brief Creates a new `BitVec` handle.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 */
extern void rs_bitvec_bv_b16_new(struct BitVecB16 *const self);
/**
 * @brief Creates a new `BitVec` handle.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 */
extern void rs_bitvec_bv_l16_new(struct BitVecL16 *const self);
/**
 * @brief Creates a new `BitVec` handle.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 */
extern void rs_bitvec_bv_b32_new(struct BitVecB32 *const self);
/**
 * @brief Creates a new `BitVec` handle.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 */
extern void rs_bitvec_bv_l32_new(struct BitVecL32 *const self);
/**
 * @brief Creates a new `BitVec` handle.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 */
extern void rs_bitvec_bv_b64_new(struct BitVecB64 *const self);
/**
 * @brief Creates a new `BitVec` handle.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 */
extern void rs_bitvec_bv_l64_new(struct BitVecL64 *const self);

/**
 * @brief Creates a new `BitVec` handle with the specified allocation size.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 * @param capacity The capacity, in storage elements, for the new `BitVec` to
 * allocate.
 */
extern void rs_bitvec_bv_b08_with_capacity(struct BitVecB08 *const self, const size_t capacity);
/**
 * @brief Creates a new `BitVec` handle with the specified allocation size.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 * @param capacity The capacity, in storage elements, for the new `BitVec` to
 * allocate.
 */
extern void rs_bitvec_bv_l08_with_capacity(struct BitVecL08 *const self, const size_t capacity);
/**
 * @brief Creates a new `BitVec` handle with the specified allocation size.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 * @param capacity The capacity, in storage elements, for the new `BitVec` to
 * allocate.
 */
extern void rs_bitvec_bv_b16_with_capacity(struct BitVecB16 *const self, const size_t capacity);
/**
 * @brief Creates a new `BitVec` handle with the specified allocation size.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 * @param capacity The capacity, in storage elements, for the new `BitVec` to
 * allocate.
 */
extern void rs_bitvec_bv_l16_with_capacity(struct BitVecL16 *const self, const size_t capacity);
/**
 * @brief Creates a new `BitVec` handle with the specified allocation size.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 * @param capacity The capacity, in storage elements, for the new `BitVec` to
 * allocate.
 */
extern void rs_bitvec_bv_b32_with_capacity(struct BitVecB32 *const self, const size_t capacity);
/**
 * @brief Creates a new `BitVec` handle with the specified allocation size.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 * @param capacity The capacity, in storage elements, for the new `BitVec` to
 * allocate.
 */
extern void rs_bitvec_bv_l32_with_capacity(struct BitVecL32 *const self, const size_t capacity);
/**
 * @brief Creates a new `BitVec` handle with the specified allocation size.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 * @param capacity The capacity, in storage elements, for the new `BitVec` to
 * allocate.
 */
extern void rs_bitvec_bv_b64_with_capacity(struct BitVecB64 *const self, const size_t capacity);
/**
 * @brief Creates a new `BitVec` handle with the specified allocation size.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 * @param capacity The capacity, in storage elements, for the new `BitVec` to
 * allocate.
 */
extern void rs_bitvec_bv_l64_with_capacity(struct BitVecL64 *const self, const size_t capacity);

/**
 * @brief Gets the allocation capacity of a `BitVec` handle.
 * @param[in] self Pointer to a `const` handle.
 * @return The number of storage elements allocated in the handle domain.
 */
extern size_t rs_bitvec_bv_b08_capacity(const struct BitVecB08 *const self);
/**
 * @brief Gets the allocation capacity of a `BitVec` handle.
 * @param[in] self Pointer to a `const` handle.
 * @return The number of storage elements allocated in the handle domain.
 */
extern size_t rs_bitvec_bv_l08_capacity(const struct BitVecL08 *const self);
/**
 * @brief Gets the allocation capacity of a `BitVec` handle.
 * @param[in] self Pointer to a `const` handle.
 * @return The number of storage elements allocated in the handle domain.
 */
extern size_t rs_bitvec_bv_b16_capacity(const struct BitVecB16 *const self);
/**
 * @brief Gets the allocation capacity of a `BitVec` handle.
 * @param[in] self Pointer to a `const` handle.
 * @return The number of storage elements allocated in the handle domain.
 */
extern size_t rs_bitvec_bv_l16_capacity(const struct BitVecL16 *const self);
/**
 * @brief Gets the allocation capacity of a `BitVec` handle.
 * @param[in] self Pointer to a `const` handle.
 * @return The number of storage elements allocated in the handle domain.
 */
extern size_t rs_bitvec_bv_b32_capacity(const struct BitVecB32 *const self);
/**
 * @brief Gets the allocation capacity of a `BitVec` handle.
 * @param[in] self Pointer to a `const` handle.
 * @return The number of storage elements allocated in the handle domain.
 */
extern size_t rs_bitvec_bv_l32_capacity(const struct BitVecL32 *const self);
/**
 * @brief Gets the allocation capacity of a `BitVec` handle.
 * @param[in] self Pointer to a `const` handle.
 * @return The number of storage elements allocated in the handle domain.
 */
extern size_t rs_bitvec_bv_b64_capacity(const struct BitVecB64 *const self);
/**
 * @brief Gets the allocation capacity of a `BitVec` handle.
 * @param[in] self Pointer to a `const` handle.
 * @return The number of storage elements allocated in the handle domain.
 */
extern size_t rs_bitvec_bv_l64_capacity(const struct BitVecL64 *const self);

/**
 * @brief Allocates space for more storage elements in a `BitVec` handle.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param additional The number of extra storage elements to allocate.
 */
extern void rs_bitvec_bv_b08_reserve(struct BitVecB08 *const self, const size_t additional);
/**
 * @brief Allocates space for more storage elements in a `BitVec` handle.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param additional The number of extra storage elements to allocate.
 */
extern void rs_bitvec_bv_l08_reserve(struct BitVecL08 *const self, const size_t additional);
/**
 * @brief Allocates space for more storage elements in a `BitVec` handle.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param additional The number of extra storage elements to allocate.
 */
extern void rs_bitvec_bv_b16_reserve(struct BitVecB16 *const self, const size_t additional);
/**
 * @brief Allocates space for more storage elements in a `BitVec` handle.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param additional The number of extra storage elements to allocate.
 */
extern void rs_bitvec_bv_l16_reserve(struct BitVecL16 *const self, const size_t additional);
/**
 * @brief Allocates space for more storage elements in a `BitVec` handle.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param additional The number of extra storage elements to allocate.
 */
extern void rs_bitvec_bv_b32_reserve(struct BitVecB32 *const self, const size_t additional);
/**
 * @brief Allocates space for more storage elements in a `BitVec` handle.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param additional The number of extra storage elements to allocate.
 */
extern void rs_bitvec_bv_l32_reserve(struct BitVecL32 *const self, const size_t additional);
/**
 * @brief Allocates space for more storage elements in a `BitVec` handle.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param additional The number of extra storage elements to allocate.
 */
extern void rs_bitvec_bv_b64_reserve(struct BitVecB64 *const self, const size_t additional);
/**
 * @brief Allocates space for more storage elements in a `BitVec` handle.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param additional The number of extra storage elements to allocate.
 */
extern void rs_bitvec_bv_l64_reserve(struct BitVecL64 *const self, const size_t additional);

/**
 * @brief Shrinks the allocated capacity of a `BitVec` to fit its live storage.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void rs_bitvec_bv_b08_shrink_to_fit(struct BitVecB08 *const self);
/**
 * @brief Shrinks the allocated capacity of a `BitVec` to fit its live storage.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void rs_bitvec_bv_l08_shrink_to_fit(struct BitVecL08 *const self);
/**
 * @brief Shrinks the allocated capacity of a `BitVec` to fit its live storage.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void rs_bitvec_bv_b16_shrink_to_fit(struct BitVecB16 *const self);
/**
 * @brief Shrinks the allocated capacity of a `BitVec` to fit its live storage.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void rs_bitvec_bv_l16_shrink_to_fit(struct BitVecL16 *const self);
/**
 * @brief Shrinks the allocated capacity of a `BitVec` to fit its live storage.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void rs_bitvec_bv_b32_shrink_to_fit(struct BitVecB32 *const self);
/**
 * @brief Shrinks the allocated capacity of a `BitVec` to fit its live storage.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void rs_bitvec_bv_l32_shrink_to_fit(struct BitVecL32 *const self);
/**
 * @brief Shrinks the allocated capacity of a `BitVec` to fit its live storage.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void rs_bitvec_bv_b64_shrink_to_fit(struct BitVecB64 *const self);
/**
 * @brief Shrinks the allocated capacity of a `BitVec` to fit its live storage.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void rs_bitvec_bv_l64_shrink_to_fit(struct BitVecL64 *const self);

/**
 * @brief Truncates the `BitVec` at the given bit length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param len The length, in bits, of the `BitVec` domain after truncation.
 */
extern void rs_bitvec_bv_b08_truncate(struct BitVecB08 *const self, const size_t len);
/**
 * @brief Truncates the `BitVec` at the given bit length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param len The length, in bits, of the `BitVec` domain after truncation.
 */
extern void rs_bitvec_bv_l08_truncate(struct BitVecL08 *const self, const size_t len);
/**
 * @brief Truncates the `BitVec` at the given bit length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param len The length, in bits, of the `BitVec` domain after truncation.
 */
extern void rs_bitvec_bv_b16_truncate(struct BitVecB16 *const self, const size_t len);
/**
 * @brief Truncates the `BitVec` at the given bit length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param len The length, in bits, of the `BitVec` domain after truncation.
 */
extern void rs_bitvec_bv_l16_truncate(struct BitVecL16 *const self, const size_t len);
/**
 * @brief Truncates the `BitVec` at the given bit length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param len The length, in bits, of the `BitVec` domain after truncation.
 */
extern void rs_bitvec_bv_b32_truncate(struct BitVecB32 *const self, const size_t len);
/**
 * @brief Truncates the `BitVec` at the given bit length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param len The length, in bits, of the `BitVec` domain after truncation.
 */
extern void rs_bitvec_bv_l32_truncate(struct BitVecL32 *const self, const size_t len);
/**
 * @brief Truncates the `BitVec` at the given bit length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param len The length, in bits, of the `BitVec` domain after truncation.
 */
extern void rs_bitvec_bv_b64_truncate(struct BitVecB64 *const self, const size_t len);
/**
 * @brief Truncates the `BitVec` at the given bit length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param len The length, in bits, of the `BitVec` domain after truncation.
 */
extern void rs_bitvec_bv_l64_truncate(struct BitVecL64 *const self, const size_t len);

/**
 * @brief Gets a `BitSlice` handle to const bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void rs_bitvec_bv_b08_as_bitslice(const struct BitVecB08 *const self, struct HBitSliceB08C *const slice);
/**
 * @brief Gets a `BitSlice` handle to const bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void rs_bitvec_bv_l08_as_bitslice(const struct BitVecL08 *const self, struct HBitSliceL08C *const slice);
/**
 * @brief Gets a `BitSlice` handle to const bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void rs_bitvec_bv_b16_as_bitslice(const struct BitVecB16 *const self, struct HBitSliceB16C *const slice);
/**
 * @brief Gets a `BitSlice` handle to const bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void rs_bitvec_bv_l16_as_bitslice(const struct BitVecL16 *const self, struct HBitSliceL16C *const slice);
/**
 * @brief Gets a `BitSlice` handle to const bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void rs_bitvec_bv_b32_as_bitslice(const struct BitVecB32 *const self, struct HBitSliceB32C *const slice);
/**
 * @brief Gets a `BitSlice` handle to const bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void rs_bitvec_bv_l32_as_bitslice(const struct BitVecL32 *const self, struct HBitSliceL32C *const slice);
/**
 * @brief Gets a `BitSlice` handle to const bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void rs_bitvec_bv_b64_as_bitslice(const struct BitVecB64 *const self, struct HBitSliceB64C *const slice);
/**
 * @brief Gets a `BitSlice` handle to const bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void rs_bitvec_bv_l64_as_bitslice(const struct BitVecL64 *const self, struct HBitSliceL64C *const slice);

/**
 * @brief Gets a `BitSlice` handle to mutable bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void rs_bitvec_bv_b08_as_mut_bitslice(struct BitVecB08 *const self, struct HBitSliceB08M *const slice);
/**
 * @brief Gets a `BitSlice` handle to mutable bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void rs_bitvec_bv_l08_as_mut_bitslice(struct BitVecL08 *const self, struct HBitSliceL08M *const slice);
/**
 * @brief Gets a `BitSlice` handle to mutable bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void rs_bitvec_bv_b16_as_mut_bitslice(struct BitVecB16 *const self, struct HBitSliceB16M *const slice);
/**
 * @brief Gets a `BitSlice` handle to mutable bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void rs_bitvec_bv_l16_as_mut_bitslice(struct BitVecL16 *const self, struct HBitSliceL16M *const slice);
/**
 * @brief Gets a `BitSlice` handle to mutable bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void rs_bitvec_bv_b32_as_mut_bitslice(struct BitVecB32 *const self, struct HBitSliceB32M *const slice);
/**
 * @brief Gets a `BitSlice` handle to mutable bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void rs_bitvec_bv_l32_as_mut_bitslice(struct BitVecL32 *const self, struct HBitSliceL32M *const slice);
/**
 * @brief Gets a `BitSlice` handle to mutable bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void rs_bitvec_bv_b64_as_mut_bitslice(struct BitVecB64 *const self, struct HBitSliceB64M *const slice);
/**
 * @brief Gets a `BitSlice` handle to mutable bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void rs_bitvec_bv_l64_as_mut_bitslice(struct BitVecL64 *const self, struct HBitSliceL64M *const slice);

/**
 * @brief Removes a bit from a bit vector, and returns it.
 *
 * The removed bit is replaced by the last bit in the vector, rather than
 * shunting all following bits down.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index of the bit to remove and replace by the end.
 * @return The bit at the specified index.
 * @retval `False` The requested bit was `0`.
 * @retval `True` The requested bit was `1`.
 * @retval `Error` `self` is `null`, or `index` is out of range.
 */
extern enum Tristate rs_bitvec_bv_b08_swap_remove(struct BitVecB08 *const self, const size_t index);
/**
 * @brief Removes a bit from a bit vector, and returns it.
 *
 * The removed bit is replaced by the last bit in the vector, rather than
 * shunting all following bits down.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index of the bit to remove and replace by the end.
 * @return The bit at the specified index.
 * @retval `False` The requested bit was `0`.
 * @retval `True` The requested bit was `1`.
 * @retval `Error` `self` is `null`, or `index` is out of range.
 */
extern enum Tristate rs_bitvec_bv_l08_swap_remove(struct BitVecL08 *const self, const size_t index);
/**
 * @brief Removes a bit from a bit vector, and returns it.
 *
 * The removed bit is replaced by the last bit in the vector, rather than
 * shunting all following bits down.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index of the bit to remove and replace by the end.
 * @return The bit at the specified index.
 * @retval `False` The requested bit was `0`.
 * @retval `True` The requested bit was `1`.
 * @retval `Error` `self` is `null`, or `index` is out of range.
 */
extern enum Tristate rs_bitvec_bv_b16_swap_remove(struct BitVecB16 *const self, const size_t index);
/**
 * @brief Removes a bit from a bit vector, and returns it.
 *
 * The removed bit is replaced by the last bit in the vector, rather than
 * shunting all following bits down.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index of the bit to remove and replace by the end.
 * @return The bit at the specified index.
 * @retval `False` The requested bit was `0`.
 * @retval `True` The requested bit was `1`.
 * @retval `Error` `self` is `null`, or `index` is out of range.
 */
extern enum Tristate rs_bitvec_bv_l16_swap_remove(struct BitVecL16 *const self, const size_t index);
/**
 * @brief Removes a bit from a bit vector, and returns it.
 *
 * The removed bit is replaced by the last bit in the vector, rather than
 * shunting all following bits down.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index of the bit to remove and replace by the end.
 * @return The bit at the specified index.
 * @retval `False` The requested bit was `0`.
 * @retval `True` The requested bit was `1`.
 * @retval `Error` `self` is `null`, or `index` is out of range.
 */
extern enum Tristate rs_bitvec_bv_b32_swap_remove(struct BitVecB32 *const self, const size_t index);
/**
 * @brief Removes a bit from a bit vector, and returns it.
 *
 * The removed bit is replaced by the last bit in the vector, rather than
 * shunting all following bits down.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index of the bit to remove and replace by the end.
 * @return The bit at the specified index.
 * @retval `False` The requested bit was `0`.
 * @retval `True` The requested bit was `1`.
 * @retval `Error` `self` is `null`, or `index` is out of range.
 */
extern enum Tristate rs_bitvec_bv_l32_swap_remove(struct BitVecL32 *const self, const size_t index);
/**
 * @brief Removes a bit from a bit vector, and returns it.
 *
 * The removed bit is replaced by the last bit in the vector, rather than
 * shunting all following bits down.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index of the bit to remove and replace by the end.
 * @return The bit at the specified index.
 * @retval `False` The requested bit was `0`.
 * @retval `True` The requested bit was `1`.
 * @retval `Error` `self` is `null`, or `index` is out of range.
 */
extern enum Tristate rs_bitvec_bv_b64_swap_remove(struct BitVecB64 *const self, const size_t index);
/**
 * @brief Removes a bit from a bit vector, and returns it.
 *
 * The removed bit is replaced by the last bit in the vector, rather than
 * shunting all following bits down.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index of the bit to remove and replace by the end.
 * @return The bit at the specified index.
 * @retval `False` The requested bit was `0`.
 * @retval `True` The requested bit was `1`.
 * @retval `Error` `self` is `null`, or `index` is out of range.
 */
extern enum Tristate rs_bitvec_bv_l64_swap_remove(struct BitVecL64 *const self, const size_t index);

/**
 * @brief Inserts a bit at the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index at which to insert the new bit.
 * @param value The value of the inserted bit.
 *
 * Any bits to the right of `index` are shifted up by one.
 */
extern void rs_bitvec_bv_b08_insert(struct BitVecB08 *const self, const size_t index, const bool value);
/**
 * @brief Inserts a bit at the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index at which to insert the new bit.
 * @param value The value of the inserted bit.
 *
 * Any bits to the right of `index` are shifted up by one.
 */
extern void rs_bitvec_bv_l08_insert(struct BitVecL08 *const self, const size_t index, const bool value);
/**
 * @brief Inserts a bit at the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index at which to insert the new bit.
 * @param value The value of the inserted bit.
 *
 * Any bits to the right of `index` are shifted up by one.
 */
extern void rs_bitvec_bv_b16_insert(struct BitVecB16 *const self, const size_t index, const bool value);
/**
 * @brief Inserts a bit at the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index at which to insert the new bit.
 * @param value The value of the inserted bit.
 *
 * Any bits to the right of `index` are shifted up by one.
 */
extern void rs_bitvec_bv_l16_insert(struct BitVecL16 *const self, const size_t index, const bool value);
/**
 * @brief Inserts a bit at the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index at which to insert the new bit.
 * @param value The value of the inserted bit.
 *
 * Any bits to the right of `index` are shifted up by one.
 */
extern void rs_bitvec_bv_b32_insert(struct BitVecB32 *const self, const size_t index, const bool value);
/**
 * @brief Inserts a bit at the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index at which to insert the new bit.
 * @param value The value of the inserted bit.
 *
 * Any bits to the right of `index` are shifted up by one.
 */
extern void rs_bitvec_bv_l32_insert(struct BitVecL32 *const self, const size_t index, const bool value);
/**
 * @brief Inserts a bit at the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index at which to insert the new bit.
 * @param value The value of the inserted bit.
 *
 * Any bits to the right of `index` are shifted up by one.
 */
extern void rs_bitvec_bv_b64_insert(struct BitVecB64 *const self, const size_t index, const bool value);
/**
 * @brief Inserts a bit at the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index at which to insert the new bit.
 * @param value The value of the inserted bit.
 *
 * Any bits to the right of `index` are shifted up by one.
 */
extern void rs_bitvec_bv_l64_insert(struct BitVecL64 *const self, const size_t index, const bool value);

/**
 * @brief Removes a bit from the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index from which to remove the new bit.
 * @return The bit at the specified index, as a tristate boolean.
 * @retval `False` The bit was `0`.
 * @retval `True` The bit was `1`.
 * @retval `Error` `self` was `null`, or `index` was out of bounds.
 */
extern bool rs_bitvec_bv_b08_remove(struct BitVecB08 *const self, const size_t index);
/**
 * @brief Removes a bit from the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index from which to remove the new bit.
 * @return The bit at the specified index, as a tristate boolean.
 * @retval `False` The bit was `0`.
 * @retval `True` The bit was `1`.
 * @retval `Error` `self` was `null`, or `index` was out of bounds.
 */
extern bool rs_bitvec_bv_l08_remove(struct BitVecL08 *const self, const size_t index);
/**
 * @brief Removes a bit from the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index from which to remove the new bit.
 * @return The bit at the specified index, as a tristate boolean.
 * @retval `False` The bit was `0`.
 * @retval `True` The bit was `1`.
 * @retval `Error` `self` was `null`, or `index` was out of bounds.
 */
extern bool rs_bitvec_bv_b16_remove(struct BitVecB16 *const self, const size_t index);
/**
 * @brief Removes a bit from the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index from which to remove the new bit.
 * @return The bit at the specified index, as a tristate boolean.
 * @retval `False` The bit was `0`.
 * @retval `True` The bit was `1`.
 * @retval `Error` `self` was `null`, or `index` was out of bounds.
 */
extern bool rs_bitvec_bv_l16_remove(struct BitVecL16 *const self, const size_t index);
/**
 * @brief Removes a bit from the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index from which to remove the new bit.
 * @return The bit at the specified index, as a tristate boolean.
 * @retval `False` The bit was `0`.
 * @retval `True` The bit was `1`.
 * @retval `Error` `self` was `null`, or `index` was out of bounds.
 */
extern bool rs_bitvec_bv_b32_remove(struct BitVecB32 *const self, const size_t index);
/**
 * @brief Removes a bit from the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index from which to remove the new bit.
 * @return The bit at the specified index, as a tristate boolean.
 * @retval `False` The bit was `0`.
 * @retval `True` The bit was `1`.
 * @retval `Error` `self` was `null`, or `index` was out of bounds.
 */
extern bool rs_bitvec_bv_l32_remove(struct BitVecL32 *const self, const size_t index);
/**
 * @brief Removes a bit from the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index from which to remove the new bit.
 * @return The bit at the specified index, as a tristate boolean.
 * @retval `False` The bit was `0`.
 * @retval `True` The bit was `1`.
 * @retval `Error` `self` was `null`, or `index` was out of bounds.
 */
extern bool rs_bitvec_bv_b64_remove(struct BitVecB64 *const self, const size_t index);
/**
 * @brief Removes a bit from the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index from which to remove the new bit.
 * @return The bit at the specified index, as a tristate boolean.
 * @retval `False` The bit was `0`.
 * @retval `True` The bit was `1`.
 * @retval `Error` `self` was `null`, or `index` was out of bounds.
 */
extern bool rs_bitvec_bv_l64_remove(struct BitVecL64 *const self, const size_t index);

/**
 * @brief Retains only the bits in a `BitVec` that satisfy a test.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param func Function which tests each bit to determine if it is retained.
 */
extern void rs_bitvec_bv_b08_retain(struct BitVecB08 *const self, bool (*func)(bool value));
/**
 * @brief Retains only the bits in a `BitVec` that satisfy a test.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param func Function which tests each bit to determine if it is retained.
 */
extern void rs_bitvec_bv_l08_retain(struct BitVecL08 *const self, bool (*func)(bool value));
/**
 * @brief Retains only the bits in a `BitVec` that satisfy a test.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param func Function which tests each bit to determine if it is retained.
 */
extern void rs_bitvec_bv_b16_retain(struct BitVecB16 *const self, bool (*func)(bool value));
/**
 * @brief Retains only the bits in a `BitVec` that satisfy a test.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param func Function which tests each bit to determine if it is retained.
 */
extern void rs_bitvec_bv_l16_retain(struct BitVecL16 *const self, bool (*func)(bool value));
/**
 * @brief Retains only the bits in a `BitVec` that satisfy a test.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param func Function which tests each bit to determine if it is retained.
 */
extern void rs_bitvec_bv_b32_retain(struct BitVecB32 *const self, bool (*func)(bool value));
/**
 * @brief Retains only the bits in a `BitVec` that satisfy a test.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param func Function which tests each bit to determine if it is retained.
 */
extern void rs_bitvec_bv_l32_retain(struct BitVecL32 *const self, bool (*func)(bool value));
/**
 * @brief Retains only the bits in a `BitVec` that satisfy a test.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param func Function which tests each bit to determine if it is retained.
 */
extern void rs_bitvec_bv_b64_retain(struct BitVecB64 *const self, bool (*func)(bool value));
/**
 * @brief Retains only the bits in a `BitVec` that satisfy a test.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param func Function which tests each bit to determine if it is retained.
 */
extern void rs_bitvec_bv_l64_retain(struct BitVecL64 *const self, bool (*func)(bool value));

/**
 * @brief Appends a bit to the back of a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param value The bit to append.
 */
extern void rs_bitvec_bv_b08_push(struct BitVecB08 *const self, const bool value);
/**
 * @brief Appends a bit to the back of a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param value The bit to append.
 */
extern void rs_bitvec_bv_l08_push(struct BitVecL08 *const self, const bool value);
/**
 * @brief Appends a bit to the back of a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param value The bit to append.
 */
extern void rs_bitvec_bv_b16_push(struct BitVecB16 *const self, const bool value);
/**
 * @brief Appends a bit to the back of a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param value The bit to append.
 */
extern void rs_bitvec_bv_l16_push(struct BitVecL16 *const self, const bool value);
/**
 * @brief Appends a bit to the back of a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param value The bit to append.
 */
extern void rs_bitvec_bv_b32_push(struct BitVecB32 *const self, const bool value);
/**
 * @brief Appends a bit to the back of a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param value The bit to append.
 */
extern void rs_bitvec_bv_l32_push(struct BitVecL32 *const self, const bool value);
/**
 * @brief Appends a bit to the back of a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param value The bit to append.
 */
extern void rs_bitvec_bv_b64_push(struct BitVecB64 *const self, const bool value);
/**
 * @brief Appends a bit to the back of a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param value The bit to append.
 */
extern void rs_bitvec_bv_l64_push(struct BitVecL64 *const self, const bool value);

/**
 * @brief Removes the last bit from a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @return Tristate boolean ofthe last bit in the vector.
 * @retval `False` The last bit was `0`.
 * @retval `True` The last bit was `1`.
 * @retval `Error` `self` is `null`, or `*self` is empty.
 */
extern enum Tristate rs_bitvec_bv_b08_pop(struct BitVecB08 *const self);
/**
 * @brief Removes the last bit from a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @return Tristate boolean ofthe last bit in the vector.
 * @retval `False` The last bit was `0`.
 * @retval `True` The last bit was `1`.
 * @retval `Error` `self` is `null`, or `*self` is empty.
 */
extern enum Tristate rs_bitvec_bv_l08_pop(struct BitVecL08 *const self);
/**
 * @brief Removes the last bit from a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @return Tristate boolean ofthe last bit in the vector.
 * @retval `False` The last bit was `0`.
 * @retval `True` The last bit was `1`.
 * @retval `Error` `self` is `null`, or `*self` is empty.
 */
extern enum Tristate rs_bitvec_bv_b16_pop(struct BitVecB16 *const self);
/**
 * @brief Removes the last bit from a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @return Tristate boolean ofthe last bit in the vector.
 * @retval `False` The last bit was `0`.
 * @retval `True` The last bit was `1`.
 * @retval `Error` `self` is `null`, or `*self` is empty.
 */
extern enum Tristate rs_bitvec_bv_l16_pop(struct BitVecL16 *const self);
/**
 * @brief Removes the last bit from a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @return Tristate boolean ofthe last bit in the vector.
 * @retval `False` The last bit was `0`.
 * @retval `True` The last bit was `1`.
 * @retval `Error` `self` is `null`, or `*self` is empty.
 */
extern enum Tristate rs_bitvec_bv_b32_pop(struct BitVecB32 *const self);
/**
 * @brief Removes the last bit from a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @return Tristate boolean ofthe last bit in the vector.
 * @retval `False` The last bit was `0`.
 * @retval `True` The last bit was `1`.
 * @retval `Error` `self` is `null`, or `*self` is empty.
 */
extern enum Tristate rs_bitvec_bv_l32_pop(struct BitVecL32 *const self);
/**
 * @brief Removes the last bit from a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @return Tristate boolean ofthe last bit in the vector.
 * @retval `False` The last bit was `0`.
 * @retval `True` The last bit was `1`.
 * @retval `Error` `self` is `null`, or `*self` is empty.
 */
extern enum Tristate rs_bitvec_bv_b64_pop(struct BitVecB64 *const self);
/**
 * @brief Removes the last bit from a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @return Tristate boolean ofthe last bit in the vector.
 * @retval `False` The last bit was `0`.
 * @retval `True` The last bit was `1`.
 * @retval `Error` `self` is `null`, or `*self` is empty.
 */
extern enum Tristate rs_bitvec_bv_l64_pop(struct BitVecL64 *const self);

/**
 * @brief Clears a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void rs_bitvec_bv_b08_clear(struct BitVecB08 *const self);
/**
 * @brief Clears a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void rs_bitvec_bv_l08_clear(struct BitVecL08 *const self);
/**
 * @brief Clears a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void rs_bitvec_bv_b16_clear(struct BitVecB16 *const self);
/**
 * @brief Clears a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void rs_bitvec_bv_l16_clear(struct BitVecL16 *const self);
/**
 * @brief Clears a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void rs_bitvec_bv_b32_clear(struct BitVecB32 *const self);
/**
 * @brief Clears a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void rs_bitvec_bv_l32_clear(struct BitVecL32 *const self);
/**
 * @brief Clears a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void rs_bitvec_bv_b64_clear(struct BitVecB64 *const self);
/**
 * @brief Clears a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void rs_bitvec_bv_l64_clear(struct BitVecL64 *const self);

/**
 * @brief Splits a bit vector into two vectors.
 * @param[in,out] self Pointer to a `BitVec` handle. After self function, it
 * will contain the `[.. at]` half of the original vector.
 * @param[out] out Pointer to an *uninitialized* `BitVec` handle. After self
 * function, it will contain a handle governing the `[at ..]` half of the
 * original vector.
 * @param at The index at which to split the vector.
 * @return Whether the split succeeded.
 * @retval `true` The split occurred; `*out` is live.
 * @retval `false` The split failed; `*out` is not live.
 */
extern bool rs_bitvec_bv_b08_split_off(struct BitVecB08 *const self, struct BitVecB08 *const out, const size_t at);
/**
 * @brief Splits a bit vector into two vectors.
 * @param[in,out] self Pointer to a `BitVec` handle. After self function, it
 * will contain the `[.. at]` half of the original vector.
 * @param[out] out Pointer to an *uninitialized* `BitVec` handle. After self
 * function, it will contain a handle governing the `[at ..]` half of the
 * original vector.
 * @param at The index at which to split the vector.
 * @return Whether the split succeeded.
 * @retval `true` The split occurred; `*out` is live.
 * @retval `false` The split failed; `*out` is not live.
 */
extern bool rs_bitvec_bv_l08_split_off(struct BitVecL08 *const self, struct BitVecL08 *const out, const size_t at);
/**
 * @brief Splits a bit vector into two vectors.
 * @param[in,out] self Pointer to a `BitVec` handle. After self function, it
 * will contain the `[.. at]` half of the original vector.
 * @param[out] out Pointer to an *uninitialized* `BitVec` handle. After self
 * function, it will contain a handle governing the `[at ..]` half of the
 * original vector.
 * @param at The index at which to split the vector.
 * @return Whether the split succeeded.
 * @retval `true` The split occurred; `*out` is live.
 * @retval `false` The split failed; `*out` is not live.
 */
extern bool rs_bitvec_bv_b16_split_off(struct BitVecB16 *const self, struct BitVecB16 *const out, const size_t at);
/**
 * @brief Splits a bit vector into two vectors.
 * @param[in,out] self Pointer to a `BitVec` handle. After self function, it
 * will contain the `[.. at]` half of the original vector.
 * @param[out] out Pointer to an *uninitialized* `BitVec` handle. After self
 * function, it will contain a handle governing the `[at ..]` half of the
 * original vector.
 * @param at The index at which to split the vector.
 * @return Whether the split succeeded.
 * @retval `true` The split occurred; `*out` is live.
 * @retval `false` The split failed; `*out` is not live.
 */
extern bool rs_bitvec_bv_l16_split_off(struct BitVecL16 *const self, struct BitVecL16 *const out, const size_t at);
/**
 * @brief Splits a bit vector into two vectors.
 * @param[in,out] self Pointer to a `BitVec` handle. After self function, it
 * will contain the `[.. at]` half of the original vector.
 * @param[out] out Pointer to an *uninitialized* `BitVec` handle. After self
 * function, it will contain a handle governing the `[at ..]` half of the
 * original vector.
 * @param at The index at which to split the vector.
 * @return Whether the split succeeded.
 * @retval `true` The split occurred; `*out` is live.
 * @retval `false` The split failed; `*out` is not live.
 */
extern bool rs_bitvec_bv_b32_split_off(struct BitVecB32 *const self, struct BitVecB32 *const out, const size_t at);
/**
 * @brief Splits a bit vector into two vectors.
 * @param[in,out] self Pointer to a `BitVec` handle. After self function, it
 * will contain the `[.. at]` half of the original vector.
 * @param[out] out Pointer to an *uninitialized* `BitVec` handle. After self
 * function, it will contain a handle governing the `[at ..]` half of the
 * original vector.
 * @param at The index at which to split the vector.
 * @return Whether the split succeeded.
 * @retval `true` The split occurred; `*out` is live.
 * @retval `false` The split failed; `*out` is not live.
 */
extern bool rs_bitvec_bv_l32_split_off(struct BitVecL32 *const self, struct BitVecL32 *const out, const size_t at);
/**
 * @brief Splits a bit vector into two vectors.
 * @param[in,out] self Pointer to a `BitVec` handle. After self function, it
 * will contain the `[.. at]` half of the original vector.
 * @param[out] out Pointer to an *uninitialized* `BitVec` handle. After self
 * function, it will contain a handle governing the `[at ..]` half of the
 * original vector.
 * @param at The index at which to split the vector.
 * @return Whether the split succeeded.
 * @retval `true` The split occurred; `*out` is live.
 * @retval `false` The split failed; `*out` is not live.
 */
extern bool rs_bitvec_bv_b64_split_off(struct BitVecB64 *const self, struct BitVecB64 *const out, const size_t at);
/**
 * @brief Splits a bit vector into two vectors.
 * @param[in,out] self Pointer to a `BitVec` handle. After self function, it
 * will contain the `[.. at]` half of the original vector.
 * @param[out] out Pointer to an *uninitialized* `BitVec` handle. After self
 * function, it will contain a handle governing the `[at ..]` half of the
 * original vector.
 * @param at The index at which to split the vector.
 * @return Whether the split succeeded.
 * @retval `true` The split occurred; `*out` is live.
 * @retval `false` The split failed; `*out` is not live.
 */
extern bool rs_bitvec_bv_l64_split_off(struct BitVecL64 *const self, struct BitVecL64 *const out, const size_t at);

/**
 * @brief Resizes a bit vector to a new length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param new_len The new length of the vector.
 * @param value The value to use if the vector is growing in size.
 */
extern void rs_bitvec_bv_b08_resize(struct BitVecB08 *const self, const size_t new_len, const bool value);
/**
 * @brief Resizes a bit vector to a new length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param new_len The new length of the vector.
 * @param value The value to use if the vector is growing in size.
 */
extern void rs_bitvec_bv_l08_resize(struct BitVecL08 *const self, const size_t new_len, const bool value);
/**
 * @brief Resizes a bit vector to a new length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param new_len The new length of the vector.
 * @param value The value to use if the vector is growing in size.
 */
extern void rs_bitvec_bv_b16_resize(struct BitVecB16 *const self, const size_t new_len, const bool value);
/**
 * @brief Resizes a bit vector to a new length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param new_len The new length of the vector.
 * @param value The value to use if the vector is growing in size.
 */
extern void rs_bitvec_bv_l16_resize(struct BitVecL16 *const self, const size_t new_len, const bool value);
/**
 * @brief Resizes a bit vector to a new length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param new_len The new length of the vector.
 * @param value The value to use if the vector is growing in size.
 */
extern void rs_bitvec_bv_b32_resize(struct BitVecB32 *const self, const size_t new_len, const bool value);
/**
 * @brief Resizes a bit vector to a new length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param new_len The new length of the vector.
 * @param value The value to use if the vector is growing in size.
 */
extern void rs_bitvec_bv_l32_resize(struct BitVecL32 *const self, const size_t new_len, const bool value);
/**
 * @brief Resizes a bit vector to a new length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param new_len The new length of the vector.
 * @param value The value to use if the vector is growing in size.
 */
extern void rs_bitvec_bv_b64_resize(struct BitVecB64 *const self, const size_t new_len, const bool value);
/**
 * @brief Resizes a bit vector to a new length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param new_len The new length of the vector.
 * @param value The value to use if the vector is growing in size.
 */
extern void rs_bitvec_bv_l64_resize(struct BitVecL64 *const self, const size_t new_len, const bool value);

/**
 * @brief Sets each element in a bit vector backing storage to a pattern.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param element The element to use when setting the backing storage.
 */
extern void rs_bitvec_bv_b08_set_elements(struct BitVecB08 *const self, const unsigned          char element);
/**
 * @brief Sets each element in a bit vector backing storage to a pattern.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param element The element to use when setting the backing storage.
 */
extern void rs_bitvec_bv_l08_set_elements(struct BitVecL08 *const self, const unsigned          char element);
/**
 * @brief Sets each element in a bit vector backing storage to a pattern.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param element The element to use when setting the backing storage.
 */
extern void rs_bitvec_bv_b16_set_elements(struct BitVecB16 *const self, const unsigned   short   int element);
/**
 * @brief Sets each element in a bit vector backing storage to a pattern.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param element The element to use when setting the backing storage.
 */
extern void rs_bitvec_bv_l16_set_elements(struct BitVecL16 *const self, const unsigned   short   int element);
/**
 * @brief Sets each element in a bit vector backing storage to a pattern.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param element The element to use when setting the backing storage.
 */
extern void rs_bitvec_bv_b32_set_elements(struct BitVecB32 *const self, const unsigned           int element);
/**
 * @brief Sets each element in a bit vector backing storage to a pattern.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param element The element to use when setting the backing storage.
 */
extern void rs_bitvec_bv_l32_set_elements(struct BitVecL32 *const self, const unsigned           int element);
/**
 * @brief Sets each element in a bit vector backing storage to a pattern.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param element The element to use when setting the backing storage.
 */
extern void rs_bitvec_bv_b64_set_elements(struct BitVecB64 *const self, const unsigned long long int element);
/**
 * @brief Sets each element in a bit vector backing storage to a pattern.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param element The element to use when setting the backing storage.
 */
extern void rs_bitvec_bv_l64_set_elements(struct BitVecL64 *const self, const unsigned long long int element);

#ifdef __cplusplus
}
#endif

#endif//RS_BITVEC_FFI_BITVEC_H
