# IMFSourceReaderEx::SetNativeMediaType

## Description

Sets the native media type for a stream on the media source.

## Parameters

### `dwStreamIndex` [in]

### `pMediaType` [in]

A pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the media type.

### `pdwStreamFlags` [out]

Receives a bitwise **OR** of zero or more of the following flags.

| Value | Meaning |
| --- | --- |
| **MF_SOURCE_READERF_ALLEFFECTSREMOVED** | All effects were removed from the stream. |
| **MF_SOURCE_READERF_CURRENTMEDIATYPECHANGED** | The current output type changed. |

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_INVALIDREQUEST** | Invalid request. |
| **MF_E_INVALIDSTREAMNUMBER** | The *dwStreamIndex* parameter is invalid. |

## Remarks

This method sets the output type that is produced by the media source. Unlike the [IMFSourceReader::SetCurrentMediaType](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-setcurrentmediatype) method, this method does not insert any decoders, video processors, or other transforms. The media source must support the specified media type natively. To get a list of supported types from the media source, call [IMFSourceReader::GetNativeMediaType](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-getnativemediatype).

In asynchronous mode, this method fails if a sample request is pending. In that case, wait for the [OnReadSample](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereadercallback-onreadsample) callback to be invoked before calling the method. For more information about using the Source Reader in asynchronous mode, see [IMFSourceReader::ReadSample](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-readsample).

This method can trigger a change in the output format for the stream. If so, the **MF_SOURCE_READERF_CURRENTMEDIATYPECHANGED** flag is returned in the *pdwStreamFlags* parameter. The method might also cause the Source Reader to remove any effects that were added by the [IMFSourceReaderEx::AddTransformForStream](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereaderex-addtransformforstream) method. If this occurs, the **MF_SOURCE_READERF_ALLEFFECTSREMOVED** flag is returned in *pdwStreamFlags*.

This method is useful with audio and video capture devices, because a device might support several output formats. This method enables the application to choose the device format before decoders and other transforms are added.

## See also

[IMFSourceReaderEx](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereaderex)