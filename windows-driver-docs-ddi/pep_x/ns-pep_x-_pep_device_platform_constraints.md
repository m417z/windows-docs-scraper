# _PEP_DEVICE_PLATFORM_CONSTRAINTS structure (pep_x.h)

## Description

The **PEP_DEVICE_PLATFORM_CONSTRAINTS** structure specifies the constraints for entry to the various D*x* power states that are supported by a device.

## Members

### `DeviceHandle` [in]

A PEPHANDLE value that identifies the device. The PEP supplied this handle in response to a previous [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification.

### `MinimumDStates` [in]

A pointer to an array of [DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state) enumeration values that indicate the lowest-powered D*x* (device power) state the device can enter for each platform idle state.

### `PlatformStateCount` [in]

The number of elements in the array pointed to by the **MinimumDStates** member. This member contains the platform state count that the PEP supplied in response to a previous [PEP_NOTIFY_PPM_QUERY_PLATFORM_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_states) notification.

## Remarks

This structure is used by the [PEP_DPM_DEVICE_IDLE_CONSTRAINTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_component_platform_constraints) notification. All three members of this structure contain input values that are supplied by the Windows power management framework (PoFx). In response to this notification, the PEP writes [DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state) enumeration values to the elements of the array pointed to by the **MinimumDStates** member. PoFx allocates the storage for this array before sending the notification.

## See also

[DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state)

[PEP_DPM_DEVICE_IDLE_CONSTRAINTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_component_platform_constraints)

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)