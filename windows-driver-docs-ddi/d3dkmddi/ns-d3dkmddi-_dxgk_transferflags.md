# _DXGK_TRANSFERFLAGS structure

## Description

The DXGK_TRANSFERFLAGS structure identifies the type of transfer operation to set up in a call to the [DxgkDdiBuildPagingBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer) function.

## Members

### `Swizzle` [in]

A UINT value that specifies whether the driver should swizzle the source to the destination during the transfer. Note that for multiple-level allocations (for example, MIP-map textures), the driver should swizzle all levels of the allocations. For more information about swizzling allocations, see [Locking Swizzled Allocations](https://learn.microsoft.com/windows-hardware/drivers/display/locking-swizzled-allocations).

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Unswizzle` [in]

A UINT value that specifies whether the driver should unswizzle the source to the destination during the transfer. Note that for multiple-level allocations (for example, MIP-map textures), the driver should unswizzle all levels of the allocations. For more information about swizzling allocations, see [Locking Swizzled Allocations](https://learn.microsoft.com/windows-hardware/drivers/display/locking-swizzled-allocations).

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `AllocationIsIdle` [in]

A UINT value that specifies whether the graphics processing unit (GPU) is using the given allocation. If this member is set, the GPU is not using the given allocation; that is, no work was queued or will be queued to the GPU until the call to [DxgkDdiBuildPagingBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer) returns.

Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

### `TransferStart` [in]

A UINT value that specifies whether the transfer operation is starting. If this member is set, the transfer operation is starting.

Setting this member is equivalent to setting the fourth bit of the 32-bit **Value** member (0x00000008).

### `TransferEnd` [in]

A UINT value that specifies whether the transfer operation is ending. If this member is set, the transfer operation is ending.

Setting this member is equivalent to setting the fifth bit of the 32-bit **Value** member (0x00000010).

### `Reserved` [in]

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 27 bits (0xFFFFFFE0) of the 32-bit **Value** member to zeros.

### `Value` [in]

A member in the union that DXGK_TRANSFERFLAGS contains that can hold a 32-bit value that identifies the transfer-operation type.

## Remarks

You can set the transfer-operation type by setting bits in the 32-bit **Value** member or by setting individual members of the structure in the union that DXGK_TRANSFERFLAGS contains.

## See also

[DXGKARG_BUILDPAGINGBUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_buildpagingbuffer)

[DxgkDdiBuildPagingBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer)