# IConfigInterleaving::put_Interleaving

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **put_Interleaving** method sets the audio preroll time and the frequency of interleaving for an AVI file.

## Parameters

### `prtInterleave` [in]

The approximate duration of each interleaved group of audio or video chunks, in 100-nanosecond units.
The exact amount of interleaving is also affected by the interleave mode, which is specified by calling [IConfigInterleaving::put_Mode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iconfiginterleaving-put_mode).

### `prtPreroll` [in]

The amount of audio data, in 100-nanosecond units, that is written to the file before the first video frame.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## Remarks

An audio preroll of 750 milliseconds is recommended when authoring a file for distribution.

If you do not call this method, the default value for *prtInterleave* is 1000 milliseconds. The smaller the number, the larger the resulting file.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IConfigInterleaving Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iconfiginterleaving)

[IConfigInterleaving::get_Interleaving](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iconfiginterleaving-get_interleaving)