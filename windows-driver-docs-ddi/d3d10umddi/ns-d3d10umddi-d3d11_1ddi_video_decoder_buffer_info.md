# D3D11_1DDI_VIDEO_DECODER_BUFFER_INFO structure

## Description

Specifies information about a video decoder buffer.

## Members

### `Type`

The type of buffer, specified as a constant value of the [D3D11_DDI_VIDEO_DECODER_BUFFER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_ddi_video_decoder_buffer_type) enumeration.

In D3d10umddi.h, [D3D11_DDI_VIDEO_DECODER_BUFFER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_ddi_video_decoder_buffer_type) and **D3D11_1DDI_VIDEO_DECODER_BUFFER_TYPE** are defined as the same type.

### `Size`

The size of the buffer, in bytes.

### `Usage`

A value from the [D3D11_1DDI_VIDEO_USAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_usage) enumeration that identifies how the decode device plays video.

## See also

[D3D11_1DDI_VIDEO_USAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_usage)

[D3D11_DDI_VIDEO_DECODER_BUFFER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_ddi_video_decoder_buffer_type)