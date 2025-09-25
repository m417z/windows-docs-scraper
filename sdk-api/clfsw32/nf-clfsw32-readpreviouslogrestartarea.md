# ReadPreviousLogRestartArea function

## Description

Reads the previous log restart area that is relative to the current restart record specified in the read context, *pvReadContext*. This read context is the one previously created by a call to [ReadLogRestartArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-readlogrestartarea).

## Parameters

### `pvReadContext` [in]

A pointer to a system-allocated read context that [ReadLogRestartArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-readlogrestartarea) returns.

 Even when those functions return **ERROR_IO_PENDING**, they still return a pointer to a valid read context. For information about asynchronous completion, see the Remarks section of this topic.

### `ppvRestartBuffer` [out]

A pointer to a variable that receives a pointer to the restart data.

### `pcbRestartBuffer` [out]

A pointer to a variable that receives the size of the restart data at **ppvRestartBuffer*, in bytes.

### `plsnRestart` [out]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure that receives the log sequence number (LSN) of the restart area that this function returns.

### `pOverlapped` [in, out, optional]

A pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that is required for asynchronous operation.

This parameter can be **NULL** if asynchronous operation is not used.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following list identifies the possible error codes:

## Remarks

The error message ERROR_LOG_BLOCK_INCOMPLETE is returned if the log block size specified by [CreateLogMarshallingArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogmarshallingarea) is not large enough to hold a complete log block.

If **ReadPreviousLogRestartArea** fails with an error code of **ERROR_IO_PENDING**, a pointer to a valid read context is placed in the variable that is pointed to by the *ppvReadContext* parameter.

To complete the log-record copy, the client should first synchronize its execution with deferred completion of the overlapped I/O operation by using [GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) or one of the synchronization [Wait Functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions). For more information, see [Synchronization and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output).

After **ReadPreviousLogRestartArea** completes asynchronously, the requested restart area is read from the disk, but a valid pointer to it is not placed in **ppvRestartBuffer*.

To obtain a valid pointer, the client must call **ReadPreviousLogRestartArea** a second time.

**Note** Common Log File System (CLFS) read contexts are not thread-safe. They should not be used by more than one thread at a time.

CLFS read contexts should not be passed into more than one asynchronous read at a time, or the function fails with ERROR_READ.

## See also

[CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[ReadLogRestartArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-readlogrestartarea)

[Synchronization and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output)