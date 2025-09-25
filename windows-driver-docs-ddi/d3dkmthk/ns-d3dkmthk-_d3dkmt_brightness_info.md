# _D3DKMT_BRIGHTNESS_INFO structure

## Description

Contains information about the brightness of an integrated display panel.

## Members

### `Type`

A value of type [D3DKMT_BRIGHTNESS_INFO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_brightness_info_type) that indicates the type of brightness information to retrieve or set.

### `PossibleLevels`

A [D3DKMT_BRIGHTNESS_POSSIBLE_LEVELS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_brightness_possible_levels) structure that contains information about all possible brightness levels that the integrated display panel supports.

### `Brightness`

The current brightness level.

### `BrightnessCaps`

A [DXGK_BRIGHTNESS_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_brightness_caps) structure that represents the brightness control capabilities of the integrated display panel.

### `BrightnessState`

A [DXGK_BRIGHTNESS_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_brightness_state) structure that represents the smooth brightness control capabilities of the integrated display panel.

### `OptimizationLevel`

A [DXGK_BACKLIGHT_OPTIMIZATION_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-dxgk_backlight_optimization_level) structure that represents the optimization level of brightness control.

### `ReductionInfo`

A value of type [DXGK_BACKLIGHT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_backlight_info) that provides the current absolute level of backlight reduction.

### `VerboseLogging`

A boolean value that indicates whether Event Tracing for Windows (ETW) logging of brightness information should be verbose.

### `NitRanges`

List of supported nit ranges.

### `GetBrightnessMillinits`

Queries the driver for the current brightness level, in millinits.

### `SetBrightnessMillinits`

Directs the driver to linearly ramp the brightness from its current brightness level to a target brightness level over a specified length of time.

### `ChildUid`

An integer that uniquely identifies the child device.

## See also

[D3DKMT_BRIGHTNESS_INFO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_brightness_info_type)

[D3DKMT_BRIGHTNESS_POSSIBLE_LEVELS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_brightness_possible_levels)

[DXGK_BACKLIGHT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_backlight_info)

[DXGK_BACKLIGHT_OPTIMIZATION_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-dxgk_backlight_optimization_level)

[DXGK_BRIGHTNESS_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_brightness_caps)

[DXGK_BRIGHTNESS_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_brightness_state)