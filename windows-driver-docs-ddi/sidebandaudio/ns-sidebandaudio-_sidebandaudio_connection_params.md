# SIDEBANDAUDIO_CONNECTION_PARAMS structure

## Description

The **SIDEBANDAUDIO_CONNECTION_PARAMS** structure describes the endpoint index and connection value.

## Members

### `EpIndex`

0 based index indicating the Endpoint on device.

### `Immediate`

Indicates whether IOCTL current value is requested or IRP should complete upon next change in value.

### `Connected`

Indicates whether the endpoint is connected or not. Could reflect jack states or wireless connection.

## Remarks

## Requirements

|   |   |
| ---- |:---- |
| **Header** | sidebandaudio.h |

## See also

[sidebandaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/)