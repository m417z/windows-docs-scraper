# _DXGK_MULTIPLANE_OVERLAY_BLEND structure

## Description

Identifies a blend operation to be performed on an overlay plane.

## Members

### `AlphaBlend`

If set, the overlay plane should use the pre-multiplied alpha channel in this plane to blend it with the plane beneath.

If zero, the overlay plane should ignore data in the alpha channel and make the blended plane entirely opaque.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Reserved`

This member is reserved and should be set to zero.

Setting this member to zero is equivalent to setting the remaining 30 bits (0xFFFFFFFC) of the 32-bit **Value** member to zeros.

This member is reserved and should be set to zero.

Setting this member to zero is equivalent to setting the remaining 31 bits (0xFFFFFFFE) of the 32-bit **Value** member to zeros.

### `Value`

A 32-bit value that identifies the type of blend operation to perform.