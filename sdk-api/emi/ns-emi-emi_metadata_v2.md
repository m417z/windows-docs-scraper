# EMI_METADATA_V2 structure

## Description

The EMI_METADATA_V2 structure provides metadata about a device that supports the
EMI_VERSION_V2 interface. This metadata contains information about the hardware
device and what EMI channels are exposed by this device.

## Members

### `HardwareOEM`

A null-terminated, Unicode string that contains the name of the OEM.

### `HardwareModel`

A null-terminated, Unicode string that specifies the device model.

### `HardwareRevision`

A value that specifies the current revision of the device.

### `ChannelCount`

A value that specifies the number of EMI channels that are exposed by this device.

### `Channels`

An array of EMI_CHANNEL_V2 instances that describe the channels exposed by this device.

## See also

[IOCTL_EMI_GET_METADATA](https://learn.microsoft.com/windows/win32/api/emi/ni-emi-ioctl_emi_get_metadata)