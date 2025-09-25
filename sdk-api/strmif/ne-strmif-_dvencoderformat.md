# _DVENCODERFORMAT enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Indicates the digital video (DV) format.

## Constants

### `DVENCODERFORMAT_DVSD:2007`

Use the 'dvsd' stream handler.

### `DVENCODERFORMAT_DVHD:2008`

Use the 'dvhd' stream handler.

### `DVENCODERFORMAT_DVSL:2009`

Use the 'dvsl' stream handler.

## Remarks

This enumeration specifies the **fccType** member of the AVI stream header. For more information, see [DV Data in the AVI File Format](https://learn.microsoft.com/windows/desktop/DirectShow/dv-data-in-the-avi-file-format).

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IDVEnc Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvenc)