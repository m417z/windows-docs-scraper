# IMFPMediaPlayer::UpdateVideo

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Updates the video frame.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The method succeeded. |
| ****MF_E_INVALIDREQUEST**** | The current media item does not contain video. |
| ****MF_E_SHUTDOWN**** | The object's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-shutdown) method was called. |

## Remarks

Call this method when your application's video playback window receives either a [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) or [WM_SIZE](https://learn.microsoft.com/windows/desktop/winmsg/wm-size) message. This method performs two functions:

* Ensures that the video frame is repainted while playback is paused or stopped.
* Adjusts the displayed video to match the current size of the video window.

**Important** Call the GDI [BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint) function before calling **UpdateVideo**.

#### Examples

```
IMFPMediaPlayer *g_pPlayer;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;

    switch (uMsg)
    {
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        if (g_pPlayer)
        {
            g_pPlayer->UpdateVideo();
        }
       	EndPaint(hwnd, &ps);
        break;

    case WM_SIZE:
        hdc = BeginPaint(hwnd, &ps);
        if (g_pPlayer)
        {
            g_pPlayer->UpdateVideo();
        }
       	EndPaint(hwnd, &ps);
        break;

    // other messages

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}
```

## See also

[IMFPMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayer)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)