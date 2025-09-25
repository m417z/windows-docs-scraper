# _PEP_COMPONENT_PLATFORM_CONSTRAINTS structure (pepfx.h)

## Description

The **PEP_COMPONENT_PLATFORM_CONSTRAINTS** structure describes the lowest-powered F*x* state of that a component can be in when the platform is in a particular idle state.

## Members

### `DeviceHandle` [in]

A PEPHANDLE value that identifies the device. The platform extension plug-in (PEP) supplied this handle in response to a previous [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification.

### `Component` [in]

The index that identifies the component. This member is an index into the **Components** array in the [PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2) structure that the PEP previously supplied in response to the **PEP_DPM_REGISTER_DEVICE** notification for this device. If the **Components** array contains N elements, component indexes range from 0 to N–1.

### `MinimumFStates` [in]

A pointer to an output buffer. The PEP writes a ULONG array to this buffer that specifies the lowest-powered F*x* state that the component can be in for each platform idle state. An element with a value of 0 indicates F0, a value of 1 indicates F1, and so on. If the platform supports M idle states, array elements 0 to M–1 specify the F*x* states corresponding to platform idle states 0 to M–1.

### `PlatformStateCount` [in]

The number of elements in the **MinimumFStates** array. The array contains one element for each platform idle state. The Windows [power management framework (PoFx)](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework) previously sent a [PEP_NOTIFY_PPM_QUERY_PLATFORM_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_states) notification to the PEP to determine the number of supported platform idle states.

## Remarks

This structure is used by the [PEP_DPM_COMPONENT_IDLE_CONSTRAINTS](https://learn.microsoft.com/windows-hardware/drivers/kernel/dpm-notifications#pep_dpm_component_idle_constraints) notification. All four members of the structure contain input values that PoFx supplies when this notification is sent. PoFx allocates the buffer pointed to by the **MinimumFStates** member, and the PEP writes to this buffer in response to the notification.

## See also

[PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2)

[PEP_DPM_COMPONENT_IDLE_CONSTRAINTS](https://learn.microsoft.com/windows-hardware/drivers/kernel/dpm-notifications#pep_dpm_component_idle_constraints)

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/dpm-notifications#pep_dpm_register_device)

[PEP_NOTIFY_PPM_QUERY_PLATFORM_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_states)