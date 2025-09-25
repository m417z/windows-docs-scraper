# AM_PROPERTY_SPHLI structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Describes the currently selected button from the DVD highlight information.

## Members

### `HLISS`

Highlight status of current selection.

### `Reserved`

Reserved for internal use. Do not use or set.

### `StartPTM`

Start presentation time divided by 90,000.

### `EndPTM`

End presentation time divided by 90,000.

### `StartX`

Start x-coordinate pixel of the current highlight button.

### `StartY`

Start y-coordinate pixel of the current highlight button.

### `StopX`

Ending x-coordinate pixel of the current highlight button.

### `StopY`

Ending y-coordinate pixel of the current highlight button.

### `ColCon`

Color contrast description of type [AM_COLCON](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvdmedia/ns-dvdmedia-am_colcon).

## Remarks

The **AM_PROPERTY_DVDSUBPIC_HLI** property uses this structure.

## See also

[DVD Subpicture Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-subpicture-property-set)