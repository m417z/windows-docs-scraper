# IsProcessorFeaturePresent function

## Description

Determines whether the specified processor feature is supported by the current computer.

## Parameters

### `ProcessorFeature` [in]

The processor feature to be tested. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PF_ARM_64BIT_LOADSTORE_ATOMIC**<br><br>25 | The 64-bit load/store atomic instructions are available. |
| **PF_ARM_DIVIDE_INSTRUCTION_AVAILABLE**<br><br>24 | The divide instructions are available. |
| **PF_ARM_EXTERNAL_CACHE_AVAILABLE**<br><br>26 | The external cache is available. |
| **PF_ARM_FMAC_INSTRUCTIONS_AVAILABLE**<br><br>27 | The floating-point multiply-accumulate instruction is available. |
| **PF_ARM_VFP_32_REGISTERS_AVAILABLE**<br><br>18 | The VFP/Neon: 32 x 64bit register bank is present. This flag has the same meaning as **PF_ARM_VFP_EXTENDED_REGISTERS**. |
| **PF_3DNOW_INSTRUCTIONS_AVAILABLE**<br><br>7 | The 3D-Now instruction set is available. |
| **PF_CHANNELS_ENABLED**<br><br>16 | The processor channels are enabled. |
| **PF_COMPARE_EXCHANGE_DOUBLE**<br><br>2 | The atomic compare and exchange operation (cmpxchg) is available. |
| **PF_COMPARE_EXCHANGE128**<br><br>14 | The atomic compare and exchange 128-bit operation (cmpxchg16b) is available.<br><br>**Windows Server 2003 and Windows XP/2000:** This feature is not supported. |
| **PF_COMPARE64_EXCHANGE128**<br><br>15 | The atomic compare 64 and exchange 128-bit operation (cmp8xchg16) is available.<br><br>**Windows Server 2003 and Windows XP/2000:** This feature is not supported. |
| **PF_FASTFAIL_AVAILABLE**<br><br>23 | _fastfail() is available. |
| **PF_FLOATING_POINT_EMULATED**<br><br>1 | Floating-point operations are emulated using a software emulator.<br><br>This function returns a nonzero value if floating-point operations are emulated; otherwise, it returns zero. |
| **PF_FLOATING_POINT_PRECISION_ERRATA**<br><br>0 | On a Pentium, a floating-point precision error can occur in rare circumstances. |
| **PF_MMX_INSTRUCTIONS_AVAILABLE**<br><br>3 | The MMX instruction set is available. |
| **PF_NX_ENABLED**<br><br>12 | [Data execution prevention](https://learn.microsoft.com/windows/desktop/Memory/data-execution-prevention) is enabled.<br><br>**Windows XP/2000:** This feature is not supported until Windows XP with SP2 and Windows Server 2003 with SP1. |
| **PF_PAE_ENABLED**<br><br>9 | The processor is PAE-enabled. For more information, see [Physical Address Extension](https://learn.microsoft.com/windows/desktop/Memory/physical-address-extension).<br><br>All x64 processors always return a nonzero value for this feature. |
| **PF_RDTSC_INSTRUCTION_AVAILABLE**<br><br>8 | The RDTSC instruction is available. |
| **PF_RDWRFSGSBASE_AVAILABLE**<br><br>22 | RDFSBASE, RDGSBASE, WRFSBASE, and WRGSBASE instructions are available. |
| **PF_SECOND_LEVEL_ADDRESS_TRANSLATION**<br><br>20 | Second Level Address Translation is supported by the hardware. |
| **PF_SSE3_INSTRUCTIONS_AVAILABLE**<br><br>13 | The SSE3 instruction set is available.<br><br>**Windows Server 2003 and Windows XP/2000:** This feature is not supported. |
| **PF_SSSE3_INSTRUCTIONS_AVAILABLE**<br><br>36 | The SSSE3 instruction set is available. |
| **PF_SSE4_1_INSTRUCTIONS_AVAILABLE**<br><br>37 | The SSE4_1 instruction set is available. |
| **PF_SSE4_2_INSTRUCTIONS_AVAILABLE**<br><br>38 | The SSE4_2 instruction set is available. |
| **PF_AVX_INSTRUCTIONS_AVAILABLE**<br><br>39 | The AVX instruction set is available. |
| **PF_AVX2_INSTRUCTIONS_AVAILABLE**<br><br>40 | The AVX2 instruction set is available. |
| **PF_AVX512F_INSTRUCTIONS_AVAILABLE**<br><br>41 | The AVX512F instruction set is available. |
| **PF_VIRT_FIRMWARE_ENABLED**<br><br>21 | Virtualization is enabled in the firmware and made available by the operating system. |
| **PF_XMMI_INSTRUCTIONS_AVAILABLE**<br><br>6 | The SSE instruction set is available. |
| **PF_XMMI64_INSTRUCTIONS_AVAILABLE**<br><br>10 | The SSE2 instruction set is available.<br><br>**Windows 2000:** This feature is not supported. |
| **PF_XSAVE_ENABLED**<br><br>17 | The processor implements the XSAVE and XRSTOR instructions.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP/2000:** This feature is not supported until Windows 7 and Windows Server 2008 R2. |
| **PF_ARM_V8_INSTRUCTIONS_AVAILABLE**<br><br>29 | This Arm processor implements the Arm v8 instructions set. |
| **PF_ARM_V8_CRYPTO_INSTRUCTIONS_AVAILABLE**<br><br>30 | This Arm processor implements the Arm v8 extra cryptographic instructions (for example, AES, SHA1 and SHA2). |
| **PF_ARM_V8_CRC32_INSTRUCTIONS_AVAILABLE**<br><br>31 | This Arm processor implements the Arm v8 extra CRC32 instructions. |
| **PF_ARM_V81_ATOMIC_INSTRUCTIONS_AVAILABLE**<br><br>34 | This Arm processor implements the Arm v8.1 atomic instructions (for example, CAS, SWP). |
| **PF_ARM_V82_DP_INSTRUCTIONS_AVAILABLE**<br><br>43 | This Arm processor implements the Arm v8.2 DP instructions (for example, SDOT, UDOT). This feature is optional in Arm v8.2 implementations and mandatory in Arm v8.4 implementations. |
| **PF_ARM_V83_JSCVT_INSTRUCTIONS_AVAILABLE**<br><br>44 | This Arm processor implements the Arm v8.3 JSCVT instructions (for example, FJCVTZS). |
| **PF_ARM_V83_LRCPC_INSTRUCTIONS_AVAILABLE**<br><br>45 | This Arm processor implements the Arm v8.3 LRCPC instructions (for example, LDAPR). Note that certain Arm v8.2 CPUs may optionally support the LRCPC instructions. |

## Return value

If the feature is supported, the return value is a nonzero value.

If the feature is not supported, the return value is zero.

If the HAL does not support detection of the feature, whether or not the hardware supports the feature, the return value is also zero.

## Remarks

Support for ``PF_SSSE3_INSTRUCTIONS_AVAILABLE`` through ``PF_AVX512F_INSTRUCTIONS_AVAILABLE`` were added in the Windows SDK (19041) and are supported by Windows 10, Version 2004 (May 2020 Update) or later.

Support for ``PF_ERMS_AVAILABLE``, ``PF_ARM_V82_DP_INSTRUCTIONS_AVAILABLE``, and ``PF_ARM_V83_JSCVT_INSTRUCTIONS_AVAILABLE`` were added in the Windows SDK (20348) and are supported by Windows 11 and Windows Server 2022.

The define ``PF_ARM_V83_LRCPC_INSTRUCTIONS_AVAILABLE`` was added in the Windows SDK (22621) and is supported by Windows 11, Version 22H2.

## See also

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)

[System Information Functions](https://learn.microsoft.com/windows/win32/SysInfo/system-information-functions)