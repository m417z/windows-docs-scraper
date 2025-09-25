# ReserveAndAppendLogAligned function

## Description

Reserves space for log buffers, or appends a log record to the log, or both. This function is like the [ReserveAndAppendLog](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-reserveandappendlog) function, but **ReserveAndAppendLogAligned** aligns the write entries of the record to the specified byte alignment.

## Parameters

### `pvMarshal` [in]

A pointer to a marshaling context that is allocated by using the [CreateLogMarshallingArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogmarshallingarea) function.

### `rgWriteEntries` [in, optional]

A pointer to an array of [CLFS_WRITE_ENTRY](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_write_entry) buffers to be marshaled into one record.

This parameter is ignored if the *cWriteEntries* parameter is zero.

### `cWriteEntries` [in]

The number of write entries in the *rgWriteEntries* array.

If this value is nonzero, you must specify a buffer in the *rgWriteEntries* parameter.

### `cbEntryAlignment` [in]

The byte alignment for each write entry in the *rgWriteEntries* parameter.

Specify 1 (one) for a simple concatenation. The *cbWriteEntryAlignment* parameter must be nonzero.

### `plsnUndoNext` [in, optional]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure that specifies the log sequence number (LSN) of the next record in the undo-chain.

### `plsnPrevious` [in, optional]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure that specifies the LSN of the previous record in the previous-chain.

### `cReserveRecords` [in]

The number of record sizes in the *rgcbReservation* array.

### `rgcbReservation` [in, out, optional]

A pointer to an array of reservation sizes for each record that the *cReserveRecords* parameter specifies.

 This parameter is ignored if the *cReserveRecords* parameter is zero. If a reservation size is negative, a reservation of that size is released.

The actual space that is reserved for each record, including required overhead, is returned in the individual array elements on successful completion. These values can be passed to the [FreeReservedLog](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-freereservedlog) function to adjust space that is reserved in the marshaling area.

### `fFlags` [in]

The flags that specify the behavior of this function.

One or more of the following values can be combined.

| Value | Meaning |
| --- | --- |
| **CLFS_FLAG_FORCE_APPEND** | Assigns a physical location for all appended records in the log that are not previously assigned a physical location. <br><br>All these records are made available for reading from other marshaling contexts. |
| **CLFS_FLAG_FORCE_FLUSH** | Assigns a physical location for all appended records in the log that are not previously assigned a physical location. <br><br>All these records are made available for reading from other marshaling contexts. Then, the records are flushed to disk. |
| **CLFS_FLAG_NO_FLAGS** | Assigns no flags. |
| **CLFS_FLAG_USE_RESERVATION** | Appends the current record by using the space that is reserved in the marshaling area. |

### `plsn` [out, optional]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure that receives the LSN of the appended record.

### `pOverlapped` [in, out, optional]

A pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure.

This parameter can be **NULL** if asynchronous operation is not used.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. The following list identifies the possible error codes:

## Remarks

The LSN that is returned by the **ReserveAndAppendLogAligned** function is not necessarily the next LSN that is used. The LSN that is returned is an estimate of the next LSN, and it varies based on which flags are specified by the *fFlags* parameter. The LSN that is returned can be used when moving the base tail. This LSN is invalidated by the next call to this function.

If the **ReserveAndAppendLogAligned** function returns **ERROR_LOG_FILE_FULL**, there is no more space in the log. This can be resolved in one of the following ways:

* Free any unneeded reservations.
* Advance the base LSN or the log archive tail, or both, to recycle containers.
* Add containers to the log.

The [CLFS Management API](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-management-api) also provides a way to handle scenarios involving full logs.

If the **ReserveAndAppendLogAligned** function is called with a valid *overlapped* structure and the log handle is created with the overlapped option, then if a call to this function fails with an error code of **ERROR_IO_PENDING**, a pointer to a valid read context is placed in the variable that is pointed to by the *ppvReadContext* parameter.

To complete the log-record copy, the client should first synchronize its execution with deferred completion of the overlapped I/O operation by using the [GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) function or one of the synchronization [Wait Functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions). For more information, see [Synchronization and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output).

## See also

[CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn)

[CLFS_WRITE_ENTRY](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_write_entry)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)