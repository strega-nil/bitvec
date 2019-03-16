// compile as `driver examples/foreign.cpp target/subdir/libbitvec.so ...`

#include <cstdint>
#include <iostream>

#include <bitvec/bitslice.hpp>
#include <bitvec/bitvec.hpp>

using rust::bitvec::BitSliceHandle;
using rust::bitvec::BitVector;
using rust::bitvec::Cursor;

int main(int argc, char* argv[]) {
	BitVector<Cursor::BigEndian, std::uint32_t> bv;
	std::cout << "New BitVector has " << bv.size() << " bits" << std::endl;
	bv.push(true);
	bv.push(false);
	std::cout << "Modified BitVector has " << bv.size() << " bit(s). The first "
	<< "bit is " << std::boolalpha << bv.at(0) << std::endl;
	return 0;
}
