# CLS_IO_STATISTICS_HEADER structure

## Description

Header for information retrieved by the [GetLogIoStatistics](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-getlogiostatistics) function, which defines the I/O performance counters of a log.

## Members

### `ubMajorVersion`

The major version of the statistics buffer.

### `ubMinorVersion`

The minor version of the statistics buffer.

### `eStatsClass`

The class of I/O statistics that is exported. Currently, flush statistics are the only statistics information exported. These statistics include the frequency of data and metadata flushes on a dedicated log and the amount of data and metadata flushed. Because flush statistics are the sole statistics class, this member is currently unused but will be used in the future.

### `cbLength`

The length of the statistics buffer, including the header.

### `coffData`

The offset of statistics counters from the beginning of the packet where the statistics data begins. This field allows transparent modifications to the header and length without affecting how the statistics data is accessed.

## Remarks

This header is followed by the I/O statistics counters.

## See also

[CLFS_IOSTATS_CLASS](https://learn.microsoft.com/windows/desktop/api/clfs/ne-clfs-clfs_iostats_class)

[CLFS_IO_STATISTICS](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_io_statistics)

[GetLogIoStatistics](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-getlogiostatistics)