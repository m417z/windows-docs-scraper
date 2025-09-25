## Description

The **WHEA_PROCESSOR_GENERIC_ERROR_SECTION** structure describes processor error data that is not specific to a particular processor architecture.

## Members

### `ValidBits`

A [**WHEA_PROCESSOR_GENERIC_ERROR_SECTION_VALIDBITS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_processor_generic_error_section_validbits) union that specifies which members of this structure contain valid data.

### `ProcessorType`

The processor architecture of the processor.

This member contains valid data only if the **ProcessorType** bit of the **ValidBits** member is set.

| Value | Description |
|---|---|
| GENPROC_PROCTYPE_XPF | x86/x64 processor family |
| GENPROC_PROCTYPE_IPF | Intel Itanium processor family |

### `InstructionSet`

The instruction set that was executing when the error occurred.

This member contains valid data only if the **InstructionSet** bit of the **ValidBits** member is set.

| Value | Description |
|---|---|
| GENPROC_PROCISA_X86 | x86 |
| GENPROC_PROCISA_IPF | Itanium |
| GENPROC_PROCISA_X64 | x64 |

### `ErrorType`

The type of error that occurred.

This member contains valid data only if the **ErrorType** bit of the **ValidBits** member is set.

| Value | Description |
|---|---|
| GENPROC_PROCERRTYPE_UNKNOWN | Unknown error |
| GENPROC_PROCERRTYPE_CACHE | Cache error |
| GENPROC_PROCERRTYPE_TLB | Translation lookaside buffer error |
| GENPROC_PROCERRTYPE_BUS | Bus error |
| GENPROC_PROCERRTYPE_MAE | Microarchitecture error |

### `Operation`

The type of operation that was executing when the error occurred.

This member contains valid data only if the **Operation** bit of the **ValidBits** member is set.

| Value | Description |
|---|---|
| GENPROC_OP_GENERIC | Unknown or generic operation |
| GENPROC_OP_DATAREAD | Data read |
| GENPROC_OP_DATAWRITE | Data write |
| GENPROC_OP_INSTRUCTIONEXE | Instruction execution |

### `Flags`

A bit-wise OR'ed combination of flags that provides additional information about the error.

This member contains valid data only if the **Flags** bit of the **ValidBits** member is set.

| Value | Description |
|---|---|
| GENPROC_FLAGS_RESTARTABLE | Program execution can be restarted reliably after the error. |
| GENPROC_FLAGS_PRECISEIP | The instruction pointer in the **InstructionPointer** member is directly associated with the error. |
| GENPROC_FLAGS_OVERFLOW | A machine check overflow occurred. This happens when a second error occurs while the results of the previous error are still in the error reporting resources. |
| GENPROC_FLAGS_CORRECTED | The error was corrected by the hardware or the firmware. |

### `Level`

The level of the structure where the error occurred, with zero being the lowest level of cache.

This member contains valid data only if the **Level** bit of the **ValidBits** member is set.

### `Reserved`

Reserved for system use.

### `CPUVersion`

The CPU version, which includes the family, model, and stepping information.

- For x86 and x64 processors, this member contains a [**WHEA_PROCESSOR_FAMILY_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_processor_family_info) union.

- For Itanium processors, this member contains the data provided in CPUID Register 3.

This member contains valid data only if the **CPUVersion** bit of the **ValidBits** member is set.

### `CPUBrandString`

The CPU brand string.

- For x86 and x64 processors, this member contains the result of executing the CPUID instruction with EAX set to 0x80000002 on input, followed by executing the CPUID instruction with EAX set to 0x80000003 on input. For more information about the CPUID instruction, see the [Intel 64 and IA-32 Architectures Software Developer's Manual](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html)

- For Itanium processors, this member contains the result of executing the **PAL_BRAND_INFO** procedure.

This member contains valid data only if the **CpuBrandString** bit of the **ValidBits** member is set.

### `ProcessorId`

An identifier that uniquely identifies the logical processor in the system.

- For x86 and x64 processors, this member contains the value programmed into the local APIC ID register.

- For Itanium processors, this member contains the value programmed into the LID register.

This member contains valid data only if the **ProcessorId** bit of the **ValidBits** member is set.

### `TargetAddress`

The target address associated with the error.

This member contains valid data only if the **TargetAddress** bit of the **ValidBits** member is set.

### `RequesterId`

An identifier that uniquely identifies the requester associated with the error.

This member contains valid data only if the **RequesterId** bit of the **ValidBits** member is set.

### `ResponderId`

An identifier that uniquely identifies the responder associated with the error.

This member contains valid data only if the **ResponderId** bit of the **ValidBits** member is set.

### `InstructionPointer`

The instruction pointer at the time that the error occurred.

This member contains valid data only if the **InstructionPointer** bit of the **ValidBits** member is set.

## Remarks

The **WHEA_PROCESSOR_GENERIC_ERROR_SECTION** structure describes the error data that is contained in a generic processor error section of an [error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records). An error record contains a generic processor error section only if the **SectionType** member of one of the [**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) structures that describe the error record sections for that error record contains **PROCESSOR_GENERIC_ERROR_SECTION_GUID**.

## See also

[**WHEA_ERROR_PACKET**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560465(v=vs.85))

[**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor)

[**WHEA_PROCESSOR_FAMILY_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_processor_family_info)

[**WHEA_PROCESSOR_GENERIC_ERROR_SECTION_VALIDBITS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_processor_generic_error_section_validbits)