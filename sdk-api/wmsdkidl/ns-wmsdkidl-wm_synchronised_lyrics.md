# WM_SYNCHRONISED_LYRICS structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WM_SYNCHRONISED_LYRICS** structure is used as the data item for the [WM/Lyrics_Synchronised](https://learn.microsoft.com/windows/desktop/wmformat/wm-lyrics-synchronised) complex metadata attribute.

## Members

### `bTimeStampFormat`

**BYTE** specifying the format of time stamps in the lyrics. Set to one of the following values.

| Value | Description |
| --- | --- |
| 1 | Time stamps are 32-bit values containing the absolute time of the lyric in frame numbers. |
| 2 | Time stamps are 32-bit values containing the absolute time of the lyric in milliseconds. |

### `bContentType`

**BYTE** specifying the type of synchronized strings that are in the lyrics data. Set to one of the following values.

| Value | Description |
| --- | --- |
| 0 | Synchronized strings other than the types listed in this table |
| 1 | Song lyrics |
| 2 | Text transcription |
| 3 | Names of parts of the content. For example, movements of classical pieces, like "Adagio" |
| 4 | Events, such as stage directions in operas |
| 5 | Chord notations |
| 6 | Trivia information |
| 7 | URLs to Web pages |
| 8 | URLs to images |

### `pwszContentDescriptor`

Pointer to a wide-character null-terminated string containing data from the encoding application. An individual application can use this member in any way desired.

### `dwLyricsLen`

**DWORD** containing the length, in bytes, of the lyric data pointed to by **pbLyrics**.

### `pbLyrics`

Pointer to a **BYTE** array containing the lyrics. You can break the lyrics into syllables, or divide them in some other way that suits the needs of your application. Each syllable or part is included as a null-terminated, wide-character string followed by a 32-bit time stamp. The unit of measurement for the time stamp is determined by the value of **bTimeStampFormat**.

## Remarks

The objects of the Windows Media Format SDK do not validate the values of time stamps for synchronized lyrics. However, the data is checked to ensure that there is a time stamp for every string, and that the data alternates between strings and integers.

## See also

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)