# IMFSourceReaderEx::AddTransformForStream

## Description

Adds a transform, such as an audio or video effect, to a stream.

## Parameters

### `dwStreamIndex` [in]

The stream to configure. The value can be any of the following.

| Value | Meaning |
| --- | --- |
| 0–0xFFFFFFFB | The zero-based index of a stream. |
| **MF_SOURCE_READER_FIRST_VIDEO_STREAM**<br><br>0xFFFFFFFC | The first video stream. |
| **MF_SOURCE_READER_FIRST_AUDIO_STREAM**<br><br>0xFFFFFFFD | The first audio stream. |

### `pTransformOrActivate` [in]

A pointer to one of the following:

* A Media Foundation transform (MFT) that exposes the [IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform) interface.
* An MFT activation object that exposes the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_INVALIDMEDIATYPE** | The transform does not support the current stream format, and no conversion was possible. See Remarks for more information. |
| **MF_E_INVALIDREQUEST** | Invalid request. |
| **MF_E_INVALIDSTREAMNUMBER** | The *dwStreamIndex* parameter is invalid. |

## Remarks

This method attempts to add the transform at the end of the current processing chain.

To use this method, make the following sequence of calls:

1. Call [IMFSourceReader::SetCurrentMediaType](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-setcurrentmediatype) to set the output type that you want for the stream. In this step, you can specify a media type that contains only the major type and subtype GUIDs. For example, to get 32-bit RGB output, set a major type of **MFMediaType_Video** and a subtype of **MFVideoFormat_RGB32**. (For more information, see [Media Type GUIDs](https://learn.microsoft.com/windows/desktop/medfound/media-type-guids).)
2. Call **AddTransformForStream**. If the Source Reader successfully connects the transform, it sets the output type on the transform.
3. Call [IMFSourceReader::GetCurrentMediaType](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-getcurrentmediatype) to get the output type from the transform. This method returns a media type with a complete format description.
4. Optionally, if you want to modify the output type, call [IMFSourceReader::SetCurrentMediaType](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-setcurrentmediatype) again to set a complete media type on the transform.

The **AddTransformForStream** method will not insert a decoder into the processing chain. If the native stream format is encoded, and the transform requires an uncompressed format, call [SetCurrentMediaType](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-setcurrentmediatype) to set the uncompressed format (step 1 in the previous list). However, the method will insert a video processor to convert between RGB and YUV formats, if required.

The method fails if the source reader was configured with the [MF_READWRITE_DISABLE_CONVERTERS](https://learn.microsoft.com/windows/desktop/medfound/mf-readwrite-disable-converters) or [MF_SOURCE_READER_ENABLE_VIDEO_PROCESSING](https://learn.microsoft.com/windows/desktop/medfound/mf-source-reader-enable-video-processing) attributes.

In asynchronous mode, the method also fails if a sample request is pending. In that case, wait for the [OnReadSample](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereadercallback-onreadsample) callback to be invoked before calling the method. For more information about using the Source Reader in asynchronous mode, see [IMFSourceReader::ReadSample](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-readsample).

You can add a transform at any time during streaming. However, the method does not flush or drain the pipeline before inserting the transform. Therefore, if data is already in the pipeline, the next sample is not guaranteed to have the transform applied.

## See also

[IMFSourceReaderEx](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereaderex)

[Source Reader](https://learn.microsoft.com/windows/desktop/medfound/source-reader)