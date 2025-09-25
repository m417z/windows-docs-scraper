# _D3DDDI_OPENRESOURCEFLAGS structure

## Description

The D3DDDI_OPENRESOURCEFLAGS structure identifies the type of resource to open.

## Members

### `Fullscreen`

A UINT value that specifies whether the shared primary resource is used with a full-screen device.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `AlphaOverride`

A UINT value that specifies whether to use the alpha channel in the shared primary resource. If **AlphaOverride** is set, the alpha channel should not be used.

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 30 bits (0xFFFFFFFC) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that is contained in D3DDDI_OPENRESOURCEFLAGS that can hold one 32-bit value that identifies the type of resource to open.

## See also

[D3DDDIARG_OPENRESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_openresource)