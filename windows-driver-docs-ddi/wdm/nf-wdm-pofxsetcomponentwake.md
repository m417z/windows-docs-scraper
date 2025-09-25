# PoFxSetComponentWake function

## Description

The **PoFxSetComponentWake** routine indicates whether the driver arms the specified component to wake whenever the component enters the idle condition.

## Parameters

### `Handle` [in]

A handle that represents the registration of the device with the power management framework (PoFx). The device driver previously received this handle from the [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) routine.

### `Component` [in]

The index that identifies the component. This parameter is an index into the **Components** array in the [PO_FX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_device_v1) structure that the device driver used to register the device with PoFx. If the **Components** array contains N elements, component indexes range from 0 to N–1.

### `WakeHint` [in]

Whether the driver arms the component to wake whenever the component enters the idle condition. If TRUE, the driver arms the component to wake. If FALSE, the driver does not arm the component to wake.

## Remarks

Before a component enters a low-power Fx state, the driver might arm the component to automatically wake in response to an input signal from an external source (for example, if the user pushes a button). The *WakeHint* parameter informs PoFx whether the driver arms the component to wake. If a component is armed to wake, PoFx will not switch the component to a low-power Fx state from which the component cannot wake.

When a device is registered with PoFx, the registration information for each component in the device is contained in a separate [PO_FX_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_v1) structure. The **DeepestWakeableIdleState** member of this structure specifies the deepest Fx state from which the component can wake.

The device driver can call **PoFxSetComponentWake** each time a change in conditions requires a change in the *WakeHint* value. After each call, the new *WakeHint* value remains in effect until the driver calls **PoFxSetComponentWake** again to update it.

If a component is in the idle condition when **PoFxSetComponentWake** is called, PoFx might change the component’s Fx state to accommodate the new *WakeHint* parameter value specified by the caller.

## See also

[PO_FX_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_v1)