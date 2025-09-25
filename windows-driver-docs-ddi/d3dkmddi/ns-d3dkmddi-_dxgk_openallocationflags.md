# _DXGK_OPENALLOCATIONFLAGS structure

## Description

The DXGK_OPENALLOCATIONFLAGS structure identifies the operation to perform for allocations.

## Members

### `Create`

A UINT value that specifies whether allocations should be created. If this member is not set, the allocations are opened.

Setting this member is equivalent to setting the first bit of the 32-bit **Value**= member (0x00000001).

### `ReadOnly`

A UINT value that specifies whether the allocation can only be read from.

Setting this member is equivalent to setting the second bit of the 32-bit **Value**= member (0x00000002).

Supported starting with Windows 8.

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 30 bits (0xFFFFFFFC) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that DXGK_OPENALLOCATIONFLAGS contains that can hold a 32-bit value that identifies the operation to perform for allocations.

## See also

[DXGKARG_OPENALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_openallocation)