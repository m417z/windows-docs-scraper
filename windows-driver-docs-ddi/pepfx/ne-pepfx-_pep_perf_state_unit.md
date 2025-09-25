# _PEP_PERF_STATE_UNIT enumeration (pepfx.h)

## Description

The **PEP_PERF_STATE_UNIT** enumeration indicates the measurement units in which the performance state (P-state) of a component is specified.

## Constants

### `PepPerfStateUnitOther`

Some other type of measurement units not explicitly described by this enumeration.

### `PepPerfStateUnitFrequency`

Hertz (frequency units).

### `PepPerfStateUnitBandwidth`

Bits per second (bandwidth units).

### `PepPerfStateUnitMax`

Reserved for use by operating system.

## Remarks

The **Type** member of the [PEP_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_component_perf_set) structure is a **PEP_PERF_STATE_UNIT** enumeration value.

## See also

[PEP_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_component_perf_set)