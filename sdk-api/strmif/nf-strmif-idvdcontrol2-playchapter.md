# IDvdControl2::PlayChapter

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `PlayChapter` method starts playback from the specified chapter in the current title.

## Parameters

### `ulChapter` [in]

Value that specifies the chapter in the current title where the DVD Navigator will start playback; this value must be from 1 through 999.

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

The DVD Navigator begins playback at the specified chapter and continues to the subsequent chapters. Use [IDvdControl2::PlayChaptersAutoStop](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-playchaptersautostop) to play the current chapter only.

The following table shows the Annex J command name to which this method name corresponds, and the domains in which this method is valid.

This method is demonstrated in the DVDSample application in **CDvdCore::PlayChapter**.

|  |  |
| --- | --- |
| Annex J Command Name | Valid Domains |
| PTT_Search | DVD_DOMAIN_Title |

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdControl2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2)

[Synchronizing DVD Commands](https://learn.microsoft.com/windows/desktop/DirectShow/synchronizing-dvd-commands)