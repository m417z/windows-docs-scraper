# ReadLogRecord function

## Description

Initiates a sequence of reads from a specified log sequence number (LSN) in one of three modes, and returns the first of the specified log records and a read context. A client can read subsequent records in the designated mode by passing the read context to [ReadNextLogRecord](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-readnextlogrecord).

## Parameters

### `pvMarshal` [in]

A pointer to a marshaling context that is allocated by using the [CreateLogMarshallingArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogmarshallingarea) function.

### `plsnFirst` [in]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure that specifies the log sequence number (LSN) of the record where the read operation should start.

This value must be an LSN of a valid record in the active range of the log.

### `eContextMode` [in]

The mode for the read context that is returned in **ppvReadContext*.

The following table identifies the three mutually exclusive read modes.

| Value | Meaning |
| --- | --- |
| **ClfsContextPrevious** | Reads the record linked to by *plsnPrevious*. |
| **ClfsContextUndoNext** | Reads the record chain linked to by *plsnUndoNext*. |
| **ClfsContextForward** | Reads the record with the LSN that immediately follows the current LSN in the read context. |

### `ppvReadBuffer` [out]

A pointer to a variable that receives a pointer to the target record in the log I/O block.

### `pcbReadBuffer` [out]

A pointer to a variable that receives the size of the data that is returned in **ppvReadBuffer*, in bytes.

### `peRecordType` [out]

A pointer to a variable that receives the type of record read.

This parameter is one of the [CLFS_RECORD_TYPE Constants](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/clfs-record-type-constants).

### `plsnUndoNext` [out]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure that receives the LSN of the next record in the undo record chain.

### `plsnPrevious` [out]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure that receives the LSN of the next record in the previous record chain.

### `ppvReadContext` [out]

A pointer to a variable that receives a pointer to a system-allocated read context when a read is successful.

If the function defers completion of an operation, it returns a valid read-context pointer and an error status of **ERROR_IO_PENDING**. On all other errors, the read-context pointer is **NULL**. For more information about handling deferred completion of the function, see the Remarks section of this topic.

After obtaining all requested log records, the client must pass the read context to [TerminateReadLog](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-terminatereadlog) to free the associated memory. Failure to do so results in memory leakage.

**Note** Common Log File System (CLFS) read contexts are not thread-safe. They should not be used by more than one thread at a time, or passed into more than one asynchronous read at a time.

### `pOverlapped` [in, out, optional]

A pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure, which is required for asynchronous operation.

 This parameter can be **NULL** if asynchronous operation is not used.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following list identifies the possible error codes.

## Remarks

The error message ERROR_LOG_BLOCK_INCOMPLETE is returned if the log block size specified by [CreateLogMarshallingArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogmarshallingarea) is not large enough to hold a complete log block.

If **ReadLogRecord** is called with a valid *pOverlapped* structure and the log handle is created with the overlapped option, then if a call to this function fails with an error code of **ERROR_IO_PENDING**, a pointer to a valid read context is placed in the variable that is pointed to by the *ppvReadContext* parameter.

If you attempt to open more read contexts than the number buffers specified in a previous call to [CreateLogMarshallingArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogmarshallingarea), ERROR_LOG_BLOCK_EXHAUSTED is returned.

To complete a log-record copy, the client should first synchronize its execution with deferred completion of the overlapped I/O operation by using [GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) or one of the synchronization [Wait Functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions). For more information, see [Synchronization and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output).

After **ReadLogRecord** completes asynchronously, the requested record is read from the disk, but is not resolved to a pointer in **ppvReadBuffer*.

To complete the requested read and obtain a valid pointer to the log record, the client must call [ReadNextLogRecord](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-readnextlogrecord), which passes in the read-context pointer that **ReadLogRecord** returns.

**Note** Common Log File System (CLFS) read contexts are not thread-safe. They should not be used by more than one thread at a time.

CLFS read contexts should not be passed into more than one asynchronous read at a time, or the function fails with ERROR_BUSY.

## See also

[CLFS_CONTEXT_MODE](https://learn.microsoft.com/windows/desktop/api/clfs/ne-clfs-clfs_context_mode)

[CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn)

[CLFS_RECORD_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/clfs-record-type-constants)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[CreateLogMarshallingArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogmarshallingarea)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[ReadNextLogRecord](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-readnextlogrecord)

[TerminateReadLog](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-terminatereadlog)