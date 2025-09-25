# MFVIDEOFORMAT structure

## Description

Describes a video format.

## Members

### `dwSize`

Size of the structure, in bytes. This value includes the size of the palette entries that may appear after the **surfaceInfo** member.

### `videoInfo`

[MFVideoInfo](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoinfo) structure. This structure contains information that applies to both compressed and uncompressed formats.

### `guidFormat`

Video subtype. See [Video Subtype GUIDs](https://learn.microsoft.com/windows/desktop/medfound/video-subtype-guids).

### `compressedInfo`

[MFVideoCompressedInfo](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideocompressedinfo) structure. This structure contains information that applies only to compressed formats.

### `surfaceInfo`

[MFVideoSurfaceInfo](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideosurfaceinfo) structure. This structure contains information that applies only to uncompressed formats.

## Remarks

Applications should avoid using this structure. Instead, it is recommended that applications use attributes to describe the video format. For a list of media type attributes, see [Media Type Attributes](https://learn.microsoft.com/windows/desktop/medfound/media-type-attributes). With attributes, you can set just the format information that you know, which is easier (and more likely to be accurate) than trying to fill in complete format information for the **MFVIDEOFORMAT** structure.

To initialize a media type object from an **MFVIDEOFORMAT** structure, call [MFInitMediaTypeFromMFVideoFormat](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfinitmediatypefrommfvideoformat).

You can use the **MFVIDEOFORMAT** structure as the format block for a DirectShow media type. Set the format GUID to FORMAT_MFVideoFormat.

## See also

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)