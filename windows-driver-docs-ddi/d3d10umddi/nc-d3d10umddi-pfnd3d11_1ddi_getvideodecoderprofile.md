# PFND3D11_1DDI_GETVIDEODECODERPROFILE callback function

## Description

Queries the attributes of a specified video decoder profile.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*Index* [in]

The zero-based index of the video decoder profile. The display miniport driver returns the maximum number of video decoder profiles that it supports through a call to its [GetVideoDecoderProfileCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideodecoderprofilecount) function.

### `unnamedParam3`

*pDecodeDesc* [out]

A pointer to a [D3D11_1DDI_VIDEO_DECODER_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_desc) structure that specifies the attributes of the specified video decoder profile.

## Remarks

The Microsoft Direct3D runtime verifies that the *Index* parameter data is valid before it calls the **GetVideoDecoderProfile** function.

## See also

[D3D11_1DDI_VIDEO_DECODER_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_desc)

[GetVideoDecoderProfileCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideodecoderprofilecount)