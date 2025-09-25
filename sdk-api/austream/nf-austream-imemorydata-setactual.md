# IMemoryData::SetActual

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

Sets the amount of audio data currently in the object.

## Parameters

### `cbDataValid` [in]

Amount of data, in bytes.

## Return value

Returns S_OK if successful or E_POINTER if the required parameter is **NULL**.

## Remarks

This method is usually called by the [IAudioMediaStream](https://learn.microsoft.com/windows/desktop/api/austream/nn-austream-iaudiomediastream) or [IAudioStreamSample](https://learn.microsoft.com/windows/desktop/api/austream/nn-austream-iaudiostreamsample) object, rather than by the application.

## See also

[IMemoryData Interface](https://learn.microsoft.com/windows/desktop/api/austream/nn-austream-imemorydata)