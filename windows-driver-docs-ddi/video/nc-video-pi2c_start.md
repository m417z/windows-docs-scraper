# PI2C_START callback function

## Description

The *I2CStart* function starts [I2C](https://learn.microsoft.com/windows-hardware/drivers/) communication.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's per-adapter device extension.

### `I2CCallbacks` [in]

Pointer to an [I2C_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_i2c_callbacks) structure, containing pointers to miniport driver-defined functions that read and write data and clock lines.

## Return value

*I2CStart* returns **TRUE** if I²C communication was successfully started, and **FALSE** otherwise.

## Remarks

The video port implements this function, which can be accessed through a pointer in the [VIDEO_PORT_I2C_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_i2c_interface) structure.

## See also

[VIDEO_PORT_I2C_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_i2c_interface)