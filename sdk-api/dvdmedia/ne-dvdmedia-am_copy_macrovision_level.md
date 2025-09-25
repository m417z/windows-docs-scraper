# AM_COPY_MACROVISION_LEVEL enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Identifies the analog copy protection level.

## Constants

### `AM_MACROVISION_DISABLED:0`

Disabled.

### `AM_MACROVISION_LEVEL1:1`

Level 1.

### `AM_MACROVISION_LEVEL2:2`

Level 2.

### `AM_MACROVISION_LEVEL3:3`

Level 3.

## Remarks

The [AM_COPY_MACROVISION](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvdmedia/ns-dvdmedia-am_copy_macrovision) structure uses this data type.

## See also

[DVD Copy Protection Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-copy-protection-property-set)