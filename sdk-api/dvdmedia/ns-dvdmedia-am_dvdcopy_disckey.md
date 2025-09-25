# AM_DVDCOPY_DISCKEY structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the DVD disc key.

## Members

### `DiscKey`

DVD disc key.

## Remarks

The AM_PROPERTY_DVDCOPY_DISC_KEY property uses this structure.

A disc key is used for the DVD CSS key exchange for decryption. Implementors should get a CSS license and further instructions from CSS.

## See also

[DVD Copy Protection Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-copy-protection-property-set)