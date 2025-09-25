# ExIsProcessorFeaturePresent function

## Description

The **ExIsProcessorFeaturePresent** routine queries for the existence of a specified processor feature.

## Parameters

### `ProcessorFeature` [in]

Specifies one of the following constant values:

#### PF_FLOATING_POINT_PRECISION_ERRATA

The processor has the Pentium floating-point divide bug.

#### PF_FLOATING_POINT_EMULATED

The processor does not have floating-point hardware.

#### PF_COMPARE_EXCHANGE_DOUBLE

The processor has an 8-byte, memory-locked compare and exchange (CMPXCHG8B) instruction.

#### PF_MMX_INSTRUCTIONS_AVAILABLE

The processor supports MMX instructions in hardware.

#### PF_XMMI_INSTRUCTIONS_AVAILABLE

The processor supports SSE instructions in hardware.

#### PF_3DNOW_INSTRUCTIONS_AVAILABLE

The processor supports AMD 3DNow instructions.

#### PF_RDTSC_INSTRUCTION_AVAILABLE

The processor supports a read-timestamp-counter (RDTSC) instruction.

#### PF_PAE_ENABLED

The processor implements Physical Address Extension (PAE) support.

#### PF_XMMI64_INSTRUCTIONS_AVAILABLE

The processor supports SSE2 instructions in hardware. This parameter value is supported only in Windows XP and later versions of Windows.

#### PF_SSE_DAZ_MODE_AVAILABLE

The processor supports the denormals-are-zero (DAZ) mode for SSE instructions. This parameter value is supported only in Windows Vista and later versions of Windows.

#### PF_NX_ENABLED

[Data execution prevention](https://learn.microsoft.com/windows/win32/memory/data-execution-prevention) is enabled. This parameter value is supported only in Windows Vista and later versions of Windows.

#### PF_SSE3_INSTRUCTIONS_AVAILABLE

The processor supports SSE3 instructions. This parameter value is supported only in Windows Vista and later versions of Windows.

#### PF_COMPARE_EXCHANGE128

The atomic compare and exchange 128-bit operation (CMPXCHG16B) is available. This parameter value is supported only in Windows Vista and later versions of Windows.

#### PF_COMPARE64_EXCHANGE128

The atomic compare 64-bit and exchange 128-bit operation (CMP8XCHG16) is available. This parameter value is supported only in Windows Vista and later versions of Windows.

#### PF_XSAVE_ENABLED

The processor supports the XSAVE and XRSTOR instructions. This parameter value is supported only in Windows 7 and later versions of Windows.

## Return value

**ExIsProcessorFeaturePresent** returns **TRUE** if the specified processor feature is present; otherwise, it returns **FALSE**.