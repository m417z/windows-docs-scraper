# _PO_FX_COMPONENT_PERF_SET structure

## Description

The **PO_FX_COMPONENT_PERF_SET** structure represents a set of performance states for a single component within a device.

## Members

### `Name`

An optional character string used to describe the component property controlled by the performance state set. For example, "Clock frequency" or "Memory bandwidth".

### `Flags`

Set to 0. Currently, no flags are defined for this member.

### `Unit`

A [PO_FX_PERF_STATE_UNIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_po_fx_perf_state_unit) value that specifies the type of unit that is controlled by the performance state set.

### `Type`

A [PO_FX_PERF_STATE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_po_fx_perf_state_type) value that specifies the type of performance states in the set (a discrete number of states or a continuous distribution of states between a minimum and maximum value).

### `Discrete`

For sets that represent a discrete number of performance states (that is, where the **Type** member is **PoFxPerfStateTypeDiscrete**), this nested structure describes the states.

### `Discrete.Count`

The number of performance states in the set.

### `Discrete.States`

A pointer to a [PO_FX_PERF_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_perf_state) array. The length of this array is specified by the **Count** member. Each array element describes one power state in the set.

### `Range`

For sets that represent a continuous distribution of performance states (that is, where the **Type** member is **PoFxPerfStateTypeRange**), this nested structure describes the minimum and maximum value of the range of performance states.

### `Range.Minimum`

The minimum performance state value.

### `Range.Maximum`

The maximum performance state value.

## Remarks

When a device driver calls the [PoFxRegisterComponentPerfStates](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregistercomponentperfstates) routine to register a component for performance state support with the power management framework (PoFx), the driver can supply a [PO_FX_COMPONENT_PERF_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_info) structure that describes the sets of the performance states supported by the component. The **PerfStateSets** member of the **PO_FX_COMPONENT_PERF_INFO** structure contains an array of **PO_FX_COMPONENT_PERF_SET** structures that represent the supported performance states.

Most drivers are expected to define a single set of performance states per component. For example, a driver might define one set of performance states to control the clock frequency for a component. However, some drivers may need to define more than one performance state set to control multiple dimensions of performance states for a component. For example, a driver might define two sets of performance states to control the clock frequency and bus bandwidth.

## See also

[Device Performance State Management](https://learn.microsoft.com/windows-hardware/drivers/kernel/component-level-performance-management)

[PO_FX_COMPONENT_PERF_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_info)

[PoFxRegisterComponentPerfStates](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregistercomponentperfstates)