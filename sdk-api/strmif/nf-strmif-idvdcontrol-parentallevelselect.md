# IDvdControl::ParentalLevelSelect

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **IDvdControl** interface is deprecated. Use [IDvdControl2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2) instread.

Sets the parental access level for the current media file.

## Parameters

### `ulParentalLevel`

Value that specifies the current media file parental access level. Should be a value from 1 to 8, inclusive. Predefined parental levels are as follows:

| Value | Description |
| --- | --- |
| 1 | The rating is G, General. |
| 3 | The rating is PG, Parental Guidance Suggested. |
| 4 | The rating is PG-13, Parental Guidance Suggested, not recommended for those under 13. |
| 6 | The rating is R, Restricted. |
| 7 | The rating is NC-17. |

## Return value

Returns an **HRESULT** value.

## Remarks

This method returns an error unless the domain is DVD_DOMAIN_Stop. For more information, see [DVD_DOMAIN](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_domain).

This method sets the current user's access level; this access level determines what media files the user can play back. Higher levels can play lower-level content; lower levels can't play higher-level content. For example, adults can watch child-safe content, but children can't watch adult content.

The [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) filter provides no restriction on setting the parental level. DVD player applications can enforce restrictions on the parental level setting, such as providing password protection for raising the current parental level. Parental management in the DVD Navigator is disabled by default.

To disable parental management, pass 0xffffffff for *ulParentalLevel*. If parental management is disabled, then the player will play the first program chain (PGC) in a parental block regardless of parental IDs.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol)

[IDvdControl::ParentalCountrySelect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-parentalcountryselect)