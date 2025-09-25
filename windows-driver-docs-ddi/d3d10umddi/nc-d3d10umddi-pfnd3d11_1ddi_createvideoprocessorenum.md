# PFND3D11_1DDI_CREATEVIDEOPROCESSORENUM callback function

## Description

Creates an enumeration object for the video processor capabilities of the driver.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pCreateData* [in]

A pointer to a [D3D11_1DDIARG_CREATEVIDEOPROCESSORENUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createvideoprocessorenum) structure. This structure specifies the attributes of the video processor enumeration object to be created.

### `unnamedParam3`

*hVideoProcessorEnum* [in]

A handle to the driver's private data for the video processor enumeration object.

### `unnamedParam4`

*hRTVideoProcessorEnum* [in]

A handle to the video processor enumeration object that the driver should use when it calls back into the Direct3D runtime.

## Return value

**CreateVideoProcessorEnum** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The video processor enumeration object was created successfully.|
|E_OUTOFMEMORY|Memory was not available to complete the operation.|

## Remarks

The Direct3D runtime calls *CreateVideoProcessorEnum* after it has called the driver's [CalcPrivateVideoProcessorEnumSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivatevideoprocessorsize)  to determine the size in bytes for the private data that the driver requires for the video processor enumeration object. The runtime allocates the memory for this private data for the driver. The driver uses this memory to store private data that is related to the video processor enumeration object.

When the runtime calls *CreateVideoProcessorEnum*, it passes the handle to the private data memory in the *hVideoProcessorEnum* parameter. This handle is actually a pointer to the memory.

## See also

[CalcPrivateVideoProcessorEnumSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivatevideoprocessorsize)

[D3D11_1DDIARG_CREATEVIDEOPROCESSORENUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createvideoprocessorenum)