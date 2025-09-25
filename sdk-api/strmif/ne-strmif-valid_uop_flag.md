# VALID_UOP_FLAG enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Indicates which user operation (UOP) commands are currently allowed by the DVD.

## Constants

### `UOP_FLAG_Play_Title_Or_AtTime:0x1`

Annex J commands: Time_Play, TimeSearch.

### `UOP_FLAG_Play_Chapter:0x2`

Annex J commands: PTT_Play, PTT_Search.

### `UOP_FLAG_Play_Title:0x4`

Annex J command: Title_Play.

### `UOP_FLAG_Stop:0x8`

Annex J command: Stop.

### `UOP_FLAG_ReturnFromSubMenu:0x10`

Annex J command: GoUp.

### `UOP_FLAG_Play_Chapter_Or_AtTime:0x20`

Annex J commands: Time_Search, PTT_Search.

### `UOP_FLAG_PlayPrev_Or_Replay_Chapter:0x40`

Annex J commands: PrevPG_Search, TopPG_Search.

### `UOP_FLAG_PlayNext_Chapter:0x80`

Annex J command: NextPG_Search.

### `UOP_FLAG_Play_Forwards:0x100`

Annex J command: Forward_Scan.

### `UOP_FLAG_Play_Backwards:0x200`

Annex J command: Backward_Scan.

### `UOP_FLAG_ShowMenu_Title:0x400`

Annex J command: Menu_Call(*Title*).

### `UOP_FLAG_ShowMenu_Root:0x800`

Annex J command: Menu_Call(*Root*).

### `UOP_FLAG_ShowMenu_SubPic:0x1000`

Annex J command: Menu_Call(*Sub-picture*).

### `UOP_FLAG_ShowMenu_Audio:0x2000`

Annex J command: Menu_Call(*Audio*).

### `UOP_FLAG_ShowMenu_Angle:0x4000`

Annex J command: Menu_Call(*Angle*).

### `UOP_FLAG_ShowMenu_Chapter:0x8000`

Annex J command: Menu_Call(*PTT*).

### `UOP_FLAG_Resume:0x10000`

Annex J command: Resume.

### `UOP_FLAG_Select_Or_Activate_Button:0x20000`

Annex J commands: Upper_Button_Select, Lower_Button_Select, Left_Button_Select, Right_Button_Select, Button_Activate, Button_Select_And_Activate.

### `UOP_FLAG_Still_Off:0x40000`

Annex J command: Still_Off.

### `UOP_FLAG_Pause_On:0x80000`

Annex J command: Pause_On.

### `UOP_FLAG_Select_Audio_Stream:0x100000`

Annex J command: Audio_Stream_Change.

### `UOP_FLAG_Select_SubPic_Stream:0x200000`

Annex J command: Sub-picture_Stream_Change.

### `UOP_FLAG_Select_Angle:0x400000`

Annex J command : Angle_Change.

### `UOP_FLAG_Select_Karaoke_Audio_Presentation_Mode:0x800000`

Annex J command: Karaoke_Audio_Presentation_Mode_Change.

### `UOP_FLAG_Select_Video_Mode_Preference:0x1000000`

Annex J command: Video_Presentation_Mode_Change.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IDvdInfo2::GetCurrentUOPS](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getcurrentuops)