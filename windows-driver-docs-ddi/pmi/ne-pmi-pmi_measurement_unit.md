# PMI_MEASUREMENT_UNIT enumeration

## Description

The PMI_MEASUREMENT_UNIT enumeration defines the units of the PMI measurement data.

## Constants

### `PmiMeasurementUnitMilliWatt`

The PMI measurement data is in units of milliwatts (mW).

### `PmiMeasurementUnitMax`

The maximum types of PMI measurement units.

## Remarks

The **MeasurementUnit** member of the [PMI_REPORTED_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_reported_capabilities) structure contains information about the measurement units of the data that is contained within the structure. This structure is returned through a successful completion of an [IOCTL_PMI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_capabilities) request.

## See also

[IOCTL_PMI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_capabilities)

[PMI_REPORTED_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_reported_capabilities)