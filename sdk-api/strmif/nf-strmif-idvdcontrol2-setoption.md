# IDvdControl2::SetOption

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetOption** method enables or disables an internal behavior flag on the [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) filter.

## Parameters

### `flag` [in]

Specifies which behavior to modify, as a member of the [DVD_OPTION_FLAG](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_option_flag) enumeration type.

### `fState` [in]

Specifies the new value of the option given in the *flag* parameter.

[DVD_OPTION_FLAG](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_option_flag) reference page.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid flag. |

## Remarks

Call **SetOption** with the desired flags immediately after creating an instance of the DVD Navigator and whenever you want to change any behaviors.

The following table shows the Annex J command name to which this method name corresponds, and the domains in which this method is valid.

| Annex J Command Name | Valid Domains |
| --- | --- |
| None | All |

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdControl2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2)