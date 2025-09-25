# PFND3D11_1DDI_GETVIDEODECODERBUFFERTYPECOUNT callback function

## Description

Queries the number of buffer types that the display miniport driver requires to perform a specified decode operation.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pDecodeDesc* [in]

A pointer to a [D3D11_1DDI_VIDEO_DECODER_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_desc) structure that specifies the video decoder operation.

### `unnamedParam3`

*pBufferTypeCount* [out]

A pointer to a UINT value that specifies the maximum number of buffer types that the driver supports for the specified video decoder operation.

## Remarks

The Microsoft Direct3D runtime verifies that the *pDecodeDesc* parameter data is valid before it calls the **GetVideoDecoderBufferTypeCount** function.

## See also

[D3D11_1DDI_VIDEO_DECODER_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_desc)