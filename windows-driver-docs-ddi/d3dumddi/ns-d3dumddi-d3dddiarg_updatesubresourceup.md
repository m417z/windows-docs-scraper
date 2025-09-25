# D3DDDIARG_UPDATESUBRESOURCEUP structure

## Description

Describes info that's used to update a destination subresource region from a source system-memory region. Used by Windows Display Driver Model (WDDM) 1.3 and later user-mode display drivers.

## Members

### `hResource`

A handle to the destination resource to copy to.

### `SubResourceIndex`

The index of the destination subresource to which data is to be copied.

### `DstBox`

A destination region, of type [D3DDDIBOX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddibox), of the subresource to which data is to be copied. If **Flags**->[BoxValid](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddiarg_copyflags) is not set, the entire subresource must be updated.

### `pSysMemUP`

A pointer to the beginning address of the source data that the [pfnUpdateSubresourceUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_updatesubresourceup) function copies to update the destination subresource.

### `RowPitch`

The offset, in bytes, to move to the next row of source data.

### `DepthPitch`

The offset, in bytes, to move to the next depth slice of source data.

### `Flags`

A [D3DDDIARG_COPYFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddiarg_copyflags) structure that specifies additional characteristics of the subresource update operation.

## See also

[D3DDDIARG_COPYFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddiarg_copyflags)

[D3DDDIBOX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddibox)

[pfnUpdateSubresourceUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_updatesubresourceup)