# PFND3D11_1DDI_CREATEVIDEODECODER callback function

## Description

Creates a video decoder object.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pCreateData* [in]

A pointer to a [D3D11_1DDIARG_CREATEVIDEODECODER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createvideodecoder) structure. This structure specifies the attributes of the video decoder object to be created.

### `unnamedParam3`

*hDecode* [in]

A handle to the driver's private data for the video decoder object.

### `unnamedParam4`

*hRTDecode* [in]

A handle to the video decoder object that the driver should use when it calls back into the runtime.

## Return value

**CreateVideoDecoder** returns one of the following values:

| Return code | Description |
|:--|:--|
| S_OK | The video decoder object was created successfully. |
| D3DDDIERR_DEVICEREMOVED | The graphics adapter was removed. |
| E_OUTOFMEMORY | Memory was not available to complete the operation. |

## Remarks

The Microsoft Direct3D runtime calls *CreateVideoDecoder* after it has called the driver's [CalcPrivateVideoDecoderSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivatevideodecodersize) to determine the size in bytes for the private data that the driver requires for the video decoder object. The runtime allocates the memory for this private data for the driver. The driver uses this memory to store private data that is related to the video decoder object.

When the runtime calls *CreateVideoDecoder*, it passes the handle to the private data memory in the *hDecoder* parameter. This handle is actually a pointer to the memory.

The driver must keep track of the handle to the display device that was used to create the cryptographic session. The driver should fail all subsequent calls that use this created cryptographic session, such as [VideoDecoderBeginFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecoderbeginframe), if the display device that is specified in those calls is different from the display device that was used to create the video decoder.

## See also

[CalcPrivateVideoDecoderSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivatevideodecodersize)

[D3D11_1DDIARG_CREATEVIDEODECODER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createvideodecoder)

[NegotiateCryptoSessionKeyExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_negotiatecryptosessionkeyeschange)

[VideoDecoderBeginFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecoderbeginframe)