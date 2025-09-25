# acmStreamPrepareHeader function

## Description

The [ACMSTREAMHEADER](https://learn.microsoft.com/windows/win32/api/msacm/ns-msacm-acmstreamheader) structure for an ACM stream conversion. This function must be called for every stream header before it can be used in a conversion stream. An application needs to prepare a stream header only once for the life of a given stream. The stream header can be reused as long as the sizes of the source and destination buffers do not exceed the sizes used when the stream header was originally prepared.

## Parameters

### `has`

Handle to the conversion steam.

### `pash`

Pointer to an [ACMSTREAMHEADER](https://learn.microsoft.com/windows/win32/api/msacm/ns-msacm-acmstreamheader) structure that identifies the source and destination buffers to be prepared.

### `fdwPrepare`

Reserved; must be zero.

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALFLAG** | At least one flag is invalid. |
| **MMSYSERR_INVALHANDLE** | The specified handle is invalid. |
| **MMSYSERR_INVALPARAM** | At least one parameter is invalid. |
| **MMSYSERR_NOMEM** | The system is unable to allocate resources. |

## Remarks

Preparing a stream header that has already been prepared has no effect, and the function returns zero. Nevertheless, you should ensure your application does not prepare a stream header multiple times.

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)