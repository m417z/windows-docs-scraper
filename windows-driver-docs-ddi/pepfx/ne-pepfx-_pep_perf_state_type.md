# _PEP_PERF_STATE_TYPE enumeration (pepfx.h)

## Description

The **PEP_PERF_STATE_TYPE** enumeration indicates the type of performance information that is specified for a performance state (P-state) of a component.

## Constants

### `PepPerfStateTypeDiscrete`

The performance information is specified as a set of discrete values.

### `PepPerfStateTypeRange`

The performance information is specified as a range of values.

### `PepPerfStateTypeMax`

Reserved for use by operating system.

## Remarks

The **Type** member of the [PEP_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_component_perf_set) structure is a **PEP_PERF_STATE_TYPE** enumeration value.

## See also

[PEP_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_component_perf_set)