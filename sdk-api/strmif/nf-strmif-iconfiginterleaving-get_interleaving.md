# IConfigInterleaving::get_Interleaving

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_Interleaving** method gets the audio preroll time and the frequency of interleaving for an AVI file.

## Parameters

### `prtInterleave` [out]

Receives the approximate duration of each interleaved group of audio or video chunks.

### `prtPreroll` [out]

Receives the amount of audio data, in 100-nanosecond units, that is written to the file before the first video frame.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## Remarks

For more information, see [IConfigInterleaving::put_Interleaving](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iconfiginterleaving-put_interleaving).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IConfigInterleaving Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iconfiginterleaving)

[IConfigInterleaving::put_Interleaving](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iconfiginterleaving-put_interleaving)