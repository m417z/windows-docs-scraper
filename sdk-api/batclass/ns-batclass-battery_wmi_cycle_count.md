# BATTERY_WMI_CYCLE_COUNT structure

## Description

Defines information about number of charge cycles of a battery for use with the [BatteryClassQueryWmiDataBlock](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassquerywmidatablock) function.

## Members

### `Tag`

A tag that identifies a specific battery.

### `CycleCount`

The number of charge/discharge cycles the battery has experienced, or zero if the battery does not support a cycle counter.

## See also

[BatteryClassQueryWmiDataBlock](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassquerywmidatablock)