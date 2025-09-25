# DVDTextStringType enumeration

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **DVDTextStringType** enumeration type indicates the type of information contained in a DVD text string.

## Constants

### `dvdStruct_Volume:0x1`

Indicates the top level of the logical hierarchy. Refers to the entire contents of a one-sided disc or one side of a two-sided disc.

### `dvdStruct_Title:0x2`

Indicates that all content strings, until the next dvd_Struct_Title, belong to one title.

### `dvdStruct_ParentalID:0x3`

Indicates the parental ID of the following strings.

### `dvdStruct_PartOfTitle:0x4`

Indicates that all content strings, until the next dvd_Struct_PartOfTitle, belong to one chapter.

### `dvdStruct_Cell:0x5`

Indicates that all content strings, until the next dvd_Struct_Cell, belong to one cell, which can be a scene from a chapter.

### `dvdStream_Audio:0x10`

Indicates that the following content strings refer to the audio stream.

### `dvdStream_Subpicture:0x11`

Indicates that the following content strings refer to the subpicture stream.

### `dvdStream_Angle:0x12`

Indicates that the following content strings refer to the angle.

### `dvdChannel_Audio:0x20`

Indicates that the following content strings refer to the audio channel.

### `dvdGeneral_Name:0x30`

Indicates the most important content string. Strings of this type contain the name of the volume, title, chapter, and so on, and can follow any structure identifiers.

### `dvdGeneral_Comments:0x31`

Identifies a content string with additional information about the title, chapter, and so on, described by the dvd_General_Name string. The exact nature or structure of these comments is not defined.

### `dvdTitle_Series:0x38`

Identifies a content string containing the name of a series to which the title belongs.

### `dvdTitle_Movie:0x39`

Identifies a content string with the main movie title.

### `dvdTitle_Video:0x3a`

Identifies a content string containing the name of the video title.

### `dvdTitle_Album:0x3b`

Identifies a content string containing the name of the album title.

### `dvdTitle_Song:0x3c`

Identifies a content string containing the name of the song title.

### `dvdTitle_Other:0x3f`

Identifies a content string containing the name of the title of some other genre.

### `dvdTitle_Sub_Series:0x40`

Identifies a content string with the name of the series localized to a particular country/region.

### `dvdTitle_Sub_Movie:0x41`

Identifies a content string with the movie title localized to a particular country/region.

### `dvdTitle_Sub_Video:0x42`

Identifies a content string with the video title localized to a particular country/region.

### `dvdTitle_Sub_Album:0x43`

Identifies a content string with the album title localized to a particular country/region.

### `dvdTitle_Sub_Song:0x44`

Identifies a content string with the song title localized to a particular country/region.

### `dvdTitle_Sub_Other:0x47`

Identifies a content string with the title of some other genre localized to a particular country/region.

### `dvdTitle_Orig_Series:0x48`

Identifies a content string with the original name of the series.

### `dvdTitle_Orig_Movie:0x49`

Identifies a content string with the original name of the movie.

### `dvdTitle_Orig_Video:0x4a`

Identifies a content string with the original name of the video.

### `dvdTitle_Orig_Album:0x4b`

Identifies a content string with the original name of the album.

### `dvdTitle_Orig_Song:0x4c`

Identifies a content string with the original name of the song.

### `dvdTitle_Orig_Other:0x4f`

Identifies a content string with the original name of the content.

### `dvdOther_Scene:0x50`

Identifies a content string pertaining to a particular scene in a movie or video.

### `dvdOther_Cut:0x51`

Identifies a content string pertaining to a particular cut in a movie or video.

### `dvdOther_Take:0x52`

Identifies a content string pertaining to a particular take in a movie or video.

## Remarks

A [DVD_TextStringType](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_textstringtype) value is returned in the [DVDTextStringType](https://learn.microsoft.com/windows/desktop/api/segment/ne-segment-dvdtextstringtype) method to identify how the disc authors have categorized the specified text string.

Not every DVD text string identifier is included in this enumeration, so an authored DVD might include other values.

One important text string type not defined in this enumeration is 0xF0, the extension-sorting text string type. You can use this type of string in many ways to enable players to sort the string data. It can be a unique number or a repetition of a previous string with the word order changed. For example, a string of type 0x30 that has the name "The Greatest Hits" might be followed by a string of type 0xF0 that says "Greatest Hits, The." As with content strings, the use of the sorting string is not strictly defined.

## See also

[DVDTextStringType](https://learn.microsoft.com/windows/desktop/api/segment/ne-segment-dvdtextstringtype)

[Video Control Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/video-control-enumerations)

[Working with DVD Text Strings](https://learn.microsoft.com/windows/desktop/DirectShow/working-with-dvd-text-strings)