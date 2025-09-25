# EMI_METADATA_V1 structure

## Description

The **EMI_METADATA** structure provides metadata about a device that supports the Energy Metering Interface (EMI) interface, such as the hardware model and hardware revision.

## Members

### `MeasurementUnit`

An [EMI_MEASUREMENT_UNIT](https://learn.microsoft.com/windows/desktop/api/emi/ne-emi-emi_measurement_unit) that specifies the unit of energy measurements that can be obtained from the device by calling [IOCTL_EMI_GET_MEASUREMENT](https://learn.microsoft.com/windows/desktop/api/emi/ni-emi-ioctl_emi_get_measurement). In devices that support **EMI_VERSION_V1**, the only supported unit is **EmiMeasurementUnitPicowattHours**.

### `HardwareOEM`

A null-terminated, Unicode string that contains the name of the OEM.

### `HardwareModel`

A null-terminated, Unicode string that specifies the device model.

### `HardwareRevision`

A value that specifies the current revision of the device.

### `MeteredHardwareNameSize`

The size of **MeteredHardwareName** in bytes, including the null terminator.

### `MeteredHardwareName`

A null-terminated, Unicode string that specifies the metered hardware name.

## Remarks

This structure is returned through a successful completion of an [IOCTL_EMI_GET_METADATA](https://learn.microsoft.com/windows/desktop/api/emi/ni-emi-ioctl_emi_get_metadata) IOCTL request.

## See also

[Energy Metering Interface](https://learn.microsoft.com/windows-hardware/drivers/powermeter/energy-meter-interface)

[IOCTL_EMI_GET_METADATA](https://learn.microsoft.com/windows/desktop/api/emi/ni-emi-ioctl_emi_get_metadata)