# _BRIGHTNESS_INTERFACE_VERSION enumeration

## Description

Specifies the brightness interface versions.

## Constants

### `BRIGHTNESS_INTERFACE_VERSION_1`

Supports brightness control in integrated display panels.

### `BRIGHTNESS_INTERFACE_VERSION_2`

Lets a display miniport driver reduce power to the display backlight and still smoothly adapt to changes in ambient light and user requests to change brightness. Starting with Windows 8, if the system includes an ambient light sensor, the driver must support the Brightness Control Interface V 2.

### `BRIGHTNESS_INTERFACE_VERSION_3`

Supports multiple displays that can be set to calibrated nit-based brightness levels.