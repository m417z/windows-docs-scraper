# PMI_EVENT_TYPE enumeration

## Description

The PMI_EVENT_TYPE enumeration defines the type of PMI power meter event that is returned through the successful completion of an [IOCTL_PMI_REGISTER_EVENT_NOTIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_register_event_notify) request.

## Constants

### `PmiCapabilitiesChangedEvent`

The event was caused by a change in the PMI capabilities of the power meter.

### `PmiThresholdEvent`

The event was caused because the power level exceeded a configured threshold of the power meter.

### `PmiConfigurationChangedEvent`

The event was caused by a change in the PMI configuration of the power meter.

### `PmiBudgetEvent`

The event was caused because the power budget exceeded or fell below the configured budget of the power meter.

### `PmiAveragingIntervalChangedEvent`

The event was caused because the interval, during which the power meter averages power measurement data, was changed.

### `PmiEventMax`

The maximum number of PMI event types.

## Remarks

The **EventType** member of the [PMI_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_event) structure contains information about the type of PMI event data that is referenced by the **Event** member of that structure. This structure is returned through a successful completion of an [IOCTL_PMI_REGISTER_EVENT_NOTIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_register_event_notify) request.

## See also

[IOCTL_PMI_REGISTER_EVENT_NOTIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_register_event_notify)

[PMI_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_event)