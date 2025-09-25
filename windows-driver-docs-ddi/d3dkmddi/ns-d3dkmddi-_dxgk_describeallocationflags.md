# _DXGK_DESCRIBEALLOCATIONFLAGS structure

## Description

Used in the [DXGKARG_DESCRIBEALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_describeallocation).**Flags** member to describe whether an existing allocation is being queried for its display mode.

## Members

### `CheckDisplayMode` [in]

This member is reserved.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Reserved` [in]

This member is reserved and should be set to zero.

Setting this member to zero is equivalent to setting the remaining 31 bits (0xFFFFFFFE) of the 32-bit **Value** member to zeros.

### `Value` [in]

A member in the union that **DXGK_DESCRIBEALLOCATIONFLAGS** contains that can hold a 32-bit value that identifies the type of allocation.

## See also

[DXGKARG_DESCRIBEALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_describeallocation)