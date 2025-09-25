## Description

The **WHEA_ERROR_PACKET_V1** structure describes the hardware error data that is passed to the operating system by a low-level hardware error handler (LLHEH).

The **WHEA_ERROR_PACKET_V1** structure is supported in Windows Server 2008 and Windows Vista SP1.

For Windows 7 and later versions of Windows, use the [**WHEA_ERROR_PACKET_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_packet_v2) structure.

## Members

### `Signature`

The signature of the hardware error packet. This member contains the value WHEA_ERROR_PACKET_V1_SIGNATURE.

### `Flags`

A [**WHEA_ERROR_PACKET_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_packet_flags) union that describes the error condition.

### `Size`

The size, in bytes, of the hardware error packet, including the raw data.

### `RawDataLength`

The length, in bytes, of the data that is contained in the **RawData** member.

### `Reserved1`

Reserved for system use.

### `Context`

Reserved for system use.

### `ErrorType`

A [WHEA_ERROR_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_whea_error_type)-typed value that indicates the type of hardware component that reported the hardware error.

### `ErrorSeverity`

A [WHEA_ERROR_SEVERITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_whea_error_severity)-typed value that indicates the severity of the error condition.

### `ErrorSourceId`

The identifier of the error source that reported the hardware error.

### `ErrorSourceType`

A [WHEA_ERROR_SOURCE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_whea_error_source_type)-typed value that indicates the type of error source that reported the hardware error.

### `Reserved2`

Reserved for system use.

### `Version`

The version of the WHEA_ERROR_PACKET_V1 structure. This member contains the value WHEA_ERROR_PKT_V1VERSION.

### `Cpu`

Reserved for system use.

### `u`

A union consisting of the following members:

### `u.ProcessorError`

A [**WHEA_PROCESSOR_GENERIC_ERROR_SECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_processor_generic_error_section) structure that describes processor error data. This member is used only when the **ErrorType** member is set to **WheaErrTypeProcessor**.

### `u.MemoryError`

A [**WHEA_MEMORY_ERROR_SECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_memory_error_section) structure that describes memory error data. This member is used only when the **ErrorType** member is set to **WheaErrTypeMemory**.

### `u.NmiError`

A [**WHEA_NMI_ERROR_SECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_nmi_error_section) structure that describes nonmaskable interrupt (NMI) error data. This member is used only when the **ErrorType** member is set to **WheaErrTypeNMI**.

### `u.PciExpressError`

A [**WHEA_PCIEXPRESS_ERROR_SECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pciexpress_error_section) structure that describes PCI Express (PCIe) error data. This member is used only when the **ErrorType** member is set to **WheaErrTypePCIExpress**.

### `u.PciXBusError`

A [**WHEA_PCIXBUS_ERROR_SECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pcixbus_error_section) structure that describes PCI or PCI-X bus error data. This member is used only when the **ErrorType** member is set to **WheaErrTypePCIXBus**.

### `u.PciXDeviceError`

A [**WHEA_PCIXDEVICE_ERROR_SECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pcixdevice_error_section) structure that describes PCI or PCI-X device error data. This member is used only when the **ErrorType** member is set to **WheaErrTypePCIXDevice**.

### `RawDataFormat`

A [WHEA_RAW_DATA_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_whea_raw_data_format)-typed value that indicates the format of the hardware error information that is contained in the **RawData** data buffer.

### `RawDataOffset`

An offset, in bytes, from the beginning of the **RawData** data buffer where a PSHED plug-in can add supplementary platform-specific error information to the hardware error packet. The amount of supplementary information that can be added to the hardware error packet is limited by the total size of the packet as specified in the **Size** member.

### `RawData`

A variable-sized data buffer that contains the raw hardware error information from the error source's status registers. The format of the hardware error data is specified by the **RawDataFormat** member.

### `u.PmemError`

## Remarks

The WHEA_ERROR_PACKET_V1 structure is used to report a hardware error in Windows Server 2008 and Windows Vista SP1.

If your [platform-specific hardware error driver (PSHED) plug-ins](https://learn.microsoft.com/windows-hardware/drivers/whea/platform-specific-hardware-error-driver-plug-ins2) run on any WHEA-compatible Windows version, You can inspect the version of WHEA_ERROR_PACKET by following these steps:

1. If the **Signature** member for the WHEA_ERROR_PACKET equals WHEA_ERROR_PACKET_V1_SIGNATURE, the code is running on an early version of Windows, and the error packet is formatted as a **WHEA_ERROR_PACKET_V1** structure.

1. If the **Signature** member for the WHEA_ERROR_PACKET equals WHEA_ERROR_PACKET_V2_SIGNATURE, the code is running on a later version of Windows, and the error packet is formatted as a [**WHEA_ERROR_PACKET_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_packet_v2) structure.

An LLHEH passes a **WHEA_ERROR_PACKET_V1** structure to the operating system when it reports a hardware error. This hardware error packet contains the raw hardware error data direct from the error source's error status registers.

The WHEA_ERROR_PACKET_V1 structure describes the error data that is contained in a hardware error packet error section of an [error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records). An error record contains a hardware error packet error section only if the **SectionType** member of one of the [**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) structures that describe the error record sections for that error record contains WHEA_PACKET_SECTION_GUID.

## See also

[Platform-Specific Hardware Error Driver (PSHED) Plug-Ins](https://learn.microsoft.com/windows-hardware/drivers/whea/platform-specific-hardware-error-driver-plug-ins2)

[**WHEA_ERROR_PACKET_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_packet_flags)

[**WHEA_ERROR_PACKET_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_packet_v2)

[**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor)

[WHEA_ERROR_SEVERITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_whea_error_severity)

[WHEA_ERROR_SOURCE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_whea_error_source_type)

[WHEA_ERROR_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_whea_error_type)

[**WHEA_MEMORY_ERROR_SECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_memory_error_section)

[**WHEA_NMI_ERROR_SECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_nmi_error_section)

[**WHEA_PCIEXPRESS_ERROR_SECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pciexpress_error_section)

[**WHEA_PCIXBUS_ERROR_SECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pcixbus_error_section)

[**WHEA_PCIXDEVICE_ERROR_SECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pcixdevice_error_section)

[**WHEA_PROCESSOR_GENERIC_ERROR_SECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_processor_generic_error_section)

[WHEA_RAW_DATA_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_whea_raw_data_format)