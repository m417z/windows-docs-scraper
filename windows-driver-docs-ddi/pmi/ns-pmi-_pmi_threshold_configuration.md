# _PMI_THRESHOLD_CONFIGURATION structure

## Description

The PMI_THRESHOLD_CONFIGURATION structure contains information about the threshold configuration of the power meter.

## Members

### `LowerThreshold`

The lower threshold of the power meter, in units of milliwatts (mW).

### `UpperThreshold`

The upper threshold of the power meter, in units of milliwatts (mW).

## Remarks

The PMI_THRESHOLD_CONFIGURATION structure specifies the current configuration of the power meter's thresholds. The **LowerThreshold** and **UpperThreshold** members specify the lower and upper range of the threshold respectively.

A Power Meter Interface (PMI) event is signaled when the [IOCTL_PMI_REGISTER_EVENT_NOTIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_register_event_notify) I/O control (IOCTL) request completes when one of the following occurs:

* Power levels that are monitored by the power meter drop below the **LowerThreshold** value.
* Power levels that are monitored by the power meter drop below the **UpperThreshold** value.

## See also

[IOCTL_PMI_REGISTER_EVENT_NOTIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_register_event_notify)