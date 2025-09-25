# DXGI_DDI_MULTIPLANE_OVERLAY_GROUP_CAPS structure

## Description

Used by the user-mode display driver to specify groups of overlay plane capabilities.

## Members

### `NumPlanes`

Specifies the number of overlay planes that are supported by the overlay planes within the capability group.

### `MaxStretchFactor`

Specifies the maximum stretch factor that is supported by the overlay planes within the capability group.

The stretch factor is the ratio of the final, stretched overlay plane size to the original size. For example, if the original overlay plane is 100 x 100 pixels, a value of 2.5 means that it can be stretched to 250 x 250 pixels.

It's not guaranteed that this stretch factor can be applied in all scenarios. For example, it might be possible to stretch only one overlay plane out of several using this factor.

### `MaxShrinkFactor`

Specifies the maximum shrink factor that is supported by the overlay planes within the capability group.

The shrink factor is the ratio of the final, shrunk overlay plane size to the original size. For example, if the original overlay plane is 100 x 100 pixels, a value of 0.25 means that it can be shrunk to 25 x 25 pixels.

It's not guaranteed that this shrink factor can be applied in all scenarios. For example, it might be possible to shrink only one overlay plane out of several using this factor.

### `OverlayCaps`

The overlay capabilities, given as a bitwise **OR** of values from the [DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ne-dxgiddi-dxgi_ddi_multiplane_overlay_feature_caps) enumeration.

### `StereoCaps`

Reserved for system use. Set this value to zero.