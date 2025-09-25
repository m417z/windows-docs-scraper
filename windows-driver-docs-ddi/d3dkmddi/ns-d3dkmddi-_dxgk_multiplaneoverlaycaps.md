# _DXGK_MULTIPLANEOVERLAYCAPS structure

## Description

Multiplane overlay capabilities returned by the [DxgkDdiGetMultiPlaneOverlayCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getmultiplaneoverlaycaps) function.

## Members

### `Rotation`

When TRUE, indicates that the hardware supports rotating the plane 90, 180, or 270 degrees.

If TRUE, RotationWithoutIndependentFlip should be FALSE.

### `RotationWithoutIndependentFlip`

When TRUE, indicates that the driver can perform plane rotation of 90, 180, or 270 degrees, but IndependentFlip cannot be used when rotating the plane.

If TRUE, Rotation should be FALSE.

### `VerticalFlip`

When TRUE, the hardware supports flipping the plane vertically.

### `HorizontalFlip`

When TRUE, the hardware supports flipping the plane horizontally.

### `StretchRGB`

When TRUE, the hardware supports stretching any plane containing RGB data.

### `StretchYUV`

When TRUE, the hardware supports stretching any plane containing YUV data.

### `BilinearFilter`

When TRUE, the hardware supports bilinear filtering.

### `HighFilter`

When TRUE, the hardware supports better than bilinear filtering.

### `Shared`

When TRUE, the multiplane overlay resources reported by the capabilities are shared across all VidPn sources.

When FALSE, the multiplane overlay resources reported by capabilities are dedicated to the specific VidPn source.

### `Immediate`

When TRUE, the HW supports immediate flips of the MPO plane.

If the flip contains changes that cannot be performed as an immediate flip, the driver can promote the flip to a VSYNC flip using the new HSync completion infrastructure.

### `Plane0ForVirtualModeOnly`

When TRUE, the hardware will always apply the stretch factor of plane 0 to the hardware cursor as well as the plane. This implies that stretching/shrinking of plane 0 should only occur when plane 0 is the desktop plane and when the stretching/shrinking is used for virtual mode support.

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 21 bits (0xFFFFFFFC) of the 32-bit **Value** member to zeros.

### `Value`