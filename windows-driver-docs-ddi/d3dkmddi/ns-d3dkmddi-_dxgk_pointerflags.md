# _DXGK_POINTERFLAGS structure

## Description

The DXGK_POINTERFLAGS structure identifies mouse pointer capabilities of the display miniport driver that the driver provides through a call to its [DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function.

## Members

### `Monochrome`

A UINT value that specifies whether the mouse pointer can display in monochrome. Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Color`

A UINT value that specifies whether the mouse pointer can display in color and with transparency (alpha). Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `MaskedColor`

A UINT value that specifies whether the mouse pointer can display in color and with a mask value in the transparency (alpha) bits. Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 29 bits (0xFFFFFFF8) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that DXGK_POINTERFLAGS contains that can hold a 32-bit value that identifies mouse pointer capabilities.

## Remarks

The display miniport driver can specify mouse pointer capabilities by setting bits in the 32-bit **Value** member or by setting individual members of the structure in the union that DXGK_POINTERFLAGS contains.

The driver always specifies a color mouse pointer by using a A8R8G8B8 pixel format.

## See also

[DXGKARG_QUERYADAPTERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo)

[DXGK_DRIVERCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)

[DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)