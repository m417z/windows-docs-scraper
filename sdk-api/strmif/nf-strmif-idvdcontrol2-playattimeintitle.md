# IDvdControl2::PlayAtTimeInTitle

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `PlayAtTimeInTitle` method starts playback from the specified time in the specified title.

## Parameters

### `ulTitle` [in]

Value that specifies the number of the title to play; this value must be from 1 through 99.

### `pStartTime` [in]

Pointer to a [DVD_HMSF_TIMECODE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_hmsf_timecode) structure that specifies where playback will begin.

### `dwFlags` [in]

Bitwise **OR** of one or more flags from the [DVD_CMD_FLAGS](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_cmd_flags) enumeration, specifying how to synchronize the command.

### `ppCmd` [out]

Receives a pointer to an [IDvdCmd](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcmd) object that can be used to synchronize DVD commands. The caller must release the interface. This parameter can be **NULL**. For more information, see [Synchronizing DVD Commands](https://learn.microsoft.com/windows/desktop/DirectShow/synchronizing-dvd-commands).

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_E_DVD_OPERATION_INHIBITED** | UOP control prohibits the operation. |
| **E_INVALIDARG** | Invalid argument. |

## Remarks

The following table shows the Annex J command name to which this method name corresponds, and the domains in which this method is valid.

|  |  |
| --- | --- |
| Annex J command name | Valid domains |
| Time_Play | * DVD_DOMAIN_VideoManagerMenu<br>* DVD_DOMAIN_VideoTitleSetMenu<br>* DVD_DOMAIN_Title<br>* DVD_DOMAIN_Stop |

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdControl2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2)

[Synchronizing DVD Commands](https://learn.microsoft.com/windows/desktop/DirectShow/synchronizing-dvd-commands)