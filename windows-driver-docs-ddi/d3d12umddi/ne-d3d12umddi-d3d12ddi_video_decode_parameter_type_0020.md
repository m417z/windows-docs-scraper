# D3D12DDI_VIDEO_DECODE_PARAMETER_TYPE_0020 enumeration

## Description

The **D3D12DDI_VIDEO_DECODE_PARAMETER_TYPE_0020** enumeration identifies the type of data that[**D3D12DDI_VIDEO_DECODE_FRAME_ARGUMENT_0020->pData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_decode_frame_argument_0020)

Contains the video decode parameter type.

## Constants

### `D3D12DDI_VIDEO_DECODE_PARAMETER_TYPE_0020_PICTURE_PARAMETERS`

Picture decoding parameter buffer.

### `D3D12DDI_VIDEO_DECODE_PARAMETER_TYPE_0020_INVERSE_QUANTIZATION_MATRIX`

Inverse quantization matrix buffer.

### `D3D12DDI_VIDEO_DECODE_PARAMETER_TYPE_0020_SLICE_CONTROL`

The slice-level parameters of a slice of bitstream data, for off-host bitstream compressed picture decoding.

### `D3D12DDI_VIDEO_DECODE_PARAMETER_TYPE_0097_HUFFMAN_TABLE`

**pData** points to a Huffman table buffer.

## Remarks

The definition of each buffer type is dependent upon the decode profile and is defined in each codec specification.

## See also

[**D3D12DDI_VIDEO_DECODE_FRAME_ARGUMENT_0020**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_decode_frame_argument_0020)