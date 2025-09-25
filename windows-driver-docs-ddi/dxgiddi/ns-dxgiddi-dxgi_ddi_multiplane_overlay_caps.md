# DXGI_DDI_MULTIPLANE_OVERLAY_CAPS structure

## Description

Used by the user-mode display driver to specify overlay plane capabilities.

## Members

### `MaxPlanes`

The maximum number of inputs, including the primary surface, to the display hardware that can be supported in the current mode. This value can change if the mode changes.

For example, if the hardware allows one overlay plane and one normal primary surface, the driver should set **MaxPlanes** to 2.

### `NumCapabilityGroups`

The number of different types of overlay planes that can be supported.

Here are 2 examples:

* If the hardware supports 2 RGB-only planes with limited stretching capabilities, plus 2 YUV planes with more flexible stretching capabilities, then the driver should set **NumCapabilityGroups** to 2.
* If the hardware supports one RGB-only plane with no stretching capabilities, plus 2 RGB-only planes with full stretching capabilities, plus 2 RGB/YUV planes with full stretching capabilities, then the driver should set **NumCapabilityGroups** to 3.