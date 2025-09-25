# EMI_CHANNEL_V2 structure

## Description

The EMI_CHANNEL_V2 structure provides data about an EMI V2 channel.

## Members

### `MeasurementUnit`

An EMI_MEASUREMENT_UNIT that specifies the unit of energy
measurements that can be obtained from the device from an
IOCTL_EMI_GET_MEASUREMENT. In EMI_VERSION_V2, the only
supported unit is picowatt-hours.

### `ChannelNameSize`

The size of ChannelName in bytes, including the null terminator.

### `ChannelName`

A null-terminated, Unicode string that specifies the channel name.