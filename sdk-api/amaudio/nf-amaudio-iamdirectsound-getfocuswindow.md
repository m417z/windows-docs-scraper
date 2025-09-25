# IAMDirectSound::GetFocusWindow

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetFocusWindow` method retrieves the window that is handling sound playback.

## Parameters

### `unnamedParam1` [out]

Pointer to a variable that receives a handle to the window. If sound playback is not associated with a window, the returned value is **NULL**.

### `unnamedParam2` [out]

Pointer to a variable that receives one of the following values.

| Value | Description |
| --- | --- |
| **TRUE** | The sound is audible when the window loses focus. |
| **FALSE** | The sound is not audible when the window loses focus. |

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | The method succeeded. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMDirectSound Interface](https://learn.microsoft.com/windows/desktop/api/amaudio/nn-amaudio-iamdirectsound)