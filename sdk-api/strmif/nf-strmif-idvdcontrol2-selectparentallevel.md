# IDvdControl2::SelectParentalLevel

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SelectParentalLevel` method sets the parental access level for the logged-on user.

## Parameters

### `ulParentalLevel`

Value that specifies the parental access level for the current user. For details, see Remarks.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid argument. |
| **VFW_E_DVD_INVALIDDOMAIN** | Invalid domain. |

## Remarks

There are eight generic parental levels defined in the DVD specification, numbered from 1 (most restrictive) through 8 (least restrictive). The meaning of these levels varies from region to region and depends on the current country/region (see [IDvdControl2::SelectParentalCountry](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-selectparentalcountry)). For the United States and Canada (DVD Region 1), the suggested values are as follows:

|  |  |
| --- | --- |
| Parental level | Meaning |
| 1 | The rating is G, general. |
| 3 | The rating is PG, parental guidance suggested. |
| 4 | The rating is PG-13, parental guidance suggested, not recommended for those under 13. |
| 6 | The rating is R, restricted. |
| 7 | The rating is NC-17, not appropriate for those under 17. |

This method sets the current user's access level; this access level determines what content the user can play. Higher levels can play lower-level content; lower levels can't play higher-level content. In other words, adults can watch child-safe content, but children can't watch adult content.

DVD player applications can enforce restrictions on the parental level setting, such as providing password protection for raising the current parental level. The application's user interface should have a way to set the level and to disable checking completely. Some discs might be authored to disallow even level 8, meaning that no level is valid and no one could watch the disc if parental management is enabled. On such discs, parental management must be disabled for the discs to be viewed. Parental management in the [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) filter is disabled by default.

To disable parental management after it has been enabled, pass 0xffffffff for *ulParentalLevel*.

This method is demonstrated in the DVDSample application in **CDvdCore::SetParentalLevel**.

The following table shows the Annex J command name to which this method name corresponds, and the domains in which this method is valid.

|  |  |
| --- | --- |
| Annex J Command Name | Valid Domains |
| Parental_Level_Select | DVD_DOMAIN_Stop |

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdControl2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2)