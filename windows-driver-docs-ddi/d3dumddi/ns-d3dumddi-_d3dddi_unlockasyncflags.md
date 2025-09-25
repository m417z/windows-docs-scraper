# _D3DDDI_UNLOCKASYNCFLAGS structure

## Description

The D3DDDI_UNLOCKASYNCFLAGS structure identifies how to unlock a resource.

## Members

### `NotifyOnly`

A UINT value that specifies whether the unlock call is for notification only. The Microsoft Direct3D runtime sets **NotifyOnly** to **TRUE** when it unlocks runtime-allocated system memory surfaces.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 31 bits (0xFFFFFFFE) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that is contained in D3DDDI_UNLOCKASYNCFLAGS that can hold one 32-bit value that identifies how to unlock a resource.

## See also

[D3DDDIARG_UNLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_unlock)