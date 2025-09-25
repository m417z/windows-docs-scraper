# _PMI_METERED_HARDWARE_INFORMATION structure

## Description

The PMI_METERED_HARDWARE_INFORMATION structure contains information about one or more power supplies that are monitored by the power meter.

## Members

### `MeteredHardwareCount`

A value that specifies the number of device identifiers that are returned in the **MeteredHardware** member.

### `MeteredHardware`

A Unicode string that specifies the name of each device that is powered by the circuit on which the power meter provides measurement data. Individual device paths are delimited by a **NULL** character, and the whole list is terminated with a double **NULL**. The format of the device name is \\Device\xyz".

**Note** For systemwide power meters, this member returns **NULL**.

## Remarks

The PMI_METERED_HARDWARE_INFORMATION structure is returned through an [IOCTL_PMI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_capabilities) I/O control (IOCTL) query request. The input data for this query request is set to the [PMI_CAPABILITIES_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_capabilities_type) enumerator value of **PmiMeteredHardware**.

If the query request completes successfully, the request returns a [PMI_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_capabilities) structure. The **Capabilities** member of this structure is formatted as a PMI_METERED_HARDWARE_INFORMATION structure.

## See also

[IOCTL_PMI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_capabilities)

[PMI_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_capabilities)