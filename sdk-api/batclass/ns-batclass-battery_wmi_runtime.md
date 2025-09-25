# BATTERY_WMI_RUNTIME structure

## Description

Defines information about the estimated runtime of a battery for use with the [BatteryClassQueryWmiDataBlock](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassquerywmidatablock) function.

## Members

### `Tag`

A tag that identifies a specific battery.

### `EstimatedRuntime`

Specifies the estimated battery run time, in seconds.

This calculation may be based on the present rate of drain and not be very accurate on some battery systems. The estimate may vary widely depending on present power usage, which could be affected by disk activity and other factors. BATTERY_UNKNOWN_TIME is returned when no estimate is available.

## See also

[BatteryClassQueryWmiDataBlock](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassquerywmidatablock)