# _DXGK_MULTIPLANE_OVERLAY_POST_COMPOSITION structure

## Description

Specifies information about any additional transforms that should occur after the planes are composed.

## Members

### `Flags`

A [DXGK_MULTIPLANE_OVERLAY_POST_COMPOSITION_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_post_composition_flags) structure indicating additional transform information.

### `SrcRect`

Contains the source rect of the virtual mode.

### `DstRect`

Contains the destination rect of the virtual mode.

### `Rotation`

Indicates additional rotation that should occur on the final image.

## Remarks

The source mode contains the virtual mode size and the destination rectangle indicates how the virtual mode maps to the physical mode.

For example, if a 1024x768 virtual mode is used with 1920x1080 physical mode, the following configurations are possible:

Stretch mode:

* SrcRect = {0, 0, 1024, 768}
* DstRect = {0, 0, 1920, 1080}

Centered mode:

* SrcRect = {0, 0, 1024, 768}
* DstRect = {448, 156, 1472, 924}

Aspect ratio stretched:

* SrcRect = {0, 0, 1024, 768}
* DstRect = {240, 0, 1680, 1080} // 1080p monitor resolution