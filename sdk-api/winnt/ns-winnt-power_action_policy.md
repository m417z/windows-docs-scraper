# POWER_ACTION_POLICY structure

## Description

Contains information used to set the system power state.

## Members

### `Action`

The requested system power state. This member must be one of the
[POWER_ACTION](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-power_action) enumeration type values.

### `Flags`

A flag that controls how to switch the power state. This member can be one or more of the following
values.

| Value | Meaning |
| --- | --- |
| **POWER_ACTION_CRITICAL**<br><br>0x80000000 | Forces a critical suspension. |
| **POWER_ACTION_DISABLE_WAKES**<br><br>0x40000000 | Disables all wake events. |
| **POWER_ACTION_LIGHTEST_FIRST**<br><br>0x10000000 | Uses the first lightest available sleep state. |
| **POWER_ACTION_LOCK_CONSOLE**<br><br>0x20000000 | Requires entry of the system password upon resume from one of the system standby states. |
| **POWER_ACTION_OVERRIDE_APPS**<br><br>0x00000004 | Has no effect. |
| **POWER_ACTION_QUERY_ALLOWED**<br><br>0x00000001 | Has no effect. |
| **POWER_ACTION_UI_ALLOWED**<br><br>0x00000002 | Applications can prompt the user for directions on how to prepare for suspension. Sets bit 0 in the *Flags* parameter passed in the *lParam* parameter of [WM_POWERBROADCAST](https://learn.microsoft.com/windows/desktop/Power/wm-powerbroadcast). |

### `EventCode`

The level of user notification. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **POWER_FORCE_TRIGGER_RESET**<br><br>0x80000000 | Clears a user power button press. |
| **POWER_LEVEL_USER_NOTIFY_EXEC**<br><br>0x00000004 | Specifies a program to be executed. |
| **POWER_LEVEL_USER_NOTIFY_SOUND**<br><br>0x00000002 | User notified using sound. |
| **POWER_LEVEL_USER_NOTIFY_TEXT**<br><br>0x00000001 | User notified using the UI. |
| **POWER_USER_NOTIFY_BUTTON**<br><br>0x00000008 | Indicates that the power action is in response to a user power button press. |
| **POWER_USER_NOTIFY_SHUTDOWN**<br><br>0x00000010 | Indicates a power action of shutdown/off. |

## See also

[GLOBAL_USER_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-global_user_power_policy)

[MACHINE_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-machine_power_policy)

[USER_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-user_power_policy)

[WM_POWERBROADCAST](https://learn.microsoft.com/windows/desktop/Power/wm-powerbroadcast)