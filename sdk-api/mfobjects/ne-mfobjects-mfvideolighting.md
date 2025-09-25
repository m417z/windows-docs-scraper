# MFVideoLighting enumeration

## Description

Describes the optimal lighting for viewing a particular set of video content.

## Constants

### `MFVideoLighting_Unknown:0`

The optimal lighting is unknown.

### `MFVideoLighting_bright:1`

Bright lighting; for example, outdoors.

### `MFVideoLighting_office:2`

Medium brightness; for example, normal office lighting.

### `MFVideoLighting_dim:3`

Dim; for example, a living room with a television and additional low lighting.

### `MFVideoLighting_dark:4`

Dark; for example, a movie theater.

### `MFVideoLighting_Last`

Reserved.

### `MFVideoLighting_ForceDWORD:0x7fffffff`

Reserved. This member forces the enumeration type to compile as a **DWORD** value.

## Remarks

This enumeration is used with the [MF_MT_VIDEO_LIGHTING](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-video-lighting-attribute) attribute.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Video Media Types](https://learn.microsoft.com/windows/desktop/medfound/video-media-types)