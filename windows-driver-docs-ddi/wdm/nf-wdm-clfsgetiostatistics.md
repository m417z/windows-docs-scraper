# ClfsGetIoStatistics function

## Description

The **ClfsGetIoStatistics** routine returns I/O statistics for a specified CLFS log.

## Parameters

### `plfoLog` [in]

A pointer to a [LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents a CLFS stream. The I/O statistics will be collected for the stream's underlying log on stable storage. The caller previously obtained this pointer by calling [ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile).

### `pvStatsBuffer` [in, out]

A pointer to a [CLFS_IO_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_io_statistics) structure that receives the I/O statistics data.

### `cbStatsBuffer` [in]

The size, in bytes, of the buffer pointed to by *pvStatsBuffer*. This parameter must be at least **sizeof**([CLFS_IO_STATISTICS_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_io_statistics_header)). If this parameter is less than **sizeof**(**CLFS_IO_STATISTICS**), *pvStatsBuffer* will receive only a portion of the available I/O statistics.

### `eStatsClass` [in]

This parameter is reserved for future use.

### `pcbStatsWritten` [out, optional]

A pointer to a ULONG-typed variable that receives the number of bytes actually written to *pvStatsBuffer*. This parameter can be **NULL**.

## Return value

**ClfsGetIoStatistics** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile)