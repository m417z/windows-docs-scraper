# PFND3D10DDI_CREATEDEVICE callback function

## Description

The **CreateDevice(D3D10)** function creates a graphics context that is referenced in subsequent calls.

## Parameters

### `unnamedParam1`

*hAdapter* [in]

A handle to the graphics adapter object that was created with the [OpenAdapter10](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_openadapter) function.

### `unnamedParam2`

*pCreateData* [in, out]

A pointer to a [D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice) structure. On input, this structure contains information that the driver can use. On output, the driver specifies information in the structure that the Microsoft Direct3D runtime can use.

## Return value

*CreateDevice(D3D10)* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The graphics context was successfully created.|
|DXGI_STATUS_NO_REDIRECTION|The graphics context was successfully created. However, the DirectX Graphics Infrastructure (DXGI) should not use the shared resource presentation path to effect communication with the Desktop Windows Manager (DWM). For more information about the DXGI DDI, see [Supporting the DXGI DDI](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-the-dxgi-ddi).|
|E_OUTOFMEMORY|[CreateDevice(D3D10)]() could not allocate the memory that was required for it to complete.|

## Remarks

A display device is a graphics context that is used to hold a collection of rendering state. The same process can create multiple devices on a given adapter. Note that the number of display devices that can simultaneously exist is limited only by available system memory. That is, a driver cannot hardcode a maximum device limit.

Generally, devices are independent of each other, so that resources that are created in one device cannot be referenced or accessed by resources that are created in another. However, cross-process resources are an exception to this rule.

## See also

[D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice)

[D3D10DDI_ADAPTERFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_adapterfuncs)

[DestroyDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroydevice)

[OpenAdapter10](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_openadapter)