# _PEP_REQUEST_COMPONENT_PERF_STATE structure (pep_x.h)

## Description

The **PEP_REQUEST_COMPONENT_PERF_STATE** structure contains a list of performance state (P-state) changes requested by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx), plus status information about the handling of these requests by the platform extension plug-in (PEP).

## Members

### `DeviceHandle` [in]

A PEPHANDLE value that identifies the device. The PEP supplied this handle in response to a previous [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification.

### `Component` [in]

The index that identifies the component. This member is an index into the **Components** array in the [PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2) structure that the PEP previously supplied in response to the **PEP_DPM_REGISTER_DEVICE** notification for this device. If the **Components** array contains N elements, component indexes range from 0 to N–1.

### `Completed` [out]

Whether the PEP has completed the requested P-state changes. Set to TRUE to indicate that the P-state changes completed synchronously. Set to FALSE to indicate that the requested P-state changes are pending and will be completed asynchronously by a PEP worker thread. For more information, see Remarks.

### `Succeeded` [out]

Whether the requested P-state changes successfully completed. Set to TRUE if the PEP successfully completed all P-state changes requested in the **PerfRequests** array. Set to FALSE if the PEP was unable to perform all the requested P-state changes, in which case the P-states in the hardware were left unchanged. The **Succeeded** member is used only for *synchronous* P-state changes. If the PEP sets **Completed** to FALSE, PoFx ignores the value in the **Succeeded** member.

### `PerfRequestsCount` [in]

The number of P-state changes requested in the array pointed to by the **PerfRequests** member.

### `PerfRequests` [in]

A pointer to an array of [PEP_COMPONENT_PERF_STATE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_component_perf_state_request) structures. Each element in the array specifies a new performance level to assign to a P-state set. The number of array elements is specified by the **PerfRequestsCount** member.

## Remarks

This structure is used by the [PEP_DPM_REQUEST_COMPONENT_PERF_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_request_component_perf_state) notification. The **DeviceHandle**, **Component**, **PerfRequestsCount**, and **PerfRequests** members of the structure contain input values that are supplied by PoFx when this notification is sent. The **Completed** and **Succeeded** members contain output values that the PEP writes to the structure in response to the notification.

The PEP can complete the requested P-state changes either synchronously or asynchronously. The PEP can set the **Completed** member to TRUE to indicate that all the requests in the **PEP_DPM_REQUEST_COMPONENT_PERF_STATE** notification have been completed synchronously—that is, before the return from the PEP's [AcceptDeviceNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pepcallbacknotifydpm) callback routine. Or, the PEP can set **Completed** to FALSE to indicate that the requests will be completed asynchronously. To complete the requests asynchronously, the PEP should call the [RequestWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackrequestworker) routine to inform PoFx that the PEP has a work request to submit, and PoFx will respond by sending a [PEP_DPM_WORK](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-peps-for-acpi-services) notification to the PEP.

PoFx writes the requested P-state changes to the **PerfRequests** array before the **PEP_DPM_REQUEST_COMPONENT_PERF_STATE** notification is sent. If the PEP handles the requested P-state changes *synchronously*, the contents of the **PerfRequests** array remain valid only until the return from the *AcceptDeviceNotification* callback routine. If the requests are completed *asynchronously*, the array contents remain valid until the PEP calls the *CompleteWork* routine to notify PoFx that the PEP has completed the pending requests.

## See also

[AcceptDeviceNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pepcallbacknotifydpm)

[PEP_COMPONENT_PERF_STATE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_component_perf_state_request)

[PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2)

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)

[PEP_DPM_REQUEST_COMPONENT_PERF_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_request_component_perf_state)

[PEP_DPM_WORK](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-peps-for-acpi-services)

[RequestWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackrequestworker)