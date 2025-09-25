# POFXCALLBACKUPDATEPLATFORMIDLESTATE callback function (pepfx.h)

## Description

The **UpdatePlatformIdleState** routine is called by the platform extension plug-in (PEP) to update the properties of the specified platform idle state.

## Parameters

### `ProcessorHandle` [in]

A POHANDLE value that represents the registration of the processor (as a device) with the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx). The PEP previously received this handle from PoFx during the [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification that informed the PEP that the processor had been registered with PoFx.

### `PlatformState` [in]

An index that identifies the platform idle state whose properties are to be updated. In response to a previous [PEP_NOTIFY_PPM_QUERY_PLATFORM_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_states) notification, the PEP specified the number of supported platform idle states. If the PEP specified N platform idle states, valid platform idle state indexes range from 0 to N-1. In response to a previous [PEP_NOTIFY_PPM_QUERY_PLATFORM_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_state) notification, the PEP specified the properties of this platform idle state.

### `Update` [in]

A pointer to a [PEP_PLATFORM_IDLE_STATE_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_platform_idle_state_update) structure that contains the updated properties of the platform idle state.

## Return value

**UpdatePlatformIdleState** returns STATUS_SUCCESS if it successfully updates the properties of the platform idle state. Possible error return values include the following status codes.

| Return value | Description |
| --- | --- |
| STATUS_NOT_SUPPORTED | The version number in the **PEP_PLATFORM_IDLE_STATE_UPDATE** structure is not a supported value. |
| STATUS_NOT_IMPLEMENTED | The **UpdatePlatformIdleState** routine is not implemented for this processor. |

## Remarks

This routine is implemented by PoFx and is called by the PEP. The **UpdatePlatformIdleState** member of the [PEP_KERNEL_INFORMATION_STRUCT_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_kernel_information_struct_v3) structure is a pointer to an **UpdatePlatformIdleState** routine.

 The PEP must wait until after it has completed all [PEP_NOTIFY_PPM_QUERY_PLATFORM_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_state) notifications to call the **UpdatePlatformIdleState** routine.

The **UpdatePlatformIdleState** routine must be called at IRQL = PASSIVE_LEVEL.

## See also

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)

[PEP_KERNEL_INFORMATION_STRUCT_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_kernel_information_struct_v3)

[PEP_NOTIFY_PPM_QUERY_PLATFORM_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_state)

[PEP_NOTIFY_PPM_QUERY_PLATFORM_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_states)

[PEP_PLATFORM_IDLE_STATE_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_platform_idle_state_update)