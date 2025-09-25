# IDvdControl2::PlayForwards

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `PlayForwards` method plays forward at the specified speed from the current location.

## Parameters

### `dSpeed` [in]

Value that specifies the playback speed. This value is a multiplier, where 1.0 is the authored speed, so a value of 2.5 plays at two and one-half times the authored speed, while a value of 0.5 plays at half the authored speed. The actual speed of playback depends on the capabilities of the video decoder. Values below 0.00001 are converted to 0.00001.

### `dwFlags` [in]

Bitwise OR of one or more flags from the [DVD_CMD_FLAGS](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_cmd_flags) enumeration, specifying how to synchronize the command.

### `ppCmd` [out]

Receives a pointer to an [IDvdCmd](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcmd) object that can be used to synchronize DVD commands. The caller must release the interface. This parameter can be **NULL**. For more information, see [Synchronizing DVD Commands](https://learn.microsoft.com/windows/desktop/DirectShow/synchronizing-dvd-commands).

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_E_DVD_OPERATION_INHIBITED** | UOP control prohibits the operation. |

## Remarks

This method is demonstrated in the DVDSample application in **CDvdCore::FastForward**.

The following table shows the Annex J command name to which this method name corresponds, and the domains in which this method is valid.

|  |  |
| --- | --- |
| Annex J Command Name | Valid Domains |
| Forward_Scan | * DVD_DOMAIN_VideoManagerMenu<br>* DVD_DOMAIN_VideoTitleSetMenu<br>* DVD_DOMAIN_Title |

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdControl2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2)