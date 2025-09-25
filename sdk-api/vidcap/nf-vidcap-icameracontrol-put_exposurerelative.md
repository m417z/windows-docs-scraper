# ICameraControl::put_ExposureRelative

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_ExposureRelative` method sets the camera's relative exposure time. The relative exposure time is expressed as a number of steps, where the size of each step depends on the camera model.

## Parameters

### `Value` [in]

Specifies the relative exposure. To get the range of possible values, call [ICameraControl::getRange_ExposureRelative](https://learn.microsoft.com/windows/desktop/api/vidcap/nf-vidcap-icameracontrol-getrange_exposurerelative).

| Value | Description |
| --- | --- |
| 0 | Set the exposure to the default exposure time, which is implementation dependent. |
| Positive value | Increment the exposure time by one step. |
| Negative value | Decrement the exposure time by one step. |

### `Flags` [in]

Zero or more flags. See [CameraControlFlags](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-cameracontrolflags). If the CameraControl_Flags_Auto flag is used, the *Value* parameter is ignored and the camera sets the default value.

## Return value

Returns an **HRESULT** value.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ICameraControl Interface](https://learn.microsoft.com/windows/desktop/api/vidcap/nn-vidcap-icameracontrol)