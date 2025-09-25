# _DXGK_MULTIPLANE_OVERLAY_STRETCH_QUALITY enumeration

## Description

Identifies filtering processes that the hardware should perform when it stretches or shrinks multiplane overlay data.

## Constants

### `DXGK_MULTIPLANE_OVERLAY_STRETCH_QUALITY_BILINEAR`

When the hardware stretches or shrinks the data, it should perform bilinear filtering. If the hardware lacks enough resources to perform bilinear shrinking, the user-mode display driver can use point sampling.

### `DXGK_MULTIPLANE_OVERLAY_STRETCH_QUALITY_HIGH`

When the hardware stretches or shrinks the data, it should perform the highest quality filtering that it supports.