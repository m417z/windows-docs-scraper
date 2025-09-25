# _D3DDDI_KERNELOVERLAYINFO structure

## Description

The D3DDDI_KERNELOVERLAYINFO structure describes information for a kernel-mode overlay object.

## Members

### `hAllocation` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the allocation to be displayed.

### `DstRect` [in]

A [D3DDDIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddirect) structure that contains the overlay destination rectangle in device coordinates.

### `SrcRect` [in]

A [D3DDDIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddirect) structure that contains the overlay source rectangle in device coordinates.

### `pPrivateDriverData` [in]

A pointer to a block of private data, which is passed from the user-mode display driver to the display miniport driver.

### `PrivateDriverDataSize` [in]

The size, in bytes, of the block of private data that is pointed to by **pPrivateDriverData**.

## See also

[D3DDDIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddirect)

[pfnCreateOverlayCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createoverlaycb)

[pfnUpdateOverlayCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_updateoverlaycb)