# IDMOVideoOutputOptimizations::GetCurrentSampleRequirements

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetCurrentSampleRequirements` method retrieves the optimization features required to process the next sample, given the features already agreed to by the application.

## Parameters

### `ulOutputStreamIndex`

Zero-based index of an output stream on the DMO.

### `pdwRequestedFeatures`

Pointer to a variable that receives the required features. The returned value is a bitwise combination of zero or more flags from the [DMO_VIDEO_OUTPUT_STREAM_FLAGS](https://learn.microsoft.com/windows/desktop/api/mediaobj/ne-mediaobj-_dmo_video_output_stream_flags) enumeration.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **DMO_E_INVALIDSTREAMINDEX** | Invalid stream index |
| **E_POINTER** | **NULL** pointer argument |
| **S_OK** | Success |

## Remarks

After an application calls the [IDMOVideoOutputOptimizations::SetOperationMode](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-idmovideooutputoptimizations-setoperationmode) method, it must provide all the features it has agreed to. However, the DMO might not require every feature on every sample. This method enables the DMO to waive an agreed-upon feature for one sample.

Before processing a sample, the application can call this method. If the DMO does not require a given feature in order to process the next sample, it omits the corresponding flag from the *pdwRequestedFeatures* parameter. For the next sample only, the application can ignore the feature. The results of this method are valid only for the next call to the [IMediaObject::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-processoutput) method.

The DMO will return only the flags that were agreed to in the **SetOperationMode** method. In other words, you cannot dynamically enable new features with this method.

## See also

[IDMOVideoOutputOptimizations Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-idmovideooutputoptimizations)