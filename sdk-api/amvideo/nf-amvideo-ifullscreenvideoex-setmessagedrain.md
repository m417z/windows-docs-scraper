# IFullScreenVideoEx::SetMessageDrain

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetMessageDrain` method specifies a window to receive mouse and keyboard messages from the video window.

## Parameters

### `hwnd` [in]

Specifies a handle to the message-drain window.

## Return value

Returns an **HRESULT** value.

## Remarks

This method is equivalent to the [IVideoWindow::put_MessageDrain](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-put_messagedrain) method.

The Full Screen video renderer posts all mouse and keyboard messages to the window designated as a message drain. The exact list of messages that are posted is the same as the list given in **put_MessageDrain**.

Applications do not need to use this method. Instead, call the Filter Graph Manager's **put_MessageDrain** method before switching to full-screen mode. The Filter Graph Manager automatically sets the same message drain on the renderer that it selects for full-screen mode.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFullScreenVideoEx Interface](https://learn.microsoft.com/windows/desktop/api/amvideo/nn-amvideo-ifullscreenvideoex)