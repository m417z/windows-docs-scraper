# IDvdInfo::GetCurrentUOPS

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **IDvdInfo** interface is deprecated. Use [IDvdInfo2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2) instead.

Retrieves which [IDvdControl](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol) methods are currently valid.

## Parameters

### `pUOP` [out]

Pointer to a **DWORD** value containing bits for all user operations (UOP). Each bit in the **DWORD** represents the state (valid or not valid) of a user operation. If the bit corresponding to a user operation is set, then that user operation is prohibited. For more information, see Remarks.

## Return value

Returns an **HRESULT** value.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | DVD is not initialized or domain is not DVD_DOMAIN_Title. |
| **S_OK** | Success. |
| **VFW_E_DVD_INVALIDDOMAIN** | Requested action is not supported on this domain ([DVD_DOMAIN](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_domain)). |
| **VFW_E_DVD_OPERATION_INHIBITED** | Requested action cannot occur at this point in the movie due to the authoring of the current DVD-Video disc. |

## Remarks

This method is valid in any domain. For more information, see [DVD_DOMAIN](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_domain).

The value of *pUOP* is a bit field defined as follows.

| Bit | Flag | User function |
| --- | --- | --- |
| 0 | UOP_FLAG_Title_Or_Time_Play | [TitlePlay](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-titleplay), [TimePlay](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-timeplay) |
| 1 | UOP_FLAG_Chapter_Search_Or_Play | [ChapterSearch](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-chaptersearch), [ChapterPlay](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-chapterplay) |
| 2 | UOP_FLAG_Title_Play | TitlePlay |
| 3 | UOP_FLAG_Stop | [StopForResume](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-stopforresume) |
| 4 | UOP_FLAG_GoUp | [GoUp](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-goup) |
| 5 | UOP_FLAG_Time_Or_Chapter_Search | [TimeSearch](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-timesearch), [ChapterSearch](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-chaptersearch) |
| 6 | UOP_FLAG_Prev_Or_Top_PG_Search | [PrevPGSearch](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-prevpgsearch), [TopPGSearch](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-toppgsearch) |
| 7 | UOP_FLAG_Next_PG_Search | [NextPGSearch](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-nextpgsearch) |
| 8 | UOP_FLAG_Forward_Scan | [ForwardScan](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-forwardscan) |
| 9 | UOP_FLAG_Backward_Scan | [BackwardScan](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-backwardscan) |
| 10 | UOP_FLAG_Title_Menu_Call | [MenuCall](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-menucall) with a parameter value of 2 (DVD_MENU_Title) |
| 11 | UOP_FLAG_Root_Menu_Call | [MenuCall](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-menucall) with a parameter value of 3 (DVD_MENU_Root) |
| 12 | UOP_FLAG_SubPic_Menu_Call | [MenuCall](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-menucall) with a parameter value of 4 (DVD_MENU_Subpicture) |
| 13 | UOP_FLAG_Audio_Menu_Call | [MenuCall](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-menucall) with a parameter value of 5 (DVD_MENU_Audio) |
| 14 | UOP_FLAG_Angle_Menu_Call | [MenuCall](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-menucall) with a parameter value of 6 (DVD_MENU_Angle) |
| 15 | UOP_FLAG_Chapter_Menu_Call | [MenuCall](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-menucall) with a parameter value of 7 (DVD_MENU_Chapter) |
| 16 | UOP_FLAG_Resume | [Resume](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-resume) |
| 17 | UOP_FLAG_Button_Select_Or_Activate | [UpperButtonSelect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-upperbuttonselect), [LowerButtonSelect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-lowerbuttonselect), [LeftButtonSelect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-leftbuttonselect), [RightButtonSelect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-rightbuttonselect), [ButtonActivate](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-buttonactivate), [ButtonSelectAndActivate](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-buttonselectandactivate) |
| 18 | UOP_FLAG_Still_Off | [StillOff](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-stilloff) |
| 19 | UOP_FLAG_Pause_On | [PauseOn](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-pauseon), [MenuLanguageSelect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-menulanguageselect) |
| 20 | UOP_FLAG_Audio_Stream_Change | [AudioStreamChange](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-audiostreamchange) |
| 21 | UOP_FLAG_SubPic_Stream_Change | [SubpictureStreamChange](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-subpicturestreamchange) |
| 22 | UOP_FLAG_Angle_Change | [AngleChange](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-anglechange), [ParentalLevelSelect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-parentallevelselect) |
| 23 | UOP_FLAG_Karaoke_Audio_Pres_Mode_Change | [KaraokeAudioPresentationModeChange](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-karaokeaudiopresentationmodechange) |
| 24 | UOP_FLAG_Video_Pres_Mode_Change | [VideoModePreferrence](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-videomodepreferrence) |

This method is useful because DVD titles can enable or disable individual user operations at almost any point during playback.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo)