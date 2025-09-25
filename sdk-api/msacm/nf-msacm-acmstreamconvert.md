# acmStreamConvert function

## Description

The **acmStreamConvert** function requests the ACM to perform a conversion on the specified conversion stream. A conversion may be synchronous or asynchronous, depending on how the stream was opened.

## Parameters

### `has`

Handle to the open conversion stream.

### `pash`

Pointer to a stream header that describes source and destination buffers for a conversion. This header must have been prepared previously by using the [acmStreamPrepareHeader](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmstreamprepareheader) function.

### `fdwConvert`

Flags for doing the conversion. The following values are defined.

| Value | Meaning |
| --- | --- |
| ACM_STREAMCONVERTF_BLOCKALIGN | Only integral numbers of blocks will be converted. Converted data will end on block-aligned boundaries. An application should use this flag for all conversions on a stream until there is not enough source data to convert to a block-aligned destination. In this case, the last conversion should be specified without this flag. |
| ACM_STREAMCONVERTF_END | ACM conversion stream should begin returning pending instance data. For example, if a conversion stream holds instance data, such as the end of an echo filter operation, this flag will cause the stream to start returning this remaining data with optional source data. This flag can be specified with the ACM_STREAMCONVERTF_START flag. |
| ACM_STREAMCONVERTF_START | ACM conversion stream should reinitialize its instance data. For example, if a conversion stream holds instance data, such as delta or predictor information, this flag will restore the stream to starting defaults. This flag can be specified with the ACM_STREAMCONVERTF_END flag. |

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **ACMERR_BUSY** | The stream header specified in *pash* is currently in use and cannot be reused. |
| **ACMERR_UNPREPARED** | The stream header specified in *pash* is currently not prepared by the [acmStreamPrepareHeader](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmstreamprepareheader) function. |
| **MMSYSERR_INVALFLAG** | At least one flag is invalid. |
| **MMSYSERR_INVALHANDLE** | The specified handle is invalid. |
| **MMSYSERR_INVALPARAM** | At least one parameter is invalid. |

## Remarks

You must use the [acmStreamPrepareHeader](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmstreamprepareheader) function to prepare the source and destination buffers before they are passed to **acmStreamConvert**.

If an asynchronous conversion request is successfully queued by the ACM or driver and the conversion is later determined to be impossible, the [ACMSTREAMHEADER](https://learn.microsoft.com/windows/win32/api/msacm/ns-msacm-acmstreamheader) structure is posted back to the application's callback function with the **cbDstLengthUsed** member set to zero.

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)