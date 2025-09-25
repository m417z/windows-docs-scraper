# acmStreamUnprepareHeader function

## Description

The **acmStreamUnprepareHeader** function cleans up the preparation performed by the [acmStreamPrepareHeader](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmstreamprepareheader) function for an ACM stream. This function must be called after the ACM is finished with the given buffers. An application must call this function before freeing the source and destination buffers.

## Parameters

### `has`

Handle to the conversion steam.

### `pash`

Pointer to an [ACMSTREAMHEADER](https://learn.microsoft.com/windows/win32/api/msacm/ns-msacm-acmstreamheader) structure that identifies the source and destination buffers to be unprepared.

### `fdwUnprepare`

Reserved; must be zero.

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **ACMERR_BUSY** | The stream header specified in *pash* is currently in use and cannot be unprepared. |
| **ACMERR_UNPREPARED** | The stream header specified in *pash* is currently not prepared by the [acmStreamPrepareHeader](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmstreamprepareheader) function. |
| **MMSYSERR_INVALFLAG** | At least one flag is invalid. |
| **MMSYSERR_INVALHANDLE** | The specified handle is invalid. |
| **MMSYSERR_INVALPARAM** | At least one parameter is invalid. |

## Remarks

Unpreparing a stream header that has already been unprepared is an error. An application must specify the source and destination buffer lengths (**cbSrcLength** and **cbDstLength**, respectively) that were used during a call to the corresponding [acmStreamPrepareHeader](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmstreamprepareheader). Failing to reset these member values will cause **acmStreamUnprepareHeader** to fail with an MMSYSERR_INVALPARAM error.

The ACM can recover from some errors. The ACM will return a nonzero error, yet the stream header will be properly unprepared. To determine whether the stream header was actually unprepared, an application can examine the ACMSTREAMHEADER_STATUSF_PREPARED flag. If **acmStreamUnprepareHeader** returns success, the header will always be unprepared.

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)