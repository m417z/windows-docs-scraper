# MFVideoInfo structure

## Description

Contains video format information that applies to both compressed and uncompressed formats.

This structure is used in the [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure.

## Members

### `dwWidth`

Width of the decoded image, in pixels.

### `dwHeight`

Height of the decoded image, in pixels.

### `PixelAspectRatio`

Pixel aspect ratio, specified as an [MFRatio](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfratio) structure.

### `SourceChromaSubsampling`

Chroma sub-sampling of the original image, specified as a member of the [MFVideoChromaSubsampling](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mfvideochromasubsampling) enumeration.

### `InterlaceMode`

Image interlacing, specified as a member of the [MFVideoInterlaceMode](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mfvideointerlacemode) enumeration.

### `TransferFunction`

R'G'B' gamma curve function, specified as a member of the [MFVideoTransferFunction](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mfvideotransferfunction) enumeration.

### `ColorPrimaries`

Color primaries of the video source, specified as a member of the [MFVideoPrimaries](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mfvideoprimaries) enumeration. This value provides the conversion from R'G'B' to linear RGB.

### `TransferMatrix`

Conversion matrix from Y'Cb'Cr' to R'G'B, specified as a member of the [MFVideoTransferMatrix](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mfvideotransfermatrix) enumeration.

### `SourceLighting`

Intended viewing conditions, specified as a member of the [MFVideoLighting](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mfvideolighting) enumeration.

### `FramesPerSecond`

Frames per second, specified as an [MFRatio](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfratio) structure. If the frame rate is unknown or variable, the numerator and denominator should both be set to zero. It is invalid for only one member of the **MFRatio** structure to be zero.

### `NominalRange`

Range of valid RGB values, specified as a member of the [MFNominalRange](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mfnominalrange) enumeration. The value indicates whether color values contain headroom and toeroom.

### `GeometricAperture`

Geometric aperture, specified as an [MFVideoArea](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoarea) structure. For more information, see [MF_MT_GEOMETRIC_APERTURE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-geometric-aperture-attribute).

### `MinimumDisplayAperture`

The display aperture, specified as an [MFVideoArea](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoarea) structure. The display aperture is the region of the video image that is intended to be shown. Any data outside of this area is the overscan region. For more information, see [MF_MT_MINIMUM_DISPLAY_APERTURE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-minimum-display-aperture-attribute).

### `PanScanAperture`

Pan-scan rectangle, specified as an [MFVideoArea](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoarea) structure. The pan-scan rectangle defines a region of the image that is displayed in pan-and-scan mode. It can be used when wide-screen content is shown on a 4 x 3 display. The value is valid only when the **VideoFlags** member contains the MFVideoFlag_PanScanEnabled flag.

### `VideoFlags`

Bitwise **OR** of zero or more flags from the [MFVideoFlags](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mfvideoflags) enumeration.

## Remarks

Developers are encouraged to use media type attributes instead of using the **MFVideoInfo** structure. The following table lists the attributes that correspond to the members of this structure.

| Structure Member | Media Type Attribute |
| --- | --- |
| **dwWidth**, **dwHeight** | [MF_MT_FRAME_SIZE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-frame-size-attribute) |
| **PixelAspectRatio** | [MF_MT_PIXEL_ASPECT_RATIO](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-pixel-aspect-ratio-attribute) |
| **SourceChromaSubsampling** | [MF_MT_VIDEO_CHROMA_SITING](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-video-chroma-siting-attribute) |
| **InterlaceMode** | [MF_MT_INTERLACE_MODE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-interlace-mode-attribute) |
| **TransferFunction** | [MF_MT_TRANSFER_FUNCTION](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-transfer-function-attribute) |
| **ColorPrimaries** | [MF_MT_VIDEO_PRIMARIES](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-video-primaries-attribute) |
| **TransferMatrix** | [MF_MT_YUV_MATRIX](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-yuv-matrix-attribute) |
| **SourceLighting** | [MF_MT_VIDEO_LIGHTING](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-video-lighting-attribute) |
| **FramesPerSecond** | [MF_MT_FRAME_RATE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-frame-rate-attribute) |
| **NominalRange** | [MF_MT_VIDEO_NOMINAL_RANGE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-video-nominal-range-attribute) |
| **GeometricAperture** | [MF_MT_GEOMETRIC_APERTURE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-geometric-aperture-attribute) |
| **MinimumDisplayAperture** | [MF_MT_MINIMUM_DISPLAY_APERTURE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-minimum-display-aperture-attribute) |
| **PanScanAperture** | [MF_MT_PAN_SCAN_APERTURE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-pan-scan-aperture-attribute) |
| **VideoFlags** | See [MFVideoFlags](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mfvideoflags). |

## See also

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)