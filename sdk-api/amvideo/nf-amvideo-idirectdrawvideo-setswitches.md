# IDirectDrawVideo::SetSwitches

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetSwitches` method sets the surface types that the renderer is allowed to use.

## Parameters

### `Switches`

Bit mask containing one or more of the following DirectShow DirectDraw Surface (AMDDS) surface types.

| Value | Description |
| --- | --- |
| AMDDS_NONE | No use for DCI/DirectDraw. |
| AMDDS_DCIPS | Use DCI primary surface. |
| AMDDS_PS | Use DirectDraw primary surface. |
| AMDDS_RGBOVR | RGB overlay surfaces. |
| AMDDS_YUVOVR | YUV overlay surfaces. |
| AMDDS_RGBOFF | RGB off-screen surfaces. |
| AMDDS_YUVOFF | YUV off-screen surfaces. |
| AMDDS_RGBFLP | RGB flipping surfaces. |
| AMDDS_YUVFLP | YUV flipping surfaces. |
| AMDDS_ALL | All the previous flags. |
| AMDDS_DEFAULT | Use all available surfaces. |
| AMDDS_YUV | (AMDDS_YUVOFF \| AMDDS_YUVOVR \| AMDDS_YUVFLP). |
| AMDDS_RGB | (AMDDS_RGBOFF \| AMDDS_RGBOVR \| AMDDS_RGBFLP). |
| AMDDS_PRIMARY | (AMDDS_DCIPS \| AMDDS_PS). |

## Return value

Returns an **HRESULT** value.

## Remarks

This method must be called before the Video Renderer is connected.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDirectDrawVideo Interface](https://learn.microsoft.com/windows/desktop/api/amvideo/nn-amvideo-idirectdrawvideo)