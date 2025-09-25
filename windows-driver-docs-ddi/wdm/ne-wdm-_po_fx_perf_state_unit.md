# _PO_FX_PERF_STATE_UNIT enumeration

## Description

The **PO_FX_PERF_STATE_UNIT** enumeration contains values that describe the type of unit that is controlled by the performance states in a [PO_FX_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_set).

## Constants

### `PoFxPerfStateUnitOther`

Indicates that the performance states control a unit other than frequency or bandwidth.

### `PoFxPerfStateUnitFrequency`

Indicates that the performance states control frequency, measured in Hz.

### `PoFxPerfStateUnitBandwidth`

Indicates that the performance states control bandwidth, measured in bits per second.

### `PoFxPerfStateUnitMaximum`

This value is reserved for system use.

## Remarks

The **Unit** member of the [PO_FX_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_set) structure is a value from the **PO_FX_PERF_STATE_UNIT** enumeration.

## See also

[PO_FX_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_perf_set)

[PoFxRegisterComponentPerfStates](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregistercomponentperfstates)