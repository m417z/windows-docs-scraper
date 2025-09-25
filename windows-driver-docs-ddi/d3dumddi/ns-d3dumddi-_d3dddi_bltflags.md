# _D3DDDI_BLTFLAGS structure

## Description

The D3DDDI_BLTFLAGS structure identifies the type of bit-block transfer (bitblt) to perform.

## Members

### `Point`

A UINT value that specifies whether to use point filtering in the bit-block transfer. Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Linear`

A UINT value that specifies whether to use linear filtering in the bit-block transfer. Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `SrcColorKey`

A UINT value that specifies whether to perform source color-keying by using the value in the **ColorKey** member. That is, any pixel in the source surface that matches the color key should not be copied to the destination surface, and all of the source pixels that do not match the color key should be copied.

Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

### `DstColorKey`

A UINT value that specifies whether to perform destination color-keying by using the value in the **ColorKey** member. That is, any pixel in the destination surface that matches the color key should be replaced with the corresponding pixel from the source surface, and all of the destination pixels that do not match the color key should not be replaced.

Setting this member is equivalent to setting the fourth bit of the 32-bit **Value** member (0x00000008).

### `MirrorLeftRight`

A UINT value that specifies whether the contents of the source surface are flipped horizontally along the center axis in the bitblt to the destination surface. That is, contents on the left side of the source surface are copied to the right side of the destination surface, and vice versa.

Setting this member is equivalent to setting the fifth bit of the 32-bit **Value** member (0x00000010).

### `MirrorUpDown`

A UINT value that specifies whether the contents of the source surface are flipped vertically along the center axis in the bitblt to the destination surface. That is, the contents on the top of the source surface are copied to the bottom of the destination surface, and vice versa.

Setting this member is equivalent to setting the sixth bit of the 32-bit **Value** member (0x00000020).

### `LinearToSrgb`

A UINT value that specifies whether to convert the linear-formatted source to sRGB format during the bitblt operation. sRGB format is gamma corrected. For more information about sRGB format, see the [sRGB](https://go.microsoft.com/fwlink/p/?linkid=10112) website.

Setting this member is equivalent to setting the seventh bit of the 32-bit **Value** member (0x00000040).

### `Rotate`

A UINT value that specifies whether to rotate the source during the bitblt operation.

Setting this member is equivalent to setting the eighth bit of the 32-bit **Value** member (0x00000080).

### `BeginPresentToDwm`

A UINT value that specifies whether the Microsoft Direct3D runtime begins a DWM present operation during the bitblt operation. For more information about **BeginPresentToDwm**, see Remarks.

Setting this member is equivalent to setting the ninth bit of the 32-bit **Value** member (0x00000100).

### `ContinuePresentToDwm`

A UINT value that specifies whether the Direct3D runtime continues a DWM present operation during the bitblt operation. For more information about **ContinuePresentToDwm**, see Remarks.

Setting this member is equivalent to setting the tenth bit of the 32-bit **Value** member (0x00000200).

### `EndPresentToDwm`

A UINT value that specifies whether the Direct3D runtime ends a DWM present operation during the bitblt operation. For more information about **EndPresentToDwm**, see Remarks.

Setting this member is equivalent to setting the eleventh bit of the 32-bit **Value** member (0x00000400).

### `Discard`

Indicates that the user-mode display driver can discard previous contents of the entire resource. The driver can take advantage of this capability to optimize performance and memory usage.

If this member is not **NULL**, **NoOverwrite** and **Tileable** must be **NULL**.

Setting this member is equivalent to setting the twelfth bit (0xFFFFF800) of the 32-bit **Value** member to zeros.

Supported starting with Windows 8.

### `NoOverwrite`

Indicates that the caller guarantees that the portion of the surface that is being written to with new data is not currently being referenced or accessed by any previous render operation. The driver can take advantage of this capability to optimize performance and memory usage.

If this member is not **NULL**, **Discard** must be **NULL**.

Setting this member is equivalent to setting the thirteenth bit (0x00001000) of the 32-bit **Value** member to zeros.

Supported starting with Windows 8.

### `Tileable`

For tile-based deferred rendering, indicates that a copy operation can operate on only the currently processed tile in the source or destination resource, and the scene does not have to be flushed in all tiles.

If this member is not **NULL**, **Discard** must be **NULL**.

Setting this member is equivalent to setting the fourteenth bit (0x00002000) of the 32-bit **Value** member to zeros.

Supported starting with Windows 8.

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 21 bits (0xFFFFF800) of the 32-bit **Value** member to zeros.

This member is reserved and should be set to zero.

Setting this member to zero is equivalent to setting the remaining 18 bits (0xFFFFC000) of the 32-bit **Value** member to zeros.

Supported starting with Windows 8.

### `Value`

A member in the union that is contained in D3DDDI_BLTFLAGS that can hold one 32-bit value that identifies the type of bitblt to perform.

## Remarks

The **BeginPresentToDwm**, **ContinuePresentToDwm**, and **EndPresentToDwm** bit-field flags inform the user-mode display driver about the time when the Direct3D runtime performs parts of a DWM present operation. Because DWM present operations can occur in multiple steps, the Direct3D runtime uses these flags to mark the steps in a sequence of bitblts. For example:

* If the present operation consists of one bitblt, the bitblt is marked as follows:
  + **BeginPresentToDwm** = **TRUE**;
  + **ContinuePresentToDwm** = **FALSE**;
  + **EndPresentToDwm** = **TRUE**;
* If the present operation consists of two bitblts, the bitblts are marked as shown in two sequential bitblt operations:
  1. First bitblt:
     + **BeginPresentToDwm** = **TRUE**;
     + **ContinuePresentToDwm** = **FALSE**;
     + **EndPresentToDwm** = **FALSE**;
  2. Second bitblt:
     + **BeginPresentToDwm** = **FALSE**;
     + **ContinuePresentToDwm** = **FALSE**;
     + **EndPresentToDwm** = **TRUE**;
* If the present operation consists of three or more bitblts, the bitblts are marked as shown in the following sequential bitblt operations:
  1. First bitblt:
     + **BeginPresentToDwm** = **TRUE**;
     + **ContinuePresentToDwm** = **FALSE**;
     + **EndPresentToDwm** = **FALSE**;
  2. Second and successive bitblts, not including the final bitblt:
     + **BeginPresentToDwm** = **FALSE**;
     + **ContinuePresentToDwm** = **TRUE**;
     + **EndPresentToDwm** = **FALSE**;
  3. Final bitblt:
     + **BeginPresentToDwm** = **FALSE**;
     + **ContinuePresentToDwm** = **FALSE**;
     + **EndPresentToDwm** = **TRUE**;

## See also

[D3DDDIARG_BLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_blt)

[Flush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfworkitem-flush)