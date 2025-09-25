# WriteLogRestartArea function

## Description

Appends a new client restart area to a log, and optionally advances the base log sequence number (LSN) of the log.

After it is successfully written to a disk, the last LSN of the log is changed to the LSN of the appended restart record. Typically, **WriteLogRestartArea** is used by applications that regularly save a known good state, and the restart area contains the LSNs for existing log record chains.

## Parameters

### `pvMarshal` [in, out]

A pointer to the marshaling context that is allocated by using the [CreateLogMarshallingArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogmarshallingarea) function.

### `pvRestartBuffer` [in]

A pointer to a buffer that contains restart data.

### `cbRestartBuffer` [in]

The size of *pvRestartBuffer*, in bytes.

### `plsnBase` [in, optional]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure that specifies the new base LSN of the log after successfully writing the restart area.

This value cannot be outside the range of the active log. It must be at least the value of the current base LSN, and not greater than the LSN that was returned in the *lastLSN* parameter from the latest call to [ReserveAndAppendLog](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-reserveandappendlog). If you omit this optional parameter, the base LSN does not change.

### `fFlags` [in]

The flags that specify the behavior of this function.

One or more of the following values can be combined.

| Value | Meaning |
| --- | --- |
| **CLFS_FLAG_NO_FLAGS** | Assigns no flags. |
| **CLFS_FLAG_USE_RESERVATION** | Appends the current record by using the space that is reserved in the marshaling area. |

### `pcbWritten` [out, optional]

A pointer to a variable that receives the number of bytes that are written when an operation completes.

### `plsnNext` [out, optional]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure that specifies the LSN of the restart area that is written.

### `pOverlapped` [in, out, optional]

A pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure.

This parameter can be **NULL** if an asynchronous operation is not used.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following list identifies the possible error codes:

## Remarks

The **WriteLogRestartArea** causes both a flush of all current buffered log records and a flush of the log metadata.

If a client calls **WriteLogRestartArea** on a log that is created to support asynchronous operations (for example, if the *fFlagsAndAttributes* parameter of [CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile) is set to **FILE_FLAG_OVERLAPPED** when the log is created), the client must supply a pointer to a valid [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure in the *pOverlapped* parameter of **WriteLogRestartArea**.

Then, if **WriteLogRestartArea** fails with an error of **ERROR_IO_PENDING**, a pointer to a valid read context is placed in the variable that is pointed to by the *ppvReadContext* parameter.

To complete the call, the client should synchronize its execution with deferred completion of the overlapped I/O operation by using [GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) or one of the synchronization [Wait Functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions). For more information, see [Synchronization and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output).

## See also

[CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)