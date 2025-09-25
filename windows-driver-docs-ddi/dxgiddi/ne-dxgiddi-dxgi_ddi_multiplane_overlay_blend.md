# DXGI_DDI_MULTIPLANE_OVERLAY_BLEND enumeration

## Description

Identifies a blend operation to be performed on an overlay plane.

## Constants

### `DXGI_DDI_MULTIPLANE_OVERLAY_BLEND_OPAQUE`

The overlay plane should ignore data in the alpha channel and make the blended plane entirely opaque.

### `DXGI_DDI_MULTIPLANE_OVERLAY_BLEND_ALPHABLEND`

The overlay plane should use the pre-multiplied alpha channel in this plane to blend it with the plane beneath.