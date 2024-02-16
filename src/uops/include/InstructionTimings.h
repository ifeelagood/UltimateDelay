#pragma once

#include <cstdint>

#include "MicroArchitecture.h"


namespace uops
{

struct InstructionTimings
{
public:
    char* asm;          // assembly instruction
	float throughput;   // instruction throughput (looped)
	float latency;      // instruction latency
	uint8_t uops;       // microoperations
};

}