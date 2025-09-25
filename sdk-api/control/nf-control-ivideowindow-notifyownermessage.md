# IVideoWindow::NotifyOwnerMessage

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `NotifyOwnerMessage` method forwards a message to the video window.

## Parameters

### `hwnd` [in]

A handle to the window, as an [OAHWND](https://learn.microsoft.com/windows/desktop/DirectShow/oahwnd) value.

### `uMsg` [in]

Specifies the message.

### `wParam` [in]

Message parameter.

### `lParam` [in]

Message parameter.

## Return value

Possible return values include the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_E_NOT_CONNECTED** | The video renderer filter is not connected. |

## Remarks

The Filter Graph Manager calls this method to pass various messages to the renderer, including the following:

* WM_ACTIVATEAPP
* WM_DEVMODECHANGE
* WM_DISPLAYCHANGE
* WM_PALETTECHANGED
* WM_PALETTEISCHANGING
* WM_QUERYNEWPALETTE
* WM_SYSCOLORCHANGE

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVideoWindow Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ivideowindow)