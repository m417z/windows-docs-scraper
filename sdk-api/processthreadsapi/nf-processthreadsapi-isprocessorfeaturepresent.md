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
| **PF_ARM_SVE_INSTRUCTIONS_AVAILABLE**<br><br>46 | This Arm processor implements the SVE (Scalable Vector Extension) instructions (**FEAT_SVE**). |
| **PF_ARM_SVE2_INSTRUCTIONS_AVAILABLE**<br><br>47 | This Arm processor implements the SVE2 instructions (**FEAT_SVE2**). |
| **PF_ARM_SVE2_1_INSTRUCTIONS_AVAILABLE**<br><br>48 | This Arm processor implements the SVE2.1 instructions (**FEAT_SVE2p1**). |
| **PF_ARM_SVE_AES_INSTRUCTIONS_AVAILABLE**<br><br>49 | This Arm processor implements the SVE AES instructions (**FEAT_SVE_AES**). |
| **PF_ARM_SVE_PMULL128_INSTRUCTIONS_AVAILABLE**<br><br>50 | This Arm processor implements the SVE 128-bit polynomial multiply long instructions (**FEAT_SVE_PMULL128**). |
| **PF_ARM_SVE_BITPERM_INSTRUCTIONS_AVAILABLE**<br><br>51 | This Arm processor implements the SVE bit permute instructions (**FEAT_SVE_BitPerm**). |
| **PF_ARM_SVE_BF16_INSTRUCTIONS_AVAILABLE**<br><br>52 | This Arm processor implements the SVE BF16 (BFloat16) instructions (**FEAT_BF16**). |
| **PF_ARM_SVE_EBF16_INSTRUCTIONS_AVAILABLE**<br><br>53 | This Arm processor implements the SVE EBF16 (Extended BFloat16) instructions (**FEAT_EBF16**). |
| **PF_ARM_SVE_B16B16_INSTRUCTIONS_AVAILABLE**<br><br>54 | This Arm processor implements the SVE B16B16 instructions (**FEAT_SVE_B16B16**). |
| **PF_ARM_SVE_SHA3_INSTRUCTIONS_AVAILABLE**<br><br>55 | This Arm processor implements the SVE SHA-3 cryptographic instructions (**FEAT_SVE_SHA3**). |
| **PF_ARM_SVE_SM4_INSTRUCTIONS_AVAILABLE**<br><br>56 | This Arm processor implements the SVE SM4 cryptographic instructions (**FEAT_SVE_SM4**). |
| **PF_ARM_SVE_I8MM_INSTRUCTIONS_AVAILABLE**<br><br>57 | This Arm processor implements the SVE I8MM (Int8 matrix multiply) instructions (**FEAT_I8MM**). |
| **PF_ARM_SVE_F32MM_INSTRUCTIONS_AVAILABLE**<br><br>58 | This Arm processor implements the SVE F32MM (FP32 matrix multiply) instructions (**FEAT_F32MM**). |
| **PF_ARM_SVE_F64MM_INSTRUCTIONS_AVAILABLE**<br><br>59 | This Arm processor implements the SVE F64MM (FP64 matrix multiply) instructions (**FEAT_F64MM**). |
| **PF_BMI2_INSTRUCTIONS_AVAILABLE**<br><br>60 | This x64 processor implements the BMI2 instruction set. |
| **PF_MOVDIR64B_INSTRUCTION_AVAILABLE**<br><br>61 | This x64 processor implements the MOVDIR64B instruction. |
| **PF_ARM_LSE2_AVAILABLE**<br><br>62 | This Arm processor implements the LSE2 atomic instructions (**FEAT_LSE2**). |
| **PF_ARM_SHA3_INSTRUCTIONS_AVAILABLE**<br><br>64 | This Arm processor implements the SHA-3 cryptographic instructions (**FEAT_SHA3**). |
| **PF_ARM_SHA512_INSTRUCTIONS_AVAILABLE**<br><br>65 | This Arm processor implements the SHA-512 cryptographic instructions (**FEAT_SHA512**). |
| **PF_ARM_V82_I8MM_INSTRUCTIONS_AVAILABLE**<br><br>66 | This Arm processor implements the I8MM (Int8 matrix multiply) NEON instructions (**FEAT_I8MM**). |
| **PF_ARM_V82_FP16_INSTRUCTIONS_AVAILABLE**<br><br>67 | This Arm processor implements the FP16 (half-precision floating point) NEON instructions (**FEAT_FP16**). |
| **PF_ARM_V86_BF16_INSTRUCTIONS_AVAILABLE**<br><br>68 | This Arm processor implements the BF16 (BFloat16) NEON instructions (**FEAT_BF16**). |
| **PF_ARM_V86_EBF16_INSTRUCTIONS_AVAILABLE**<br><br>69 | This Arm processor implements the EBF16 (Extended BFloat16) NEON instructions (**FEAT_EBF16**). |
| **PF_ARM_SME_INSTRUCTIONS_AVAILABLE**<br><br>70 | This Arm processor implements the SME (Scalable Matrix Extension) instructions (**FEAT_SME**). |
| **PF_ARM_SME2_INSTRUCTIONS_AVAILABLE**<br><br>71 | This Arm processor implements the SME2 instructions (**FEAT_SME2**). |
| **PF_ARM_SME2_1_INSTRUCTIONS_AVAILABLE**<br><br>72 | This Arm processor implements the SME2.1 instructions (**FEAT_SME2p1**). |
| **PF_ARM_SME2_2_INSTRUCTIONS_AVAILABLE**<br><br>73 | This Arm processor implements the SME2.2 instructions (**FEAT_SME2p2**). |
| **PF_ARM_SME_AES_INSTRUCTIONS_AVAILABLE**<br><br>74 | This Arm processor implements the SVE AES instructions when in Streaming SVE mode (**FEAT_SSVE_AES**). |
| **PF_ARM_SME_SBITPERM_INSTRUCTIONS_AVAILABLE**<br><br>75 | This Arm processor implements the SVE bit permute instructions when in Streaming SVE mode (**FEAT_SSVE_BitPerm**). |
| **PF_ARM_SME_SF8MM4_INSTRUCTIONS_AVAILABLE**<br><br>76 | This Arm processor implements the SVE FMMLA (widening, 4-way, FP8 to FP16) instruction when in Streaming SVE mode (**FEAT_SSVE_F8F16MM**). |
| **PF_ARM_SME_SF8MM8_INSTRUCTIONS_AVAILABLE**<br><br>77 | This Arm processor implements the SVE FMMLA (widening, 8-way, FP8 to FP32) instruction when in Streaming SVE mode (**FEAT_SSVE_F8F32MM**). |
| **PF_ARM_SME_SF8DP2_INSTRUCTIONS_AVAILABLE**<br><br>78 | This Arm processor implements the SVE2 FP8DOT2 instructions when in Streaming SVE mode (**FEAT_SSVE_FP8DOT2**). |
| **PF_ARM_SME_SF8DP4_INSTRUCTIONS_AVAILABLE**<br><br>79 | This Arm processor implements the SVE2 FP8DOT4 instructions when in Streaming SVE mode (**FEAT_SSVE_FP8DOT4**). |
| **PF_ARM_SME_SF8FMA_INSTRUCTIONS_AVAILABLE**<br><br>80 | This Arm processor implements the SVE2 FP8FMA instructions when in Streaming SVE mode (**FEAT_SSVE_FP8FMA**). |
| **PF_ARM_SME_F8F32_INSTRUCTIONS_AVAILABLE**<br><br>81 | This Arm processor implements the SME F8F32 instructions (**FEAT_SME_F8F32**). |
| **PF_ARM_SME_F8F16_INSTRUCTIONS_AVAILABLE**<br><br>82 | This Arm processor implements the SME F8F16 instructions (**FEAT_SME_F8F16**). |
| **PF_ARM_SME_F16F16_INSTRUCTIONS_AVAILABLE**<br><br>83 | This Arm processor implements the SME F16F16 instructions (**FEAT_SME_F16F16**). |
| **PF_ARM_SME_B16B16_INSTRUCTIONS_AVAILABLE**<br><br>84 | This Arm processor implements the SME B16B16 instructions (**FEAT_SME_B16B16**). |
| **PF_ARM_SME_F64F64_INSTRUCTIONS_AVAILABLE**<br><br>85 | This Arm processor implements the SME F64F64 instructions (**FEAT_SME_F64F64**). |
| **PF_ARM_SME_I16I64_INSTRUCTIONS_AVAILABLE**<br><br>86 | This Arm processor implements the SME I16I64 instructions (**FEAT_SME_I16I64**). |
| **PF_ARM_SME_LUTv2_INSTRUCTIONS_AVAILABLE**<br><br>87 | This Arm processor implements the SME LUTv2 instructions (**FEAT_SME_LUTv2**). |
| **PF_ARM_SME_FA64_INSTRUCTIONS_AVAILABLE**<br><br>88 | This Arm processor implements SME FA64 (Full AArch64 instruction set when in Streaming SVE mode) (**FEAT_SME_FA64**). |
| **PF_UMONITOR_INSTRUCTION_AVAILABLE**<br><br>89 | This x64 processor implements the UMONITOR instruction. |

