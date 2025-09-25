## Description

The **WHEA_XPF_PROCESSOR_ERROR_SECTION** structure describes processor error data that is specific to the x86/x64 processor architecture.

## Members

### `ValidBits`

A [**WHEA_XPF_PROCESSOR_ERROR_SECTION_VALIDBITS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_processor_error_section_validbits) union that specifies which members of this structure contain valid data and the number of structures that are contained in the **VariableInfo** member.

### `LocalAPICId`

The value programmed into the local APIC ID register.

This member contains valid data only if the **ValidBits.LocalAPICId** bit is set.

### `CpuId`

A 48-byte buffer that contains the results of executing the CPUID instruction. For more information about the CPUID instruction, see the [Intel 64 and IA-32 Architectures Software Developer's Manual](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html).

This member contains valid data only if the **ValidBits.CpuId** bit is set.

### `VariableInfo`

A variable length buffer that contains zero or more [**WHEA_XPF_PROCINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_procinfo) structures followed by zero or more [**WHEA_XPF_CONTEXT_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_context_info) structures. The number of WHEA_XPF_PROCINFO structures is specified in **ValidBits.ProcInfoCount**. The number of WHEA_XPF_CONTEXT_INFO structures is specified in **ValidBits.ContextInfoCount**. For a diagram that shows how these data structures are stored in the buffer, see the Remarks section.

## Remarks

The WHEA_XPF_PROCESSOR_ERROR_SECTION structure describes the error data that is contained in an x86/x64 processor error section of an [error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records). An error record contains an x86/x64 processor error section only if the **SectionType** member of one of the [**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) structures that describes the error record sections for that error record contains XPF_PROCESSOR_ERROR_SECTION_GUID.

The following diagram shows how the data structures that contain the processor error data are stored in the **VariableInfo** member.

![Diagram illustrating how the data structures that contain the processor error data are stored in the VariableInfo member](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/images/wheaxpfsection.png)

## See also

[**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor)

[**WHEA_XPF_CONTEXT_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_context_info)

[**WHEA_XPF_PROCESSOR_ERROR_SECTION_VALIDBITS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_processor_error_section_validbits)

[**WHEA_XPF_PROCINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_procinfo)