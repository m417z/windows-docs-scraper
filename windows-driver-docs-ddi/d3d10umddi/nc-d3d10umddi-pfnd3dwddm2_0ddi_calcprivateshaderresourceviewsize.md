## Description

**CalcPrivateShaderResourceViewSize(WDDM 2.0)** determines the size of the user-mode display driver's (UMD's) private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for a shader resource view.

## Parameters

### `unnamedParam1`

[in] **hDevice** is a handle to the display device (graphics context).

### `unnamedParam2`

[in] **pCreateShaderResourceView** is a pointer to a [**D3DWDDM2_0DDIARG_CREATESHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddiarg_createshaderresourceview) structure that describes the parameters that UMD uses to calculate the size of the memory region.

## Return value

**CalcPrivateShaderResourceViewSize(WDDM 2.0)** returns the size of the memory region that the driver requires to create a shader resource view.

## See also

[**CreateShaderResourceView(WDDM 2.0)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_createshaderresourceview)

[**D3DWDDM2_0DDIARG_CREATESHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddiarg_createshaderresourceview)