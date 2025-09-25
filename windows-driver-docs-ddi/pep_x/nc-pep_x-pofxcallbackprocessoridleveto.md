# POFXCALLBACKPROCESSORIDLEVETO callback function (pep_x.h)

## Description

The **ProcessorIdleVeto** routine increments or decrements the veto count for a veto code for a processor idle state.

## Parameters

### `ProcessorHandle` [in]

A POHANDLE value that represents the registration of the processor (as a device) with [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx). The platform extension plug-in (PEP) previously received this handle from PoFx during the [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification that informed the PEP that the processor had been registered with PoFx.

### `ProcessorState` [in]

The index of the processor idle state whose veto count is being incremented or decremented. The PEP previously specified the supported processor idle states in response to a [PEP_NOTIFY_PPM_QUERY_IDLE_STATES_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_idle_states_v2) notification. If the PEP specified N processor idle states, valid processor idle state indexes range from 0 to N–1.

### `VetoReason` [in]

A PEP-defined veto code that indicates why the processor idle state cannot be entered. The PEP previously specified the supported veto reasons in response to a [PEP_NOTIFY_PPM_QUERY_VETO_REASONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_veto_reason) notification. If the PEP specified M veto reasons, valid veto codes range from 1 to M.

### `Increment` [in]

Whether to increment or decrement the veto count. Set to TRUE to increment the veto count for this veto reason, or to FALSE to decrement the count.

Whether to increment or decrement the veto count. Set to TRUE to increment the veto count for this veto reason, or to FALSE to decrement the count.

## Return value

This routine does not return a value.

## Remarks

This routine is implemented by the power management framework (PoFx) and is called by the platform extension plug-in (PEP). The **ProcessorIdleVeto** member of the [PEP_KERNEL_INFORMATION_STRUCT_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_kernel_information_struct_v3) structure is a pointer to a **ProcessorIdleVeto** routine.

## See also

[PEP_KERNEL_INFORMATION_STRUCT_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_kernel_information_struct_v3)