# _PEP_COMPONENT_PERF_INFO structure (pep_x.h)

## Description

The **PEP_COMPONENT_PERF_INFO** structure describes the performance states (P-states) of a component.

## Members

### `SetCount`

The number of elements in the **PerfStateSets** array.

### `PerfStateSets`

The first element in an array of [PEP_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_component_perf_set) structures. Each array element describes a P-state of the component. If the array contains more than one element, the additional elements immediately follow the end of the **PEP_COMPONENT_PERF_INFO** structure.

## Remarks

This structure is used in conjunction with the [PEP_DPM_REGISTER_COMPONENT_PERF_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_component_perf_states) notification. The **PerfStateSets** member of the [PEP_REGISTER_COMPONENT_PERF_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_component_perf_states) structure is a **PEP_COMPONENT_PERF_INFO** structure.

The **PEP_COMPONENT_PERF_INFO** structure contains input values that are supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx). The platform extension plug-in (PEP) must not write to this structure.

## See also

[PEP_COMPONENT_PERF_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_component_perf_info)

[PEP_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_component_perf_set)

[PEP_DPM_REGISTER_COMPONENT_PERF_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_component_perf_states)

[PEP_REGISTER_COMPONENT_PERF_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_component_perf_states)