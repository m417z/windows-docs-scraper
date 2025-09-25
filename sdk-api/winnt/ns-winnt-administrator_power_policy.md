# ADMINISTRATOR_POWER_POLICY structure

## Description

Represents the administrator override power policy settings.

## Members

### `MinSleep`

The minimum system power sleep state. This member must be one of the
[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-system_power_state) enumeration type values between
**PowerSystemSleeping1** (power state S1) and
**PowerSystemHibernate** (power state S4).

### `MaxSleep`

The maximum system power sleep state. This member must be one of the
[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-system_power_state) enumeration type values between
**PowerSystemSleeping1** (power state S1) and
**PowerSystemHibernate** (power state S4).

### `MinVideoTimeout`

The minimum allowable video idle time-out before turning the display device off, in seconds.

### `MaxVideoTimeout`

The maximum allowable video idle time-out before turning the display device off, in seconds.

### `MinSpindownTimeout`

The minimum allowable disk idle time before flushing the cache manager and spinning down a hard disk
device, in seconds.

### `MaxSpindownTimeout`

The maximum allowable disk idle time before flushing the cache manager and spinning down a hard disk
device, in seconds.

## Remarks

The **ADMINISTRATOR_POWER_POLICY**
structure defines limits to certain power policy values that are applied globally to all users' power schemes. The
values in the **ADMINISTRATOR_POWER_POLICY**
structure override any settings selected by the user in the Power Options control panel program.

To set an administrator override policy, call the
[CallNtPowerInformation](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-callntpowerinformation) function.

## See also

[CallNtPowerInformation](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-callntpowerinformation)