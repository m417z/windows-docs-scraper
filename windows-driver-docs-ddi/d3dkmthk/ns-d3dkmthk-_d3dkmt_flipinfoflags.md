# _D3DKMT_FLIPINFOFLAGS structure

## Description

The D3DKMT_FLIPINFOFLAGS structure identifies flipping capabilities of the display miniport driver that the OpenGL installable client driver (ICD) obtains by calling the [D3DKMTQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo) function.

## Members

### `FlipInterval`

A UINT value that specifies whether the display miniport driver natively supports the scheduling of a flip command to take effect after two, three or four vertical syncs occur. Regardless of whether the display miniport driver supports a flip interval of two or greater, the driver must support an immediate flip and a flip interval of one.

Setting this member is equivalent to setting the first bit of a 32-bit value (0x00000001).

### `Reserved`

This member is reserved and should be set to zero. Setting this member is equivalent to setting the remaining 31 bits (0xFFFFFFFE) of a 32-bit value to zeros.

## See also

[D3DKMTQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo)

[D3DKMT_FLIPQUEUEINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_flipqueueinfo)

[D3DKMT_QUERYADAPTERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryadapterinfo)