# _D3DKMT_BLTMODEL_PRESENTHISTORYTOKEN structure

## Description

The D3DKMT_BLTMODEL_PRESENTHISTORYTOKEN structure identifies a bit-block transfer (bitblt) present-history operation.

## Members

### `hLogicalSurface` [in]

A 64-bit value that specifies the handle to a logical surface to copy from.

### `hPhysicalSurface` [in]

A 64-bit value that specifies the handle to a physical surface to copy to.

### `EventId` [in]

A 64-bit value that identifies the bitblt event.

### `DirtyRegions` [in]

A [D3DKMT_DIRTYREGIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_dirtyregions) structure that identifies the active rectangles (dirty regions) of the bitblt surface.

## See also

[D3DKMT_DIRTYREGIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_dirtyregions)

[D3DKMT_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_presenthistorytoken)