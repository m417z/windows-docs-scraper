# PFND3D11_1DDI_GETVIDEODECODERBUFFERINFO callback function

## Description

Queries the description of a video decoder buffer for a specified video operation.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pDecodeDesc* [in]

A pointer to a [D3D11_1DDI_VIDEO_DECODER_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_desc) structure that specifies the video decoder operation.

### `unnamedParam3`

*Index* [in]

The zero-based index of the video decoder buffer type that is used for the specified operation. The display miniport driver returns the maximum number of video decoder buffer types that are required for the operation through a call to its [GetVideoDecoderBufferTypeCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideodecoderbuffertypecount) function.

### `unnamedParam4`

*pInfo* [out]

A pointer to a [D3D11_1DDI_VIDEO_DECODER_BUFFER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_buffer_info) structure that describes the video decoder buffer.

## Remarks

The Microsoft Direct3D runtime verifies that the *pDecodeDesc* and *Index* parameter data is valid before it calls the **GetVideoDecoderBufferInfo** function.

## See also

[D3D11_1DDI_VIDEO_DECODER_BUFFER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_buffer_info)

[D3D11_1DDI_VIDEO_DECODER_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_desc)

[GetVideoDecoderBufferTypeCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideodecoderbuffertypecount)