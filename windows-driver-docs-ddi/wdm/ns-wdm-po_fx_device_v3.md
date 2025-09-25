# PO_FX_DEVICE_V3 structure

## Description

The **PO_FX_DEVICE_V3** structure describes the power attributes of a device to the power management framework (PoFx), DFx (Directed [PoFx](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework))

## Members

### `Version`

The version number of this structure. If the driver will register for directed power support with DFx, set this member to **PO_FX_VERSION_V3**.

### `Flags`

Controls whether direct child devices and power child devices can opt out of Directed PoFx.

Possible flag values include:

|Flag|Description|
|-|-|
|**PO_FX_DEVICE_FLAG_DIRECT_CHILDREN_OPTIONAL**|Allows direct child devices of this device to optionally support Directed PoFx. If not set, all direct children must support Directed PoFx for this device to fully support Directed PoFx.|
|**PO_FX_DEVICE_FLAG_POWER_CHILDREN_OPTIONAL**|Allows power child devices of this device to optionally support Directed PoFx. If not provided, all power children must support Directed PoFx for this device to fully support Directed PoFx.|
|**PO_FX_DEVICE_FLAG_DFX_CHILDREN_OPTIONAL**|Sets both **PO_FX_DEVICE_FLAG_DIRECT_CHILDREN_OPTIONAL** and **PO_FX_DEVICE_FLAG_POWER_CHILDREN_OPTIONAL**|
|**PO_FX_DEVICE_FLAG_DISABLE_FAST_RESUME**|Forces PoFx to prevent the S0-IRP from being completed before the D0-IRP on resume from a system state such as Hibernate or Sleep. Mutually exclusive with **PO_FX_DEVICE_FLAG_ENABLE_FAST_RESUME**.|
|**PO_FX_DEVICE_FLAG_ENABLE_FAST_RESUME**|Forces PoFx to allow the S0-IRP to be completed before the D0-IRP on resume from a system state such as Hibernate or Sleep. Mutually exclusive with **PO_FX_DEVICE_FLAG_ENABLE_FAST_RESUME**.|

### `ComponentActiveConditionCallback`

A pointer to the [ComponentActiveConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_active_condition_callback) callback routine that is implemented by the device driver.

### `ComponentIdleConditionCallback`

A pointer to the [ComponentIdleConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_condition_callback) callback routine that is implemented by the device driver.

### `ComponentIdleStateCallback`

A pointer to the [ComponentIdleStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_state_callback) callback routine that is implemented by the device driver.

### `DevicePowerRequiredCallback`

A pointer to the [DevicePowerRequiredCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_device_power_required_callback) callback routine that is implemented by the device driver.

### `DevicePowerNotRequiredCallback`

A pointer to the [DevicePowerNotRequiredCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_device_power_not_required_callback) callback routine that is implemented by the device driver.

### `PowerControlCallback`

A pointer to the [PowerControlCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_power_control_callback) callback routine that is implemented by the device driver.

### `DirectedPowerUpCallback`

A pointer to the [*PO_FX_DIRECTED_POWER_UP_CALLBACK*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_directed_power_up_callback) callback routine that is implemented by the device driver. A device can provide only the `DirectedPower*` callbacks when registering for PoFx. It does not need to implement the rest of the PoFx callbacks.

### `DirectedPowerDownCallback`

A pointer to the [*PO_FX_DIRECTED_POWER_DOWN_CALLBACK*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_directed_power_down_callback) callback routine that is implemented by the device driver.

### `DirectedFxTimeoutInSeconds`

Provides a hint to the framework specifying a recommended timeout in seconds in which the device should have idled out after software activity is no longer present. The default value is 2 minutes.

### `DeviceContext`

A pointer to a caller-allocated device context. This pointer is passed as a parameter to each driver-implemented callback function that is pointed to by this structure. The device driver uses this context to store information about the current power state of the device. This context is opaque to PoFx.

### `ComponentCount`

The number of elements in the **Components** array. Additionally, this member specifies the number of components in the device.

### `Components`

This member is the first element in an array of one or more PO_FX_COMPONENT_V2 elements. If the array contains more than one element, the additional elements immediately follow the **PO_FX_DEVICE_V2** structure. The array contains one element for each component in the device. The Fx power state of each component can be controlled independently of the Fx power states of the other components in the device. The **ANYSIZE_ARRAY** constant is defined to be 1 in the Ntdef.h header file.

## Remarks

To register a device with PoFx, a driver calls the [**PoFxRegisterDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) routine and supplies, as a parameter, a pointer to a **PO_FX_DEVICE** structure that describes the device. To use PoFx but not DFx, register with PoFx using either [PO_FX_DEVICE_V2 structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_device_v2) or PO_FX_DEVICE_V3 structure.

Each element in the **Components** array describes the power state attributes of one component in the device. Each component in the device is identified by its **Components** array index. Routines such as [PoFxActivateComponent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxactivatecomponent) and [PoFxCompleteIdleCondition](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxcompleteidlecondition) use the array index of a component to identify the component.

A device driver is not required to implement all eight callback routines. The driver can set a function pointer in the **PO_FX_DEVICE** structure to NULL if the driver does not implement the corresponding callback routine. However, certain callback routines must be implemented. Specifically, if one or more components in a device has more than one Fx state, the driver must implement [ComponentIdleStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_state_callback), [ComponentActiveConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_active_condition_callback), and [ComponentIdleConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_condition_callback) routines. Otherwise, device registration fails and [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) returns **STATUS_INVALID_PARAMETER**.

If a driver does not provide one of **PO_FX_DEVICE_FLAG_DISABLE_FAST_RESUME** or **PO_FX_DEVICE_FLAG_ENABLE_FAST_RESUME** the system will fallback to the platform's default configuration. The default configuration is **PO_FX_DEVICE_FLAG_ENABLE_FAST_RESUME** for x86/x64 platforms, and **PO_FX_DEVICE_FLAG_DISABLE_FAST_RESUME** for ARM32/ARM64 platforms. These flags are only honored for Win11 22000+ and are silently ignored for prior releases. For WDF drivers these flags can be provided using the **PoFxDeviceFlags** field of [WDF_POWER_FRAMEWORK_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_power_framework_settings).

## See also

/windows-hardware/drivers/kernel/introduction-to-the-directed-power-management-framework

[ComponentActiveConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_active_condition_callback)

[ComponentIdleConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_condition_callback)

[ComponentIdleStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_state_callback)

[DevicePowerNotRequiredCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_device_power_not_required_callback)

[DevicePowerRequiredCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_device_power_required_callback)

[PO_FX_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_v1)

[PoFxActivateComponent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxactivatecomponent)

[PoFxCompleteIdleCondition](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxcompleteidlecondition)

[PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice)

[PowerControlCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_power_control_callback)