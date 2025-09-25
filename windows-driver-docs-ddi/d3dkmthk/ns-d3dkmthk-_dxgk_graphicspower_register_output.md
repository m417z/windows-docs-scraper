# _DXGK_GRAPHICSPOWER_REGISTER_OUTPUT structure

## Description

A structure containing output data used to manage shared power components.

## Members

### `DeviceHandle`

An opaque handle that should be provided when making callbacks to the graphics device.

### `InitialGrfxPowerState`

The power state of the graphics device represented by the DeviceHandle at the time of internal IOCTL handling. The IOCTL call and parsing of this InitialGrfxPowerState must be protected by a mutex that also protects the [PowerNotificationCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pdxgk_power_notification) callback.

### `SetSharedPowerComponentStateCb`

A callback to indicate whether the specified power component is active. The component index should match the index used by the graphics driver when the component was indicated at driver initialization and the component must be one of the shared power component types. If this callback is used to set a state which has already been set by this driver for this graphics device, the call will have no effect.

If setting a component active, the graphics driver will be notified synchronously before this callback returns. This callback must be called from <= APC_LEVEL. It is possible for this call to fail with STATUS_DEVICE_REMOVED if the device is being removed, and [RemovalNotificationCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pdxgk_removal_notification) has not yet been called, or the graphics adapter is not running. See [PDXGK_SET_SHARED_POWER_COMPONENT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pdxgk_set_shared_power_component_state).

### `UnregisterCb`

 A callback to un-register itself with the graphics driver. All shared power components should no longer be active. The system will behave as if SetSharedPowerComponentStateCb had been called for all active shared power components with a new active state of FALSE. Upon return, previously provided callbacks can no longer be used. This callback must be called from <= APC_LEVEL. See [PDXGK_GRAPHICSPOWER_UNREGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pdxgk_graphicspower_unregister).