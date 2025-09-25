# PFND3D11_1DDI_CALCPRIVATEVIDEODECODERSIZE callback function

## Description

Returns the number of bytes that the driver requires to store private data for the video decoder state.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pDecoder* [in]

A pointer to a [D3D11_1DDIARG_CREATEVIDEODECODER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createvideodecoder) structure that describes the video decoder.

## Return value

The required number of bytes for the video decoder state.

## Remarks

The runtime will validate the members of the [D3D11_1DDIARG_CREATEVIDEODECODER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createvideodecoder) structure before it calls this function.

This function is not expected to fail.

## See also

[D3D11_1DDIARG_CREATEVIDEODECODER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createvideodecoder)