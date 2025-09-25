# IFullScreenVideoEx::HideOnDeactivate

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `HideOnDeactivate` method . Depending on the setting, the full-screen video window is either minimized or hidden. If it is minimized, it appears as an icon in the task bar; otherwise, it does not.

## Parameters

### `Hide` [in]

Value that specifies the behavior when the application is deactivated. Set to OATRUE to hide the icon; set to OAFALSE to display the icon.

| Value | Description |
| --- | --- |
| OATRUE | Hide the video window. |
| OAFALSE | Minimize the video window. (Default) |

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **S_OK** | Success. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFullScreenVideoEx Interface](https://learn.microsoft.com/windows/desktop/api/amvideo/nn-amvideo-ifullscreenvideoex)