# acmStreamReset function

## Description

The **acmStreamReset** function stops conversions for a given ACM stream. All pending buffers are marked as done and returned to the application.

## Parameters

### `has`

Handle to the conversion stream.

### `fdwReset`

Reserved; must be zero.

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALFLAG** | At least one flag is invalid. |
| **MMSYSERR_INVALHANDLE** | The specified handle is invalid. |

## Remarks

Resetting an ACM conversion stream is necessary only for asynchronous conversion streams. Resetting a synchronous conversion stream will succeed, but no action will be taken.

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)