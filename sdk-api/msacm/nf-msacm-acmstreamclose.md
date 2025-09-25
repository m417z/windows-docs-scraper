# acmStreamClose function

## Description

The **acmStreamClose** function closes an ACM conversion stream. If the function is successful, the handle is invalidated.

## Parameters

### `has`

Handle to the open conversion stream to be closed.

### `fdwClose`

Reserved; must be zero.

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **ACMERR_BUSY** | The conversion stream cannot be closed because an asynchronous conversion is still in progress. |
| **MMSYSERR_INVALFLAG** | At least one flag is invalid. |
| **MMSYSERR_INVALHANDLE** | The specified handle is invalid. |

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)