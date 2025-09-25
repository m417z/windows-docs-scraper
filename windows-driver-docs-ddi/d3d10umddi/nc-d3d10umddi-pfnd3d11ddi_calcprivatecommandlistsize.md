# PFND3D11DDI_CALCPRIVATECOMMANDLISTSIZE callback function

## Description

The **CalcPrivateCommandListSize** function determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for a command list.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pCreateCommandList* [in]

A pointer to a [D3D11DDIARG_CREATECOMMANDLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createcommandlist) structure that describes the parameters that the user-mode display driver uses to calculate the size of the memory region.

## Return value

**CalcPrivateCommandListSize** returns the size of the memory region that the driver requires to create a command list.

## Remarks

The driver is only required to implement **CalcPrivateCommandListSize** if the driver supports the D3D11DDICAPS_COMMANDLISTS_BUILD_2 capability that can be returned in the [D3D11DDI_THREADING_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_threading_caps) structure from a call to the [GetCaps(D3D10_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_2ddi_getcaps) function.

## See also

[D3D11DDIARG_CREATECOMMANDLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createcommandlist)

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[D3D11DDI_THREADING_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_threading_caps)

[GetCaps(D3D10_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_2ddi_getcaps)