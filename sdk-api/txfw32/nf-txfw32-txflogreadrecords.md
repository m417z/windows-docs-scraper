# TxfLogReadRecords function

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Reads the redo records from the log.

## Parameters

### `TxfLogContext` [in]

A pointer to the context.

### `BufferLength` [in]

The size of the output buffer, in bytes.

### `Buffer` [out]

A pointer to the buffer that receives the records. For more information, see [TXF_LOG_RECORD_BASE](https://learn.microsoft.com/windows/desktop/api/txfw32/ns-txfw32-txf_log_record_base).

### `BytesUsed` [out]

The number of bytes written to the output buffer.

### `RecordCount` [out]

The number of records written to the output buffer.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible error codes include the
following.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The replication context is invalid. |
| **ERROR_MORE_DATA** | Some of the available records were copied into the buffer. Call this function again to retrieve the rest of the records. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer is not large enough to contain even one record. If *BytesUsed* is nonzero, then there was enough space to copy the [TXF_LOG_RECORD_BASE](https://learn.microsoft.com/windows/desktop/api/txfw32/ns-txfw32-txf_log_record_base) structure, which indicates the required buffer size to read the next complete record. |
| **ERROR_FILE_CORRUPT** | The format of the log file being processed is unrecognized. |

## See also

[TXF_LOG_RECORD_BASE](https://learn.microsoft.com/windows/desktop/api/txfw32/ns-txfw32-txf_log_record_base)