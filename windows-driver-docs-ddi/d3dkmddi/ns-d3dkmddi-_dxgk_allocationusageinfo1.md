# _DXGK_ALLOCATIONUSAGEINFO1 structure

## Description

The DXGK_ALLOCATIONUSAGEINFO1 structure describes how an allocation can be used in DMA buffering.

## Members

### `Flags` [out]

A union that contains either a structure (with the first eight members that are described below) or a 32-bit value (in the **Value** member) that identifies how the allocation is used:

### `Flags.PrivateFormat`

A UINT value that specifies whether the allocation is a private vendor format.

Setting this is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Flags.Swizzled`

A UINT value that specifies whether the allocation is swizzled or tiled.

Setting this is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `Flags.MipMap`

A UINT value that specifies whether the allocation is a MIP-mapped texture.

Setting this is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

### `Flags.Cube`

A UINT value that specifies whether the allocation is a cube texture.

Setting this is equivalent to setting the fourth bit of the 32-bit **Value** member (0x00000008).

### `Flags.Volume`

A UINT value that specifies whether the allocation is a volume texture.

Setting this is equivalent to setting the fifth bit of the 32-bit **Value** member (0x00000010).

### `Flags.Vertex`

A UINT value that specifies whether the allocation is a vertex buffer.

Setting this is equivalent to setting the sixth bit of the 32-bit **Value** member (0x00000020).

### `Flags.Index`

A UINT value that specifies whether the allocation is an index buffer.

Setting this is equivalent to setting the seventh bit of the 32-bit **Value** member (0x00000040).

### `Flags.Reserved`

This member is reserved and should be set to zero. Setting this to zero is equivalent to setting the remaining 25 bits (0xFFFFFF80) of the 32-bit **Value** member to zeros.

### `Flags.Value`

Specifies a member in the union contained in the **Flags** member that can hold one 32-bit value that identifies how the allocation is used.

### `Format` [out]

A [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)-typed value that indicates the pixel format of the allocation. The **PrivateFormat** bit-field flag in the **Flags** member must be set to 0 (FALSE).

### `PrivateFormat` [out]

A private format value for the allocation. The **PrivateFormat** bit-field flag in the **Flags** member must be set to 1 (TRUE).

### `SwizzledFormat` [out]

A swizzled format value for the allocation that is private to a specific vendor.

### `ByteOffset` [out]

The offset, in bytes, into the video memory manager's allocation that marks the start of the driver's version of the allocation.

### `Width` [out]

The width, in pixels, of the allocation.

### `Height` [out]

The height, in number of lines, of the allocation.

### `Pitch` [out]

The pitch, in bytes, of the allocation--that is, the distance, in bytes, to the start of the next line.

### `Depth` [out]

The depth, in levels, of the allocation (for MIP-mapped and volume textures only).

### `SlicePitch` [out]

The slice pitch, in bytes, from level to level (for cube and volume textures only).

## See also

[DXGKARG_CREATEALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createallocation)

[DXGK_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo)

[DXGK_ALLOCATIONUSAGEHINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationusagehint)

[DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)