# GLOBAL_USER_POWER_POLICY structure

## Description

Contains global user power policy settings that apply to all power schemes for a user. This structure is part of the
[GLOBAL_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-global_power_policy) structure.

## Members

### `Revision`

The current structure revision level. Set this value by calling [GetCurrentPowerPolicies](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-getcurrentpowerpolicies) or [ReadGlobalPwrPolicy](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-readglobalpwrpolicy) before using a **GLOBAL_USER_POWER_POLICY** structure to set power policy.

### `PowerButtonAc`

A
[POWER_ACTION_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-power_action_policy) structure that defines the action to take when the power button is pressed and the system is running on AC power.

### `PowerButtonDc`

A
[POWER_ACTION_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-power_action_policy) structure that defines the action to take when the power button is pressed and the system is running on battery power.

### `SleepButtonAc`

A
[POWER_ACTION_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-power_action_policy) structure that defines the action to take when the sleep button is pressed and the system is running on AC power.

### `SleepButtonDc`

A
[POWER_ACTION_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-power_action_policy) structure that defines the action to take when the sleep button is pressed and the system is running on battery power.

### `LidCloseAc`

A
[POWER_ACTION_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-power_action_policy) structure that defines the action to take when the lid is closed and the system is running on AC power.

### `LidCloseDc`

A
[POWER_ACTION_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-power_action_policy) structure that defines the action to take when the lid is closed and the system is running on battery power.

### `DischargePolicy`

An array of
[SYSTEM_POWER_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_power_level) structures that defines the actions to take at system battery discharge events.

### `GlobalFlags`

A flag that enables or disables miscellaneous user power policy settings. This member can be one or more of the values described in
[Global Flags Constants](https://learn.microsoft.com/windows/desktop/Power/global-flags-constants).

## See also

[GLOBAL_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-global_power_policy)

[POWER_ACTION_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-power_action_policy)

[SYSTEM_POWER_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_power_level)