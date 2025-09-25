## Description

The **D3D12DDI_VIDEO_ENCODER_MOTION_ESTIMATION_PRECISION_MODE_0080** enumeration lists the possible motion estimation precision modes.

## Constants

### `D3D12DDI_VIDEO_ENCODER_MOTION_ESTIMATION_PRECISION_MODE_0080_MAXIMUM`

Indicates no limit in the precision for motion estimation vectors, thus allowing the maximum precision supported by the driver.

### `D3D12DDI_VIDEO_ENCODER_MOTION_ESTIMATION_PRECISION_MODE_0080_FULL_PIXEL`

Indicates that the precision for motion estimation vectors has to be at most full-pixel.

### `D3D12DDI_VIDEO_ENCODER_MOTION_ESTIMATION_PRECISION_MODE_0080_HALF_PIXEL`

Indicates that the precision for motion estimation vectors has to be at most half-pixel.

### `D3D12DDI_VIDEO_ENCODER_MOTION_ESTIMATION_PRECISION_MODE_0080_QUARTER_PIXEL`

Indicates that the precision for motion estimation vectors has to be at most quarter-pixel.

### `D3D12DDI_VIDEO_ENCODER_MOTION_ESTIMATION_PRECISION_MODE_0095_EIGHTH_PIXEL`

Indicates that the precision for motion estimation vectors has to be at most eighth-pixel. Added in Windows 11, version 24H2 (WDDM 3.2).

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDIARG_CREATE_VIDEO_ENCODER_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_encoder_0082_0)