# _VIDEO_PORT_I2C_INTERFACE structure

## Description

The VIDEO_PORT_I2C_INTERFACE structure describes the [I2C](https://learn.microsoft.com/windows-hardware/drivers/) service routines provided by the video port driver.

## Members

### `Size`

Specifies the size in bytes of this structure.

### `Version`

Specifies the version of the interface to be returned by the miniport driver. The current interface version is defined in *video.h*, and has the form VIDEO_PORT_I2C_INTERFACE_*N*.

### `Context`

Pointer to a miniport driver-defined context for the interface.

### `InterfaceReference`

Pointer to the video port driver-implemented reference routine for this interface.

### `InterfaceDereference`

Pointer to the video port driver-implemented dereference routine for this interface.

### `I2CStart`

Pointer to the video port driver's [I2CStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pi2c_start) routine.

### `I2CStop`

Pointer to the video port driver's [I2CStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pi2c_stop) routine.

### `I2CWrite`

Pointer to the video port driver's [I2CWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pi2c_write) routine.

### `I2CRead`

Pointer to the video port driver's [I2CRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pi2c_read) routine.

## Remarks

PnP video miniport drivers that can use I²C should fill in the **Size** and **Version** members of this structure, and then call [VideoPortQueryServices](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueryservices), which initializes the remaining members of this structure.

## See also

[INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)

[VideoPortQueryServices](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueryservices)