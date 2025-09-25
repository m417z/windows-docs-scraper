# IDvdControl2::ShowMenu

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `ShowMenu` method displays the specified menu, if available.

## Parameters

### `MenuID` [in]

A [DVD_MENU_ID](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-dvd_menu_id) enumeration value that specifies the menu to display.

### `dwFlags` [in]

Bitwise OR of one or more flags from the [DVD_CMD_FLAGS](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_cmd_flags) enumeration, specifying how to synchronize the command.

### `ppCmd` [out]

Receives a pointer to an [IDvdCmd](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcmd) object that can be used to synchronize DVD commands. The caller must release the interface. This parameter can be **NULL**. For more information, see [Synchronizing DVD Commands](https://learn.microsoft.com/windows/desktop/DirectShow/synchronizing-dvd-commands).

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The *MenuID* parameter is invalid. |
| **VFW_E_DVD_INVALIDDOMAIN** | Invalid domain. |
| **VFW_E_DVD_MENU_DOES_NOT_EXIST** | The specified menu does not exist. |
| **VFW_E_DVD_OPERATION_INHIBITED** | UOP control prohibits the operation. |

## Remarks

The Video Manager Menu (VMGM) should be accessible from the Title or the Video Title Set domains. The Video Title Set menus (VTSMs) might only be accessible through the VMGM. Any submenus under each VTSM (for chapters, angles, and audio and subpicture streams) are only accessible through that VTSM.

This method is demonstrated in the DVDSample application application in **CDvdCore::RootMenu** and **CDvdCore::TitleMenu**.

The following table shows the Annex J command name to which this method name corresponds, and the domains in which this method is valid.

|  |  |
| --- | --- |
| Annex J Command Name | Valid Domains |
| Menu_Call | All. |

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdControl2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2)

[Working With DVD Menus](https://learn.microsoft.com/windows/desktop/DirectShow/working-with-dvd-menus)