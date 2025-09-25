# _PEP_REGISTER_COMPONENT_PERF_STATES structure (pepfx.h)

## Description

The **PEP_REGISTER_COMPONENT_PERF_STATES** structure describes the performance states (P-states) of the specified component.

## Members

### `DeviceHandle` [in]

A PEPHANDLE value that identifies the device. The platform extension plug-in (PEP) supplied this handle in response to a previous [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification.

### `Component` [in]

The index that identifies the component. This member is an index into the **Components** array in the [PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2) structure that the PEP previously supplied in response to the **PEP_DPM_REGISTER_DEVICE** notification for this device. If the **Components** array contains N elements, component indexes range from 0 to N–1.

### `Flags` [in]

A set of input flags. No flag bits are currently defined for this member, which is always zero.

### `PerfStateInfo` [in]

A pointer to a [PEP_COMPONENT_PERF_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_component_perf_info) structure that contains the performance information for this component's P-states. If this member is non-NULL, it points to P-state information that was supplied by the device driver.

## Remarks

This structure is used by the [PEP_DPM_REGISTER_COMPONENT_PERF_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_component_perf_states) notification. The values of all members of the **PEP_REGISTER_COMPONENT_PERF_STATES** structure are supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) when the notification is sent. The PEP must not write to this structure.

If the **PerfStateInfo** member is not NULL, the device driver has provided P-state information and requires the PEP to use it.

## See also

[PEP_COMPONENT_PERF_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_component_perf_info)

[PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2)

[PEP_DPM_REGISTER_COMPONENT_PERF_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_component_perf_states)

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)