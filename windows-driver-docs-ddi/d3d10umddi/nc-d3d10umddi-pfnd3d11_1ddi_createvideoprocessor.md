# PFND3D11_1DDI_CREATEVIDEOPROCESSOR callback function

## Description

Creates a video processor object.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pCreateData* [in]

A pointer to a [D3D11_1DDIARG_CREATEVIDEOPROCESSOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createvideoprocessor) structure. This structure specifies the attributes of the video processor object to be created.

### `unnamedParam3`

*hVideoProcessor* [in]

A handle to the driver's private data for the video processor object.

### `unnamedParam4`

*hRTVideoProcessor* [in]

A handle to the video processor object that the driver should use when it calls back into the Direct3D runtime.

## Return value

**CreateVideoProcessor** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The video processor object was created successfully.|
|D3DDDIERR_DEVICEREMOVED|The graphics adapter was removed.|
|E_OUTOFMEMORY|Memory was not available to complete the operation.|

## Remarks

The *CreateVideoProcessor* function creates a video processor object that contains specific capabilities and state. Multiple video processor objects can exist at the same time, each with its own unique state.

The Direct3D runtime calls *CreateVideoProcessor* after it has called the driver's [CalcPrivateVideoProcessorSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivatevideoprocessorsize) to determine the size in bytes for the private data that the driver requires for the video processor object. The runtime allocates the memory for this private data for the driver. The driver uses this memory to store private data that is related to the video processor object.

When the runtime calls *CreateVideoProcessor*, it passes the handle to the private data memory in the *hProcessor* parameter. This handle is actually a pointer to the memory.

## See also

[CalcPrivateVideoProcessorSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivatevideoprocessorsize)

[D3D11_1DDIARG_CREATEVIDEOPROCESSOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createvideoprocessor)