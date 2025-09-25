# _PANEL_BRIGHTNESS_SENSOR_DATA structure

## Description

Used to set the level of optimization to control the brightness of a panel.

## Members

### `AlsReadingValid`

Not all devices will support all or any of the sensor types. This is a bitmask representing which sensor values are valid. The valid flags may change between calls.

### `ChromaticityCoordinateValid`

Indicates whether the chromaticity coordinate is valid.

### `ColorTemperatureValid`

Indicates whether the color temperature is valid.

### `Reserved`

Reserved.

### `Value`

Value of the brightness sensor data.

### `AlsReading`

Sensor readings the driver can use to determine the best way to achieve the desired brightness under current lighting conditions. Not all devices will support all or any sensor readings, and the driver should not fail if any are missing.

### `ChromaticityCoordinate`

The chromaticity coordinates from a color sensor.

### `ColorTemperature`

Color temperature in Kelvin, measured by a color sensor.