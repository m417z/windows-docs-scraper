# PFND3DDDI_DXVAHD_CREATEVIDEOPROCESSOR callback function

## Description

The **CreateVideoProcessor** function creates a Microsoft DirectX Video Acceleration (DirectX VA) video processor that is used to process high-definition video.

## Parameters

### `unnamedParam1`

### `unnamedParam2`

*hDevice* [in]

A handle to the display device (graphics context).

*pData* [in, out]

A pointer to a [D3DDDIARG_DXVAHD_CREATEVIDEOPROCESSOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_createvideoprocessor) structure. On input, contains information that the driver can use. On output, the driver specifies information that the Microsoft Direct3D runtime can use.

## Return value

**CreateVideoProcessor** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The video processor is successfully created.|
|E_OUTOFMEMORY|CreateVideoProcessor could not allocate the required memory for it to complete.|

## See also

[D3DDDIARG_DXVAHD_CREATEVIDEOPROCESSOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_createvideoprocessor)

[DestroyVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_destroyvideoprocessor)