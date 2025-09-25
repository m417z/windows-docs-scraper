# _DXGK_MULTIPLANE_OVERLAY_YCbCr_FLAGS structure

## Description

Identifies YUV range and conversion info that describes a multiplane overlay.

## Members

### `NominalRange`

If set, YUV values range from 16 to 235, inclusive, instead of the default range of 0 to 255, inclusive.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Bt709`

If set, YUV values should be converted using the BT.709 standard, instead of the default BT.601 conversion.

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `xvYCC`

If set, YUV values contain xvYCC data, instead of conventional YCbCr data.

Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

### `Reserved`

This member is reserved and should be set to zero.

Setting this member to zero is equivalent to setting the remaining 29 bits (0xFFFFFFF8) of the 32-bit **Value** member to zeros.

### `Value`

A 32-bit value that identifies the type of blend operation to perform.