
#include <windows.h>
#include <stdio.h>
#include <string.h>

#ifdef _WIN64
#include <intrin.h>
#endif

#include "cpu.h"
#include "types.h"


#if _MSC_VER < 1400
void __cpuid(int cpuInfo[], int eaxValue)
{
    int r_eax = 0, r_ebx = 0, r_ecx = 0, r_edx = 0;
    __asm
    {
        mov eax, eaxValue;
        cpuid;
        mov r_eax, eax;
        mov r_ebx, ebx;
        mov r_ecx, ecx;
        mov r_edx, edx;
    }
	cpuInfo[0] = r_eax;
	cpuInfo[1] = r_ebx;
	cpuInfo[2] = r_ecx;
	cpuInfo[3] = r_edx;
}
#endif

#if _MSC_VER < 1400
UINT64 __rdtsc()
{
    UINT32 r_eax, r_edx;
    __asm
    {
        rdtsc;
        mov r_eax, eax;
        mov r_edx, edx;
    }
    return ((UINT64)r_eax) | (((UINT64)r_edx) << 32);
}
#endif


static inline UINT64 rdtsc_diff() {
// 	unsigned long long ret, ret2;
// #ifdef _WIN32 || WIN32
// 	unsigned int r_eax, r_edx;
// 	__asm
// 	{
// 		rdtsc
// 		mov r_eax, eax
// 		mov r_edx, edx
// }
// 	ret = ((unsigned long long)r_eax) | (((unsigned long long)r_edx) << 32);
// 	__asm
// 	{
// 		rdtsc
// 		mov r_eax, eax
// 		mov r_edx, edx
// 	}
// 	ret2 = ((unsigned long long)r_eax) | (((unsigned long long)r_edx) << 32);
// #elif _WIN64
// 	//unsigned __int64 i;
// 	ret = __rdtsc();
// 	ret2 = __rdtsc();
// #endif
//     return ret2 - ret;
	UINT64 ret = __rdtsc();
	UINT64 ret2 = __rdtsc();
	return ret2 - ret;
}

static inline UINT64 rdtsc_diff_vmexit() {
//     unsigned long long ret, ret2;
// #ifdef _WIN32 || WIN32
//     unsigned int r_eax, r_edx;
//     __asm
//     {
//         rdtsc
//         mov r_eax, eax
//         mov r_edx, edx
//     }
//     ret = ((unsigned long long)r_eax) | (((unsigned long long)r_edx) << 32);
//     /* vm exit forced here. it uses: eax = 0; cpuid; */
//     __asm
//     {
//         mov eax, 0x00
//         cpuid
//     }
//     /**/
//     __asm
//     {
//         rdtsc
//         mov r_eax, eax
//         mov r_edx, edx
//     }
//     ret2 = ((unsigned long long)r_eax) | (((unsigned long long)r_edx) << 32);
// #elif _WIN64
// 	int CPUInfo[4] = { -1 };
// 	ret = __rdtsc();
// 	__cpuid(CPUInfo, 0);
// 	ret2 = __rdtsc();
// #endif
//     return ret2 - ret;
	UINT64 ret, ret2;
	int CPUInfo[4] = { 0 };
	ret = __rdtsc();
	__cpuid(CPUInfo, 0);
	ret2 = __rdtsc();
	return ret2 - ret;
}

