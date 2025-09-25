# IVideoProcAmp::put_WhiteBalanceComponent

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_WhiteBalanceComponent` method sets the camera's white balance, specified as red and blue component values.

## Parameters

### `Value1` [in]

Specifies the red component.

### `Value2` [in]

Specifies the blue component.

### `Flags` [in]

Zero or more flags. See [VideoProcAmpFlags](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-videoprocampflags). If the VideoProcAmp_Flags_Auto flag is used, the *Value* parameter is ignored and the camera sets the default value.

## Return value

Returns an **HRESULT** value.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVideoProcAmp Interface](https://learn.microsoft.com/windows/desktop/api/vidcap/nn-vidcap-ivideoprocamp)