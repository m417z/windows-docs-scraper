# DXGK_CHECK_MULTIPLANE_OVERLAY_SUPPORT_RETURN_INFO structure

## Description

Specifies limitations on hardware support of multiplane overlays.

## Members

### `FailingPlane`

The zero-based index of the first overlay plane in the list of planes that the hardware cannot support. For example, if planes 0 and 1 could have been supported, but not plane 2, then the driver should set **FailingPlane** to 2.

Setting this member is equivalent to setting the first 4 bits of the 32-bit **Value** member (0x0000000F).

### `TryAgain`

The multiplane overlay configuration isn't supported because of a transient condition, which isn't permanent and should end soon. Therefore the support check call should be tried again and will probably succeed after another one or two VSync intervals.

Setting this member is equivalent to setting the fifth bit of the 32-bit **Value** member (0x00000010).

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 27 bits (0xFFFFFFE0) of the 32-bit **Value** member to zeros.

### `Value`

A 32-bit value that identifies the hardware support limitations.