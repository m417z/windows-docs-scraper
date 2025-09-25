# SYSTEM_POWER_CAPABILITIES structure

## Description

Contains information about the power capabilities of the system.

## Members

### `PowerButtonPresent`

If this member is **TRUE**, there is a system power button.

### `SleepButtonPresent`

If this member is **TRUE**, there is a system sleep button.

### `LidPresent`

If this member is **TRUE**, there is a lid switch.

### `SystemS1`

If this member is **TRUE**, the operating system supports [sleep state S1](https://learn.microsoft.com/windows/desktop/Power/system-power-states).

### `SystemS2`

If this member is **TRUE**, the operating system supports [sleep state S2](https://learn.microsoft.com/windows/desktop/Power/system-power-states).

### `SystemS3`

If this member is **TRUE**, the operating system supports [sleep state S3](https://learn.microsoft.com/windows/desktop/Power/system-power-states).

### `SystemS4`

If this member is **TRUE**, the operating system supports [sleep state S4](https://learn.microsoft.com/windows/desktop/Power/system-power-states) (hibernation).

### `SystemS5`

If this member is **TRUE**, the operating system supports [power off state S5](https://learn.microsoft.com/windows/desktop/Power/system-power-states) (soft off).

### `HiberFilePresent`

If this member is **TRUE**, the system hibernation file is present.

### `FullWake`

If this member is **TRUE**, the system supports wake capabilities.

### `VideoDimPresent`

If this member is **TRUE**, the system supports video display dimming
capabilities.

### `ApmPresent`

If this member is **TRUE**, the system supports APM BIOS power management
features.

### `UpsPresent`

If this member is **TRUE**, there is an uninterruptible power supply
(UPS).

### `ThermalControl`

If this member is **TRUE**, the system supports thermal zones.

### `ProcessorThrottle`

If this member is **TRUE**, the system supports processor throttling.

### `ProcessorMinThrottle`

The minimum level of system processor throttling supported, expressed as a percentage.

### `ProcessorThrottleScale`

### `spare2`

### `ProcessorMaxThrottle`

The maximum level of system processor throttling supported, expressed as a percentage.

### `FastSystemS4`

If this member is **TRUE**, the system supports the [hybrid sleep state](https://learn.microsoft.com/windows/desktop/Power/system-power-states).

### `Hiberboot`

### `WakeAlarmPresent`

If this member is **TRUE**, the platform has support for ACPI wake alarm devices. For more details on wake alarm devices, please see the ACPI specification section 9.18.

### `AoAc`

If this member is **TRUE**, the system supports the S0 low power idle model.

### `DiskSpinDown`

If this member is **TRUE**, the system supports allowing the removal of power to
fixed disk devices.

### `HiberFileType`

### `AoAcConnectivitySupported`

### `spare3`

Reserved.

### `SystemBatteriesPresent`

If this member is **TRUE**, there are one or more batteries in the system.

### `BatteriesAreShortTerm`

If this member is **TRUE**, the system batteries are short-term. Short-term batteries
are used in uninterruptible power supplies (UPS).

### `BatteryScale`

A [BATTERY_REPORTING_SCALE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-battery_reporting_scale) structure
that contains information about how system battery metrics are reported.

### `AcOnLineWake`

The lowest [system sleep state](https://learn.microsoft.com/windows/desktop/Power/system-power-states) (Sx) that will generate a wake event when the system is on AC power. This
member must be one of the [SYSTEM_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-system_power_state)
enumeration type values.

### `SoftLidWake`

The lowest [system sleep state](https://learn.microsoft.com/windows/desktop/Power/system-power-states) (Sx) that will generate a wake event via the lid switch. This member must be
one of the [SYSTEM_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-system_power_state) enumeration
type values.

### `RtcWake`

The lowest [system sleep state](https://learn.microsoft.com/windows/desktop/Power/system-power-states) (Sx) supported by hardware that will generate a wake event via the Real Time Clock (RTC). This
member must be one of the
[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-system_power_state) enumeration type
values.

To wake the computer using the RTC, the operating system must also support waking from the sleep state the computer is in when the RTC generates the wake event. Therefore, the effective lowest sleep state from which an RTC wake event can wake the computer is the lowest sleep state supported by the operating system that is equal to or higher than the value of **RtcWake**. To determine the sleep states that the operating system supports, check the **SystemS1**, **SystemS2**, **SystemS3**, and **SystemS4** members.

### `MinDeviceWakeState`

The minimum allowable [system power state](https://learn.microsoft.com/windows/desktop/Power/system-power-states) supporting wake events. This member must be one of the
[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-system_power_state) enumeration type
values. Note that this state may change as different device drivers are installed on the system.

### `DefaultLowLatencyWake`

The default [system power state](https://learn.microsoft.com/windows/desktop/Power/system-power-states) used if an application calls
[RequestWakeupLatency](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-requestwakeuplatency) with
**LT_LOWEST_LATENCY**. This member must be one of the
[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-system_power_state) enumeration type
values.

### `HiberBoot`

If this member is set to **TRUE**, the system is currently capable of performing a fast startup transition. This setting is based on whether the machine is capable of hibernate, whether the machine currently has hibernate enabled (hiberfile exists), and the local and group policy settings for using hibernate (including the Hibernate option in the Power control panel).

## See also

[CallNtPowerInformation](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-callntpowerinformation)

[System Power States](https://learn.microsoft.com/windows/desktop/Power/system-power-states)