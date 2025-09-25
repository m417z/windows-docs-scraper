# _PEP_QUERY_COMPONENT_PERF_SET_NAME structure (pep_x.h)

## Description

The **PEP_QUERY_COMPONENT_PERF_SET_NAME** structure contains query information about a set of performance state values (P-state set) for a component.

## Members

### `DeviceHandle` [in]

A PEPHANDLE value that identifies the device. The PEP supplied this handle in response to a previous [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification.

### `Component` [in]

The index that identifies the component. This member is an index into the **Components** array in the [PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2) structure that the PEP previously supplied in response to the **PEP_DPM_REGISTER_DEVICE** notification for this device. If the **Components** array contains N elements, component indexes range from 0 to N–1.

### `Set` [in]

The index that identifies this P-state set. If this component has M P-state sets, P-state set indexes range from 0 to M–1. The PEP previously specified the number of P-state sets in response to a [PEP_DPM_QUERY_COMPONENT_PERF_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_capabilities) notification.

### `NameSize` [in, out]

On input, the size, in bytes, of the buffer pointed to by the **Name** member. If **Name** is NULL, the PEP overwrites the input value of **NameSize** with the buffer size required for the name string.

### `Name` [in]

A pointer to an output buffer. The PEP writes the name of the P-state to this buffer. The name is stored as a wide-character, null-terminated string. The **Name** member is NULL if the Windows power management framework (PoFx) needs to determine how large a buffer to allocate for the name string. If **Name** is non-NULL, the buffer must be large enough to contain the entire string, including the terminating null character.

## Remarks

This structure is used by the [PEP_DPM_QUERY_COMPONENT_PERF_SET_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_set_name) notification. The **DeviceHandle**, **Component**, and **Set** members of the structure contain input values supplied by PoFx when this notification is sent. If the **Name** member is non-NULL, the PEP writes a string to the buffer pointed to by **Name**. If **Name** is NULL, PEP writes the required buffer size to the **NameSize** member.

The string that the PEP writes to the output buffer should contain a descriptive name for the P-state set. This name is intended to make log entries and diagnostic messages easier to understand.

## See also

[PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2)

[PEP_DPM_QUERY_COMPONENT_PERF_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_capabilities)

[PEP_DPM_QUERY_COMPONENT_PERF_SET_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_set_name)

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)