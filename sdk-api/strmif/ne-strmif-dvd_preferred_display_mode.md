# DVD_PREFERRED_DISPLAY_MODE enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** Deprecated.

Indicates the user's preferred window aspect ratio and conversion method.

## Constants

### `DISPLAY_CONTENT_DEFAULT:0`

Use the default window size and content type.

### `DISPLAY_16x9:1`

Use a 16 x 9 window.

### `DISPLAY_4x3_PANSCAN_PREFERRED:2`

Use a 4 x 3 window and convert to pan-scan, if possible.

### `DISPLAY_4x3_LETTERBOX_PREFERRED:3`

Use a 4 x 3 window and convert to letterbox, if possible.

## Remarks

The **DVD_PREFERRED_DISPLAY_MODE** enumeration indicates the user's preferred window aspect ratio and preferred method of conversion of 16 x 9 content to a 4 x 3 window aspect ratio. Pan-scan and letterboxing are the two conversion methods. Displaying a video at the largest possible size inside the display window without any cropping or stretching is called displaying in letterbox format. *Pan-scan* is specifically cropping a 16 x 9 video for display in a 4 x 3 window using parameters defined by the video author.

This enumerated type indicates a preference of conversion mechanisms because some content can only be displayed using one of these methods. Content that is 4 x 3 is always converted to a 16 x 9 window by using sideboxing, where black bars are added to the right and left sides of the display instead of the top and bottom of the display as in the 16 x 9 to 4 x 3 conversion using letterboxing.

The following table shows the conversion method used between the actual content type listed in the first column, and the user display preference setting, indicated by one of the other columns.

| Actual content type | 16 x 9 | 4 x 3 pan-scan | 4 x 3 letterbox |
| --- | --- | --- | --- |
| 4 x 3 | Sideboxing | None | None |
| 16 x 9 letterbox only | None | Letterbox | Letterbox |
| 16 x 9 pan-scan only | None | Pan-scan | Pan-scan |
| 16 x 9 pan-scan or letterbox | None | Pan-scan | Letterbox |

The native window size used is always the user's preferred size.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IDvdControl::VideoModePreferrence](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-videomodepreferrence)