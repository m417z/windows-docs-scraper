# _PO_FX_DEVICE_V1 structure

## Description

The **PO_FX_DEVICE** structure describes the power attributes of a device to the power management framework (PoFx).

## Members

### `Version`

The version number of this structure. If the driver will register for performance state support with PoFx, set this member to **PO_FX_VERSION_V2**. Otherwise, set this member to **PO_FX_VERSION_V1**.

### `ComponentCount`

The number of elements in the **Components** array. Additionally, this member specifies the number of components in the device.

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

### `DeviceContext`

A pointer to a caller-allocated device context. This pointer is passed as a parameter to each driver-implemented callback function that is pointed to by this structure. The device driver uses this context to store information about the current power state of the device. This context is opaque to PoFx.

### `Components`

This member is the first element in an array of one or more [PO_FX_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_v1) elements. If the array contains more than one element, the additional elements immediately follow the **PO_FX_DEVICE** structure. The array contains one element for each component in the device. The Fx power state of each component can be controlled independently of the Fx power states of the other components in the device. The **ANYSIZE_ARRAY** constant is defined to be 1 in the Ntdef.h header file.

## Remarks

To register a device with PoFx, a driver calls the [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) routine and supplies, as a parameter, a pointer to a **PO_FX_DEVICE** structure that describes the device.

Each element in the **Components** array describes the power state attributes of one component in the device. Each component in the device is identified by its **Components** array index. Routines such as [PoFxActivateComponent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxactivatecomponent) and [PoFxCompleteIdleCondition](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxcompleteidlecondition) use the array index of a component to identify the component.

A device driver is not required to implement all six callback routines. The driver can set a function pointer in the **PO_FX_DEVICE** structure to NULL if the driver does not implement the corresponding callback routine. However, certain callback routines must be implemented. Specifically, if one or more components in a device has more than one Fx state, the driver must implement [ComponentIdleStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_state_callback), [ComponentActiveConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_active_condition_callback), and [ComponentIdleConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_condition_callback) routines. Otherwise, device registration fails and [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) returns **STATUS_INVALID_PARAMETER**.

## See also

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