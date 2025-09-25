# _DXGK_BRIGHTNESS_SENSOR_DATA structure

## Description

Describes the sensor data brightness.

## Members

### `Flags`

Flags that represent the type of brightness for the sensor data.

### `Flags.AlsReadingValid`

The ALS reading is valid.

### `Flags.ChromaticityValid`

The chromaticity is valid.

### `Flags.ColorTemperatureValid`

The color temperature is valid.

### `Flags.Reserved`

Reserved.

### `ValidSensorValues`

A bitmask that represents which sensor values are valid. The valid flags may change between calls. Not all devices will support all or any of the sensor types.

### `Size`

The size of the structure. Fields for new sensor types will always be added to the end of the structure if it is revised in future updates.

### `AlsReading`

Luminance in lux, measured by an ALS sensor.

### `Chromaticity`

A [DXGK_BRIGHTNESS_SENSOR_DATA_CHROMATICITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_brightness_sensor_data_chromaticity) structure that contains CIE 1931 chromaticity coordinates from a color sensor.

### `ColorTemperature`

Color temperature in Kelvin, measured by a color sensor.