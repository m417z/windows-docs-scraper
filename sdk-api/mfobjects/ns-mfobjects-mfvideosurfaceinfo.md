# MFVideoSurfaceInfo structure

## Description

Contains information about an uncompressed video format. This structure is used in the [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure.

## Members

### `Format`

For compressed formats, this value must be zero. For uncompressed formats, the value is a FOURCC or **D3DFORMAT** value that identifies the format. Use the **Data1** field from the subtype GUID. See [Video Subtype GUIDs](https://learn.microsoft.com/windows/desktop/medfound/video-subtype-guids).

### `PaletteEntries`

Number of palette entries. The value must be between 0 and 256.

### `Palette`

Array of [MFPaletteEntry Union](https://learn.microsoft.com/windows/win32/api/mfobjects/ns-mfobjects-mfpaletteentry)s that contains the color table for a palettized format. The size of the array is given in the **PaletteEntries** member. If the format is not palettized, set **PaletteEntries** to zero.

## See also

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)