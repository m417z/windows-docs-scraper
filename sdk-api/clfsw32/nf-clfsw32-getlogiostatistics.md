# GetLogIoStatistics function

## Description

Retrieves log I/O statistics for a dedicated or multiplexed log that is associated with the specified handle. This function queries Common Log File System (CLFS) for specific types of log I/O statistics. Calling this function on a multiplexed log only associates the statistics with the underlying log.

## Parameters

### `hLog` [in]

A handle to an open log file that [CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile) gets. The log handle can refer to either a dedicated or multiplexed log file.

### `pvStatsBuffer` [in, out]

A pointer to a buffer to receive the I/O statistics.

This buffer must be at least as large as an I/O statistics packet header. For more information, see [CLFS_IO_STATISTICS_HEADER](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_io_statistics_header).

### `cbStatsBuffer` [in]

The size of the I/O statistics buffer *pvStatsBuffer*, in bytes.

If the buffer is not large enough for the statistics packet, the function fails with **ERROR_MORE_DATA**.

### `eStatsClass` [in]

This parameter is not implemented at this time; it is reserved for future use.

### `pcbStatsWritten` [out, optional]

A pointer to a variable to receive the size of the I/O statistics packet that is written to *pvStatsBuffer*.

This value is less than or equal to *cbStatsBuffer*.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following list identifies the possible error codes:

## See also

[CLFS_IOSTATS_CLASS](https://learn.microsoft.com/windows/desktop/api/clfs/ne-clfs-clfs_iostats_class)

[CLFS_IO_STATISTICS_HEADER](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_io_statistics_header)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)