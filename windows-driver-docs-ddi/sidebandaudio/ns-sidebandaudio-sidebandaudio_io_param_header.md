# SIDEBANDAUDIO_IO_PARAM_HEADER structure

## Description

The **SIDEBANDAUDIO_IO_PARAM_HEADER** structure describes the size and type of the IO parameter.

## Members

### `ParamSet`

Parameter Set - This could be Microsoft Standard set or IHV defined.

### `TypeId`

Type of parameter.

### `Size`

Size in bytes of Parameter. In case of IOCTL_SBAUD_GET_SIOPxxx Size will indicate size of any extra input parameter.

### `Alignment`

Allows for byte alignment.

## Remarks

## Requirements

|   |   |
| ---- |:---- |
| **Header** | sidebandaudio.h |

## See also

[sidebandaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/)