# SIDEBANDAUDIO_SIOP_REQUEST_PARAM structure

## Description

The **SIDEBANDAUDIO_SIOP_REQUEST_PARAM** structure describes the variable SIOP request parameter.

## Members

### `EpIndex`

0 based index indicating the Endpoint on device.

### `RequestedSiop`

The requested SIOP in the form of a [SIDEBANDAUDIO_IO_PARAM_HEADER structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ns-sidebandaudio-sidebandaudio_io_param_header).

### `Alignment`

Allows for byte alignment.

## -union-fields

## Remarks

## Requirements

|   |   |
| ---- |:---- |
| **Header** | sidebandaudio.h |

## See also

[SIDEBANDAUDIO_IO_PARAM_HEADER structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ns-sidebandaudio-sidebandaudio_io_param_header)

[sidebandaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/)