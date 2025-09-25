# DVD_PARENTAL_LEVEL enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Identifies flags for the generic parental levels defined in the DVD specification.

## Constants

### `DVD_PARENTAL_LEVEL_8:0x8000`

Parental level 8.

### `DVD_PARENTAL_LEVEL_7:0x4000`

Parental level 7.

### `DVD_PARENTAL_LEVEL_6:0x2000`

Parental level 6.

### `DVD_PARENTAL_LEVEL_5:0x1000`

Parental level 5.

### `DVD_PARENTAL_LEVEL_4:0x800`

Parental level 4.

### `DVD_PARENTAL_LEVEL_3:0x400`

Parental level 3.

### `DVD_PARENTAL_LEVEL_2:0x200`

Parental level 2.

### `DVD_PARENTAL_LEVEL_1:0x100`

Parental level 1.

## Remarks

**DVD_PARENTAL_LEVEL_8** is the most restrictive level and **DVD_PARENTAL_LEVEL_1** is the least restrictive. The way in which the levels are interpreted or used varies from country/region to country/region. In the United States and Canada, the levels correspond to the Motion Picture Association of America (MPAA) rating levels as shown in the following table.

| Parental level | Meaning |
| --- | --- |
| 1 | The rating is G, General. |
| 3 | The rating is PG, Parental Guidance Suggested. |
| 4 | The rating is PG-13, Parental Guidance Suggested, not recommended for those under 13. |
| 6 | The rating is R, Restricted. |
| 7 | The rating is NC-17. |

This enumeration is used in the [IDvdInfo2::GetTitleParentalLevels](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-gettitleparentallevels) method.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IDvdInfo2::GetTitleParentalLevels](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-gettitleparentallevels)