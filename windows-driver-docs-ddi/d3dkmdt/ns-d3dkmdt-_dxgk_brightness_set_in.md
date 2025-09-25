# _DXGK_BRIGHTNESS_SET_IN structure

## Description

Contains input parameters for the [DxgkBrightnessSet3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_set_3) callback function.

## Members

### `BrightnessMillinits`

The brightness level in millinits to transition to. If the driver has not set [DXGK_BRIGHTNESS_CAPS.NitsBrightness](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_brightness_caps), then this value means the brightness level in uncalibrated thousandths of a percent.

For example, if **BrightnessMillinits** is set to 60500 and **NitsBrightness** is set, this means 60.5 nits luminance. If **NitsBrightness** is not set, this means 60.5%.

### `TransitionTimeMs`

How long the transition should take in milliseconds.

### `SensorReadings`

A [DXGK_BRIGHTNESS_SENSOR_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_brightness_sensor_data) structure that contains sensor readings the driver can use to determine the best way to achieve the desired brightness under current lighting conditions. Not all devices will support all or any sensor readings, and the driver should not fail if any are missing.