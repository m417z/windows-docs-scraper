# STORAGE_DEVICE_POWER_CAP structure

## Description

This structure is used as an input and output buffer for the [**IOCTL_STORAGE_DEVICE_POWER_CAP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_device_power_cap).

## Members

### `Version`

The version of this structure. This should be set to **STORAGE_DEVICE_POWER_CAP_VERSION_V1**.

### `Size`

The size of this structure, in bytes.

### `Units`

The units of the **MaxPower** value. This value can be either a percentage (0-100%) or an absolute value in milliwatts. The output buffer's **Units** value will match the value from the input buffer.

### `MaxPower`

On input, **MaxPower** specifies the desired maximum power consumption value for the storage device. On output, **MaxPower** contains the value of the actual maximum power consumption level of the device. The output buffer value may be equal to, less than, or greater than the desired threshold, depending on what the device supports.

## See also

[**IOCTL_STORAGE_DEVICE_POWER_CAP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_device_power_cap)