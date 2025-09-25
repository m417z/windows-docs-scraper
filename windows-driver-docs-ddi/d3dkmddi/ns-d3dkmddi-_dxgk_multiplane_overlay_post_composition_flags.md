# _DXGK_MULTIPLANE_OVERLAY_POST_COMPOSITION_FLAGS structure

## Description

A structure containing the flags describing the transformations applied to an image.

## Members

### `VerticalFlip`

Indicates that the image should be flipped vertically.

### `HorizontalFlip`

Indicates that the image should be flipped horizontally.

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 30 bits (0xFFFFFFFC) of the 32-bit **Value** member to zeros.

### `Value`

## Remarks

Applying VerticalFlip and HorizontalFlip simultaneously results in 180 degree rotation.