# DVD_TextStringType enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Defines a subset of the DVD text-string types.

## Constants

### `DVD_Struct_Volume:0x1`

Indicates the top-level of the logical hierarchy. Refers to the entire contents of a one-sided disc or one side of a two-sided disc.

### `DVD_Struct_Title:0x2`

Indicates that all content strings, until the next **DVD_Struct_Title**, belong to one title.

### `DVD_Struct_ParentalID:0x3`

Indicates the parental ID of the following strings.

### `DVD_Struct_PartOfTitle:0x4`

Indicates that all content strings, until the next **DVD_Struct_PartOfTitle**, belong to one chapter.

### `DVD_Struct_Cell:0x5`

Indicates that all content strings, until the next **DVD_Struct_Cell**, belong to one cell, which can be a scene from a chapter.

### `DVD_Stream_Audio:0x10`

Indicates that the following content strings refer to the audio stream.

### `DVD_Stream_Subpicture:0x11`

Indicates that the following content strings refer to the subpicture stream.

### `DVD_Stream_Angle:0x12`

Indicates that the following content strings refer to the angle.

### `DVD_Channel_Audio:0x20`

Indicates that the following content strings refer to the audio channel.

### `DVD_General_Name:0x30`

Indicates the most important content string. Strings of this type contain the name of the volume, title, chapter, and so on, and can follow any structure identifiers.

### `DVD_General_Comments:0x31`

Identifies a content string with additional information about the title, chapter, and so on, described by the **DVD_General_Name** string. The exact nature or structure of these comments is not defined.

### `DVD_Title_Series:0x38`

Identifies a content string containing the name of a series to which the title belongs.

### `DVD_Title_Movie:0x39`

Identifies a content string with the main movie title.

### `DVD_Title_Video:0x3a`

Identifies a content string containing the name of the video title.

### `DVD_Title_Album:0x3b`

Identifies a content string containing the name of the album title.

### `DVD_Title_Song:0x3c`

Identifies a content string containing the name of the song title.

### `DVD_Title_Other:0x3f`

Identifies a content string containing the name of the title of some other genre.

### `DVD_Title_Sub_Series:0x40`

Identifies a content string with the name of the series localized to a particular country/region.

### `DVD_Title_Sub_Movie:0x41`

Identifies a content string with the movie title localized to a particular country/region.

### `DVD_Title_Sub_Video:0x42`

Identifies a content string with the video title localized to a particular country/region.

### `DVD_Title_Sub_Album:0x43`

Identifies a content string with the album title localized to a particular country/region.

### `DVD_Title_Sub_Song:0x44`

Identifies a content string with the song title localized to a particular country/region.

### `DVD_Title_Sub_Other:0x47`

Identifies a content string with the title of some other genre localized to a particular country/region.

### `DVD_Title_Orig_Series:0x48`

Identifies a content string with the original name of the series.

### `DVD_Title_Orig_Movie:0x49`

Identifies a content string with the original name of the movie.

### `DVD_Title_Orig_Video:0x4a`

Identifies a content string with the original name of the video.

### `DVD_Title_Orig_Album:0x4b`

Identifies a content string with the original name of the album.

### `DVD_Title_Orig_Song:0x4c`

Identifies a content string with the original name of the song.

### `DVD_Title_Orig_Other:0x4f`

Identifies a content string with the original name of the content.

### `DVD_Other_Scene:0x50`

Identifies a content string pertaining to a particular scene in a movie or video.

### `DVD_Other_Cut:0x51`

Identifies a content string pertaining to a particular cut in a movie or video.

### `DVD_Other_Take:0x52`

Identifies a content string pertaining to a particular take in a movie or video.

## Remarks

The [IDvdInfo2::GetDVDTextStringAsUnicode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getdvdtextstringasunicode) and [IDvdInfo2::GetDVDTextStringAsNative](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getdvdtextstringasnative) methods return this enumeration type. The value specifies how the text string is categorized. These methods can also return identifiers that are not defined in this enumeration. For more information, see [Working with DVD Text Strings](https://learn.microsoft.com/windows/desktop/DirectShow/working-with-dvd-text-strings).

Not every DVD text string identifier is included in this enumeration, so an authored DVD might include other values.

One important identifier that is not included in this enumeration is 0xF0, the code for sorting. You can use this string to sort the string data. It can be a unique number or a repetition of a previous string with the word order changed. For example, a DVD might have a string of 0x30 (DVD_General_Name) with the value "The Greatest Hits", which might be followed by another string of type 0xF0 with the value "Greatest Hits, The". As with content strings, however, the use of the sorting string is not strictly defined.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[Working with DVD Text Strings](https://learn.microsoft.com/windows/desktop/DirectShow/working-with-dvd-text-strings)