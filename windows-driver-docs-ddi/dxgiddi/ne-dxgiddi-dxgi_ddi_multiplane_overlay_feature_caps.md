# DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS enumeration

## Description

Identifies overlay capabilities.

## Constants

### `DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_ROTATION_WITHOUT_INDEPENDENT_FLIP`

### `DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_VERTICAL_FLIP`

The overlay plane can flip the data vertically, making it appear upside-down.

### `DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_HORIZONTAL_FLIP`

The overlay plane can flip the data horizontally, making it appear as a right-to-left mirror image.

### `DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_DEINTERLACE`

Reserved for system use. The user-mode display driver should not use this value.

### `DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_STEREO`

Reserved for system use. The user-mode display driver should not use this value.

### `DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_RGB`

### `DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_YUV`

### `DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_BILINEAR_FILTER`

Can do bilinear stretching.

### `DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_HIGH_FILTER`

Can do better than bilinear stretching.

### `DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_ROTATION`

The overlay plane can rotate the data 90, 180, and 270 degrees.

### `DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_FULLSCREEN_POST_COMPOSITION`

Indicates that the caps reported in this group apply to a fullscreen plane and that all operation applied to this plane occur after composition with other MPO planes has occurred. This is useful for the following scenarios:

* Panel fitter HW can be employed to stretch the surface to match the screen. This is useful for supporting virtual modes.

    * It can stretch or shrink the desktop plane for the VidPnSourceId to match of a single monitor with the following limitations:

        * The entire allocation must be stretched – no sub rectangles are supported.
        * This must be plane 0 in the Z order.

    * If a HW cursor is supported, the HW cursor will get composed with the desktop plane prior to the stretching (i.e. the HW cursor will get stretched or shrunk with the rest of the desktop plane).
    * If other MPO planes are supported in addition to the panel fitter, the clip rectangles for the other MPO planes are bound to the source rect of the panel fitter plane.

* In HDR scenarios, the presenting the HDR allocation (potentially with metadata) will just look like an MPO present with a single plane that covers the entire screen.

This flag should not be reported in the same capability groups as normal MPO.

### `DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_RESERVED1`

### `DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_SHARED`

Indicates that the hardware described in this capability group could be shared across outputs.

For example, if hardware supports a dedicated panel fitter per output, but also supports 4 additional MPO planes that are shared across multiple outputs, the driver would report the following capability groups on each output:

* One capability group for the panel fitter that does not set the DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_SHARED capability flag.
* One or more capability groups describing the 4 MPO planes that do set the DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_SHARED capability.

### `DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_IMMEDIATE`

Indicates that the HW supports immediate flips of the MPO plane as long as the only change is the display start address.

### `DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_PLANE0_FOR_VIRTUAL_MODE_ONLY`

Indicates that stretching/shrinking of plane 0 should only occur when plane 0 is the desktop plane and the stretching/shrinking is used for virtual mode support.