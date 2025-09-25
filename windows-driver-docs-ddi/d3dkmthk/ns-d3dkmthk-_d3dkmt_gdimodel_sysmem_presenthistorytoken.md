# _D3DKMT_GDIMODEL_SYSMEM_PRESENTHISTORYTOKEN structure

## Description

The D3DKMT_GDIMODEL_SYSMEM_PRESENTHISTORYTOKEN structure identifies a GDI system present-history operation.

## Members

### `hlsurf` [in]

A 64-bit value that specifies the handle to a logical surface to copy from.

### `dwDirtyFlags` [in]

A set of flags in a 32-bit value that identifies the active rectangles (dirty regions) of the GDI surface.

### `uiCookie` [in]

A 64-bit value that specifies the handle to a physical surface to copy to.

## See also

[D3DKMT_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_presenthistorytoken)