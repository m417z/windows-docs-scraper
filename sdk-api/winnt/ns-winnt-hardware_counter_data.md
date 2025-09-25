# HARDWARE_COUNTER_DATA structure

## Description

Contains the hardware counter value.

## Members

### `Type`

The type of hardware counter data collected. For possible values, see the [HARDWARE_COUNTER_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-hardware_counter_type) enumeration.

### `Reserved`

Reserved. Initialize to zero.

### `Value`

The counter index. Each hardware counter in a processor's performance monitoring unit (PMU) is identified by an index.

## Remarks

This structure is a member of the [PERFORMANCE_DATA](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-performance_data) structure.

## See also

[PERFORMANCE_DATA](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-performance_data)