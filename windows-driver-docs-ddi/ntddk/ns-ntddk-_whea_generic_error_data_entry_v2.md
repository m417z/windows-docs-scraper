## Description

The WHEA_GENERIC_ERROR_DATA_ENTRY structure describes an error data section in a generic error status block.

## Members

### `SectionType`

A GUID that identifies the type of error data that is contained in the error data section. The standard section types are defined as follows:

| Section type | Description |
|---|---|
| WHEA_PACKET_SECTION_GUID | The error data section contains the hardware error packet that was passed to the operating system by the low-level hardware error handler (LLHEH) that reported the error. This data is described by a [**WHEA_ERROR_PACKET**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560465(v=vs.85)) structure. |
| PROCESSOR_GENERIC_ERROR_SECTION_GUID | The error data section contains processor error data that is not specific to a particular processor architecture. This data is described by a [**WHEA_PROCESSOR_GENERIC_ERROR_SECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_processor_generic_error_section) structure. |
| FIRMWARE_ERROR_RECORD_REFERENCE_GUID | The error data section contains a reference to a firmware error record that is specific to the Itanium processor architecture. This data is described by a [**WHEA_FIRMWARE_ERROR_RECORD_REFERENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_firmware_error_record_reference) structure. |
| IPF_PROCESSOR_ERROR_SECTION_GUID | The error data section contains processor error data that is specific to the Itanium processor architecture. For more information about the format of the error data that is contained in this error data section, see the [Intel Itanium Processor Family System Abstraction Layer Specification](https://www.intel.com/content/dam/www/public/us/en/documents/specification-updates/itanium-system-abstraction-layer-specification.pdf). |
| MEMORY_ERROR_SECTION_GUID | The error data section contains platform memory error data. This data is described by a [**WHEA_MEMORY_ERROR_SECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_memory_error_section) structure. |
| NMI_SECTION_GUID | The error data section contains nonmaskable interrupt (NMI) error data. This data is described by a [**WHEA_NMI_ERROR_SECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_nmi_error_section) structure. |
| PCIEXPRESS_ERROR_SECTION_GUID | The error data section contains PCI Express (PCIe) error data. This data is described by a [**WHEA_PCIEXPRESS_ERROR_SECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pciexpress_error_section) structure. |
| PCIXBUS_ERROR_SECTION_GUID | The error data section contains PCI/PCI-X bus error data. This data is described by a [**WHEA_PCIXBUS_ERROR_SECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pcixbus_error_section) structure. |
| WHEA_PCIXDEVICE_ERROR_SECTION | The error data section contains PCI/PCI-X device error data. This data is described by a [**WHEA_PCIXDEVICE_ERROR_SECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pcixdevice_error_section) structure. |
| XPF_PROCESSOR_ERROR_SECTION_GUID | The error data section contains processor error data that is specific to the x86 or x64 processor architecture. This data is described by a [**WHEA_XPF_PROCESSOR_ERROR_SECTION**](https://learn.microsoft.com/previous-versions/ff560655(v=vs.85)) structure. |

For error data sections that do not conform to one of the standard section types, this member contains a platform-specific GUID that identifies the type of error data that is contained in the error data section. If a platform-specific GUID is not defined for the type of error data that is contained in the error data section, this member contains GENERIC_SECTION_GUID.

### `ErrorSeverity`

A [**WHEA_ERROR_SEVERITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_whea_error_severity)-typed value that indicates the severity of the error condition that is described by the error data section.

### `Revision`

A [**WHEA_REVISION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_revision) union that describes the revision level of the WHEA_GENERIC_ERROR_DATA_ENTRY structure.

### `ValidBits`

A bitwise OR'ed combination of values that specifies which members of this structure contain valid data. Possible values are:

| Values | Description |
|---|---|
| 0x01 | A single bit that indicates that the **FRUId** member contains valid data. |
| 0x02 | A single bit that indicates that the **FRUText** member contains valid data. |

### `Flags`

A bitwise OR'ed combination of values that describes the error data section. Possible values are:

| Values | Description |
|---|---|
| 0x01 | A single bit that indicates that this error data section is the primary section within the generic error status block. When there are multiple sections contained in a generic error status block, the primary section is the section that is used for error recovery. |
| 0x02 | A single bit that indicates that the error described by this error data section was not contained within the processor or memory hierarchy. In this situation, the error might have propagated to other components of the system. |
| 0x04 | A single bit that indicates that the component must be reinitialized or re-enabled by the operating system. |
| 0x08 | A single bit that indicates that an error threshold has been exceeded. |
| 0x10 | A single bit that indicates that a resource could not be queried for error information due to conflicts with other system software or resources. In this situation, some of the fields of the error data section will be invalid. |
| 0x20 | A single bit that indicates that the reported error is a latent error (one not yet consumed) that could result in a more severe error when it is consumed. |

### `ErrorDataLength`

The length, in bytes, of the error data that is contained in the **Data** member.

### `FRUId`

A GUID that identifies the Field Replaceable Unit (FRU) that contains the hardware where the error occurred. This member contains valid data only if the **0x01** bit is set in the **ValidBits** member.

### `FRUText`

A character string that identifies the Field Replaceable Unit (FRU) that contains the hardware where the error occurred. This member contains valid data only if the **0x02** bit is set in the **ValidBits** member.

### `Timestamp`

Defines the **WHEA_TIMESTAMP** member **Timestamp**.

### `Data`

A variable-sized buffer that contains the error data for the error data section. The format of the data that is contained in this buffer is determined by the section type that is specified in the **SectionType** member.

## Remarks

A generic error status block can contain one or more WHEA_GENERIC_ERROR_DATA_ENTRY structures. Each WHEA_GENERIC_ERROR_DATA_ENTRY structure describes a section of error information that is part of the error status data for a generic error source.

The **Data** member of the [**WHEA_GENERIC_ERROR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error) structure contains a generic error status block that contains the WHEA_GENERIC_ERROR_DATA_ENTRY structures. The number of WHEA_GENERIC_ERROR_DATA_ENTRY structures that are included in the generic error status block is specified by the **ErrorDataEntryCount** member of the [**WHEA_GENERIC_ERROR_BLOCKSTATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error_blockstatus) union.

## See also

[**WHEA_GENERIC_ERROR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error)

[**WHEA_GENERIC_ERROR_BLOCKSTATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error_blockstatus)