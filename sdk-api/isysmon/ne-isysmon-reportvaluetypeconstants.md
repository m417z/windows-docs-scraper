# ReportValueTypeConstants enumeration

## Description

Determines if the Histogram and Report views graph the last value sampled or a calculated value using values from the sampling period, such as the average or minimum value.

## Constants

### `sysmonDefaultValue:0`

The value displayed depends on the source of the counter data. If the source of the counter data is from the current activity of the computer, **sysmonCurrentValue** is used. If the source of the counter data is a log file, **sysmonAverage** is used.

### `sysmonCurrentValue:0x1`

The current value of the counter.

### `sysmonAverage:0x2`

The average value of the counter over the sampling period.

### `sysmonMinimum:0x3`

The minimum value of the counter over the sampling period.

### `sysmonMaximum:0x4`

The maximum value of the counter over the sampling period.

## See also

[SystemMonitor.ReportValueType](https://learn.microsoft.com/windows/desktop/SysMon/systemmonitor-reportvaluetype)