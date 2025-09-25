# IAMAudioRendererStats::GetStatParam

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetStatParam` method retrieves performance information from the audio renderer.

## Parameters

### `dwParam` [in]

Specifies a member of the [_AM_AUDIO_RENDERER_STAT_PARAM](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-_am_audio_renderer_stat_param) enumeration, indicating which information to retrieve.

### `pdwParam1` [out]

Pointer to a variable that receives performance information. The meaning of the returned value depends on the value of *dwParam*.

### `pdwParam2` [out]

Pointer to a variable that receives performance information. The meaning of the returned value depends on the value of *dwParam*.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure. |
| **E_INVALIDARG** | Invalid argument. |
| **E_NOTIMPL** | The renderer does not track the specified information. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |

## See also

[IAMAudioRendererStats Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamaudiorendererstats)