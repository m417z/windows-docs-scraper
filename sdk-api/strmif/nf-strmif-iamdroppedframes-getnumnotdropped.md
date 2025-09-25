# IAMDroppedFrames::GetNumNotDropped

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetNumNotDropped` method retrieves the total number of frames that the filter has delivered since it started streaming.

## Parameters

### `plNotDropped` [out]

Pointer to a variable that receives the number of delivered frames.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | **NULL** pointer argument. |

## Remarks

The filter resets the count to zero when it transitions from stopped to paused.

If your application uses the [IAMStreamControl](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamstreamcontrol) interface to control a pin, the driver might continue to count dropped and non-dropped frames while the pin is off. To get an accurate count, call this method once when you turn on the pin, and again when you turn off the pin. The difference is the total number of dropped frames. (If the start time occurs later than the call to [IAMStreamControl::StartAt](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamstreamcontrol-startat), the application should listen for the [EC_STREAM_CONTROL_STARTED](https://learn.microsoft.com/windows/desktop/DirectShow/ec-stream-control-started) event.) These remarks also apply if your application uses the [ICaptureGraphBuilder2::ControlStream](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-icapturegraphbuilder2-controlstream) method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMDroppedFrames Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamdroppedframes)