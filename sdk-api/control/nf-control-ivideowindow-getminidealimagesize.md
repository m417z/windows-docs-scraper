# IVideoWindow::GetMinIdealImageSize

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetMinIdealImageSize` method retrieves the minimum ideal size for the video image.

## Parameters

### `pWidth` [out]

Receives the minimum ideal width, in pixels.

### `pHeight` [out]

Receives the minimum ideal height, in pixels.

## Return value

Possible return values include the following:

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer. |
| **S_FALSE** | Could not retrieve a minimum image size. |
| **S_OK** | Success. |
| **VFW_E_WRONG_STATE** | Filter is stopped. |

## Remarks

The maximum ideal size may differ from the native video size, because the video hardware might have specific stretching requirements.

This method returns S_FALSE under various circumstances:

* The filter is using an [IOverlay](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ioverlay) transport.
* UseWhenFullScreen mode is on. (See [IDirectDrawVideo::UseWhenFullScreen](https://learn.microsoft.com/previous-versions/ms785118(v=vs.85)).)
* Video playback is using a stretchable offscreen surface. (The **dwCaps** member of the DDCAPS structure includes the DDCAPS_BLTSTRETCH flag. See [IDirectDrawVideo::GetCaps](https://learn.microsoft.com/previous-versions/ms785104(v=vs.85)).)
* The video surface has no minimum overlay stretch. (The **dwMinOverlayStretch** member of the DDCAPS structure is zero. See [IDirectDrawVideo::GetCaps](https://learn.microsoft.com/previous-versions/ms785104(v=vs.85)).)

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVideoWindow Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ivideowindow)

[IVideoWindow::GetMaxIdealImageSize](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-getmaxidealimagesize)