## Return value

If the feature is supported, the return value is a nonzero value.

If the feature is not supported, the return value is zero.

If the HAL does not support detection of the feature, whether or not the hardware supports the feature, the return value is also zero.

## Remarks

Support for ``PF_SSSE3_INSTRUCTIONS_AVAILABLE`` through ``PF_AVX512F_INSTRUCTIONS_AVAILABLE`` were added in the Windows SDK (19041) and are supported by Windows 10, Version 2004 (May 2020 Update) or later.

Support for ``PF_ERMS_AVAILABLE``, ``PF_ARM_V82_DP_INSTRUCTIONS_AVAILABLE``, and ``PF_ARM_V83_JSCVT_INSTRUCTIONS_AVAILABLE`` were added in the Windows SDK (20348) and are supported by Windows 11 and Windows Server 2022.

The define ``PF_ARM_V83_LRCPC_INSTRUCTIONS_AVAILABLE`` was added in the Windows SDK (22621) and is supported by Windows 11, Version 22H2.

Support for ``PF_ARM_SVE_INSTRUCTIONS_AVAILABLE`` through ``PF_MOVDIR64B_INSTRUCTION_AVAILABLE`` and ``PF_ARM_SHA3_INSTRUCTIONS_AVAILABLE`` through ``PF_ARM_V86_EBF16_INSTRUCTIONS_AVAILABLE`` were added in the Windows SDK (26100) and are supported by Windows 11, version 24H2 and Windows Server 2025 or later.

## See also

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)

[System Information Functions](https://learn.microsoft.com/windows/win32/SysInfo/system-information-functions)