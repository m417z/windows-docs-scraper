# acmDriverClose function

## Description

The **acmDriverClose** function closes a previously opened ACM driver instance. If the function is successful, the handle is invalidated.

## Parameters

### `had`

Handle to the open driver instance to be closed.

### `fdwClose`

Reserved; must be zero.

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **ACMERR_BUSY** | The driver is in use and cannot be closed. |
| **MMSYSERR_INVALFLAG** | At least one flag is invalid. |
| **MMSYSERR_INVALHANDLE** | The specified handle is invalid. |

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)