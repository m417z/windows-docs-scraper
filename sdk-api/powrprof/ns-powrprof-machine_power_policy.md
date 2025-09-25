# MACHINE_POWER_POLICY structure

## Description

Contains computer power policy settings that are unique to each power scheme on the computer. This structure is part of the
[POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-power_policy) structure.

## Members

### `Revision`

The current structure revision level. Set this value by calling [GetCurrentPowerPolicies](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-getcurrentpowerpolicies) or [ReadPwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-readpwrscheme) before using a **MACHINE_POWER_POLICY** structure to set power policy.

### `MinSleepAc`

The minimum system power state (lowest Sx value) to enter on a system sleep action when running on AC power. This member must be one of the
[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-system_power_state) enumeration type values.

### `MinSleepDc`

The minimum system power state (lowest Sx value) to enter on a system sleep action when running on battery power. This member must be one of the
[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-system_power_state) enumeration type values.

### `ReducedLatencySleepAc`

The maximum system power state (highest Sx value) to enter on a system sleep action when running on AC power, and when there are outstanding latency requirements. This member must be one of the
[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-system_power_state) enumeration type values. If an application calls
[RequestWakeupLatency](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-requestwakeuplatency) with LT_LOWEST_LATENCY, **ReducedLatencySleepAc** is used in place of **MaxSleepAc**.

### `ReducedLatencySleepDc`

The maximum system power state (highest Sx value) to enter on a system sleep action when running on battery power, and when there are outstanding latency requirements. This member must be one of the
[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-system_power_state) enumeration type values. If an application calls
[RequestWakeupLatency](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-requestwakeuplatency) with LT_LOWEST_LATENCY, **ReducedLatencySleepAc** is used in place of **MaxSleepAc**.

### `DozeTimeoutAc`

This member is ignored.

### `DozeTimeoutDc`

This member is ignored.

### `DozeS4TimeoutAc`

Time to wait between entering the suspend state and entering the hibernate sleeping state when the system is running on AC power, in seconds. A value of zero indicates never hibernate.

### `DozeS4TimeoutDc`

Time to wait between entering the suspend state and entering the hibernate sleeping state when the system is running on battery power, in seconds. A value of zero indicates never hibernate.

### `MinThrottleAc`

The minimum throttle setting allowed before being overthrottled when the system is running on AC power. Thermal conditions would be the only reason for going below the minimum setting. When the processor is overthrottled, the system will initiate the **OverThrottledAc** policy. Note that the power policy manager has a hard-coded policy to initiate a CriticalShutdownOff whenever any thermal zone indicates a critical thermal condition. Range: 0-100.

### `MinThrottleDc`

The minimum throttle setting allowed before being overthrottled when the system is running on battery power. Thermal conditions would be the only reason for going below the minimum setting. When the processor is overthrottled, the system will initiate the **OverThrottledDc** policy. Note that the power policy manager has a hard-coded policy to initiate a CriticalShutdownOff whenever any thermal zone indicates a critical thermal condition. Range: 0-100.

### `pad1`

Reserved.

### `OverThrottledAc`

A
[POWER_ACTION_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-power_action_policy) structure that defines the action to take when a processor has become overthrottled (as defined by the **MinThrottleAc** member) when the system is running on AC power.

### `OverThrottledDc`

A
[POWER_ACTION_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-power_action_policy) structure that defines the action to take when a processor has become overthrottled (as defined by the **MinThrottleDc** member) when the system is running on battery power.

## Remarks

**DozeS4TimeoutAc** and **DozeS4TimeoutDc** correspond to the **DozeS4Timeout** member of [SYSTEM_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_power_policy). These values are merged from the machine power policy to the system power policy when the [SetActivePwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-setactivepwrscheme) function is called to apply a power scheme.

## See also

[POWER_ACTION_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-power_action_policy)

[POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-power_policy)