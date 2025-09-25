# _D3DKMT_GDIMODEL_PRESENTHISTORYTOKEN structure

## Description

The D3DKMT_GDIMODEL_PRESENTHISTORYTOKEN structure identifies a GDI present-history operation.

## Members

### `hLogicalSurface` [in]

A 64-bit value that specifies the handle to a logical surface to copy from.

### `hPhysicalSurface` [in]

A 64-bit value that specifies the handle to a physical surface to copy to.

### `ScrollRect`

This member is reserved and should be set to zero.

Supported starting with Windows 8.

### `ScrollOffset`

This member is reserved and should be set to zero.

Supported starting with Windows 8.

### `DirtyRegions` [in]

A [D3DKMT_DIRTYREGIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_dirtyregions) structure that identifies the active rectangles (dirty regions) of the GDI surface.

## See also

[D3DKMT_DIRTYREGIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_dirtyregions)

[D3DKMT_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_presenthistorytoken)