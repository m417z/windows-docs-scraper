# DXGKCB_GETHANDLEDATAFLAGS structure

## Description

The **DXGKCB_GETHANDLEDATAFLAGS** structure indicates whether allocations belong to a resource.

## Members

### `DeviceSpecific`

A UINT value that specifies whether allocations belong to a resource. If this member is set, the allocations belong to a resource.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 31 bits (0xFFFFFFFE) of the 32-bit **Value** member to zeros.

### `Value`

The 32-bit value that indicates all of the flags set in the union.

## See also

[**DXGKARGCB_GETHANDLEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_gethandledata)