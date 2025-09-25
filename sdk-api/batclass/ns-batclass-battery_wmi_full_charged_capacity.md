# BATTERY_WMI_FULL_CHARGED_CAPACITY structure

## Description

Defines information about the capacity of a battery for use with the [BatteryClassQueryWmiDataBlock](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassquerywmidatablock))

## Members

### `Tag`

A tag that identifies a specific battery.

### `FullChargedCapacity`

The current fully charged capacity, measured for example in milliwatt-hours, of a battery. If BATTERY_CAPACITY_RELATIVE is set, the units are undefined. For more information see the [BATTERY_INFORMATION](https://learn.microsoft.com/previous-versions/ff536283(v=vs.85)).

## See also

[BatteryClassQueryWmiDataBlock](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassquerywmidatablock)