## Description

The WHEA_PROCESSOR_FAMILY_INFO union describes the processor family information for an x86 or x64 processor.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.Stepping`

The stepping of the processor.

### `DUMMYSTRUCTNAME.Model`

The processor model identifier.

### `DUMMYSTRUCTNAME.Family`

The processor family identifier.

### `DUMMYSTRUCTNAME.ProcessorType`

The processor type identifier.

### `DUMMYSTRUCTNAME.Reserved1`

Reserved for system use.

### `DUMMYSTRUCTNAME.ExtendedModel`

The extended processor model identifier.

### `DUMMYSTRUCTNAME.ExtendedFamily`

The extended processor family identifier.

### `DUMMYSTRUCTNAME.Reserved2`

Reserved for system use.

### `DUMMYSTRUCTNAME.NativeModelId`

### `AsULONGLONG`

A ULONGLONG representation of the contents of the WHEA_PROCESSOR_FAMILY_INFO union.

## Remarks

For x86 and x64 processors, the **CPUVersion** member of the [**WHEA_PROCESSOR_GENERIC_ERROR_SECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_processor_generic_error_section) structure contains a WHEA_PROCESSOR_FAMILY_INFO union.

The contents of this union are obtained by executing the CPUID instruction with the EAX register set to 1 on input. For more information about the CPUID instruction, see the [Intel 64 and IA-32 Architectures Software Developer's Manual](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html). For additional information about the data that is contained in the members of this union, see [AP-485 Intel Processor Identification and the CPUID Instruction](https://www.intel.com/content/www/us/en/developer/overview.html).

## See also

[WHEA_PROCESSOR_GENERIC_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_processor_generic_error_section)