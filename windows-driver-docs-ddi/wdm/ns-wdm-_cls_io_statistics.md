# _CLS_IO_STATISTICS structure

## Description

The **CLFS_IO_STATISTICS** structure holds I/O statistics data for a Common Log File System (CLFS) log.

## Members

### `hdrIoStats`

A [CLFS_IO_STATISTICS_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_io_statistics_header) structure that holds header information for the set of statistics.

### `cFlush`

The number of data flushes.

### `cbFlush`

The number of bytes of data flushed.

### `cMetaFlush`

The number of metadata flushes.

### `cbMetaFlush`

The number of bytes of metadata flushed.

## See also

[CLFS_IO_STATISTICS_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_io_statistics_header)

[ClfsGetIoStatistics](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsgetiostatistics)