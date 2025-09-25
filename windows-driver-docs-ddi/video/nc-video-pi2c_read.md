# PI2C_READ callback function

## Description

The *I2CRead* function reads data over the [I2C](https://learn.microsoft.com/windows-hardware/drivers/) channel.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's per-adapter device extension.

### `I2CCallbacks` [in]

Pointer to an [I2C_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_i2c_callbacks) structure, containing pointers to miniport driver-defined functions that read and write data and clock lines.

### `Buffer` [out]

Pointer to the data to be read.

### `Length` [in]

Specifies the number of bytes to be read.

## Return value

*I2CRead* returns **TRUE** if the data was successfully read, and **FALSE** otherwise.

## Remarks

The video port implements this function, which can be accessed through a pointer in the [VIDEO_PORT_I2C_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_i2c_interface) structure.

## See also

[VIDEO_PORT_I2C_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_i2c_interface)