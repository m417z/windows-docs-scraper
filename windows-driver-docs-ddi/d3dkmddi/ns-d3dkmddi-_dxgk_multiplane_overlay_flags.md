# DXGK_MULTIPLANE_OVERLAY_FLAGS structure

## Description

The **DXGK_MULTIPLANE_OVERLAY_FLAGS** structure defines flags that control the behavior of a multiplane overlay operation.

## Members

### `VerticalFlip`

The overlay plane should flip the data vertically, making it appear upside-down.

### `HorizontalFlip`

The overlay plane should flip the data horizontally, making it appear as a right-to-left mirror image.

### `StaticCheck`

The overlay plane can be scanned out directly. **StaticCheck** is a capability query that doesn't affect the current presentation state. Added in Windows 11 (WDDM 3.0).

### `Reserved`

This member is reserved and should be set to zero.

### `Value`

Represents the collective value of the flags and can be used when the individual bits don't need to be accessed separately.

## See also

[**DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_attributes)

[**DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_attributes2)

[**DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_attributes3)