# _PO_FX_CORE_DEVICE structure (pepfx.h)

## Description

The **PO_FX_CORE_DEVICE** structure contains information about the power-state attributes of the components in a core system resource, and provides a software interface for power-managing these components.

## Members

### `Version`

The version number of this structure.

### `ComponentCount`

The number of elements in the **Components** array at the end of this structure. This count includes all elements of the array, and includes both the first element, which is a member of this structure, and any additional elements that follow the end of this structure.

### `ComponentActiveConditionCallback`

A pointer to a [ComponentActiveConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_active_condition_callback) callback routine. PoFx calls this routine to notify the driver that the specified component completed a transition from the idle condition to the active condition.

### `ComponentIdleConditionCallback`

A pointer to a [ComponentIdleConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_condition_callback) callback routine. PoFx calls this routine to notify the driver that the specified component completed a transition from the active condition to the idle condition.

### `ComponentCriticalTransitionCallback`

A pointer to a [ComponentCriticalTransitionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_critical_transition_callback) callback routine. PoFx calls this routine to notify the driver that the specified component is about to make a transition between the idle condition and the active condition.

### `ComponentIdleStateCallback`

A pointer to a [ComponentIdleStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_state_callback) callback routine. PoFx calls this routine to notify the driver of a pending change to the F*x* power state of the specified component.

### `DeviceContext`

A pointer to a PEP-defined device context. PoFx supplies this pointer as the first parameter in calls to the *ComponentActiveConditionCallback*, *ComponentIdleConditionCallback*, *ComponentCriticalTransitionCallback*, and *ComponentIdleStateCallback* routines. This context is opaque to PoFx.

### `Components`

The first element in an array of [PO_FX_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_v1) structures. Each element in the array describes the power attributes of a component in the device. If the array contains more than one element, the additional elements immediately follow the end of the **PO_FX_CORE_DEVICE** structure. The number of elements in the array is specified in the **ComponentCount** member of the **PO_FX_CORE_DEVICE** structure.

## Remarks

This structure is used by the [PoFxRegisterCoreDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregistercoredevice) routine.

A *core system resource* is a hardware device, such as a timer or an interrupt controller, that is managed by the Windows hardware abstraction layer (HAL).

For more information about component transitions between the active condition and the idle condition, see [Component-Level Power Management](https://learn.microsoft.com/windows-hardware/drivers/kernel/component-level-power-management).

## See also

[ComponentActiveConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_active_condition_callback)

[ComponentCriticalTransitionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_critical_transition_callback)

[ComponentIdleConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_condition_callback)

[ComponentIdleStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_state_callback)

[PO_FX_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_v1)

[PoFxRegisterCoreDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregistercoredevice)