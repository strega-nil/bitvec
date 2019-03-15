// compile as `driver examples/foreign.cpp target/subdir/libbitvec.so ...`

#include <cstdint>
#include <iostream>

#include <bitvec/bitslice.hpp>

using rust::bitvec::BitSliceHandle;
using rust::bitvec::Cursor;

int main(int argc, char* argv[]) {
	uint32_t arr[8];
	BitSliceHandle<Cursor::BigEndian, uint32_t> bs(arr, 8);
	bs.set_all(0);
	bs.set(17, true);
	std::cout << "Slice contains " << bs.size() << " bits, and "
		<< bs.count_ones() << " are set " << std::endl;
}
