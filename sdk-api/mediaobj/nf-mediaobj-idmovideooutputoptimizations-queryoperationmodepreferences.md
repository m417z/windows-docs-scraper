# IDMOVideoOutputOptimizations::QueryOperationModePreferences

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `QueryOperationModePreferences` method retrieves the DMO's preferred optimization features.

## Parameters

### `ulOutputStreamIndex`

Zero-based index of an output stream on the DMO.

### `pdwRequestedCapabilities`

Pointer to a variable that receives the DMO's requested features. The returned value is a bitwise combination of zero or more flags from the [DMO_VIDEO_OUTPUT_STREAM_FLAGS](https://learn.microsoft.com/windows/desktop/api/mediaobj/ne-mediaobj-_dmo_video_output_stream_flags) enumeration.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **DMO_E_INVALIDSTREAMINDEX** | Invalid stream index |
| **E_POINTER** | **NULL** pointer argument |
| **S_OK** | Success |

## See also

[IDMOVideoOutputOptimizations Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-idmovideooutputoptimizations)