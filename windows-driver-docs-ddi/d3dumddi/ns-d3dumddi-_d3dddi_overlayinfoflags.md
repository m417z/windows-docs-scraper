# _D3DDDI_OVERLAYINFOFLAGS structure

## Description

The D3DDDI_OVERLAYINFOFLAGS structure identifies the type of overlay operation to perform.

## Members

### `DstColorKey`

A UINT value that specifies whether to perform destination color keying by using the value in the **DstColorKeyLow** member of the [D3DDDI_OVERLAYINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_overlayinfo) structure. That is, any pixel in the destination surface that matches the color key should be replaced with the corresponding pixel from the source resource, and all of the destination pixels that do not match the color key should not be replaced.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `DstColorKeyRange`

A UINT value that specifies whether to perform destination color keying by using a range of values from the **DstColorKeyLow** and **DstColorKeyHigh** members of D3DDDI_OVERLAYINFO.

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `SrcColorKey`

A UINT value that specifies whether to perform source color keying by using the value in the **SrcColorKeyLow** member of D3DDDI_OVERLAYINFO. That is, any pixel in the source resource that matches the color key should not be copied to the destination surface, and all of the source pixels that do not match the color key should be copied.

Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

### `SrcColorKeyRange`

A UINT value that specifies whether to perform source color keying by using a range of values from the **SrcColorKeyLow** and **SrcColorKeyHigh** members of D3DDDI_OVERLAYINFO.

Setting this member is equivalent to setting the fourth bit of the 32-bit **Value** member (0x00000008).

### `Bob`

A UINT value that specifies whether the overlay should deinterlace by using the [bob-style deinterlacing algorithm](https://learn.microsoft.com/windows-hardware/drivers/display/bob-deinterlacing-algorithm).

Setting this member is equivalent to setting the fifth bit of the 32-bit **Value** member (0x00000010).

### `Interleaved`

A UINT value that specifies whether the allocation that is being displayed contains both even and odd fields interleaved together.

Setting this member is equivalent to setting the sixth bit of the 32-bit **Value** member (0x00000020).

### `MirrorLeftRight`

A UINT value that specifies whether the contents of the source resource are flipped horizontally along the center axis in the overlay to the destination surface. That is, contents on the left side of the source resource are copied to the right side of the destination surface, and vice versa.

Setting this member is equivalent to setting the seventh bit of the 32-bit **Value** member (0x00000040).

### `MirrorUpDown`

A UINT value that specifies whether the contents of the source resource are flipped vertically along the center axis in the overlay to the destination surface. That is, contents on the top of the source resource are copied to the bottom of the destination surface, and vice versa.

Setting this member is equivalent to setting the eighth bit of the 32-bit **Value** member (0x00000080).

### `Deinterlace`

A UINT value that specifies whether the overlay should deinterlace the data in any manner the overlay requires.

Setting this member is equivalent to setting the ninth bit of the 32-bit **Value** member (0x00000100).

### `LimitedRGB`

Supported in Windows 7 and later versions.

A UINT value that specifies whether the overlay is full range RGB or limited range RGB. Setting this member indicates limited range RGB. In limited range RGB, the RGB range is compressed such that 16:16:16 is black and 235:235:235 is white.

Setting this member is equivalent to setting the tenth bit of the 32-bit **Value** member (0x00000200).

### `YCbCrBT709`

Supported in Windows 7 and later versions.

A UINT value that specifies whether the overlay is BT.601 or BT.709. Setting this member indicates BT.709, for high-definition TV (HDTV) and

is equivalent to setting the eleventh bit of the 32-bit **Value** member (0x00000400).

### `YCbCrxvYCC`

Supported in Windows 7 and later versions.

A UINT value that specifies whether the overlay is conventional YCbCr or extended YCbCr (xvYCC). Setting this member indicates extended YCbCr (xvYCC) and is equivalent to setting the twelfth bit of the 32-bit **Value** member (0x00000800).

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 20 bits (0xFFFFF000) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that is contained in D3DDDI_OVERLAYINFOFLAGS that can hold one 32-bit value that identifies the type of overlay operation to perform.

## See also

[D3DDDI_OVERLAYINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_overlayinfo)