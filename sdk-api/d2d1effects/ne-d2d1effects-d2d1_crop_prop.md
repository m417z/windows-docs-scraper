# D2D1_CROP_PROP enumeration

## Description

Identifiers for properties of the [Crop effect](https://learn.microsoft.com/windows/desktop/Direct2D/crop).

## Constants

### `D2D1_CROP_PROP_RECT:0`

The region to be cropped specified as a vector in the form (left, top, width, height). Units are in DIPs.

**Note** The rectangle will be truncated if it overlaps the edge boundaries of the input image.

Type is [D2D1_VECTOR_4F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_4f)

Default value is {-FLT_MAX, -FLT_MAX, FLT_MAX, FLT_MAX}

### `D2D1_CROP_PROP_BORDER_MODE:1`

Indicates how the effect handles the crop rectangle falling on fractional pixel coordinates.

Type is [D2D1_BORDER_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_border_mode).

Default value is D2D1_BORDER_MODE_SOFT.

### `D2D1_CROP_PROP_FORCE_DWORD:0xffffffff`