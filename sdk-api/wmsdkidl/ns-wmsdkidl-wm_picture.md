# WM_PICTURE structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WM_PICTURE** structure is used as the data item for the [WM/Picture](https://learn.microsoft.com/windows/desktop/wmformat/wmpicture) complex metadata attribute.

## Members

### `pwszMIMEType`

Pointer to a wide-character null-terminated string containing the multipurpose Internet mail extension (MIME) type of the picture.

### `bPictureType`

**BYTE** value containing one of the following values.

| Value | Description |
| --- | --- |
| 0 | Picture of a type not specifically listed in this table |
| 1 | 32 pixel by 32 pixel file icon. Use only with portable network graphics (PNG) format |
| 2 | File icon not conforming to type 1 above |
| 3 | Front album cover |
| 4 | Back album cover |
| 5 | Leaflet page |
| 6 | Media. Typically this type of image is of the label side of a CD |
| 7 | Picture of the lead artist, lead performer, or soloist |
| 8 | Picture of one of the artists or performers |
| 9 | Picture of the conductor |
| 10 | Picture of the band or orchestra |
| 11 | Picture of the composer |
| 12 | Picture of the lyricist or writer |
| 13 | Picture of the recording studio or location |
| 14 | Picture taken during a recording session |
| 15 | Picture taken during a performance |
| 16 | Screen capture from a movie or video |
| 17 | A bright colored fish |
| 18 | Illustration |
| 19 | Logo of the band or artist |
| 20 | Logo of the publisher or studio |

### `pwszDescription`

Pointer to a wide-character null-terminated string containing a description of the picture.

### `dwDataLen`

**DWORD** value containing the size, in bytes, of the picture data pointed to by **pbData**.

### `pbData`

Pointer to a **BYTE** array containing the picture data.

## See also

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)