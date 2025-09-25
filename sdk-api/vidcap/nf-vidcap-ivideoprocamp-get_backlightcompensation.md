# IVideoProcAmp::get_BacklightCompensation

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_BacklightCompensation` method returns the camera's backlight compensation setting.

## Parameters

### `pValue` [out]

Receives the backlight compensation setting. If the value is zero, backlight compensation is disabled. Otherwise, backlight compensation is enabled. The camera may support a Boolean setting (0/1) or a range of settings. If it supports a range of settings, higher numbers indicate a greater degree of backlight compensation.

### `pFlags` [out]

Receives one or more flags. See [VideoProcAmpFlags](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-videoprocampflags).

## Return value

Returns an **HRESULT** value.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVideoProcAmp Interface](https://learn.microsoft.com/windows/desktop/api/vidcap/nn-vidcap-ivideoprocamp)