# _PO_FX_PERF_STATE_CHANGE structure

## Description

The **PO_FX_PERF_STATE_CHANGE** structure contains information about a change to a performance state that is being requested by calling the [PoFxIssueComponentPerfStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxissuecomponentperfstatechange) or [PoFxIssueComponentPerfStateChangeMultiple](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxissuecomponentperfstatechangemultiple) routine.

## Members

### `Set`

The index of the performance state set that is being changed within the collection of performance state sets for the component.

### `StateIndex`

For sets that represent a discrete number of performance states (that is, where the **Type** member of the [PO_FX_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_set) is **PoFxPerfStateTypeDiscrete**), this member is the index of the performance state to use for the new performance level.

### `StateValue`

For sets that represent a continuous distribution of performance states (that is, where the **Type** member of the [PO_FX_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_set) is **PoFxPerfStateTypeRange**), this member is the value of the performance state to use for the new performance level.

## Remarks

The **PO_FX_PERF_STATE_CHANGE** structure is used for the *PerfChange* parameter of the [PoFxIssueComponentPerfStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxissuecomponentperfstatechange) routine and the *PerfChanges* parameter of the [PoFxIssueComponentPerfStateChangeMultiple](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxissuecomponentperfstatechangemultiple) routine.

## See also

[Device Performance State Management](https://learn.microsoft.com/windows-hardware/drivers/kernel/component-level-performance-management)

[PoFxIssueComponentPerfStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxissuecomponentperfstatechange)

[PoFxIssueComponentPerfStateChangeMultiple](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxissuecomponentperfstatechangemultiple)