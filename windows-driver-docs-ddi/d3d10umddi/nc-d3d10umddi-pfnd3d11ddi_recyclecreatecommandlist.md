# PFND3D11DDI_RECYCLECREATECOMMANDLIST callback function

## Description

The *RecycleCreateCommandList* function creates a command list and makes a previously unused DDI handle completely valid again.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pCreateCommandList* [in]

A pointer to a [D3D11DDIARG_CREATECOMMANDLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createcommandlist) structure that describes the parameters that the user-mode display driver uses to create a command list.

### `unnamedParam3`

*hCommandList* [in]

A handle to the driver's private data for the command list.

### `unnamedParam4`

*hRTCommandList* [in]

A handle to the command list that the driver should use, when it calls back into the Direct3D runtime.

## Return value

*RecycleCreateCommandList* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The command list is successfully created.|
|E_OUTOFMEMORY|RecycleCreateCommandList could not allocate memory that is required for it to complete.|

## Remarks

The driver is only required to implement *RecycleCreateCommandList* if the driver supports the D3D11DDICAPS_COMMANDLISTS_BUILD_2 capability, which can be returned in the [D3D11DDI_THREADING_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_threading_caps) structure from a call to the [GetCaps(D3D10_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_2ddi_getcaps) function.

For more information about *RecycleCreateCommandList*, see [Optimization for Small Command Lists](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-command-lists).

## See also

[CalcPrivateCommandListSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_calcprivatecommandlistsize)

[D3D11DDIARG_CREATECOMMANDLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createcommandlist)

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[D3D11DDI_THREADING_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_threading_caps)

[GetCaps(D3D10_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_2ddi_getcaps)