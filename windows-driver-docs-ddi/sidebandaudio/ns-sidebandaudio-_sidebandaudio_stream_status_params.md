# SIDEBANDAUDIO_STREAM_STATUS_PARAMS structure

## Description

The **SIDEBANDAUDIO_STREAM_STATUS_PARAMS** structure describes the endpoint index and Device Error NTSTATUS.

## Members

### `EpIndex`

0 based index indicating the Endpoint on device.

### `Immediate`

Indicates whether IOCTL current value is requested or IRP should complete upon next change in value.

### `Status`

Indicates status of stream including cause of any failure.

## Remarks

## Requirements

|   |   |
| ---- |:---- |
| **Header** | sidebandaudio.h |

## See also

[sidebandaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/)