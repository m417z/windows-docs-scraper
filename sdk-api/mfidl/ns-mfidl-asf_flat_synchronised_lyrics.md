# ASF_FLAT_SYNCHRONISED_LYRICS structure

## Description

Contains synchronized lyrics stored as metadata for a media source. This structure is used as the data item for the **WM/Lyrics_Synchronised** metadata attribute.

## Members

### `bTimeStampFormat`

Specifies the format of time stamps in the lyrics. This member is equivalent to the **bTimeStampFormat** member in the **WM_SYNCHRONISED_LYRICS** structure. The **WM_SYNCHRONISED_LYRICS** structure is documented in the Windows Media Format SDK.

### `bContentType`

Specifies the type of synchronized strings that are in the lyric data. This member is equivalent to the **bContentType** member in the **WM_SYNCHRONISED_LYRICS** structure.

### `dwLyricsLen`

Size, in bytes, of the lyric data.

## Remarks

The **WM/Lyrics_Synchronised** attribute is defined in the Windows Media Format SDK. The attribute contains lyrics synchronized to times in the source file.

To get this attribute from a media source, call [IMFMetadata::GetProperty](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmetadata-getproperty), passing in the constant g_wszWMLyrics_Synchronised for the *pwszName* parameter. The method retrieves a **PROPVARIANT** that contains a binary array (VT_BLOB). The layout of the array is as follows:

* **ASF_FLAT_SYNCHRONISED_LYRICS** structure.
* Null-terminated wide-character string that contains a description.
* Lyric data. The format of the lyric data is described in the Windows Media Format SDK documentation.

This format differs from the **WM_SYNCHRONISED_LYRICS** structure used in the Windows Media Format SDK. The **WM_SYNCHRONISED_LYRICS** structure contains internal pointers to two strings and the lyric data. If the structure is copied, these pointers become invalid. The **ASF_FLAT_SYNCHRONISED_LYRICS** structure does not contain internal pointers, so it is safe to copy the structure.

## See also

[IMFMetadata](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmetadata)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)