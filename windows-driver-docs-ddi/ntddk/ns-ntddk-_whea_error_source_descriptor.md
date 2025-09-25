# _WHEA_ERROR_SOURCE_DESCRIPTOR structure

## Description

The WHEA_ERROR_SOURCE_DESCRIPTOR structure describes an error source.

## Members

### `Length`

The size, in bytes, of the WHEA_ERROR_SOURCE_DESCRIPTOR structure.

### `Version`

The version number of the WHEA_ERROR_SOURCE_DESCRIPTOR structure. This member contains the value WHEA_ERROR_SOURCE_DESCRIPTOR_VERSION_10.

### `Type`

A [WHEA_ERROR_SOURCE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_whea_error_source_type)-typed value that specifies the type of the error source.

### `State`

A [WHEA_ERROR_SOURCE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_whea_error_source_state)-typed value that specifies the state of the error source.

### `MaxRawDataLength`

The maximum number of bytes of raw data included in a hardware error packet that is reported by this error source. This number must be large enough to include any additional platform-specific error information that is added to the hardware error packet by the PSHED or by a PSHED plug-in.

### `NumRecordsToPreallocate`

The number of error records that should be pre-allocated for hardware errors that are reported by this error source.

### `MaxSectionsPerRecord`

The maximum number of error record sections that are required in an error record to describe a hardware error that is reported by this error source. This number must be large enough to include any additional error record sections that are added to the error record by the PSHED or by a PSHED plug-in during the processing of the error.

### `ErrorSourceId`

The identifier of the error source. This identifier is unique only on the system where the error source exists.

### `PlatformErrorSourceId`

The identifier of the error source as enumerated by the hardware platform. This identifier is unique only on the system where the error source exists.

### `Flags`

A bitwise OR'ed combination of flags that describes the error source. Possible flags are:

#### WHEA_ERROR_SOURCE_FLAG_DEFAULTSOURCE

This flag indicates that the error source is a default error source for the type of hardware platform on which it exists.

#### WHEA_ERROR_SOURCE_FLAG_FIRMWAREFIRST

This flag indicates that the errors that are reported by this error source are handled by the firmware before control of the hardware error processing is passed to the operating system.

#### WHEA_ERROR_SOURCE_FLAG_GLOBAL

This flag indicates that the settings specified for the error source are to be applied to all of the error sources in the system that are of the same type as that specified in the **Type** member.

### `Info`

A union of descriptor structures that are specific to each different type of error source.

### `Info.XpfMceDescriptor`

A [WHEA_XPF_MCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_mce_descriptor) structure that describes an x86 or x64 processor machine check exception (MCE) error source.

### `Info.XpfCmcDescriptor`

A [WHEA_XPF_CMC_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_cmc_descriptor) structure that describes an x86 or x64 processor corrected machine check (CMC) error source.

### `Info.XpfNmiDescriptor`

A [WHEA_XPF_NMI_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_nmi_descriptor) structure that describes an x86 or x64 processor nonmaskable interrupt (NMI) error source.

### `Info.IpfMcaDescriptor`

A [WHEA_IPF_MCA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_ipf_mca_descriptor) structure that describes an Itanium processor machine check abort (MCA) error source.

### `Info.IpfCmcDescriptor`

A [WHEA_IPF_CMC_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_ipf_cmc_descriptor) structure that describes an Itanium processor corrected machine check (CMC) error source.

### `Info.IpfCpeDescriptor`

A [WHEA_IPF_CPE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_ipf_cpe_descriptor) structure that describes an Itanium processor corrected platform error (CPE) error source.

### `Info.AerRootportDescriptor`

A [WHEA_AER_ROOTPORT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_aer_rootport_descriptor) structure that describes a PCI Express (PCIe) root port error source.

### `Info.AerEndpointDescriptor`

A [WHEA_AER_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_aer_endpoint_descriptor) structure that describes a PCIe endpoint error source.

### `Info.AerBridgeDescriptor`

A [WHEA_AER_BRIDGE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_aer_bridge_descriptor) structure that describes a PCIe bridge error source.

### `Info.GenErrDescriptor`

A [WHEA_GENERIC_ERROR_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error_descriptor) structure that describes a generic error source.

### `Info.GenErrDescriptorV2`

A [WHEA_DEVICE_DRIVER_DESCRIPTOR_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-whea_generic_error_descriptor_v2) structure.

### `Info.DeviceDriverDescriptor`

A [WHEA_DEVICE_DRIVER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-whea_device_driver_descriptor) structure.

## Remarks

The WHEA_ERROR_SOURCE_DESCRIPTOR structure describes an error source. The WHEA_ERROR_SOURCE_DESCRIPTOR structure is also used to configure an error source.

A user-mode WHEA management application can control the error sources in the system by calling the methods in the [WHEAErrorSourceMethods](https://learn.microsoft.com/windows-hardware/drivers/ddi/_whea/) WMI provider class.

## See also

[DisableErrorSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_disable_error_source)

[EnableErrorSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_enable_error_source)

[GetAllErrorSources](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_get_all_error_sources)

[GetErrorSourceInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_get_error_source_info)

[SetErrorSourceInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_set_error_source_info)

[WHEAErrorSourceMethods::DisableErrorSourceRtn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_whea/)

[WHEAErrorSourceMethods::EnableErrorSourceRtn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_whea/)

[WHEAErrorSourceMethods::GetAllErrorSourcesRtn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_whea/)

[WHEAErrorSourceMethods::GetErrorSourceInfoRtn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_whea/)

[WHEAErrorSourceMethods::SetErrorSourceInfoRtn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_whea/)

[WHEA_AER_BRIDGE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_aer_bridge_descriptor)

[WHEA_AER_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_aer_endpoint_descriptor)

[WHEA_AER_ROOTPORT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_aer_rootport_descriptor)

[WHEA_ERROR_SOURCE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_whea_error_source_state)

[WHEA_ERROR_SOURCE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_whea_error_source_type)

[WHEA_GENERIC_ERROR_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error_descriptor)

[WHEA_IPF_CMC_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_ipf_cmc_descriptor)

[WHEA_IPF_CPE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_ipf_cpe_descriptor)

[WHEA_IPF_MCA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_ipf_mca_descriptor)

[WHEA_XPF_CMC_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_cmc_descriptor)

[WHEA_XPF_MCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_mce_descriptor)

[WHEA_XPF_NMI_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_nmi_descriptor)