# _PEP_PPM_QUERY_DISCRETE_PERF_STATES structure (pepfx.h)

## Description

Used in the **PEP_NOTIFY_PPM_QUERY_DISCRETE_PERF_STATES** notification that stores the list of discrete performance states that PEP supports, if the **PEP_NOTIFY_PPM_QUERY_CAPABILITIES** notification indicates support for discrete performance states.

## Members

### `Count`

On input, the size of the array pointed to by *States*.

### `States`

On output, an array of [PEP_PROCESSOR_PERF_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_processor_perf_state) structures that indicates performance states that is filled by PEP.

## See also

[PEP_PPM_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_capabilities)

[Processor power management (PPM) notifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/)