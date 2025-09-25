# ICameraControl::get_ZoomRelative

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_ZoomRelative` method returns the camera's relative zoom. The relative zoom indicates the direction in which the lens is moving.

## Parameters

### `pValue` [out]

Receives the relative zoom. The size of the value represents the desired zoom speed; a higher value represents a higher speed. To get the range of possible values, call [ICameraControl::getRange_ZoomRelative](https://learn.microsoft.com/windows/desktop/api/vidcap/nf-vidcap-icameracontrol-getrange_zoomrelative).

| Value | Description |
| --- | --- |
| 0 | Stopped. |
| Positive value | Zoom lens moving in the telephoto direction. |
| Negative value | Zoom lens moving in the wide angle direction. |

### `pFlags` [out]

Receives one or more flags. See [CameraControlFlags](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-cameracontrolflags).

## Return value

Returns an **HRESULT** value.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ICameraControl Interface](https://learn.microsoft.com/windows/desktop/api/vidcap/nn-vidcap-icameracontrol)