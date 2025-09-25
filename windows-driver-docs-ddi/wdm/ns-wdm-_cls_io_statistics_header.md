# _CLS_IO_STATISTICS_HEADER structure

## Description

The **CLFS_IO_STATISTICS_HEADER** structure holds the header portion of a [CLFS_IO_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_io_statistics) structure.

## Members

### `ubMajorVersion`

The major version of the [CLFS_IO_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_io_statistics) structure.

### `ubMinorVersion`

The minor version of the **CLFS_IO_STATISTICS** structure.

### `eStatsClass`

Reserved for future use. This member is ignored.

### `cbLength`

The size, in bytes, of the **CLFS_IO_STATISTICS** structure, including the header.

### `coffData`

The offset, in bytes, from the beginning of the **CLFS_IO_STATISTICS** structure to the beginning of the statistics data. This member allows for transparent modifications to the header.

## See also

[CLFS_IO_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_io_statistics)

[ClfsGetIoStatistics](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsgetiostatistics)