# ICameraControl::put_PanTilt

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_PanTilt` method sets the camera's pan and tilt angles.

## Parameters

### `PanValue` [in]

Specifies the panning angle, in arc seconds. An arc second is 1/3600th of a degree. See [ICameraControl::put_Pan](https://learn.microsoft.com/windows/desktop/api/vidcap/nf-vidcap-icameracontrol-put_pan).

### `TiltValue` [in]

Specifies the tilt angle, in arc seconds. See [ICameraControl::put_Tilt](https://learn.microsoft.com/windows/desktop/api/vidcap/nf-vidcap-icameracontrol-put_tilt).

### `Flags` [in]

Zero or more flags. See [CameraControlFlags](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-cameracontrolflags). If the CameraControl_Flags_Auto flag is used, the *Value* parameter is ignored and the camera sets the default value.

## Return value

Returns an **HRESULT** value.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ICameraControl Interface](https://learn.microsoft.com/windows/desktop/api/vidcap/nn-vidcap-icameracontrol)