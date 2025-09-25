# DVD_MENU_ID enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the DVD menu in a call to [IDvdControl2::ShowMenu](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-showmenu).

## Constants

### `DVD_MENU_Title:2`

Specifies the top menu in a DVD-Video volume. This menu is also known as the Title Menu or Video Manager Menu and it provides access to all VTS (Video Title Set) menus on the disc.

### `DVD_MENU_Root:3`

Specifies the root menu for a VTS.

### `DVD_MENU_Subpicture:4`

Specifies the subpicture submenu in a VTS menu.

### `DVD_MENU_Audio:5`

Specifies the audio submenu in a VTS menu.

### `DVD_MENU_Angle:6`

Specifies the angle submenu in a VTS menu.

### `DVD_MENU_Chapter:7`

Choose a chapter submenu in a VTS menu.

## Remarks

The root menu always provides a means of getting to the subpicture, audio, angle and chapter menus if they exist.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IDvdControl2::ShowMenu](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-showmenu)