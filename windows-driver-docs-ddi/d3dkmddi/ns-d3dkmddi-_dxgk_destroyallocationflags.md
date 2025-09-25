# _DXGK_DESTROYALLOCATIONFLAGS structure

## Description

The DXGK_DESTROYALLOCATIONFLAGS structure identifies how to release allocations.

## Members

### `DestroyResource`

A UINT value that specifies whether the resource that the **hResource** member of the [DXGKARG_DESTROYALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_destroyallocation) structure specifies should be released along with allocations.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 31 bits (0xFFFFFFFE) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that DXGK_DESTROYALLOCATIONFLAGS contains that can hold a 32-bit value that identifies how to release allocations.

## See also

[DXGKARG_DESTROYALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_destroyallocation)