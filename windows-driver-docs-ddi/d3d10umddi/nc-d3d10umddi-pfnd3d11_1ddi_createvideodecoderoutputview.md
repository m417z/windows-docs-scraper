# PFND3D11_1DDI_CREATEVIDEODECODEROUTPUTVIEW callback function

## Description

Creates a resource view for a video decoder. This view defines the output sample for the video decoding operation.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pCreateData* [in]

A pointer to a [D3D11_1DDIARG_CREATEVIDEODECODEROUTPUTVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createvideodecoderoutputview) structure. This structure specifies the attributes of the video decoder output view to be created.

### `unnamedParam3`

*hView* [in]

A handle to the driver's private data for the video decoder output view.

### `unnamedParam4`

*hRTView* [in]

A handle to the video decoder output view that the driver should use when it calls back into the Direct3D runtime.

## Return value

**CreateVideoDecoderOutputView** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The video decoder output view was created successfully. |
| **D3DDDIERR_DEVICEREMOVED** | The graphics adapter was removed. |
| **E_OUTOFMEMORY** | Memory was not available to complete the operation. |

## Remarks

The Direct3D runtime calls *CreateVideoDecoderOutputView* after it has called the driver's [CalcPrivateVideoProcessorOutputViewSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivatevideoprocessoroutputviewsize) to determine the size in bytes for the private data that the driver requires for the video decoder object. The runtime allocates the memory for this private data for the driver. The driver uses this memory to store private data that is related to the video decoder object.

When the runtime calls *CreateVideoDecoderOutputView*, it passes the handle to the private data memory in the *hView* parameter. This handle is actually a pointer to the memory.

## See also

[CalcPrivateVideoProcessorOutputViewSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivatevideoprocessoroutputviewsize)

[D3D11_1DDIARG_CREATEVIDEODECODER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createvideodecoder)

[NegotiateCryptoSessionKeyExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_negotiatecryptosessionkeyeschange)

[VideoDecoderBeginFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecoderbeginframe)