
#include <string.h>
#include <windows.h>

#include "bochs.h"
#include "cpu.h"
#include "types.h"
#include "utils.h"

/*
   Reference for CPUID functions: https://www.symantec.com/avcenter/reference/Virtual_Machine_Threats.pdf
 */

int bochs_reg_key1() {
	return pafish_exists_regkey_value_str(HKEY_LOCAL_MACHINE, "HARDWARE\\Description\\System", "SystemBiosVersion", "BOCHS");
}

int bochs_cpu_amd1() {
	char cpu_brand[49];
	cpu_write_brand(cpu_brand);
	/* It checks the lowercase P in 'processor', an actual AMD returns Processor */
	return !memcmp(cpu_brand, "AMD Athlon(tm) processor", 24) ? TRUE : FALSE;
}

int bochs_cpu_amd2() {
//     int r_eax;
// 
//     __asm
//     {
//         xor eax, eax
//         cpuid
//         cmp ecx, 0x444d4163
//         jne b2not_detected
//         mov eax, 0x8ffffff
//         cpuid
//         jecxz b2detected
//       b2not_detected :
//         xor eax, eax
//         jmp b2exit
//       b2detected :
//         mov eax, 0x1
//       b2exit :
//         nop
//         mov r_eax, eax
//     }
// 	return r_eax ? TRUE : FALSE;
	int CPUInfo[4] = { 0 };
	__cpuid(CPUInfo, 0);
	if (CPUInfo[2] != 0x444d4163)
	{
		return FALSE;
	}
	__cpuid(CPUInfo, 0x8ffffff);
	if (CPUInfo[2])
	{
		return FALSE;
	}
	return TRUE;
}

int bochs_cpu_intel1() {
	char cpu_brand[49];
	cpu_write_brand(cpu_brand);
	/* This processor name is not known to be valid in an actual CPU */
	return !memcmp(cpu_brand, "              Intel(R) Pentium(R) 4 CPU        ", 47) ? TRUE : FALSE;
}

