# SYSTEM_POWER_POLICY structure

## Description

Contains information about the current system power policy.

## Members

### `Revision`

The current structure revision.

### `PowerButton`

A
[POWER_ACTION_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-power_action_policy) structure that defines the system power action to initiate when the system power button is pressed.

### `SleepButton`

A
[POWER_ACTION_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-power_action_policy) structure that defines the system power action to initiate when the system sleep button is pressed.

### `LidClose`

A
[POWER_ACTION_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-power_action_policy) structure that defines the system power action to initiate when the system lid switch is closed.

### `LidOpenWake`

The maximum power state (highest Sx value) from which a lid-open event should wake the system. This member must be one of the
[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-system_power_state) enumeration type values.

### `Reserved`

Reserved.

### `Idle`

A
[POWER_ACTION_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-power_action_policy) structure that defines the system power action to initiate when the system idle timer expires.

### `IdleTimeout`

The time that the level of system activity must remain below the idle detection threshold before the system idle timer expires, in seconds.

### `IdleSensitivity`

The level of system activity that defines the threshold for idle detection, expressed as a percentage.

### `DynamicThrottle`

The current system processor dynamic throttling policy. This member must be one of the values described in
[Processor Performance Control Policy Constants](https://learn.microsoft.com/windows/desktop/Power/processor-performance-control-policy-constants).

### `Spare2`

Reserved.

### `MinSleep`

The minimum system sleep state (lowest Sx value) currently supported. This member must be one of the
[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-system_power_state) enumeration type values.

### `MaxSleep`

The maximum system sleep state (highest Sx value) currently supported. This member must be one of the
[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-system_power_state) enumeration type values.

### `ReducedLatencySleep`

The system power state (Sx value) to enter on a system sleep action when there are outstanding latency requirements. This member must be one of the
[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-system_power_state) enumeration type values. If an application calls
[RequestWakeupLatency](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-requestwakeuplatency) with LT_LOWEST_LATENCY, **ReducedLatencySleep** will be used in place of **MaxSleep**.

### `WinLogonFlags`

This member can be zero or WINLOGON_LOCK_ON_SLEEP (0x00000001).

### `Spare3`

Reserved.

### `DozeS4Timeout`

The time to wait between entering the suspend state and entering the hibernate sleeping state, in seconds. A value of zero indicates never hibernate.

### `BroadcastCapacityResolution`

The resolution of change in current battery capacity that should cause the system to be notified of a system power state changed event.

### `DischargePolicy`

An array of
[SYSTEM_POWER_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_power_level) structures that defines the actions to take at system battery discharge events.

### `VideoTimeout`

The time before the display is turned off, in seconds.

### `VideoDimDisplay`

If this member is **TRUE**, the system includes support for display dimming.

### `VideoReserved`

Reserved.

### `SpindownTimeout`

The time before power to fixed disk drives is turned off, in seconds.

### `OptimizeForPower`

If this member is **TRUE**, the system will turn on cooling fans and run the processor at full speed when passive cooling is specified. This causes the operating system to be biased toward using the fan and running the processor at full speed.

### `FanThrottleTolerance`

The lower limit that the processor may be throttled down to prior to turning on system fans in response to a thermal event, expressed as a percentage.

### `ForcedThrottle`

The processor throttle level to be imposed by the system, expressed as a percentage.

### `MinThrottle`

The minimum processor throttle level, expressed as a percentage.

### `OverThrottled`

A
[POWER_ACTION_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-power_action_policy) structure that defines the system power action to initiate in response to a thermal event when processor throttling is unable to adequately reduce the system temperature.

## See also

[CallNtPowerInformation](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-callntpowerinformation)

[POWER_ACTION_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-power_action_policy)

[SYSTEM_POWER_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_power_level)