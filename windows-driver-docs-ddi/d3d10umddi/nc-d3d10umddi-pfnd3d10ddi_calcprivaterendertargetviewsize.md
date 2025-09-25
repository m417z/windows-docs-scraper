# PFND3D10DDI_CALCPRIVATERENDERTARGETVIEWSIZE callback function

## Description

The **CalcPrivateRenderTargetViewSize** function determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for a render target view.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pCreateRenderTargetView* [in]

A pointer to a [D3D10DDIARG_CREATERENDERTARGETVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createrendertargetview) structure that describes the parameters that the user-mode display driver uses to calculate the size of the memory region.

## Return value

**CalcPrivateRenderTargetViewSize** returns the size of the memory region that the driver requires for creating a render target view.

## See also

[D3D10DDIARG_CREATERENDERTARGETVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createrendertargetview)

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)