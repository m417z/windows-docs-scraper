# _SIDEBANDAUDIO_PARAMS_MSFT_TYPE_ID enumeration

## Description

Parameters defined for SIDEBANDAUDIO_PARAMS_SET_STANDARD - Microsoft Type IDs

## Constants

### `SBAUD_PARAMS_TYPE_RESERVED`

The reserved type parameter set.

## Remarks

For the Microsoft sideband standard set of parameters, the following GUID is defined.

```cpp
// {BF34616B-8265-4D70-ADB2-91B350CCD5D2}
DEFINE_GUID(SIDEBANDAUDIO_PARAMS_SET_STANDARD,
    0xbf34616b, 0x8265, 0x4d70, 0xad, 0xb2, 0x91, 0xb3, 0x50, 0xcc, 0xd5, 0xd2);
```

## Requirements

|   |   |
| ---- |:---- |
| **Header** | sidebandaudio.h |

## See also

[sidebandaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/)