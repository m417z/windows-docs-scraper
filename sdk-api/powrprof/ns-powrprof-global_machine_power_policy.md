# GLOBAL_MACHINE_POWER_POLICY structure

## Description

Contains global computer power policy settings that apply to all power schemes for all
users. This structure is part of the
[GLOBAL_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-global_power_policy) structure.

## Members

### `Revision`

The current structure revision level. Set this value by calling
[GetCurrentPowerPolicies](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-getcurrentpowerpolicies) or
[ReadGlobalPwrPolicy](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-readglobalpwrpolicy) before using a
**GLOBAL_MACHINE_POWER_POLICY** structure
to set power policy.

### `LidOpenWakeAc`

The maximum power state (highest Sx value) from which a lid-open event should wake the system when running
on AC power. This member must be one of the
[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-system_power_state) enumeration type values. A value
of **PowerSystemUnspecified** indicates that a lid-open event does not wake the
system.

### `LidOpenWakeDc`

The maximum power state (highest Sx value) from which a lid-open event should wake the system when running
on battery. This member must be one of the
[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-system_power_state) enumeration type values. A value
of **PowerSystemUnspecified** indicates that a lid-open event does not wake the
system.

### `BroadcastCapacityResolution`

The resolution of change in the current battery capacity that should cause the system to be notified of a
system power state changed event.

## See also

[GLOBAL_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-global_power_policy)