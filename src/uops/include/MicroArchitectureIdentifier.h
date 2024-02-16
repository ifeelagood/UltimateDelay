#pragma once

#include <cstdint>

#include "MicroArchitecture.h"

namespace uops
{

struct MicroArchitectureIdentifier
{
public:
	uint8_t family; // family + extended family
	uint8_t model;  // model  + extended model
	MicroArchitecture arch;
public:
	MicroArchitectureIdentifier();
	MicroArchitectureIdentifier(MicroArchitecture arch, uint16_t cpuid);
	MicroArchitectureIdentifier(MicroArchitecture arch, uint8_t family, uint8_t model); 
};


}

