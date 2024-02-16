#include <iostream>
#include <cstdint>
#include <format>
#include <iomanip>

// include compiler intrinsics for msvc
#if defined(_MSC_VER) && !defined(__INTEL_COMPILER)
#include <intrin.h> 
#endif

struct CPUInfo
{
	int32_t eax, ebx, ecx, edx;


	CPUInfo();
	CPUInfo(int32_t registers[4])
		: eax(registers[0]), ebx(registers[1]), ecx(registers[2]), edx(registers[3])
	{}

	friend std::ostream& operator<<(std::ostream& os, const CPUInfo& info)
	{
		os << "CPUID" << '\n'
			<< '\t' << "EAX: " << std::setfill('0') << std::setw(sizeof(int32_t) * 2) << std::hex << info.eax << '\n'
			<< '\t' << "EBX: " << std::setfill('0') << std::setw(sizeof(int32_t) * 2) << std::hex << info.ebx << '\n'
			<< '\t' << "ECX: " << std::setfill('0') << std::setw(sizeof(int32_t) * 2) << std::hex << info.ecx << '\n'
			<< '\t' << "EDX: " << std::setfill('0') << std::setw(sizeof(int32_t) * 2) << std::hex << info.edx <<
			std::endl;

		return os;
	}
};

CPUInfo cpuid(int functionid)
{

#if defined(_MSC_VER) && !defined(__INTEL_COMPILER)
	int32_t registers[4];
	__cpuid(registers, functionid);

	CPUInfo info(registers);

#elif defined(__clang__)
	CPUInfo info;

	__asm__ volatile ("CPUID"
	: "=a"(info.eax), "=b"(info.ebx), "=c"(info.ecx), "=d"(info.edx)
		: "a"(info.functionid)
		);

#endif
	return info;
}

int main(int argc, char* argv[])
{
	auto info = cpuid(0);

	std::cout << info;

	return EXIT_SUCCESS;
}