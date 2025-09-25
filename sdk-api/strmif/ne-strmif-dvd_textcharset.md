# DVD_TextCharSet enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Defines which character set a specified string is encoded with.

## Constants

### `DVD_CharSet_Unicode:0`

Unicode character set.

### `DVD_CharSet_ISO646:1`

ISO 646 character set.

### `DVD_CharSet_JIS_Roman_Kanji:2`

Japanese Industrial Standards (JIS) Roman Kanji character set.

### `DVD_CharSet_ISO8859_1:3`

ISO 8859-1 character set.

### `DVD_CharSet_ShiftJIS_Kanji_Roman_Katakana:4`

JIS Kanji-Roman-Katakana character set.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IDvdInfo2::GetDVDTextLanguageInfo](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getdvdtextlanguageinfo)