static inline void cpuid_brand(char * brand, uint32_t eax_value) {
//     int r_eax = 0, r_ebx = 0, r_ecx = 0, r_edx = 0;
// 
//     __asm
//     {
//         mov eax, eax_value
//         cpuid
//         mov r_eax, eax
//         mov r_ebx, ebx
//         mov r_ecx, ecx
//         mov r_edx, edx
//     }
// 
//     sprintf(brand, "%c%c%c%c", r_eax, (r_eax >> 8), (r_eax >> 16), (r_eax >> 24));
//     sprintf(brand + 4, "%c%c%c%c", r_ebx, (r_ebx >> 8), (r_ebx >> 16), (r_ebx >> 24));
//     sprintf(brand + 8, "%c%c%c%c", r_ecx, (r_ecx >> 8), (r_ecx >> 16), (r_ecx >> 24));
//     sprintf(brand + 12, "%c%c%c%c", r_edx, (r_edx >> 8), (r_edx >> 16), (r_edx >> 24));
	int CPUInfo[4] = { 0 };
	__cpuid(CPUInfo, eax_value);
// 	sprintf(brand, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 
// 		CPUInfo[0], (CPUInfo[0] >> 8), (CPUInfo[0] >> 16), (CPUInfo[0] >> 24),
// 		CPUInfo[1], (CPUInfo[1] >> 8), (CPUInfo[1] >> 16), (CPUInfo[1] >> 24),
// 		CPUInfo[2], (CPUInfo[2] >> 8), (CPUInfo[2] >> 16), (CPUInfo[2] >> 24),
// 		CPUInfo[3], (CPUInfo[3] >> 8), (CPUInfo[3] >> 16), (CPUInfo[3] >> 24)
// 		);
    brand[0] = 0xff & CPUInfo[0];
    brand[1] = 0xff & (CPUInfo[0] >> 8);
    brand[2] = 0xff & (CPUInfo[0] >> 16);
    brand[3] = 0xff & (CPUInfo[0] >> 24);

    brand[4] = 0xff & CPUInfo[1];
    brand[5] = 0xff & (CPUInfo[1] >> 8);
    brand[6] = 0xff & (CPUInfo[1] >> 16);
    brand[7] = 0xff & (CPUInfo[1] >> 24);

    brand[8] = 0xff & CPUInfo[2];
    brand[9] = 0xff & (CPUInfo[2] >> 8);
    brand[10] = 0xff & (CPUInfo[2] >> 16);
    brand[11] = 0xff & (CPUInfo[2] >> 24);

    brand[12] = 0xff & CPUInfo[3];
    brand[13] = 0xff & (CPUInfo[3] >> 8);
    brand[14] = 0xff & (CPUInfo[3] >> 16);
    brand[15] = 0xff & (CPUInfo[3] >> 24);
}

static inline int cpuid_hv_bit() {
//     int r_ecx = 0;
// 
//     __asm
//     {
//         mov eax, 0x01
//         cpuid
//         mov r_ecx, ecx
//     }
//     return (r_ecx >> 31) & 0x1;
	int CPUInfo[4] = { 0 };
	__cpuid(CPUInfo, 0x01);
	return (CPUInfo[2] >> 31) & 0x01;
}

int cpu_rdtsc() {
	int i;
	UINT64 avg = 0;
	for (i = 0; i < 10; i++) {
		avg = avg + rdtsc_diff();
		Sleep(500);
	}
	avg = avg / 10;
	return (avg < 750 && avg > 0) ? FALSE : TRUE;
}

int cpu_rdtsc_force_vmexit() {
	int i;
	UINT64 avg = 0;
	for (i = 0; i < 10; i++) {
		avg = avg + rdtsc_diff_vmexit();
		Sleep(500);
	}
	avg = avg / 10;
	return (avg < 1000 && avg > 0) ? FALSE : TRUE;
}

int cpu_hv() {
	return cpuid_hv_bit() ? TRUE : FALSE;
}

void cpu_write_vendor(char * vendor) {
    int CPUInfo[4] = { 0 };
    __cpuid(CPUInfo, 0);
    // 	sprintf(vendor, "%c%c%c%c%c%c%c%c%c%c%c%c\0", 
    // 		CPUInfo[1], (CPUInfo[1] >> 8), (CPUInfo[1] >> 16), (CPUInfo[1] >> 24), 
    // 		CPUInfo[3], (CPUInfo[3] >> 8), (CPUInfo[3] >> 16), (CPUInfo[3] >> 24), 
    // 		CPUInfo[2], (CPUInfo[2] >> 8), (CPUInfo[2] >> 16), (CPUInfo[2] >> 24)
    // 		);
    vendor[0] = 0xff & CPUInfo[1];
    vendor[1] = 0xff & (CPUInfo[1] >> 8);
    vendor[2] = 0xff & (CPUInfo[1] >> 16);
    vendor[3] = 0xff & (CPUInfo[1] >> 24);

    vendor[4] = 0xff & CPUInfo[3];
    vendor[5] = 0xff & (CPUInfo[3] >> 8);
    vendor[6] = 0xff & (CPUInfo[3] >> 16);
    vendor[7] = 0xff & (CPUInfo[3] >> 24);

    vendor[8] = 0xff & CPUInfo[2];
    vendor[9] = 0xff & (CPUInfo[2] >> 8);
    vendor[10] = 0xff & (CPUInfo[2] >> 16);
    vendor[11] = 0xff & (CPUInfo[2] >> 24);

    vendor[12] = 0;
}

