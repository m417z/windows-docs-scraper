# SYSTEM_BATTERY_STATE structure

## Description

Contains information about the current state of the system battery.

## Members

### `AcOnLine`

If this member is **TRUE**, the system battery charger is currently operating on external
power.

### `BatteryPresent`

If this member is **TRUE**, at least one battery is present in the system.

### `Charging`

If this member is **TRUE**, a battery is currently charging.

### `Discharging`

If this member is **TRUE**, a battery is currently discharging.

### `Spare1`

Reserved.

### `Tag`

### `MaxCapacity`

The theoretical capacity of the battery when new.

### `RemainingCapacity`

The estimated remaining capacity of the battery.

### `Rate`

The current rate of discharge of the battery, in mW. A nonzero, positive rate indicates charging; a
negative rate indicates discharging. Some batteries report only discharging rates. This value should be treated
as a **LONG** as it can contain negative values (with the high bit set).

### `EstimatedTime`

The estimated time remaining on the battery, in seconds.

### `DefaultAlert1`

The manufacturer's suggestion of a capacity, in mWh, at which a low battery alert should occur. Definitions
of low vary from manufacturer to manufacturer. In general, a warning state will occur before a low state, but
you should not assume that it always will. To reduce risk of data loss, this value is usually used as the
default setting for the critical battery alarm.

### `DefaultAlert2`

The manufacturer's suggestion of a capacity, in mWh, at which a warning battery alert should occur.
Definitions of warning vary from manufacturer to manufacturer. In general, a warning state will occur before a
low state, but you should not assume that it always will. To reduce risk of data loss, this value is usually
used as the default setting for the low battery alarm.

## See also

[CallNtPowerInformation](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-callntpowerinformation)