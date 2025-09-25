# PFND3D11DDI_CALCPRIVATEUNORDEREDACCESSVIEWSIZE callback function

## Description

The **CalcPrivateUnorderedAccessViewSize** function determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for an unordered access view.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pCreateUnorderedAccessView* [in]

A pointer to a [D3D11DDIARG_CREATEUNORDEREDACCESSVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createunorderedaccessview) structure that describes the parameters that the user-mode display driver uses to calculate the size of the memory region.

## Return value

**CalcPrivateUnorderedAccessViewSize** returns the size of the memory region that the driver requires to create an unordered access view.

## See also

[D3D11DDIARG_CREATEUNORDEREDACCESSVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createunorderedaccessview)

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)