void cpu_write_hv_vendor(char * vendor) {
    int CPUInfo[4] = { 0 };
    __cpuid(CPUInfo, 0x40000000);
    // 	sprintf(vendor, "%c%c%c%c%c%c%c%c%c%c%c%c\0", 
    // 		CPUInfo[1], (CPUInfo[1] >> 8), (CPUInfo[1] >> 16), (CPUInfo[1] >> 24), 
    // 		CPUInfo[2], (CPUInfo[2] >> 8), (CPUInfo[2] >> 16), (CPUInfo[2] >> 24), 
    // 		CPUInfo[3], (CPUInfo[3] >> 8), (CPUInfo[3] >> 16), (CPUInfo[3] >> 24)
    // 		);

    vendor[0] = 0xff & CPUInfo[1];
    vendor[1] = 0xff & (CPUInfo[1] >> 8);
    vendor[2] = 0xff & (CPUInfo[1] >> 16);
    vendor[3] = 0xff & (CPUInfo[1] >> 24);

    vendor[4] = 0xff & CPUInfo[2];
    vendor[5] = 0xff & (CPUInfo[2] >> 8);
    vendor[6] = 0xff & (CPUInfo[2] >> 16);
    vendor[7] = 0xff & (CPUInfo[2] >> 24);

    vendor[8] = 0xff & CPUInfo[3];
    vendor[9] = 0xff & (CPUInfo[3] >> 8);
    vendor[10] = 0xff & (CPUInfo[3] >> 16);
    vendor[11] = 0xff & (CPUInfo[3] >> 24);

    vendor[12] = 0;
}

void cpu_write_brand(char * brand) {
// 	int r_eax;
// 	/* Check if Processor Brand String is supported */
//     __asm
//     {
//         mov eax, 0x80000000
//         cpuid
//         cmp eax, 0x80000004
//         xor eax, eax
//         setge al
//         mov r_eax, eax
//     }
// 	/* It's supported, so fill char * brand */
// 	if (r_eax) {
// 		cpuid_brand(brand,    0x80000002);
// 		cpuid_brand(brand+16, 0x80000003);
// 		cpuid_brand(brand+32, 0x80000004);
// 		brand[48] = 0x00;
// 	}

	int CPUInfo[4] = { 0 };
	/* Check if Processor Brand String is supported */
	__cpuid(CPUInfo, 0x80000000);
	/* It's supported, so fill char * brand */
	if (CPUInfo[0] >= 0x80000004) {
		cpuid_brand(brand, 0x80000002);
		cpuid_brand(brand + 16, 0x80000003);
		cpuid_brand(brand + 32, 0x80000004);
		brand[48] = 0x00;
	}
}

int cpu_known_vm_vendors() {
	int i;
	char cpu_hv_vendor[13];
	string strs[6];
	strs[0] = "KVMKVMKVM\0\0\0"; /* KVM */
	strs[1] = "Microsoft Hv"; /* Microsoft Hyper-V or Windows Virtual PC */
	strs[2] = "VMwareVMware"; /* VMware */
	strs[3] = "XenVMMXenVMM"; /* Xen */
	strs[4] = "prl hyperv  "; /* Parallels */
	strs[5] = "VBoxVBoxVBox"; /* VirtualBox */
	cpu_write_hv_vendor(cpu_hv_vendor);
	for (i = 0; i < 6; i++) {
		if (!memcmp(cpu_hv_vendor, strs[i], 12)) return TRUE;
	}
	return FALSE;
}

