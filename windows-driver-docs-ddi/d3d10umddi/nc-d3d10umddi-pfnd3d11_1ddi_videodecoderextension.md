# PFND3D11_1DDI_VIDEODECODEREXTENSION callback function

## Description

Performs an extended function for DirectX Video Acceleration (DXVA) decoding. This method enables extensions to the basic DXVA decoder functionality.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hDecoder* [in]

A handle to the video decoder object that was created through a call to the [CreateVideoDecoder](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideodecoder) function.

### `unnamedParam3`

*pExtension* [in]

A pointer to a [D3D11_1DDIARG_VIDEODECODEREXTENSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_videodecoderextension) structure that contains data for the extended function.

## Return value

**VideoDecoderExtension** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The extension was performed successfully.|
|D3DDDIERR_DEVICEREMOVED|The graphics adapter was removed.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|
|E_OUTOFMEMORY|Memory was not available to complete the operation.|

## See also

[CreateVideoDecoder](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideodecoder)

[D3D11_1DDIARG_VIDEODECODEREXTENSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_videodecoderextension)