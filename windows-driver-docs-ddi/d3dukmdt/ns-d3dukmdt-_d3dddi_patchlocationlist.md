# _D3DDDI_PATCHLOCATIONLIST structure

## Description

The D3DDDI_PATCHLOCATIONLIST structure describes the location of an allocation to patch (that is, assign a physical address to the allocation).

## Members

### `AllocationIndex` [in]

An index of the element in the allocation list that specifies the allocation that is referenced by the patch location.

### `SlotId` [in/out]

A UINT that identifies the slot where the allocation will reside. Resources with identical slot identifiers can replace each other.

Setting this member is equivalent to setting bits in the first 24 bits of the 32-bit **Value** member (0x00FFFFFF).

### `Reserved` [in]

This member is reserved and should be set to zero.

Setting this member to zero is equivalent to setting the remaining 8 bits (0xFF000000) of the 32-bit **Value** member to zeros.

### `Value` [in]

A 32-bit value that identifies the location of an allocation to patch.

### `DriverId` [in/out]

The driver-defined identifier of the allocation specification.

### `AllocationOffset` [in/out]

The starting offset, in bytes, within the allocation that is referenced.

### `PatchOffset` [in/out]

The offset, in bytes, into the DMA buffer that must be patched.

### `SplitOffset` [in/out]

The offset, in bytes, where the DMA buffer must be split if the allocation cannot be brought into video memory.

## See also

[CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice)

[D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice)

[D3DDDICB_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_render)

[D3DDDI_ALLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationlist)

[pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb)