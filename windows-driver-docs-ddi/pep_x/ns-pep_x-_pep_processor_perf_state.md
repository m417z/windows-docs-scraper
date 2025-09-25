# _PEP_PROCESSOR_PERF_STATE structure (pep_x.h)

## Description

Use in the **PEP_NOTIFY_PPM_QUERY_DISCRETE_PERF_STATES** notification. This structure describes the properties of a single performance state.

## Members

### `Performance`

On output, the performance level (on the scale returned by the [PEP_QUERY_COMPONENT_PERF_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_capabilities) notification) of this performance state.

### `Frequency`

On output, the frequency (in MHz) of this performance state.

### `Reserved`

Reserved.

## See also

[PEP_PPM_QUERY_DISCRETE_PERF_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_discrete_perf_states)

[Processor power management (PPM) notifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/)