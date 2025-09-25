# PFND3D10DDI_CALCPRIVATEELEMENTLAYOUTSIZE callback function

## Description

The *CalcPrivateElementLayoutSize* function determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for an element layout.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pCreateElementLayout* [in]

A pointer to a [D3D10DDIARG_CREATEELEMENTLAYOUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createelementlayout) structure that describes the parameters that the user-mode display driver uses to calculate the size of the memory region.

## Return value

*CalcPrivateElementLayoutSize* returns the size of the memory region that the driver requires for creating an element layout.

## See also

[D3D10DDIARG_CREATEELEMENTLAYOUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createelementlayout)

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)