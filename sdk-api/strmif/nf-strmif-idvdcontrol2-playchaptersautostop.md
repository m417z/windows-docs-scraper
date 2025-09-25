# IDvdControl2::PlayChaptersAutoStop

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `PlayChaptersAutoStop` method plays the number of chapters specified, starting at the specified chapter within the specified title.

## Parameters

### `ulTitle` [in]

Value that specifies the title in which the chapter is located; this value must be from 1 through 99.

### `ulChapter` [in]

Value that specifies the chapter in the specified title where the DVD Navigator will start playback; this value must be from 1 through 999.

### `ulChaptersToPlay` [in]

Number of chapters to play from the start chapter.

### `dwFlags` [in]

Bitwise **OR** of one or more flags from the [DVD_CMD_FLAGS](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_cmd_flags) enumeration, specifying how to synchronize the command.

### `ppCmd` [out]

Receives a pointer to an [IDvdCmd](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcmd) object that can be used to synchronize DVD commands. The caller must release the interface. This parameter can be **NULL**. For more information, see [Synchronizing DVD Commands](https://learn.microsoft.com/windows/desktop/DirectShow/synchronizing-dvd-commands).

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_UNEXPECTED** | The DVD Navigator is not initialized or the title is not a One Sequential PGC Title. |
| **E_INVALIDARG** | The *ulTitle* value does not exist or is greater than the number of titles, or *ulChapter* does not exist or is greater than the number of chapters, or *ulChapter* plus *ulChaptersToPlay* is greater than the number of chapters. |
| **VFW_E_DVD_GRAPHNOTREADY** | The graph is not in a running state. |

## Remarks

This method works only on One_Sequential_PGC_Titles. When the specified number of chapters have been played, the DVD Navigator sends the application an [EC_DVD_CHAPTER_AUTOSTOP](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-chapter-autostop) event notification.

The following table shows the Annex J command name to which this method name corresponds, and the domains in which this method is valid.

|  |  |
| --- | --- |
| Annex J Command Name | Valid Domains |
| None. | All. |

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdControl2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2)

[Synchronizing DVD Commands](https://learn.microsoft.com/windows/desktop/DirectShow/synchronizing-dvd-commands)