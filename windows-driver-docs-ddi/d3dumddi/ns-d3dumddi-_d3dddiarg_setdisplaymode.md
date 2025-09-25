# _D3DDDIARG_SETDISPLAYMODE structure

## Description

The D3DDDIARG_SETDISPLAYMODE structure describes parameters for setting the display mode.

## Members

### `hResource` [in]

A handle to the resource that contains the display surface.

### `SubResourceIndex` [in]

The zero-based index into the resource, which is specified by the handle in the **hResource** member. This index indicates the display surface.

## See also

[SetDisplayMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setdisplaymode)