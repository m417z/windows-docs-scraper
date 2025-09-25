# PDXGK_POWER_NOTIFICATION callback

## Description

A callback providing notification that the graphics device will be undergoing a device power state transition.

## Parameters

### `GraphicsDeviceHandle`

An opaque handle which should be provided when making callbacks to the graphics device.

### `NewGrfxPowerState`

A [**DEVICE_POWER_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_device_power_state) value that indicates the new graphics power state that is in the process of being set.

### `PreNotification`

Boolean value that indicates whether a notification should be provided.

### `PrivateHandle`

An opaque handle provided in any callbacks. This handle must be globally unique, therefore, a pointer to the calling driver's PDO or FDO should be used.

## Remarks

This callback is made at PASSIVE_LEVEL. The driver may block in order to complete the servicing of the operation only when the new power state is PowerDeviceD3. In this case, the call must still be completed in a timely fashion, as it can block the completion of the overall device power state transition and is subject to causing a power watchdog bug check. The driver must not block when the new state is PowerDeviceD0. When going into PowerDeviceD3, both a "pre" and "post" notification will be provided, assuming that the transition is not canceled in the interim. When going into PowerDeviceD0, only a "post" notification will be provided. It is permitted for this callback handler to call the SetSharedPowerComponentStateCb graphics callback if desired; no other callbacks into graphics kernel are permitted from this handler.

> [!IMPORTANT]
> The initial graphics power state will be provided in the IOCTL output, however, since it is possible that the graphics device may be undergoing a power state transition while registration is occurring, a mutex must be acquired around the IOCTL call and parsing of the original state, and that same mutex must be acquired in this callback function. That way, should the state be transitioning, the callback will provide the most up to date state information.

## See also

[**DEVICE_POWER_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_device_power_state)