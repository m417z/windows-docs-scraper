# CLS_IO_STATISTICS structure

## Description

Defines the statistics that are reported by [GetLogIoStatistics](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-getlogiostatistics). Initially, statistics packets report only flush statistics, including the frequency of data and metadata flushes on a physical log and the amount of data and metadata flushed. The flush statistics are defined by the following I/O statistics packet types.

## Members

### `hdrIoStats`

The header for the statistics buffer.

### `cFlush`

The frequency of data flushes for the logging session.

### `cbFlush`

The cumulative number of bytes of data flushed in the logging session.

### `cMetaFlush`

The frequency of metadata flushes for the logging session.

### `cbMetaFlush`

The cumulative number of bytes of metadata flushed in the logging session.

## See also

[CLFS_IO_STATISTICS_HEADER](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_io_statistics_header)

[GetLogIoStatistics](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-getlogiostatistics)