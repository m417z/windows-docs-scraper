# SYSTEM_POWER_LEVEL structure

## Description

Contains information about system battery drain policy settings. This structure is part of the
[GLOBAL_USER_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-global_user_power_policy) structure.

## Members

### `Enable`

If this member is **TRUE**, the alarm should be activated when the battery discharges below the value set in **BatteryLevel**.

### `Spare`

Reserved.

### `BatteryLevel`

The battery capacity for this battery discharge policy, expressed as a percentage.

### `PowerPolicy`

A
[POWER_ACTION_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-power_action_policy) structure that defines the action to take for this battery discharge policy.

### `MinSystemState`

The minimum system sleep state to enter when the battery discharges below the value set in **BatteryLevel**. This member must be one of the
[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-system_power_state) enumeration type values.

## See also

[GLOBAL_USER_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-global_user_power_policy)

[POWER_ACTION_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-power_action_policy)