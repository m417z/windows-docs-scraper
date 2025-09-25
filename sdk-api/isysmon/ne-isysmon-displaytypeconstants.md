# DisplayTypeConstants enumeration

## Description

Determines how the performance counter data is graphed, for example, as a line graph or a histogram.

## Constants

### `sysmonLineGraph:1`

Counter values are displayed in a line graph. Each marker on the line graph represents a data value.

### `sysmonHistogram:2`

Counter values are displayed as a histogram.

### `sysmonReport:3`

Counter values are displayed in a report format. Only the current value for each counter is displayed.

### `sysmonChartArea:4`

Counter values are displayed as a line graph. The area between the line and the x-axis is shaded. You can only use this option if the source of the counter data is a log file.

### `sysmonChartStackedArea:5`

Counter values are displayed as a line graph. The line graph for each counter is stacked one upon the other. The area between the line and the x-axis or adjacent counter is shaded. You can only use this option if the source of the counter data is a log file.

If the sum of all the counter values exceeds the maximum scale value of the graph, SYSMON uses an appropriate scale value for each counter in order to fit the counters within the maximum scale value of the graph.

## Remarks

The following enumeration values were introduced in Windows Vista.

* **sysmonChartArea**
* **sysmonChartStackedArea**

## See also

[SystemMonitor.DisplayType](https://learn.microsoft.com/windows/desktop/SysMon/systemmonitor-displaytype)