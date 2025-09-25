# _STARTIO_PERFORMANCE_PARAMETERS structure

## Description

The **STARTIO_PERFORMANCE_PARAMETERS** structure describes the performance parameters that are returned to the miniport driver by the [StorPortGetStartIoPerfParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetstartioperfparams) routine.

## Members

### `Version`

The version number of the structure. This member is valid starting with Windows 8.

### `Size`

The size of the structure.

### `MessageNumber`

The offset in the device's MSI-X table for the optimal MSI-X message with which to interrupt. If the device does not support MSI-X messages, this member will be zero.

### `ChannelNumber`

Denotes the concurrent channel in which Storport is passing the I/O. If the miniport driver did not set up concurrent channels, this member will be zero.

## See also

[StorPortGetStartIoPerfParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetstartioperfparams)