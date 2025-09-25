## Description

The **CalcPrivateUnorderedAccessViewSize** function determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for an unordered access view.

## Parameters

### `unnamedParam1`

[in] **hDevice** is a handle to the display device (graphics context).

### `unnamedParam2`

[in] **pCreateUnorderedAccessView** is a pointer to a [**D3DWDDM2_0DDIARG_CREATEUNORDEREDACCESSVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddiarg_createunorderedaccessview) structure that describes the parameters that the user-mode display driver uses to calculate the size of the memory region.

## Return value

**CalcPrivateUnorderedAccessViewSize** returns the size in bytes of the memory region that the driver requires to create an unordered access view.

## See also

[**D3DWDDM2_0DDIARG_CREATEUNORDEREDACCESSVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddiarg_createunorderedaccessview)

[**D3D11DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)