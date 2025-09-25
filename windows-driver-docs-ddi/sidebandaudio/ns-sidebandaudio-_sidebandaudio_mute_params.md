# SIDEBANDAUDIO_MUTE_PARAMS structure

## Description

The **SIDEBANDAUDIO_MUTE_PARAMS** structure describes the endpoint index, channel, immediate mode of operation and mute value.

## Members

### `EpIndex`

0 based index indicating the Endpoint on device.

### `Immediate`

Indicates whether IOCTL current value is requested or IRP should complete upon next change in value.

### `Channel`

0 based index indicating the channel number.

### `Value`

Boolean representing mute state:
- TRUE - Muted
- FALSE - Unmuted

## Remarks

## Requirements

|   |   |
| ---- |:---- |
| **Header** | sidebandaudio.h |

## See also

[sidebandaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/)

[IOCTL_SBAUD_GET_MUTE_STATUS_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ni-sidebandaudio-ioctl_sbaud_get_mute_status_update)