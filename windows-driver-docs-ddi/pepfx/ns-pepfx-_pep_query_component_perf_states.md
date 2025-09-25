# _PEP_QUERY_COMPONENT_PERF_STATES structure (pepfx.h)

## Description

The **PEP_QUERY_COMPONENT_PERF_STATES** structure contains a list of discrete performance state (P-state) values for the specified P-state set.

## Members

### `DeviceHandle` [in]

A PEPHANDLE value that identifies the device. The PEP supplied this handle in response to a previous [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification.

### `Component` [in]

The index that identifies the component. This member is an index into the **Components** array in the [PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2) structure that the PEP previously supplied in response to the **PEP_DPM_REGISTER_DEVICE** notification for this device. If the **Components** array contains N elements, component indexes range from 0 to N–1.

### `Set` [in]

The index that identifies this P-state set. If M is the number of P-state sets for this component, P-state set indexes range from 0 to M–1. The PEP previously specified the number of P-state sets in response to a [PEP_DPM_QUERY_COMPONENT_PERF_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_capabilities) notification.

### `States` [in]

A pointer to an output buffer. The PEP writes an array of [PEP_PERF_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_perf_state) structures to this buffer. Each array element describes one P-state in the P-state set specified by the **Set** member. The Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) allocated this buffer, which is guaranteed to be large enough to contain an array of the length that the PEP previously wrote to the **Discrete.Count** member of the [PEP_QUERY_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_set) structure in response to a [PEP_DPM_QUERY_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_set) notification.

## Remarks

This structure is used by the [PEP_DPM_QUERY_COMPONENT_PERF_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_states) notification. All four members of this structure contain input values that are supplied by PoFx when this notification is sent.

## See also

[PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2)

[PEP_DPM_QUERY_COMPONENT_PERF_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_states)

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)

[PEP_PERF_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_perf_state)