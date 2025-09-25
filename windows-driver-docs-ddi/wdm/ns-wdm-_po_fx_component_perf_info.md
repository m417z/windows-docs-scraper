# _PO_FX_COMPONENT_PERF_INFO structure

## Description

The **PO_FX_COMPONENT_PERF_INFO** structure describes all the sets of performance states for a single component within a device.

## Members

### `PerfStateSetsCount`

The number of elements in the array **PerfStateSets** array.

### `PerfStateSets`

This member is the first element in an array of one or more [PO_FX_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_set) elements. Each **PO_FX_COMPONENT_PERF_SET** represents one set of supported performance states for a component. If the array contains more than one element, the additional elements immediately follow the first element.

## Remarks

When a device driver calls the [PoFxRegisterComponentPerfStates](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregistercomponentperfstates) routine to register a component for performance state support with the power management framework (PoFx), the driver can supply a **PO_FX_COMPONENT_PERF_INFO** structure that describes the sets of the performance states supported by the component. The **PerfStateSets** member of the **PO_FX_COMPONENT_PERF_INFO** structure contains an array of [PO_FX_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_set) structures that represent the supported performance states.

Most drivers are expected to define a single set of performance states per component. For example, a driver might define one set of performance states to control the clock frequency for a component. However, some drivers may need to define more than one performance state set to control multiple dimensions of performance states for a component. For example, a driver might define two sets of performance states to control the clock frequency and bus bandwidth.

## See also

[Component-Level Performance State Management](https://learn.microsoft.com/windows-hardware/drivers/kernel/component-level-performance-management)

[PO_FX_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_set)

[PoFxRegisterComponentPerfStates](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregistercomponentperfstates)