# PO_FX_COMPONENT_CRITICAL_TRANSITION_CALLBACK callback function

## Description

The *ComponentCriticalTransitionCallback* callback routine handles a transition of the specified component between the F0 (fully on) and low-power F*x* component power states.

## Parameters

### `Context` [in]

A pointer to the device context. The device driver uses this context to store information about the current power state of the device. This context is driver-defined and is opaque to PoFx. The driver specified this pointer in the **DeviceContext** member of the [PO_FX_CORE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_po_fx_core_device) structure that the driver used to register the device with the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx).

### `Component` [in]

The index that identifies the component. This parameter is an index into the **Components** array in the **PO_FX_CORE_DEVICE** structure that the device driver used to register the device with PoFx. If the **Components** array contains N elements, component indexes range from 0 to N–1.

### `Active` [in]

Indicates whether this notification is for a transition to the F0 component power state. If TRUE, the component has just completed a transition from a low-power F*x* state to F0. If FALSE, the component is about to start a transition from F0 to a low-power F*x* state.

## Remarks

This callback routine is implemented by a device driver, and is called by PoFx. PoFx calls this routine to notify the driver of power transitions of device components.

The **ComponentCriticalTransitionCallback** member of the [PO_FX_CORE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_po_fx_core_device) structure is a pointer to a *ComponentCriticalTransitionCallback* callback routine. A pointer to a **PO_FX_CORE_DEVICE** structure is passed as an input parameter in the PoFxRegisterCoreDevice call that registers a core device with the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx).

To handle calls to this routine, the device driver saves or restores the register state or other hardware context of the specified component in the device.

If *Active* = TRUE, PoFx has called this routine *after* the component completed a transition from a low-power F*x* state to F0. In this call, the routine restores the previously saved hardware context of the component.

If *Active* = FALSE, PoFx has called this routine *before* the component starts a pending transition from F0 to a low-power F*x* state. In this call, the routine saves the component's hardware context so that this context can later be restored.

For more information about F*x* component power states, see [Component-Level Power Management](https://learn.microsoft.com/windows-hardware/drivers/kernel/component-level-power-management).

## See also

[PO_FX_CORE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_po_fx_core_device)