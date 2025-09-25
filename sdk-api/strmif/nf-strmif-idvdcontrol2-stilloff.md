# IDvdControl2::StillOff

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `StillOff` method resumes playback, canceling still mode.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_UNEXPECTED** | The [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) filter is in a menu domain and the menu has buttons. |
| **VFW_E_DVD_INVALIDDOMAIN** | Invalid domain. |
| **VFW_E_DVD_OPERATION_INHIBITED** | UOP control prohibits the operation. |

## Remarks

A *still* is a static image presented by the disc. It is not the same as the frozen display image that appears when the user clicks the **Pause** button. When the DVD Navigator encounters a still image, it sends the application an EC_DVD_STILL_ON message, goes into still-store mode displaying the image, and waits for `StillOff` to be called before resuming playback.

If the DVD Navigator is not in still-store mode, this method does nothing.

The following table shows the Annex J command name to which this method name corresponds, and the domains in which this method is valid.

|  |  |
| --- | --- |
| Annex J Command Name | Valid Domains |
| Still_Off | * DVD_DOMAIN_VideoManagerMenu<br>* DVD_DOMAIN_VideoTitleSetMenu<br>* DVD_DOMAIN_Title |

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdControl2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2)