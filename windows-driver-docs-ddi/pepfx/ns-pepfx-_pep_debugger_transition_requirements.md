# _PEP_DEBUGGER_TRANSITION_REQUIREMENTS structure (pepfx.h)

## Description

The **PEP_DEBUGGER_TRANSITION_REQUIREMENTS** structure indicates the platform idle states for which the debugger device must be turned on.

## Members

### `DeviceHandle` [in]

A PEPHANDLE value that identifies the debugger device. The platform extension plug-in (PEP) supplied this handle in response to a previous [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification.

### `PlatformStateCount` [in]

The number of entries in the array pointed to by the **PowerTransitionRequired** member. This number is the same as the number of supported platform idle states that the PEP specified in response to a previous [PEP_NOTIFY_PPM_QUERY_PLATFORM_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_states) notification.

### `PowerTransitionRequired` [in]

An output buffer to which the PEP writes a BOOLEAN array that indicates the platform idle states for which power to the debugger device must be turned on. This buffer is allocated by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) and is guaranteed to be large enough to contain the number of array elements specified by the **PlatformStateCount** member. Set an array element to TRUE if the debugger device must be turned on in the corresponding platform idle state. Set to FALSE to indicate that the device is not required to be turned on in this state. If the platform supports N idle states, the array contains N elements, and idle states are numbered 0 to N–1 in the order in which they are represented in the array.

## Remarks

This structure is used by the [PEP_DPM_QUERY_DEBUGGER_TRANSITION_REQUIREMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_debugger_transition_requirements) notification. All three members of the structure contain input values that are supplied by PoFx when this notification is sent to the PEP.

During a debugging session, the debugger component that runs on the target computer communicates with the host computer through a debugger device such as a USB host controller, UART, or networking device.

## See also

[PEP_DPM_QUERY_DEBUGGER_TRANSITION_REQUIREMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_debugger_transition_requirements)

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)

[PEP_NOTIFY_PPM_QUERY_PLATFORM_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_states)