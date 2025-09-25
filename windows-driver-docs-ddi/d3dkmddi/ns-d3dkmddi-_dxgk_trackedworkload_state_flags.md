# _DXGK_TRACKEDWORKLOAD_STATE_FLAGS structure

## Description

Indicates GPU configurations, including the appropriate frequencies and power level, for a context.

## Members

### `Saturated`

The driver should set this state flag if the driver cannot go higher than specified. This includes transient states like thermal limits.

### `OptimalLevel`

The driver should set this flag if for the given power level, we are in an optimal efficiency range for the tracked workload. The driver should set this flag only when, for certain workloads, lowering the frequency will reduce the performance per watt.

### `Reserved`

This value is reserved.

### `Value`

## Remarks

## See also