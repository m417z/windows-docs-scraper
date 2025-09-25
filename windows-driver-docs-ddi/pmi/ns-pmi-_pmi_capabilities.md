# _PMI_CAPABILITIES structure

## Description

The PMI_CAPABILITIES structure contains information about the power metering and budgeting capabilities of a power meter.

## Members

### `Version`

A value that specifies the version of this structure. For Windows 7, Windows Server 2008 R2, and later versions of Windows, this value must be 1.

### `Size`

A value, in units of bytes, that specifies the size of the structure.

### `CapabilityType`

A [PMI_CAPABILITIES_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_capabilities_type) enumeration value that specifies the data type of the **Capabilities** member.

### `Capabilities`

A union of the supported Power Meter Interface (PMI) capability structures. Based on the value of the **CapabilityType** member, one of the following **Capabilities** submembers is used to reference the following PMI capability structures:

### `Capabilities.ReportedCapabilities`

A [PMI_METERED_HARDWARE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_metered_hardware_information) structure that specifies one or more hardware devices that are monitored by the power meter.

The **Capabilities** member contains this structure if the **CapabilityType** member is set to **PmiMeteredHardware**.

### `Capabilities.MeteredHardwareInformation`

A [PMI_REPORTED_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_reported_capabilities) structure that specifies the PMI capabilities of the power meter, such as the following:

* Asset information
* Measurement capabilities
* Power and budget capabilities

The **Capabilities** member contains this structure if the **CapabilityType** member is set to **PmiReportedCapabilities**.

## Remarks

The PMI_CAPABILITIES structure is used to query many PMI capabilities that are supported by a power meter.

The PMI capability information is returned through an [IOCTL_PMI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_capabilities) I/O control (IOCTL) query request. The input data for this query request is set to a [PMI_CAPABILITIES_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_capabilities_type) enumerator value that specifies the type of PMI capability data to return.

If the IOCTL query request completes successfully, the request returns a PMI_CAPABILITIES structure. The **Capabilities** member of this structure contains data formatted as the requested PMI capabilities structure.

For example, if an IOCTL query request of [IOCTL_PMI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_capabilities) is made with the input data set to **PmiReportedCapabilities** and the request completes successfully, the request returns a PMI_CAPABILITIES structure with its members set to the following values:

* The **CapabilitiesType** member is set to **PmiReportedCapabilities**.
* The **Capabilities** member contains data that is formatted as a [PMI_REPORTED_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_reported_capabilities) structure.

## See also

[IOCTL_PMI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_capabilities)

[PMI_CAPABILITIES_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_capabilities_type)

[PMI_METERED_HARDWARE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_metered_hardware_information)

[PMI_REPORTED_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_reported_capabilities)