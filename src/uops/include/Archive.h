#pragma once

#include <istream>
#include <ostream>

namespace uops
{

struct Archive
{
public:
	static constexpr int8_t MAGIC[4] = { 'U','O','P','S' };

public:
	int8_t magic[4];               // UOPS
	uint32_t archIdentifierCount;  // number of CPUID microarchitecture identifier records


};

}