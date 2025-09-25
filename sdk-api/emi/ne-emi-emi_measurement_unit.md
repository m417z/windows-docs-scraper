# EMI_MEASUREMENT_UNIT enumeration

## Description

The **EMI_MEASUREMENT_UNIT** enumeration represents the available units of energy measurements that can be retrieved from a device by using [IOCTL_EMI_GET_MEASUREMENT](https://learn.microsoft.com/windows/desktop/api/emi/ni-emi-ioctl_emi_get_measurement).

## Constants

### `EmiMeasurementUnitPicowattHours`

The energy measurement is returned in picowatt-hours.

## Remarks

When a component calls [EMI_METADATA](https://learn.microsoft.com/windows/win32/api/emi/ns-emi-emi_metadata_v1) structure output parameter.

In devices that implement **EMI_VERSION_V1**, picowatt-hours is the only supported unit.

## See also

[EMI_METADATA](https://learn.microsoft.com/windows/win32/api/emi/ns-emi-emi_metadata_v1)

[Energy Metering Interface](https://learn.microsoft.com/windows-hardware/drivers/powermeter/energy-meter-interface)

[IOCTL_EMI_GET_MEASUREMENT](https://learn.microsoft.com/windows/desktop/api/emi/ni-emi-ioctl_emi_get_measurement)