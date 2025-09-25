# acmDriverRemove function

## Description

The **acmDriverRemove** function removes an ACM driver from the list of available ACM drivers. The driver will be removed for the calling application only. If the driver is globally installed, other applications will still be able to use it.

## Parameters

### `hadid`

Handle to the driver identifier to be removed.

### `fdwRemove`

Reserved; must be zero.

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **ACMERR_BUSY** | The driver is in use and cannot be removed. |
| **MMSYSERR_INVALFLAG** | At least one flag is invalid. |
| **MMSYSERR_INVALHANDLE** | The specified handle is invalid. |

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)