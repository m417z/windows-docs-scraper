# _PEP_WORK_COMPLETE_PERF_STATE structure (pepfx.h)

## Description

The **PEP_WORK_COMPLETE_PERF_STATE** structure describes the completion status of a previously requested update to the performance values assigned to a list of performance state (P-state) sets.

## Members

### `DeviceHandle`

A handle that represents the registration of the device with the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework) (PoFx). The PEP received this handle in a previous [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification.

### `Component` [in]

The index that identifies the component. This member is an index into the **Components** array in the [PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2) structure that the PEP previously supplied in response to the **PEP_DPM_REGISTER_DEVICE** notification for this device. If the **Components** array contains N elements, component indexes range from 0 to N–1.

### `Succeeded`

Whether the requested P-state changes successfully completed. Set to TRUE if the PEP successfully completed all P-state changes requested in a previous [PEP_DPM_REQUEST_COMPONENT_PERF_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_request_component_perf_state) notification. Set to FALSE if the PEP was unable to perform all the requested P-state changes, in which case the P-states in the hardware were left unchanged.

## Remarks

The **CompletePerfState** member of the [PEP_WORK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_information) structure is a **PEP_WORK_COMPLETE_PERF_STATE** structure. If PoFx sends a [PEP_DPM_REQUEST_COMPONENT_PERF_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_request_component_perf_state) notification to request performance level changes to one or more P-state sets, and the PEP chooses to handle this request asynchronously, the PEP uses a **PEP_WORK_COMPLETE_PERF_STATE** structure to describe the completion status of the request.

## See also

[PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2)

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)

[PEP_DPM_REQUEST_COMPONENT_PERF_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_request_component_perf_state)

[PEP_WORK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_information)