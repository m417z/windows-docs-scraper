# PFND3D11_1DDI_GETVIDEODECODERCONFIGCOUNT callback function

## Description

Queries the number of video decoder configurations that are supported by the display miniport driver for the specified decoder operation.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pDecodeDesc* [in]

A pointer to a [D3D11_1DDI_VIDEO_DECODER_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_desc) structure that specifies the video decoder operation.

### `unnamedParam3`

*pConfigCount* [out]

A pointer to a UINT value that specifies the maximum number of decoder configurations that are supported.

## Remarks

The Microsoft Direct3D runtime verifies that the *pDecodeDesc* parameter data is valid before it calls the **GetVideoDecoderConfigCount** function.

## See also

[D3D11_1DDI_VIDEO_DECODER_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_desc)