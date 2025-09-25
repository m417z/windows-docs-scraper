# SIDEBANDAUDIO_SUPPORTED_FORMATS structure

## Description

The **SIDEBANDAUDIO_SUPPORTED_FORMATS** structure describes the formats supported by the Audio Endpoint.

## Members

### `CbSize`

Size of structure including storage for Formats Array allocated after the struct.

### `EpIndex`

 0 based index indicating the Endpoint on device.

### `NumFormats`

Number of KSDATAFORMAT structures.

### `Formats`

Array of pointers of KSDATAFORMAT.

## Remarks

## Requirements

|   |   |
| ---- |:---- |
| **Header** | sidebandaudio.h |

## See also

[sidebandaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/)

[IOCTL_SBAUD_GET_SUPPORTED_FORMATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ni-sidebandaudio-ioctl_sbaud_get_supported_formats)