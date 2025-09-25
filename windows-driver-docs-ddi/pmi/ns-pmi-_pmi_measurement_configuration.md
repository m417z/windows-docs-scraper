# _PMI_MEASUREMENT_CONFIGURATION structure

## Description

The PMI_MEASUREMENT_CONFIGURATION structure contains information about the current power measurement configuration of a power meter.

## Members

### `AveragingInterval`

A value, in units of milliseconds (mS), that specifies the interval during which the power meter averages power measurement data.

## Remarks

The PMI_MEASUREMENT_CONFIGURATION structure specifies the current measurement parameters that the power meter uses when it monitors the power that is consumed by the system from a power supply. The **AverageInterval** member specifies the time interval over which the power meter averages the power measurement data it collects from a power supply.

**Note** The **AverageInterval** member must have a value between the values of the **MinimumAverageInterval** and **MaximumAverageInterval** members of the [PMI_REPORTED_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_reported_capabilities) structure. This structure is returned in the [PMI_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_capabilities) structure of an [IOCTL_PMI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_capabilities) I/O control (IOCTL) query request.

## See also

[IOCTL_PMI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_capabilities)

[PMI_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_capabilities)

[PMI_REPORTED_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_reported_capabilities)