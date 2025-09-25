# SIDEBANDAUDIO_SIDETONE_PARAMS structure

## Description

The **SIDEBANDAUDIO_SIDETONE_PARAMS** structure describes the endpoint index and sidetone value.

## Members

### `EpIndex`

0 based index indicating the Endpoint on device.

### `Immediate`

Indicates whether IOCTL current value is requested or IRP should complete upon next change in value.

### `Channel`

Sidetone Volume and Mute per channel. Set as ULONG(-1) if channel specific sidetone values are not required.

### `Sidetone`

A [SIDEBANDAUDIO_SIDETONE_DESCRIPTOR structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ns-sidebandaudio-_sidebandaudio_sidetone_descriptor) that describes the Sidetone on the device.

## Remarks

## Requirements

|   |   |
| ---- |:---- |
| **Header** | sidebandaudio.h |

## See also

[sidebandaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/)

[SIDEBANDAUDIO_SIDETONE_DESCRIPTOR structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ns-sidebandaudio-_sidebandaudio_sidetone_descriptor)