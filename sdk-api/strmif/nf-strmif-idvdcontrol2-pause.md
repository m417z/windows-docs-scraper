# IDvdControl2::Pause

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This method is deprecated. Applications should call [IMediaControl::Pause](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediacontrol-pause) instead. For more information, see [Data Flow in the DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/data-flow-in-the-dvd-navigator).

The `Pause` method pauses or resumes playback at the current location.

## Parameters

### `bState` [in]

Value of type Boolean that specifies whether to pause playback; **TRUE** means to pause.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_E_DVD_INVALIDDOMAIN** | Invalid domain. |
| **VFW_E_DVD_OPERATION_INHIBITED** | UOP control prohibits the DVD Navigator from entering a paused state. |

## Remarks

Putting the DVD Navigator into a paused state freezes playback and any internal timers, similar to [IMediaControl::Pause](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediacontrol-pause). If the filter graph is not running, this method does nothing.

The following table shows the Annex J command name to which this method name corresponds, and the domains in which this method is valid.

|  |  |
| --- | --- |
| Annex J Command Name | Valid Domains |
| Pause_On, Pause_Off | * DVD_DOMAIN_VideoManagerMenu<br>* DVD_DOMAIN_VideoTitleSetMenu<br>* DVD_DOMAIN_Title |

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdControl2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2)