# DXVA2_VideoLighting enumeration

## Description

Describes the intended lighting conditions for viewing video content. These flags are used in the [DXVA2_ExtendedFormat](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_extendedformat) structure.

## Constants

### `DXVA2_VideoLightingMask:0xf`

Bitmask to validate flag values. This value is not a valid flag.

### `DXVA2_VideoLighting_Unknown:0`

Unknown. Treat as DXVA2_VideoLighting_dim.

### `DXVA2_VideoLighting_bright:1`

Outdoor lighting.

### `DXVA2_VideoLighting_office:2`

Medium brightness; for example, an office.

### `DXVA2_VideoLighting_dim:3`

Dim; for example, a living room with a television and some additional low lighting.

### `DXVA2_VideoLighting_dark:4`

Dark; for example, a movie theater.

## Remarks

This enumeration is equivalent to the **DXVA_VideoLighting** enumeration used in DXVA 1.0.

If you are using the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface to describe the video format, the video lighting is specified in the [MF_MT_VIDEO_LIGHTING](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-video-lighting-attribute) attribute.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)