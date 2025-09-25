# POFXCALLBACKPLATFORMIDLEVETO callback function (pep_x.h)

## Description

The **PlatformIdleVeto** routine increments or decrements the veto count for a veto code for a platform idle state.

## Parameters

### `ProcessorHandle` [in]

A POHANDLE value that represents the registration of the processor (as a device) with [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx). The platform extension plug-in (PEP) previously received this handle from PoFx during the [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification that informed the PEP that the processor had been registered with PoFx.

### `PlatformState` [in]

The index of the platform idle state whose veto count is being incremented or decremented. The PEP previously specified the supported platform idle states in response to a [PEP_NOTIFY_PPM_QUERY_PLATFORM_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_states) notification. If the PEP specified N platform idle states, valid platform idle state indexes range from 0 to N–1.

### `VetoReason` [in]

A PEP-defined veto code that indicates why the platform idle state cannot be entered. The PEP previously specified the number of supported veto reasons in response to a [PEP_NOTIFY_PPM_QUERY_VETO_REASONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_veto_reason) notification. If the PEP specified M veto reasons, valid veto codes range from 1 to M.

### `Increment` [in]

Whether to increment or decrement the veto count. Set to TRUE to increment the veto count for this veto reason, or to FALSE to decrement the count.

## Return value

**PlatformIdleVeto** returns STATUS_SUCCESS if the call successfully increments or decrements the veto count. Possible error return values include the following status code.

| Return value | Description |
| --- | --- |
| STATUS_NOT_IMPLEMENTED | Indicates that the **PlatformIdleVeto** routine is not implemented for this processor. |

## Remarks

This routine is implemented by the PoFx and is called by the PEP. The **PlatformIdleVeto** member of the [PEP_KERNEL_INFORMATION_STRUCT_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_kernel_information_struct_v3) structure is a pointer to a **PlatformIdleVeto** routine.

After the PEP handles the [PEP_NOTIFY_PPM_QUERY_PLATFORM_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_states) notification, each platform idle state starts with a veto count of zero for all veto codes. The PEP can increment the veto count of a veto code to prevent the operating system from transitioning the platform to this idle state. The PEP decrements the veto count when the veto reason that caused the count to be incremented is no longer in effect. Only after the count for all veto codes has decremented to zero is the operating system allowed to transition the platform to this idle state.

This routine must be called at IRQL = PASSIVE_LEVEL.

## See also

[PEP_KERNEL_INFORMATION_STRUCT_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_kernel_information_struct_v3)

[PEP_NOTIFY_PPM_QUERY_PLATFORM_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_states)

[PEP_NOTIFY_PPM_QUERY_VETO_REASONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_veto_reason)