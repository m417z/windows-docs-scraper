# D3DWDDM2_4DDI_VIDEO_DECODER_HISTOGRAM_COMPONENT enumeration

## Description

Convenience indices for arrays of per component histogram information.

## Constants

### `D3DWDDM2_4DDI_VIDEO_DECODER_HISTOGRAM_COMPONENT_Y`

If the format is a YUV format, indicates a histogram for the Y component.

### `D3DWDDM2_4DDI_VIDEO_DECODER_HISTOGRAM_COMPONENT_U`

If the format is a YUV format, indicates a histogram for the U component.

### `D3DWDDM2_4DDI_VIDEO_DECODER_HISTOGRAM_COMPONENT_V`

If the format is a YUV format, indicates a histogram for the V component.

### `D3DWDDM2_4DDI_VIDEO_DECODER_HISTOGRAM_COMPONENT_R`

If the format is an RGB/BGR format, indicates a histogram for the R component.

### `D3DWDDM2_4DDI_VIDEO_DECODER_HISTOGRAM_COMPONENT_G`

If the format is an RGB/BGR format, indicates a histogram for the G component.

### `D3DWDDM2_4DDI_VIDEO_DECODER_HISTOGRAM_COMPONENT_B`

If the format is an RGB/BGR format, indicates a histogram for the B component

### `D3DWDDM2_4DDI_VIDEO_DECODER_HISTOGRAM_COMPONENT_A`

If the format has an alpha channel, indicates a histogram for the A component

## Syntax

```cpp
typedef enum D3DWDDM2_4DDI_VIDEO_DECODER_HISTOGRAM_COMPONENT
{
    D3DWDDM2_4DDI_VIDEO_DECODER_HISTOGRAM_COMPONENT_Y = 0,
    D3DWDDM2_4DDI_VIDEO_DECODER_HISTOGRAM_COMPONENT_U = 1,
    D3DWDDM2_4DDI_VIDEO_DECODER_HISTOGRAM_COMPONENT_V = 2,

    D3DWDDM2_4DDI_VIDEO_DECODER_HISTOGRAM_COMPONENT_R = 0,
    D3DWDDM2_4DDI_VIDEO_DECODER_HISTOGRAM_COMPONENT_G = 1,
    D3DWDDM2_4DDI_VIDEO_DECODER_HISTOGRAM_COMPONENT_B = 2,

    D3DWDDM2_4DDI_VIDEO_DECODER_HISTOGRAM_COMPONENT_A = 3,
} D3DWDDM2_4DDI_VIDEO_DECODER_HISTOGRAM_COMPONENT;
```

## Remarks

## See also

[D3DWDDM2_4DDI_VIDEO_DECODER_HISTOGRAM_COMPONENT_FLAGS enumeration](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm2_4ddi_video_decoder_histogram_component_flags)