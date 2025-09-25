# POFXCALLBACKUPDATEPROCESSORIDLESTATE callback function (pep_x.h)

## Description

The **UpdateProcessorIdleState** routine is called by the platform extension plug-in (PEP) to update the properties of the specified processor idle state.

## Parameters

### `ProcessorHandle` [in]

A POHANDLE value that represents the registration of the processor (as a device) with the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx). The PEP previously received this handle from PoFx during the [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification that informed the PEP that the processor had been registered with PoFx.

### `ProcessorState` [in]

An index that identifies the processor idle state whose properties are to be updated. In response to a previous [PEP_NOTIFY_PPM_QUERY_IDLE_STATES_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_idle_states_v2) notification, the PEP specified the number of supported processor idle states and the properties of these states. If the PEP specified N processor idle states, valid processor idle state indexes range from 0 to N-1.

### `Update` [in]

A pointer to a [PEP_PROCESSOR_IDLE_STATE_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_processor_idle_state_update) structure that contains the updated properties of the processor idle state.

## Return value

**UpdateProcessorIdleState** returns STATUS_SUCCESS if it successfully updates the properties of the processor idle state. Possible error return values include the following status codes.

| Return value | Description |
| --- | --- |
| STATUS_NOT_SUPPORTED | The version number in the **PEP_PROCESSOR_IDLE_STATE_UPDATE** structure is not a supported value. |
| STATUS_NOT_IMPLEMENTED | The **UpdateProcessorIdleState** routine is not implemented for this processor. |

## Remarks

This routine is implemented by PoFx and is called by the PEP. The **UpdateProcessorIdleState** member of the [PEP_KERNEL_INFORMATION_STRUCT_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_kernel_information_struct_v3) structure is a pointer to an **UpdateProcessorIdleState** routine.

The **UpdateProcessorIdleState** routine must be called at IRQL = PASSIVE_LEVEL.

## See also

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)

[PEP_KERNEL_INFORMATION_STRUCT_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_kernel_information_struct_v3)

[PEP_PROCESSOR_IDLE_STATE_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_processor_idle_state_update)