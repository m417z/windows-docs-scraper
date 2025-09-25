# DXGK_DIAGNOSTIC_PSR_REFRESH_REASON structure

## Description

Indicates the reason or reasons for exiting PSR (Panel Self-Refresh).

## Members

### `Present`

Pixels in one or more planes have been modified, requiring that the display be updated. This could be that the pixel data has changed or a change to MPO visibility, position, scaling, orientation or some combination of these.

### `CursorUpdate`

The cursor image, position, visibility or a combination of these have been updated.

### `VSyncEnabled`

Vsync interrupts have been enabled and the hardware requires scanout to be driven in order to generate the Vsync interrupt.

### `ColorTransformationChange`

Any form of color transform is being applied which requires the pixels on the panel to be updated. This could be any one of: legacy gamma, DXGI gamma, the 3x4 matrix color transform or any newer form of color transform.

### `BrightnessChange`

The display brightness has been changed and based on the hardware/display technology, this requires refreshing the pixels in the panel. For a display using a backlight, a brightness change would only require leaving PSR if backlight optimizations mean that the pixels also need to be updated.

### `SinkRequest`

The display panel has requested an update from the host.

### `Other`

A reason understood by the driver but not specified by any of the above. Ideally, a new flag should be defined for any such reason in the next release.

### `Reserved`

Reserved.

### `Value`

## Remarks

See [_DXGK_DIAGNOSTIC_PSR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_diagnostic_psr) structure, in the remarks section for more info about PSR.

## See also