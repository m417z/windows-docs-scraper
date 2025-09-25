# AM_DVDCOPY_BUSKEY structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Identifies the DVD bus key.

## Members

### `BusKey`

DVD drive bus key.

### `Reserved`

Reserved.

## Remarks

The AM_PROPERTY_DVDCOPY_DVD_KEY1 and AM_PROPERTY_DVDCOPY_DEC_KEY2 properties use this structure.

A bus key is used for the DVD CSS key exchange for decryption. Implementors should get a CSS license and further instructions from CSS.

## See also

[DVD Copy Protection Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-copy-protection-property-set)