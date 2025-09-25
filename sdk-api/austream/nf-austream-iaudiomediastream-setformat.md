# IAudioMediaStream::SetFormat

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

Sets the format for the stream.

## Parameters

### `lpWaveFormat` [in]

Pointer to a [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure that contains stream format information.

## Return value

Returns an **HRESULT** value, which can include the following values or others not listed.

| Return code | Description |
| --- | --- |
| **MS_E_INCOMPATIBLE** | Format of the [IAudioData](https://learn.microsoft.com/windows/desktop/api/austream/nn-austream-iaudiodata) object is not compatible with stream. |
| **E_INVALIDARG** | Invalid argument. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |

## See also

[IAudioMediaStream Interface](https://learn.microsoft.com/windows/desktop/api/austream/nn-austream-iaudiomediastream)