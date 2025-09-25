# MFVideoChromaSubsampling enumeration

## Description

Contains flags that define the chroma encoding scheme for Y'Cb'Cr' data.

## Constants

### `MFVideoChromaSubsampling_Unknown:0`

Unknown encoding scheme.

### `MFVideoChromaSubsampling_ProgressiveChroma:0x8`

Chroma should be reconstructed as if the underlying video was progressive content, rather than skipping fields or applying chroma filtering to minimize artifacts from reconstructing 4:2:0 interlaced chroma.

### `MFVideoChromaSubsampling_Horizontally_Cosited:0x4`

Chroma samples are aligned horizontally with the luma samples, or with multiples of the luma samples. If this flag is not set, chroma samples are located 1/2 pixel to the right of the corresponding luma sample.

### `MFVideoChromaSubsampling_Vertically_Cosited:0x2`

Chroma samples are aligned vertically with the luma samples, or with multiples of the luma samples. If this flag is not set, chroma samples are located 1/2 pixel down from the corresponding luma sample.

### `MFVideoChromaSubsampling_Vertically_AlignedChromaPlanes:0x1`

The U and V planes are aligned vertically. If this flag is not set, the chroma planes are assumed to be out of phase by 1/2 chroma sample, alternating between a line of U followed by a line of V.

### `MFVideoChromaSubsampling_MPEG2`

Specifies the chroma encoding scheme for MPEG-2 video. Chroma samples are aligned horizontally with the luma samples, but are not aligned vertically. The U and V planes are aligned vertically.

### `MFVideoChromaSubsampling_MPEG1`

Specifies the chroma encoding scheme for MPEG-1 video.

### `MFVideoChromaSubsampling_DV_PAL`

Specifies the chroma encoding scheme for PAL DV video.

### `MFVideoChromaSubsampling_Cosited`

Chroma samples are aligned vertically and horizontally with the luma samples. YUV formats such as 4:4:4, 4:2:2, and 4:1:1 are always cosited in both directions and should use this flag.

### `MFVideoChromaSubsampling_Last`

Reserved.

### `MFVideoChromaSubsampling_ForceDWORD:0x7fffffff`

Reserved. This member forces the enumeration type to compile as a **DWORD** value.

## Remarks

These flags are used with the [MF_MT_VIDEO_CHROMA_SITING](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-video-chroma-siting-attribute) attribute.

For more information about these values, see the remarks for the [DXVA2_VideoChromaSubSampling](https://learn.microsoft.com/windows/desktop/api/dxva2api/ne-dxva2api-dxva2_videochromasubsampling) enumeration, which is the DirectX Video Acceleration (DXVA) equivalent of this enumeration.

## See also

[Extended Color Information](https://learn.microsoft.com/windows/desktop/medfound/extended-color-information)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Video Media Types](https://learn.microsoft.com/windows/desktop/medfound/video-media-types)