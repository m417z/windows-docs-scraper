# KS_CameraControlAsyncOperation enumeration

## Description

Defines notifications that the driver uses to start and stop an asynchronous camera operation, including setting the flash, the image pin control properties, the region of interest in the image, or video stabilization.

## Constants

### `KS_CAMERACONTROL_ASYNC_START`

Initiate an asynchronous camera control operation.

### `KS_CAMERACONTROL_ASYNC_STOP`

Stop the requested asynchronous camera control operation and maintain current camera control settings, including the lens focus.

### `KS_CAMERACONTROL_ASYNC_RESET`

Stop the requested asynchronous camera control operation and reset the lens focus to infinity.

## Remarks

For more information, see [KSPROPERTY_CAMERACONTROL_S_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_cameracontrol_s_ex).

## See also

[KSPROPERTY_CAMERACONTROL_S_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_cameracontrol_s_ex)