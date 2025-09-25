# PMI_MEASUREMENT_TYPE enumeration

## Description

The PMI_MEASUREMENT_TYPE enumeration defines the source of the PMI measurement data.

## Constants

### `PmiMeasurementTypeInput`

The PMI measurement data is based on input power.

### `PmiMeasurementTypeOutput`

The PMI measurement data is based on output power.

### `PmiMeasurementTypeMax`

The maximum types of PMI measurement data.

## Remarks

The **MeasurementType** member of the [PMI_REPORTED_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_reported_capabilities) structure specifies the type of PMI measurement data reported by a power meter. This structure is returned through a successful completion of an [IOCTL_PMI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_capabilities) request.

PMI measurement data is returned through a query request of [IOCTL_PMI_GET_MEASUREMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_measurement).

## See also

[IOCTL_PMI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_capabilities)

[IOCTL_PMI_GET_MEASUREMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_measurement)

[PMI_REPORTED_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_reported_capabilities)