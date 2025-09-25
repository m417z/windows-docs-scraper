# _D3DKMT_OFFER_PRIORITY enumeration

## Description

Indicates the importance of video memory resources that the user-mode display driver offers for reuse.

## Constants

### `D3DKMT_OFFER_PRIORITY_LOW`

The allocation has low value and should be discarded before other offered allocations. Specify this type for allocations that have no useful content.

### `D3DKMT_OFFER_PRIORITY_NORMAL`

The allocation has useful content but can easily be regenerated.

### `D3DKMT_OFFER_PRIORITY_HIGH`

The allocation has useful content and cannot easily be regenerated. The video memory manager (which is part of Dxgkrnl.sys) should therefore avoid discarding this allocation before other offered allocations.

### `D3DKMT_OFFER_PRIORITY_AUTO`

The video memory manager should make a policy decision on the allocation's value based on its priority for eviction.

## See also

[D3DKMT_OFFERALLOCATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_offerallocations)