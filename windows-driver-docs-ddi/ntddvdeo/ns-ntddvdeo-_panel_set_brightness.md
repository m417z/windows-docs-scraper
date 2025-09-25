# _PANEL_SET_BRIGHTNESS structure

## Description

Directs the driver to linearly ramp the brightness from its current brightness level to a target brightness level over a specified length of time.

## Members

### `Millinits`

The brightness level in millinits to transition to.

### `TransitionTimeInMs`

How long the transition should take.

### `SensorData`

Contains sensor readings the driver can use to determine the best way to achieve the desired brightness under current lighting conditions. Not all devices will support all or any sensor readings, and the driver should not fail if any are missing.

### `Level`

The optimization level of brightness control.

### `Version`

The target version. This value should always be DXGK_BRIGHTNESS_INTERFACE_VERSION_3.