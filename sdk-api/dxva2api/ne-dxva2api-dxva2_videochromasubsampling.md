# DXVA2_VideoChromaSubSampling enumeration

## Description

Describes how chroma values are positioned relative to the luma samples in a YUV video frame. These flags are used in the [DXVA2_ExtendedFormat](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_extendedformat) structure.

## Constants

### `DXVA2_VideoChromaSubsamplingMask:0xf`

Bitmask to validate flag values. This value is not a valid flag.

### `DXVA2_VideoChromaSubsampling_Unknown:0`

Unknown encoding scheme.

### `DXVA2_VideoChromaSubsampling_ProgressiveChroma:0x8`

Chroma should be reconstructed as if the underlying video was progressive content, rather than skipping fields or applying chroma filtering to minimize artifacts from reconstructing 4:2:0 interlaced chroma.

### `DXVA2_VideoChromaSubsampling_Horizontally_Cosited:0x4`

Horizontally cosited. Chroma samples are aligned horizontally with multiples of the luma samples. If this flag is not set, chroma samples are located 1/2 pixel to the right of the corresponding luma samples.

### `DXVA2_VideoChromaSubsampling_Vertically_Cosited:0x2`

Vertically cosited. Chroma samples are aligned vertically with multiples of the luma samples. If this flag is not set, chroma samples are located 1/2 pixel down from the corresponding luma samples.

### `DXVA2_VideoChromaSubsampling_Vertically_AlignedChromaPlanes:0x1`

The chroma planes are vertically aligned. If this flag is not set, chroma planes are out of phase by 1/2 chroma sample, and the Cb and Cr samples are sited on alternate lines.

### `DXVA2_VideoChromaSubsampling_MPEG2`

Specifies the chroma encoding scheme for MPEG-2 video. Chroma samples are aligned horizontally with the luma samples, but are not aligned vertically. The U and V planes are aligned vertically.

### `DXVA2_VideoChromaSubsampling_MPEG1`

Specifies the chroma encoding scheme for MPEG-1 video.

### `DXVA2_VideoChromaSubsampling_DV_PAL`

Specifies the chroma encoding scheme for PAL DV video.

### `DXVA2_VideoChromaSubsampling_Cosited`

Horizontally and vertically cosited. Chroma samples are aligned vertically and horizontally with the luma samples. YUV formats such as 4:4:4, 4:2:2, and 4:1:1 are always cosited in both directions and should use this flag.

## Remarks

The following diagrams show the most common arrangements.

### 4:4:4 horizontally and vertically cosited.

![Diagram showing 4x4 grid; each cell contains two circles--one for luma and one for chroma ](https://learn.microsoft.com/windows/win32/api/dxva2api/images/1a4cc0bf-87e4-4695-a14f-2f8a653f7ba9.gif)

### 4:2:2 horizontally and vertically cosited.

![Diagram similar to the original one, but cells in the second and fourth columns have luma but not chroma](https://learn.microsoft.com/windows/win32/api/dxva2api/images/11280687-7d75-4b6d-9e69-d78d767f3491.gif)

### 4:1:1 horizontally and vertically cosited.

![Diagram similar to the original one, but only cells in the first column contain chroma ](https://learn.microsoft.com/windows/win32/api/dxva2api/images/7443405f-735c-44fd-ad09-613f696eadf3.gif)

### 4:2:0 progressive, horizontally cosited.

![Diagram similar to the original one, but chroma circles appear only on odd-numbered row boundaries in odd-numbered columns](https://learn.microsoft.com/windows/win32/api/dxva2api/images/ba14c38b-bcab-4e68-ab24-e4a9162ce12f.gif)
Example: MPEG-2 progressive.

### 4:2:0 progressive, not cosited horizontally or vertically.

![Diagram similar to the original one, but chroma circles appear only at intersections of odd-numbered row boundaries and odd-numbered columns boundaries](https://learn.microsoft.com/windows/win32/api/dxva2api/images/6fec0c32-14a9-43d2-9703-f3e5df2dc7a0.gif)
Example: JPEG progressive.

### 4:2:0 interlaced, vertically cosited; chroma planes out of phase.

![Diagram showing two 4x4 matrices; one is lower than the other by half the width of a row, and chroma circles in each column alternate between Cr and Cb](https://learn.microsoft.com/windows/win32/api/dxva2api/images/f75760b6-59d2-4865-803d-e7ea5dd65914.gif)
Example: DV PAL interlaced.

### 4:2:0 interlaced, horizontally cosited.

![Diagram showing two instances of the fourth diagram; one is lower than the other by half the width of a row](https://learn.microsoft.com/windows/win32/api/dxva2api/images/c09b7773-fcb7-4949-a894-1d35a113ed9b.gif)
Example: MPEG-2 interlaced.

This enumeration is equivalent to the DXVA_VideoChromaSubsampling enumeration used in DXVA 1.0.

If you are using the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface to describe the video format, chroma siting is specified in the [MF_MT_VIDEO_CHROMA_SITING](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-video-chroma-siting-attribute) attribute.

## See also

[Extended Color Information](https://learn.microsoft.com/windows/desktop/medfound/extended-color-information)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)