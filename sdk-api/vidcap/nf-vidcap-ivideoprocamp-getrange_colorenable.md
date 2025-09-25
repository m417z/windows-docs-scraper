# IVideoProcAmp::getRange_ColorEnable

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `getRange_ColorEnable` method returns the range of color-enable settings supported by the camera.

## Parameters

### `pMin` [out]

Receives the minimum color-enable setting.

### `pMax` [out]

Receives the maximum color-enable setting.

### `pSteppingDelta` [out]

Receives the smallest step between settings.

### `pDefault` [out]

Receives the default color-enable setting.

### `pCapsFlag` [out]

Receives one or more flags. See [VideoProcAmpFlags](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-videoprocampflags).

## Return value

Returns an **HRESULT** value.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVideoProcAmp Interface](https://learn.microsoft.com/windows/desktop/api/vidcap/nn-vidcap-ivideoprocamp)