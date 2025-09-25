# acmDriverDetails function

## Description

The **acmDriverDetails** function queries a specified ACM driver to determine its capabilities.

## Parameters

### `hadid`

Handle to the driver identifier of an installed ACM driver. Disabled drivers can be queried for details.

### `padd`

Pointer to an [ACMDRIVERDETAILS]() structure that will receive the driver details. The **cbStruct** member must be initialized to the size, in bytes, of the structure.

### `fdwDetails`

Reserved; must be zero.

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALFLAG** | At least one flag is invalid. |
| **MMSYSERR_INVALHANDLE** | The specified handle is invalid. |
| **MMSYSERR_INVALPARAM** | At least one parameter is invalid. |

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)