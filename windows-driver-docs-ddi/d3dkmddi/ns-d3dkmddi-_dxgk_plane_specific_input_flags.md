# _DXGK_PLANE_SPECIFIC_INPUT_FLAGS structure

## Description

A structure containing the input flags to be used for the driver that apply to a plane.

## Members

### `Enabled`

Indicates whether the overlay plane is enabled for display.

### `FlipImmediate`

Indicates that the driver should perform a flip operation that occurs without vertical sync.

### `FlipOnNextVSync`

Indicates that the driver should perform a flip operation that occurs on the next vertical sync.

If the current line being displayed is less than [DXGK_MULTIPLANE_OVERLAY_PLANE3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_plane3).MaxImmediateFlipLine, the driver should convert this flip to an immediate flip and set [DXGK_PLANE_SPECIFIC_OUTPUT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_plane_specific_output_flags). FlipConvertedToImmediate to TRUE.

### `SharedPrimaryTransition`

Specifies that the driver is transitioning to or from a shared managed primary allocation.

This member is set if either of the following transitions occurs:

- The current primary allocation is not a shared primary allocation, but the new one is.
- The current primary allocation is a shared primary allocation, but the new one is not.

When SharedPrimaryTransition is set, the display miniport driver must validate that the hardware can seamlessly switch back and forth between primary and shared primary allocations, and it must perform any hardware programming needed to make the seamless switch occur.

### `IndependentFlipExclusive`

When IndependentFlipExlusive is set, the flip is done in the independent flip exclusive mode. The front buffer is accessed only by the display hardware and not by the DWM. The kernel mode driver can apply vertical sync-related optimizations.

### `FlipImmediateNoTearing`

Drivers that support Variable Refresh Rate can support this flag. When FlipImmediateNoTearing is set, the driver should flip as soon as possible, but only within the blank period to avoid tearing.

If the monitor is already in the blank period at the time of the flip request, the driver should immediately end the blank period and start the next frame immediately.

If the monitor is in the active period, the flip needs to wait until the active period ends. As soon as the blank period starts, the driver should process the flip and start a new active period so that the blank period is as short as possible between those two frames.

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 27 bits (0xFFFFFFE0) of the 32-bit **Value** member to zeros.

### `Value`