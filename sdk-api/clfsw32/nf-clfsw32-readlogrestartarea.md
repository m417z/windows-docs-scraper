# ReadLogRestartArea function

## Description

 Returns the last restart area that is written successfully to the log associated with the marshaling area of [WriteLogRestartArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-writelogrestartarea). The function also returns a read context that allows the caller to cursor backward or forward through a log from the restart record.

This read context is useful when scanning through previous restart areas prior to the current one by invoking [ReadPreviousLogRestartArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-readpreviouslogrestartarea).

## Parameters

### `pvMarshal` [in]

A pointer to a marshaling context that is allocated by using the [CreateLogMarshallingArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogmarshallingarea) function.

### `ppvRestartBuffer` [out]

A pointer to a variable that receives a pointer to the restart data in the log I/O block.

### `pcbRestartBuffer` [out]

A pointer to a variable that receives the amount of restart data.

### `plsn` [out]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure that receives the log sequence number (LSN) of the restart area.

### `ppvContext` [out]

A pointer to a variable that receives a pointer to a system-allocated read context when a read is successful.

If the function defers completion of an operation, it returns a valid read-context pointer and an error status of **ERROR_IO_PENDING**. On all other errors, the read-context pointer is **NULL**. For more information about handling deferred completion of the function, see the Remarks section of this topic.

After obtaining all requested log records, the client must pass the read context to [TerminateReadLog](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-terminatereadlog) to free the associated memory. Failure to do so results in memory leakage.

**Note** Common Log File System (CLFS) read contexts are not thread-safe. They should not be used by more than one thread at a time, or passed into more than one asynchronous read at a time.

### `pOverlapped` [in, out, optional]

A pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that is required for asynchronous operation.

This parameter can be **NULL** if an asynchronous operation is not used.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following list identifies the possible error codes:

## Remarks

The error message ERROR_LOG_BLOCK_INCOMPLETE is returned if the log block size specified by [CreateLogMarshallingArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogmarshallingarea) is not large enough to hold a complete log block.

Typically, **ReadLogRestartArea** is used only during client restart, either after a crash or after a normal shutdown.

If there is no restart area in the log, **ReadLogRestartArea** fails with the code **ERROR_LOG_NO_RESTART**.

If **ReadLogRestartArea** fails with an error code of **ERROR_IO_PENDING**, a pointer to a valid read context is placed in the variable pointed to by the *ppvReadContext* parameter.

To complete the log-record copy, the client should first synchronize its execution with deferred completion of the overlapped I/O operation by calling [GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult), or one of the synchronization [Wait Functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions). For more information, see [Synchronization and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output).

After **ReadLogRestartArea** completes asynchronously, the requested restart area is read from the disk, but a valid pointer to it is not placed in **ppvRestartBuffer*.

To obtain a valid pointer, the client must call [ReadPreviousLogRestartArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-readpreviouslogrestartarea), which passes in the read-context pointer returned by **ReadLogRestartArea**.

**Note** Common Log File System (CLFS) read contexts are not thread-safe. They should not be used by more than one thread at a time.

CLFS read contexts should not be passed into more than one asynchronous read at a time, or the function fails with ERROR_BUSY.

## See also

[CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[ReadPreviousLogRestartArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-readpreviouslogrestartarea)

[Synchronization and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output)

[WriteLogRestartArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-writelogrestartarea)