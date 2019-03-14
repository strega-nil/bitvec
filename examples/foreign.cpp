// compile as `driver examples/foreign.cpp target/subdir/libbitvec.so ...`

#include <cstdint>
#include <cstdio>
#include "../ffi/bitslice.hpp"

using rust::bitvec::BitSliceHandle;
using rust::bitvec::Endian;

int main(int argc, char* argv[]) {
	uint32_t arr[8];
	BitSliceHandle<uint32_t, Endian::Big> bs(arr, 8, 1, 7);
	printf("Slice has %lu bits\n", bs.size());
}
