# IDMOVideoOutputOptimizations::SetOperationMode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetOperationMode` method notifies the DMO of the optimization features that are in effect.

## Parameters

### `ulOutputStreamIndex`

Zero-based index of an output stream on the DMO.

### `dwEnabledFeatures`

Bitwise combination of zero or more flags from the [DMO_VIDEO_OUTPUT_STREAM_FLAGS](https://learn.microsoft.com/windows/desktop/api/mediaobj/ne-mediaobj-_dmo_video_output_stream_flags) enumeration.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **DMO_E_INVALIDSTREAMINDEX** | Invalid stream index |
| **E_INVALIDARG** | Invalid argument |
| **S_OK** | Success |

## Remarks

Before calling this method, call the [IDMOVideoOutputOptimizations::QueryOperationModePreferences](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-idmovideooutputoptimizations-queryoperationmodepreferences) method to determine which features the DMO requests. Then call this method to inform the DMO which of those features you are providing. If you are not providing any of them, it is not necessary to call this method. The DMO does not assume that any of them will be provided.

The application must provide all the features it has agreed to. For some features, however, the DMO might not require the feature on every sample. To determine if the DMO can dispense with any features on the next sample, call the [IDMOVideoOutputOptimizations::GetCurrentSampleRequirements](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-idmovideooutputoptimizations-getcurrentsamplerequirements) method. In effect, this enables the DMO to waive an agreed-upon feature for one sample.

Before streaming begins, subsequent calls to this method override earlier calls. To set multiple features, you must do so in a single method call. Once streaming begins, this method returns an error. Streaming begins when the applications calls [IMediaObject::ProcessInput](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-processinput) on at least one input stream.

When streaming ends, the application can renegotiate the features. Streaming ends if the application calls the [IMediaObject::Flush](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-flush) method, or if the application calls [IMediaObject::Discontinuity](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-discontinuity) on all the input streams and then processes all of the remaining output.

## See also

[IDMOVideoOutputOptimizations Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-idmovideooutputoptimizations)