# USER_POWER_POLICY structure

## Description

Contains power policy settings that are unique to each power scheme for a user. This structure is part of the
[POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-power_policy) structure.

## Members

### `Revision`

The current structure revision level. Set this value by calling [GetCurrentPowerPolicies](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-getcurrentpowerpolicies) or [ReadPwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-readpwrscheme) before using a **USER_POWER_POLICY** structure to set power policy.

### `IdleAc`

A
[POWER_ACTION_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-power_action_policy) structure that defines the system power action to initiate when the system is running on AC (utility) power and the system idle timer expires.

### `IdleDc`

A
[POWER_ACTION_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-power_action_policy) structure that defines the system power action to initiate when the system is running on battery power and the system idle timer expires.

### `IdleTimeoutAc`

The time that the level of system activity must remain below the idle detection threshold before the system idle timer expires when running on AC (utility) power, in seconds.

This member is ignored if the system is performing an automated resume because there is no user present. To temporarily keep the system running while an application is performing a task, use the [SetThreadExecutionState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadexecutionstate) function.

### `IdleTimeoutDc`

The time that the level of system activity must remain below the idle detection threshold before the system idle timer expires when running on battery power, in seconds.

This member is ignored if the system is performing an automated resume because there is no user present. To temporarily keep the system running while an application is performing a task, use the [SetThreadExecutionState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadexecutionstate) function.

### `IdleSensitivityAc`

The level of system activity that defines the threshold for idle detection when the system is running on AC (utility) power, expressed as a percentage.

### `IdleSensitivityDc`

The level of system activity that defines the threshold for idle detection when the system is running on battery power, expressed as a percentage.

### `ThrottlePolicyAc`

The processor dynamic throttling policy to use when the system is running on AC (utility) power.

### `ThrottlePolicyDc`

The processor dynamic throttling policy to use when the system is running on battery power.

### `MaxSleepAc`

The maximum system sleep state when the system is running on AC (utility) power. This member must be one of the
[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-system_power_state) enumeration type values.

### `MaxSleepDc`

The maximum system sleep state when the system is running on battery power. This member must be one of the
[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-system_power_state) enumeration type values.

### `Reserved`

Reserved.

### `VideoTimeoutAc`

The time before the display is turned off when the system is running on AC (utility) power, in seconds.

### `VideoTimeoutDc`

The time before the display is turned off when the system is running on battery power, in seconds.

### `SpindownTimeoutAc`

The time before power to fixed disk drives is turned off when the system is running on AC (utility) power, in seconds.

### `SpindownTimeoutDc`

The time before power to fixed disk drives is turned off when the system is running on battery power, in seconds.

### `OptimizeForPowerAc`

If this member is **TRUE**, the system will turn on cooling fans and run the processor at full speed when passive cooling is specified and the system is running on AC (utility) power. This causes the operating system to be biased toward using the fan and running the processor at full speed.

### `OptimizeForPowerDc`

If this member is **TRUE**, the system will turn on cooling fans and run the processor at full speed when passive cooling is specified and the system is running on battery power. This causes the operating system to be biased toward using the fan and running the processor at full speed.

### `FanThrottleToleranceAc`

The lower limit that the processor may be throttled down to prior to turning on system fans in response to a thermal event while the system is operating on AC (utility) power, expressed as a percentage.

### `FanThrottleToleranceDc`

The lower limit that the processor may be throttled down to prior to turning on system fans in response to a thermal event while the system is operating on battery power, expressed as a percentage.

### `ForcedThrottleAc`

The processor throttle level to be imposed by the system while the computer is running on AC (utility) power, expressed as a percentage.

### `ForcedThrottleDc`

The processor throttle level to be imposed by the system while the computer is running on battery power, expressed as a percentage.

## See also

[POWER_ACTION_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-power_action_policy)

[POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-power_policy)