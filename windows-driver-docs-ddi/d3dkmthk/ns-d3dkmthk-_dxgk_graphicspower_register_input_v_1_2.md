# DXGK_GRAPHICSPOWER_REGISTER_INPUT_V_1_2 structure

## Description

The **DXGK_GRAPHICSPOWER_REGISTER_INPUT_V_1_2** structure is used to register the power state of a new input.

## Members

### `Version`

The current version being used. This value must be set to one of the following DXGK_GRAPHICSPOWER_VERSIONs:

```cpp
#define DXGK_GRAPHICSPOWER_VERSION_1_0 0x1000
#define DXGK_GRAPHICSPOWER_VERSION_1_1 0x1001
#define DXGK_GRAPHICSPOWER_VERSION_1_2 0x1002
#define DXGK_GRAPHICSPOWER_VERSION DXGK_GRAPHICSPOWER_VERSION_1_2
```

By default, DXGK_GRAPHICSPOWER_VERSION represents the latest version. The graphics subsystem supports the current version and all previous versions. If this value is a version that isn't recognized, we will fail with STATUS_NOINTERFACE. This should only happen in the case the non-graphics driver was built for a newer OS than what is currently running, and in this case we expect the non-graphics driver to retry with a lower version number.

DXGK_GRAPHICSPOWER_VERSION_1_1 supports F-state change notifications.
DXGK_GRAPHICSPOWER_VERSION_1_2 supports initial enumeration of shared power component data and state.

### `PrivateHandle`

An opaque handle that will be provided in any callbacks. This handle must be globally unique, therefore, a pointer to the calling driver’s PDO or FDO should be used. This handle will be used as a key by graphics to track this specific registration, and will be associated with the non-graphics driver callbacks in order to handle their future removal.

### `PowerNotificationCb`

A callback providing notification that the graphics device will be undergoing a device power state transition, and provide a new DEVICE_POWER_STATE. This callback is required to be implemented. See [**PDXGK_POWER_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pdxgk_power_notification).

### `RemovalNotificationCb`

A callback notifying that the graphics device is being removed. Any further callbacks into graphics for this DeviceHandle will return a failing NTSTATUS code and will be blocked until you return from the RemovalNotificationCb callback. This callback is required to be implemented. See [**PDXGK_REMOVAL_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pdxgk_removal_notification)

### `FStateNotificationCb`

Issues a state notification. This callback is optional, and is used by non-graphics drivers. See [**PDXGK_FSTATE_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pdxgk_fstate_notification).

### `InitialComponentStateCb`

Initializes the component state. See [**PDXGK_INITIAL_COMPONENT_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pdxgk_initial_component_state).

## Remarks

Graphics drivers indicate what power components exist by responding to the queries DXGKQAITYPE_NUMPOWERCOMPONENTS and DXGKQAITYPE_POWERCOMPONENTINFO in [_DXGK_QUERYADAPTERINFOTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype).

If a graphics driver registers at least one [DXGK_POWER_COMPONENT_SHARED](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_power_component_type) component, a GRAPHICSPOWER interface will be created for that adapter. The interface will not be registered for adapters that do not expose any of these components.

Graphics drivers can register a “blocking” component by setting the [DXGK_POWER_RUNTIME_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_power_runtime_component) flag *ActiveInD3* to **0**, or a “nonblocking” component by setting this flag to **1**.

A blocking power component will prevent the graphics device from powering down when in use while a non-blocking power component will not. Both allow the graphics driver to properly manage its power planes when in-use by the non-graphics driver.

A graphics driver may expose both a blocking and non-blocking power component for a single physical/logical component, if it wishes to provide the ability for the non-graphics driver to selectively choose blocking or non-blocking usage.

When the GRAPHICSPOWER driver interface is available and enabled, a non-graphics driver can make an IO call to the graphics driver to register itself with the graphics driver providing and obtaining callbacks which will be used to manage the shared power components. The IO call will use the [**IOCTL_INTERNAL_GRAPHICSPOWER_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ni-d3dkmthk-ioctl_internal_graphicspower_register) control code, with input data **DXGK_GRAPHICSPOWER_REGISTER_INPUT_V_1_2** and output data [_DXGK_GRAPHICSPOWER_REGISTER_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_dxgk_graphicspower_register_output).