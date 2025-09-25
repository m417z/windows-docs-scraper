# DXVA2_VideoProcessBltParams structure

## Description

Contains parameters for the [IDirectXVideoProcessor::VideoProcessBlt](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideoprocessor-videoprocessblt) method.

## Members

### `TargetFrame`

Presentation time for the target frame, in 100-nanosecond units. If the video is interlaced, this value must be either the start time for the frame or the midpoint for the frame. If the video is progressive, this value must be the start time.

### `TargetRect`

Specifies the target rectangle, which is the rectangle within the destination surface where the output video frame is drawn.

The target rectangle cannot be larger than the destination surface.

### `ConstrictionSize`

Size to which the output video should be downsampled.
If this feature is supported, the driver sets the **DXVA2_VideoProcess_Constriction** flag in the [DXVA2_VideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_videoprocessorcaps) structure.

The downsampling size cannot be less than zero, or larger than the size of the target rectangle (**TargetRect**).

### `StreamingFlags`

Reserved. Set to zero.

### `BackgroundColor`

A [DXVA2_AYUVSample16](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_ayuvsample16) structure that specifies the background color for the destination rectangle. The background color is used wherever no video image appears, but only within the **TargetRect** rectangle. The color is specified as an AYUV color value with 16 bits per channel.

The alpha channel (**Alpha**) must be opaque (0xFFFF). The DXVA driver should ignore the value of the alpha channel.

The color space for the background color is given by the **DestFormat** member. Note that the background color is always specified as a YUV color, even if the destination surface is RGB.

### `DestFormat`

A [DXVA2_ExtendedFormat](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_extendedformat) structure that contains extended color information for the destination rectangle. For video playback, the recommended value for the nominal range is DXVA2_NominalRange_Unknown. For more information, see [DXVA2_NominalRange](https://learn.microsoft.com/windows/desktop/api/dxva2api/ne-dxva2api-dxva2_nominalrange) enumeration.

### `ProcAmpValues`

A [DXVA2_ProcAmpValues](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_procampvalues) structure that specifies color adjustment (ProcAmp) settings. These values must fall within the ranges returned by the [IDirectXVideoProcessor::GetProcAmpRange](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideoprocessor-getprocamprange) method.

### `Alpha`

Alpha value that is applied to the composited image when it is copied to the destination surface. The alpha value is fixed-point value, specified as a [DXVA2_Fixed32](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_fixed32) structure. To specify 100% opacity, use the [DXVA2_Fixed32OpaqueAlpha](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-dxva2_fixed32opaquealpha) function.

### `NoiseFilterLuma`

A [DXVA2_FilterValues](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_filtervalues) structure that contains parameters for the luma noise filter.

### `NoiseFilterChroma`

A [DXVA2_FilterValues](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_filtervalues) structure that contains parameters for the chroma noise filter.

### `DetailFilterLuma`

A [DXVA2_FilterValues](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_filtervalues) structure that contains parameters for the luma detail filter.

### `DetailFilterChroma`

A [DXVA2_FilterValues](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_filtervalues) structure that contains parameters for the chroma detail filter.

### `DestData`

Contains additional flags. The following flags are defined.

| Value | Meaning |
| --- | --- |
| **DXVA2_DestData_RFF** | Repeat first field (RFF) bit. |
| **DXVA2_DestData_TFF** | Top field first (TFF) bit. |
| **DXVA2_DestData_RFF_TFF_Present** | If set, the RFF and TFF flags are used. |

Currently, these flags are ignored. They are intended for use with interlaced output, which is not supported at this time.

## See also

[DXVA Video Processing](https://learn.microsoft.com/windows/desktop/medfound/dxva-video-processing)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)