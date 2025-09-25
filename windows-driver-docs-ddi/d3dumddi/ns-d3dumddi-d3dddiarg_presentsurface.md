# D3DDDIARG_PRESENTSURFACE structure

## Description

Describes a surface to display.

## Members

### `hResource` [in]

A handle to the resource that contains the surface. **hResource** can be **NULL** if the user-mode display driver should perform a color-fill operation to the screen.

### `SubResourceIndex` [in]

The zero-based index into the resource, which is specified by the handle in the **hResource** member. This index indicates the subresource or surface to display.

## See also

[Present](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_present)