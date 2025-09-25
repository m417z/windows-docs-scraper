# _D3DDDI_OFFER_PRIORITY enumeration

## Description

Indicates the importance of video memory resources that the user-mode display driver offers for reuse.

## Constants

### `D3DDDI_OFFER_PRIORITY_NONE`

The allocation should not be offered.

**Note** Do not use this value in the [D3DDDICB_OFFERALLOCATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_offerallocations).**Priority** member.

### `D3DDDI_OFFER_PRIORITY_LOW`

The allocation has low value and should be discarded before other offered allocations. Specify this type for allocations that have no useful content.

### `D3DDDI_OFFER_PRIORITY_NORMAL`

The allocation has useful content but can easily be regenerated.

### `D3DDDI_OFFER_PRIORITY_HIGH`

The allocation has useful content and cannot easily be regenerated. The video memory manager (which is part of Dxgkrnl.sys) should therefore avoid discarding this allocation before other offered allocations.

### `D3DDDI_OFFER_PRIORITY_AUTO`

The video memory manager should make a policy decision on the allocation's value based on its priority for eviction.

## See also

[D3DDDICB_OFFERALLOCATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_offerallocations)

[D3DDDI_ALLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationlist)