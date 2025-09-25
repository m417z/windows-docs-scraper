# AM_DVD_YUV structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Contains DVD YUV subpicture data.

## Members

### `Reserved`

Reserved.

### `Y`

Y color data.

### `U`

U color data.

### `V`

V color data.

## Remarks

This structure is contained within the [AM_PROPERTY_SPPAL](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvdmedia/ns-dvdmedia-am_property_sppal) structure.

## See also

[DVD Subpicture Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-subpicture-property-set)