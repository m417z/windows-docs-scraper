# ReadNextLogRecord function

## Description

Reads the next record in a sequence that is initiated by a call to [ReadLogRecord](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-readlogrecord) or [ReadLogRestartArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-readlogrestartarea). By using **ReadNextLogRecord** iteratively, a client can read all records of a specified type in a log. The direction of enumeration is determined by specifying the context mode when beginning the read sequence.

## Parameters

### `pvReadContext` [in, out]

A pointer to a read context that the system allocates and creates during a successful call to [ReadLogRecord](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-readlogrecord) or [ReadLogRestartArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-readlogrestartarea).

If the function defers completion of an operation, it returns a pointer to a valid read context and an error status of **ERROR_IO_PENDING**. For information about handling asynchronous completion, see the Remarks section of this topic.

### `ppvBuffer` [out]

A pointer to a variable that receives a pointer to the read data.

### `pcbBuffer` [out]

A pointer to a variable that receives the size of the read data that is returned in *ppvReadBuffer*, in bytes.

### `peRecordType` [in, out]

A pointer that, on input, specifies the record type filter of the next record read, and on output specifies the record type that is returned.

Clients can specify any of the following record types.

| Value | Meaning |
| --- | --- |
| **ClfsDataRecord** | Only user-data records are read. |
| **ClfsRestartRecord** | Only restart records are read. |
| **ClfsClientRecord** | All restart and data records are read. |

### `plsnUser` [in, optional]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure that specifies the log client to read this log sequence number (LSN) as the next LSN instead of reading forward to the next record, reading the previous LSN, or reading the next undo LSN.

This parameter gives log clients the ability to cursor through user-defined LSN chains in client buffers. The relationship of this parameter to the current LSN held by the read context must be consistent with the context mode, *ecxMode*, that is specified in the [ReadLogRecord](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-readlogrecord) entry points; otherwise, an error code of **ERROR_INVALID_PARAMETER** is returned.

### `plsnUndoNext` [out]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure that receives the LSN of the next record in an undo record chain.

### `plsnPrevious` [out]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure that receives the LSN of the next record in the previous record chain.

### `plsnRecord` [out]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure that receives the LSN of the current record read into the read context.

### `pOverlapped` [in, out, optional]

A pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that is required for asynchronous operation.

This parameter can be **NULL** if asynchronous operation is not used.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following list identifies the possible error codes:

## Remarks

If **ReadNextLogRecord** returns with a status code of **ERROR_IO_PENDING**, the client should synchronize its execution with deferred completion of the overlapped I/O operation by using [GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult), or one of the synchronization [Wait Functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions). For more information, see [Synchronization and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output).

After **ReadNextLogRecord** completes asynchronously, the requested record is read from the disk, but is not resolved to a pointer in **ppvReadBuffer*. To obtain a valid pointer to the record, the client must call **ReadNextLogRecord** a second time.

**Note** Common Log File System (CLFS) read contexts are not thread-safe. They should not be used by more than one thread at a time.

CLFS read contexts should not be passed into more than one asynchronous read at a time, or the function fails with ERROR_READ.

## See also

[CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn)

[CLFS_RECORD_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/clfs-record-type-constants)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[ReadLogRecord](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-readlogrecord)

[ReadLogRestartArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-readlogrestartarea)

[Synchronization and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output)