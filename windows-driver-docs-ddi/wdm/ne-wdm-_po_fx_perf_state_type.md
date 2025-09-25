# _PO_FX_PERF_STATE_TYPE enumeration

## Description

The **PO_FX_PERF_STATE_TYPE** enumeration contains values that describe the type of performance states in a [PO_FX_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_set).

## Constants

### `PoFxPerfStateTypeDiscrete`

Indicates that the performance state set contains a discrete number of states.

### `PoFxPerfStateTypeRange`

Indicates that the performance state set contains a continuous distribution of states between a minimum and maximum value.

### `PoFxPerfStateTypeMaximum`

This value is reserved for system use.

## Remarks

The **Type** member of the [PO_FX_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_set) structure is a value from the **PO_FX_PERF_STATE_TYPE** enumeration.

## See also

[PO_FX_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_set)

[PoFxRegisterComponentPerfStates](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregistercomponentperfstates)