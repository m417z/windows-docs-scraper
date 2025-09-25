# EMI_CHANNEL_MEASUREMENT_DATA structure

## Description

The **EMI_MEASUREMENT_DATA** structure provides data about the current energy measurement and the time at which the measurement was taken.

## Members

### `AbsoluteEnergy`

The total accumulated energy in the units specified by the [EMI_METADATA](https://learn.microsoft.com/windows/win32/api/emi/ns-emi-emi_metadata_v1) struct returned by [IOCTL_EMI_GET_METADATA](https://learn.microsoft.com/windows/desktop/api/emi/ni-emi-ioctl_emi_get_metadata). In **EMI_VERSION_V1**, the only supported unit is picowatt-hours.

### `AbsoluteTime`

The time at which the energy measurement was taken, in 100 ns intervals.

## Remarks

This structure is returned through a successful completion of an [IOCTL_EMI_GET_MEASUREMENT](https://learn.microsoft.com/windows/desktop/api/emi/ni-emi-ioctl_emi_get_measurement) IOCTL request.

## See also

[Energy Metering Interface](https://learn.microsoft.com/windows-hardware/drivers/powermeter/energy-meter-interface)

[IOCTL_EMI_GET_MEASUREMENT](https://learn.microsoft.com/windows/desktop/api/emi/ni-emi-ioctl_emi_get_measurement)