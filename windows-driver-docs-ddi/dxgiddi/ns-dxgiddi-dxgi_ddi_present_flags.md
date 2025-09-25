# DXGI_DDI_PRESENT_FLAGS structure

## Description

Identifies how to perform a present operation.

## Members

### `Blt`

Specifies whether to perform a bit-block transfer (bitblt) data to the primary surface.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Flip`

Specifies whether to flip to a new surface.

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `PreferRight`

Supported in Windows 8 and later versions.

Specifies that, if a stereo present operation must be reduced to mono, the present operation should show the view from the right eye.

If this member is not set, the default mono present operation shows the view from the left eye.

Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

### `TemporaryMono`

Supported in Windows 8 and later versions.

Specifies that a present operation should use the left buffer as a mono (non-stereo) buffer.

Setting this member is equivalent to setting the fourth bit of the 32-bit **Value** member (0x00000008).

### `AllowTearing`

### `AllowFlexibleRefresh`

### `NoScanoutTransform`

Supported in Windows 10, version 1901 and later.

This flag will only be passed if the driver set the D3DWDDM2_6DDI_SCANOUT_FLAG_TRANSFORMATION_DESIRED flag, instead of the D3DWDDM2_6DDI_SCANOUT_FLAG_TRANSFORMATION_REQUIRED flag of the [D3DWDDM2_6DDI_SCANOUT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm2_6ddi_scanout_flags) enumeration.

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 28 bits (0xFFFFFFF0) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that is contained in DXGI_DDI_PRESENT_FLAGS that can hold one 32-bit value that identifies how to perform a present operation.

## See also

[DXGI_DDI_ARG_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_present)

[PresentDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)