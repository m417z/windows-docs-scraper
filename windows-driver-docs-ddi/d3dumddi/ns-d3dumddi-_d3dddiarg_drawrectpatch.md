# _D3DDDIARG_DRAWRECTPATCH structure

## Description

The D3DDDIARG_DRAWRECTPATCH structure describes a rectangular patch to draw.

## Members

### `Handle` [in]

The handle to the patch surface.

## Remarks

The **Handle** member refers to the patch surface, so that the next time the patch surface is drawn, the Microsoft Direct3D runtime is not required to re-specify the D3DRECTPATCH_INFO data structure for the patch surface. The user-mode display driver can precompute and cache forward-difference coefficients and any other information, which allows subsequent calls to the driver's [DrawRectPatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawrectpatch) function that use the same handle to run more efficiently.

## See also

[DrawRectPatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawrectpatch)