# _PEP_QUERY_CURRENT_COMPONENT_PERF_STATE structure (pepfx.h)

## Description

The **PEP_QUERY_CURRENT_COMPONENT_PERF_STATE** structure contains information about the current P-state in the specified P-state set.

## Members

### `DeviceHandle`

A **PEPHANDLE** value that identifies the device. The PEP supplied this handle in response to a previous [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification.

### `Component`

The index that identifies the component. This member is an index into the *Components* array in the [PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2) structure that the PEP previously supplied in response to the **PEP_DPM_REGISTER_DEVICE** notification for this device. If the *Components* array contains N elements, component indexes range from 0 to N–1.

### `Set`

The index that identifies this P-state set. If M is the number of P-state sets for this component, P-state set indexes range from 0 to M–1. The PEP previously specified the number of P-state sets in response to a [PEP_DPM_QUERY_COMPONENT_PERF_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_capabilities) notification.

### `StateIndex`

The index of the current P-state for the specified P-state set. Write to this member if the performance values for the P-state set are of type **PoFxPerfStateTypeDiscrete**.

### `StateValue`

The value of the current P-state for the specified P-state set. Write to this member if the performance values for the P-state set are of type **PoFxPerfStateTypeRange**.

## Remarks

This structure is used by the **PEP_DPM_QUERY_CURRENT_COMPONENT_PERF_STATE** notification. The *DeviceHandle*, *Component*, and *Set* members contain input values supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) when this notification is sent. The *StateIndex* member or *StateValue* member contains an output value that the PEP writes to the structure in response to the notification.

The unnamed union contains the current performance level of this P-state set expressed either as an index into a set of discrete values or as a value in a range. In response to a previous [PEP_DPM_QUERY_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_set) notification, the PEP indicated whether the performance values in the P-state set are of type **PoFxPerfStateTypeDiscrete** or **PoFxPerfStateTypeRange**.

## See also

- [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)
- [PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2)
- [PEP_DPM_QUERY_COMPONENT_PERF_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_capabilities)
- [PEP_DPM_QUERY_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_set)