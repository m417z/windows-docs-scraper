# CLFS_IOSTATS_CLASS enumeration

## Description

Defines types of I/O statistics reported by CLFS and is used when a client calls [GetLogIoStatistics](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-getlogiostatistics). Currently, log flush rates are the only type of statistic reported, but this enumeration will reflect more types of statistics in the future.

## Constants

### `ClfsIoStatsDefault:0x0000`

The default I/O statistics exported.

### `ClfsIoStatsMax:0xFFFF`

The log flush rate.

## See also

[GetLogIoStatistics](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-getlogiostatistics)