# STORAGE_DEVICE_POWER_CAP structure

## Description

This structure is used as an input and output buffer for the [IOCTL_STORAGE_DEVICE_POWER_CAP](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_device_power_cap).

## Members

### `Version`

The version of this structure. This should be set to STORAGE_DEVICE_POWER_CAP_VERSION_V1.

### `Size`

The size of this structure.

### `Units`

The units of the *MaxPower* value, of type [STORAGE_DEVICE_POWER_CAP_UNITS](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_device_power_cap_units).

### `MaxPower`

Contains the value of the actual maximum power consumption level of the device. This may be equal to, less than, or greater than the desired threshold, depending on what the device supports.