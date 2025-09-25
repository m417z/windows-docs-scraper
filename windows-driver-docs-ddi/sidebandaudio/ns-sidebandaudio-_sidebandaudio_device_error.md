# SIDEBANDAUDIO_DEVICE_ERROR structure

## Description

The **SIDEBANDAUDIO_DEVICE_ERROR** structure describes the error reported on the Device.

## Members

### `EpIndex`

Zero based index indicating the Endpoint on device.

### `Immediate`

Indicates whether IOCTL current value is requested or IRP should complete upon next change in value.

### `Status`

Indicates status of the device.

## Remarks

## Requirements

|   |   |
| ---- |:---- |
| **Header** | sidebandaudio.h |

## See also

[sidebandaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/)