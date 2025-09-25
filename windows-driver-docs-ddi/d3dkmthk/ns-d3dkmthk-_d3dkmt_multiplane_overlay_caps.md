# _D3DKMT_MULTIPLANE_OVERLAY_CAPS structure

## Description

Contains multiplane overlay capabilities.

## Members

### `Rotation`

Specifies the clockwise rotation of the overlay plane.

### `RotationWithoutIndependentFlip`

When TRUE, indicates that the driver can perform plane rotation of 90, 180, or 270 degrees, but IndependentFlip cannot be used when rotating the plane.

### `VerticalFlip`

The overlay plane should flip the data vertically.

### `HorizontalFlip`

The overlay plane should flip the data horizontally.

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

### `Version3DDISupport`

Driver supports the WDDM 2.2 MPO (multi-plane overlay) DDIs.

### `Reserved`

Reserved for internal use.

### `Value`

The value used to operate over the other members.

## Remarks

## See also