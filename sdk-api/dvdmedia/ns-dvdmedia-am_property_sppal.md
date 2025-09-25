# AM_PROPERTY_SPPAL structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the DVD subpicture palette.

## Members

### `sppal`

Array of 16 YUV elements that correspond to the 4-bit color numbers requested within the subpicture command stream. The YUV elements are of type [AM_DVD_YUV](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvdmedia/ns-dvdmedia-am_dvd_yuv).

## Remarks

The AM_PROPERTY_DVDSUBPIC_PALETTE property uses this structure.

## See also

[DVD Subpicture Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-subpicture-property-set)