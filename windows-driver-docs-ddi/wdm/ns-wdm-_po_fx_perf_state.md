## Description

The **PO_FX_PERF_STATE** structure represents a performance state for a single component within a device.

## Members

### `Value`

The value of this performance state. The units are specified by the **Unit** member of the [**PO_FX_COMPONENT_PERF_SET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_set) that contains this performance state. For example, if **Value** is 100000000 and the **Unit** member of the **PO_FX_COMPONENT_PERF_SET** is **PoFxPerfStateUnitFrequency**, this performance state represents 100 MHz.

### `Context`

A pointer to additional context for the performance state that cannot be presented by the **Value** member. This data can be shared between the driver and the platform extension plug-in (PEP).

Using the **Context** member can hinder the visualization of performance states in Windows Performance Analyzer.

## Remarks

The **States** member of the [**PO_FX_COMPONENT_PERF_SET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_set) structure contains an array of **PO_FX_PERF_STATE** elements.

## See also

[Device Performance State Management](https://learn.microsoft.com/windows-hardware/drivers/kernel/component-level-performance-management)

[**PO_FX_COMPONENT_PERF_SET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_set)

[PO_FX_PERF_STATE_UNIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_po_fx_perf_state_unit)

[PoFxRegisterComponentPerfStates](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregistercomponentperfstates)