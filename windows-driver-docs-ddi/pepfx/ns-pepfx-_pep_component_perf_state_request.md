# _PEP_COMPONENT_PERF_STATE_REQUEST structure (pepfx.h)

## Description

The **PEP_COMPONENT_PERF_STATE_REQUEST** structure specifies a performance state (P-state) set and a new performance level to assign to this set.

## Members

### `Set`

The index of the P-state set to which to assign the new performance level. If N is the number of P-state sets specified for this component, P-state set indexes range from 0 to N–1. The PEP previously specified the number of P-state sets in response to a [PEP_DPM_QUERY_COMPONENT_PERF_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_capabilities) notification.

### `StateIndex`

The index of the discrete value to use as the new performance level. This member is used if the performance level for this P-state set is expressed as an index into an array of discrete values. The PEP previously supplied this array of discrete values in response to a [PEP_DPM_QUERY_COMPONENT_PERF_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_states) notification.

### `StateValue`

The value to use as the new performance level. This member is used if the performance level for this P-state set is expressed as a value in a continuous range of possible values. The PEP previously supplied this range in response to a [PEP_DPM_QUERY_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_set) notification.

## Remarks

The unnamed union contains a value that indicates the new performance level that has been selected for this P-state set.

The *PerfRequests* member of the [PEP_REQUEST_COMPONENT_PERF_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_request_component_perf_state) structure is a pointer to an array of **PEP_COMPONENT_PERF_STATE_REQUEST** structures.

## See also

- [PEP_DPM_QUERY_COMPONENT_PERF_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_capabilities)
- [PEP_DPM_QUERY_COMPONENT_PERF_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_states)
- [PEP_DPM_QUERY_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_set)
- [PEP_REQUEST_COMPONENT_PERF_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_request_component_perf_state)