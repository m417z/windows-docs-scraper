# PFND3D11_1DDI_CREATEVIDEOPROCESSORINPUTVIEW callback function

## Description

Creates a resource view for a video processor. This view defines the input sample for the video processing operation.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pView* [in]

A pointer to a [D3D11_1DDIARG_CREATEVIDEOPROCESSORINPUTVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createvideoprocessorinputview) structure. This structure specifies the attributes of the video processor input view to be created.

### `unnamedParam3`

*hView* [in]

A handle to the driver's private data for the video processor input.

### `unnamedParam4`

*hRTView* [in]

A handle to the video processor input that the driver should use when it calls back into the Direct3D runtime.

## Return value

**CreateVideoProcessorInputView** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The video processor input view was created successfully.|
|D3DDDIERR_DEVICEREMOVED|The graphics adapter was removed.|
|DXGI_ERROR_UNSUPPORTED|The D3D11_1DDIARG_CREATEVIDEOPROCESSORINPUTVIEW contained incorrect or unsupported data. For example, the driver should return DXGI_ERROR_UNSUPPORTED if the FourCC member specified an unsupported code value.|
|E_OUTOFMEMORY|Memory was not available to complete the operation.|

## Remarks

The Direct3D runtime calls *CreateVideoProcessorInputView* after it has called the driver's [CalcPrivateVideoProcessorInputViewSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivatevideoprocessorinputviewsize) to determine the size in bytes for the private data that the driver requires for the video processor input view. The runtime allocates the memory for this private data for the driver. The driver uses this memory to store private data that is related to the video processor input view.

When the runtime calls *CreateVideoProcessorInputView*, it passes the handle to the private data memory in the *hView* parameter. This handle is actually a pointer to the memory.

## See also

[CalcPrivateVideoProcessorInputViewSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivatevideoprocessorinputviewsize)

[D3D11_1DDIARG_CREATEVIDEOPROCESSORINPUTVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createvideoprocessorinputview)