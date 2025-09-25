# PMI_CAPABILITIES_TYPE enumeration

## Description

The PMI_CAPABILITIES_TYPE enumeration defines the type of capabilities data that is referenced by the **Capability** member of the [PMI_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_capabilities) structure. This enumeration is also used to specify the type of **PMI_CAPABILITIES** structure to return through an [IOCTL_PMI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_capabilities) I/O control (IOCTL) request.

## Constants

### `PmiReportedCapabilities`

The PMI capabilities data, formatted as a [PMI_REPORTED_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_reported_capabilities) structure, specifies the power capabilities of the power meter.

### `PmiMeteredHardware`

The PMI capabilities data, formatted as a [PMI_METERED_HARDWARE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_metered_hardware_information) structure, specifies the hardware devices that the power meter provides measurement data to.

### `PmiCapabilitiesMax`

The maximum number of PMI capability structures.

## Remarks

The **CapabilityType** member of the [PMI_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_capabilities) structure contains information about the type of PMI capability data that is referenced by the **Capabilities** member of that structure. This structure is returned through a successful completion of an [IOCTL_PMI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_capabilities) IOCTL request.

## See also

[IOCTL_PMI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_capabilities)

[PMI_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_capabilities)

[PMI_METERED_HARDWARE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_metered_hardware_information)

[PMI_REPORTED_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_reported_capabilities)