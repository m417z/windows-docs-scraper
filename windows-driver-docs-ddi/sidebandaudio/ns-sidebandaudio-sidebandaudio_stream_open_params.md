# SIDEBANDAUDIO_STREAM_OPEN_PARAMS structure

## Description

The **SIDEBANDAUDIO_STREAM_OPEN_PARAMS** structure describes the variable I/O parameters for IOCTLs.

## Members

### `EpIndex`

0 based index indicating the Endpoint on device.

### `Format`

Stream Format KSDATAFORMAT.

### `SiopCount`

Number of Input parameters.

### `Alignment`

Alignment - Allows for byte alignment.

## Remarks

## Requirements

|   |   |
| ---- |:---- |
| **Header** | sidebandaudio.h |

## See also

[sidebandaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/)