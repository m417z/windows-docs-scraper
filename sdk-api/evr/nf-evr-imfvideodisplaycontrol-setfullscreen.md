# IMFVideoDisplayControl::SetFullscreen

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

[This API is not supported and may be altered or unavailable in the future. ]

Sets or unsets full-screen rendering mode.

To implement full-screen playback, an application should simply resize the video window to cover the entire area of the monitor. Also set the window to be a topmost window, so that the application receives all mouse-click messages. For more information about topmost windows, see the documentation for the [SetWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowpos) function.

## Parameters

### `fFullscreen` [in]

If **TRUE**, the enhanced video renderer (EVR) uses full-screen mode. If **FALSE**, the EVR draws the video in the application-provided clipping window.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The video renderer has been shut down. |

## Remarks

The default EVR presenter implements full-screen mode using Direct3D exclusive mode.

If you use this method to switch to full-screen mode, set the application window to be a topmost window and resize the window to cover the entire monitor. This ensures that the application window receives all mouse-click messages. Also set the keyboard focus to the application window. When you switch out of full-screen mode, restore the window's original size and position.

By default, the cursor is still visible in full-screen mode. To hide the cursor, call **ShowCursor**.

The transition to and from full-screen mode occurs asynchronously. To get the current mode, call [IMFVideoDisplayControl::GetFullscreen](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-imfvideodisplaycontrol-getfullscreen).

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[IMFVideoDisplayControl](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imfvideodisplaycontrol)

[Using the Video Display Controls](https://learn.microsoft.com/windows/desktop/medfound/using-the-video-display-controls)