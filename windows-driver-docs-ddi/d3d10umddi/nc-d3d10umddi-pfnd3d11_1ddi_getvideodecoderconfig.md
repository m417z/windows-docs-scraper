# PFND3D11_1DDI_GETVIDEODECODERCONFIG callback function

## Description

Queries the video decoder configuration for a specified video operation.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pDecodeDesc* [in]

A pointer to a [D3D11_1DDI_VIDEO_DECODER_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_desc) structure that specifies the video decoder operation.

### `unnamedParam3`

*Index* [in]

The zero-based index of the video decoder configuration that is used for the specified operation. The display miniport driver specifies the maximum number of video decoder configurations that are required for the operation through a call to its [GetVideoDecoderConfigCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideodecoderconfigcount) function.

### `unnamedParam4`

*pConfig* [out]

A pointer to a [D3D11_1DDI_VIDEO_DECODER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_config) structure that describes the video decoder configuration.

## Remarks

The Microsoft Direct3D runtime verifies that the *pDecodeDesc* and *Index* parameter data is valid before it calls the **GetVideoDecoderConfig** function.

## See also

[D3D11_1DDI_VIDEO_DECODER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_config)

[D3D11_1DDI_VIDEO_DECODER_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_desc)

[GetVideoDecoderConfigCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideodecoderconfigcount)