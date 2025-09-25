# PROCESSOR_POWER_POLICY_INFO structure

## Description

Contains information about processor C-state policy settings. This structure is part of the
[PROCESSOR_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_power_policy) structure.

## Members

### `TimeCheck`

The time that must expire before promotion or demotion is considered, in microseconds.

### `DemoteLimit`

The minimum amount of time that must be spent in the idle loop to avoid demotion, in microseconds.

### `PromoteLimit`

The time that must be exceeded to cause promotion to a deeper idle state, in microseconds.

### `DemotePercent`

The value that scales the threshold at which the power policy manager decreases the performance of the processor, expressed as a percentage.

### `PromotePercent`

The value that scales the threshold at which the power policy manager increases the performance of the processor, expressed as a percentage.

### `Spare`

Reserved.

### `AllowDemotion`

When set, allows the kernel power policy manager to demote from the current state.

### `AllowPromotion`

When set, allows the kernel power policy manager to promote from the current state.

### `Reserved`

Reserved.

## See also

[PROCESSOR_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_power_policy)