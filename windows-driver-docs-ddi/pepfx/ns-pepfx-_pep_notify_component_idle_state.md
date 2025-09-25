# _PEP_NOTIFY_COMPONENT_IDLE_STATE structure (pepfx.h)

## Description

The **PEP_NOTIFY_COMPONENT_IDLE_STATE** structure contains status information about a component's pending transition to a new F*x* power state.

## Members

### `DeviceHandle` [in]

A PEPHANDLE value that identifies the device. The PEP supplied this handle in response to a previous [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification.

### `Component` [in]

The index that identifies the component. This member is an index into the **Components** array in the [PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2) structure that the PEP previously supplied in response to the **PEP_DPM_REGISTER_DEVICE** notification for this device. If the **Components** array contains N elements, component indexes range from 0 to N–1.

### `IdleState` [in]

The new F*x* power state that the component will transition to. If this parameter is zero, the new state is F0; if this parameter is one, the new state is F1; and so on.

### `DriverNotified` [in]

Whether the driver for the device has already been notified of the pending transition to the new F*x* state. If TRUE, the [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) already notified the driver by calling the driver's [ComponentIdleStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_state_callback) callback routine. If FALSE, PoFx has not yet notified the driver.

### `Completed` [out]

Whether the PEP has completed all necessary preparations for the specified component to enter the new F*x* state. Set to TRUE to indicate that the PEP has completed all necessary preparations, or to FALSE to indicate that is has not.

If FALSE, the PEP must complete the necessary preparations at a later time and then inform PoFx when the preparations have been completed. To do so, the PEP calls the [RequestWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackrequestworker) routine to request a work item, and then responds to the ensuing [PEP_DPM_WORK](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-peps-for-acpi-services) notification by submitting a work request of type **PepWorkCompleteIdleState** to inform PoFx that the preparations are complete.

## Remarks

This structure is used by the [PEP_DPM_NOTIFY_COMPONENT_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_notify_component_idle_state) notification. The first four members of this structure contain input values that are supplied by PoFx. The **Completed** member contains an output value that the PEP writes to the structure in response to this notification.

## See also

[PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2)

[PEP_DPM_NOTIFY_COMPONENT_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_notify_component_idle_state)

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)

[PEP_DPM_WORK](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-peps-for-acpi-services)

[RequestWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackrequestworker)