# D3D12DDI_VIDEO_DECODE_FRAME_ARGUMENT_0020 structure

## Description

Contains the decode parameters for the frame. Parameter definitions are specified by the codec specification for each decode profile.

## Members

### `Type`

The type of the parameter. For more information, see the [D3D12DDI_VIDEO_DECODE_PARAMETER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_decode_parameter_type_0020) enumeration.

### `pData`

A pointer to the parameter data.

### `Size`

The size, in bytes, of the parameter data specified by the *pData* parameter.

## See also

[D3D12DDI_VIDEO_DECODE_PARAMETER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_decode_parameter_type_0020)