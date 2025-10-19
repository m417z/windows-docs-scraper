# IMFSourceReaderEx::RemoveAllTransformsForStream

## Description

Removes all of the Media Foundation transforms (MFTs) for a specified stream, with the exception of the decoder.

## Parameters

### `dwStreamIndex` [in]

The stream for which to remove the MFTs. The value can be any of the following.

| Value | Meaning |
| --- | --- |
| 0–0xFFFFFFFB | The zero-based index of a stream. |
| **MF_SOURCE_READER_FIRST_VIDEO_STREAM**<br><br>0xFFFFFFFC | The first video stream. |
| **MF_SOURCE_READER_FIRST_AUDIO_STREAM**<br><br>0xFFFFFFFD | The first audio stream. |

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_INVALIDREQUEST** | Invalid request. |
| **MF_E_INVALIDSTREAMNUMBER** | The *dwStreamIndex* parameter is invalid. |

## Remarks

Calling this method can reset the current output type for the stream. To get the new output type, call [IMFSourceReader::GetCurrentMediaType](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-getcurrentmediatype).

In asynchronous mode, this method fails if a sample request is pending. In that case, wait for the [OnReadSample](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereadercallback-onreadsample) callback to be invoked before calling the method. For more information about using the Source Reader in asynchronous mode, see [IMFSourceReader::ReadSample](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-readsample).

## See also

[IMFSourceReaderEx](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereaderex)