# _D3DDDI_MULTIPLANE_OVERLAY_FEATURE_CAPS enumeration

## Description

Identifies overlay capabilities.

## Constants

### `D3DDDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_ROTATION`

The overlay plane can rotate the data 90, 180, and 270 degrees.

### `D3DDDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_VERTICAL_FLIP`

The overlay plane can flip the data vertically, making it appear upside-down.

### `D3DDDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_HORIZONTAL_FLIP`

The overlay plane can flip the data horizontally, making it appear as a right-to-left mirror image.

### `D3DDDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_DEINTERLACE`

Reserved for system use. The user-mode display driver should not use this value.

### `D3DDDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_RGB`

The overlay plane supports RGB format.

### `D3DDDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_YUV`

The overlay plane supports YUV format.

### `D3DDDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_BILINEAR_FILTER`

The overlay plane supports stretching and shrinking using bilinear filtering.

### `D3DDDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_HIGH_FILTER`

The overlay plane supports stretching and shrinking using filtering that is better than bilinear filtering.