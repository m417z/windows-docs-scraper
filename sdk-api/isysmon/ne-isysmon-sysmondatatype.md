# SysmonDataType enumeration

## Description

Determines the type of data to return from a given data point on the graph.

## Constants

### `sysmonDataAvg:1`

Average value of the counter.

### `sysmonDataMin:2`

Minimum value of the counter.

### `sysmonDataMax:3`

Maximum value of the counter.

### `sysmonDataTime:4`

Date and time that the counter value was collected. If SYSMON compresses more than one sample into the counter value, the date and time are from the last sample.

### `sysmonDataCount:5`

Number of samples that were compressed into the data point.

## See also

[CounterItem.GetDataAt](https://learn.microsoft.com/windows/desktop/SysMon/counteritem-getdataat)