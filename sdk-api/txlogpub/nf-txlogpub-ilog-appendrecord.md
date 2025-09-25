# ILog::AppendRecord

## Description

Write a new record to the end of the log.

## Parameters

### `rgBlob` [in]

A pointer to an array of BLOBs of data to be written.

### `cBlob` [in]

The size of the *rgBlob* array, in elements.

### `fForceNow` [in]

Indicates whether to force the data to disk. If **TRUE**, the contents of the log up to this record must be forced to disk before the call returns. If **FALSE**, this record may be buffered in memory to be written after the call returns successfully.

### `plsn` [in, out]

A pointer to the LSN of the newly appended record. If the LSN of the newly appended record is not needed, this parameter can be **NULL**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Each log record written or read by [ILog](https://learn.microsoft.com/windows/desktop/api/txlogpub/nn-txlogpub-ilog) is an opaque BLOB of data. As a convenience to callers, **AppendRecord** allows multiple BLOBs to be concatenated into a single record; because many implementations of **ILog** will copy records to a buffer in memory, it may be inefficient for the caller to allocate memory for concatenating the parts of a record. However, once a record is appended to the log, **ILog** provides no method to extract individual BLOBs from the record. It is the responsibility of the caller to parse the data in records read from the log. See [ILog::ReadRecord](https://learn.microsoft.com/windows/desktop/api/txlogpub/nf-txlogpub-ilog-readrecord).

### Notes to Callers

A failure return value indicates that any records appended to the log since the last time it was successfully forced are not guaranteed to be on disk. The [ILog](https://learn.microsoft.com/windows/desktop/api/txlogpub/nn-txlogpub-ilog) interface does not provide a method to determine which records have been successfully written to disk. If you need to know which records were successfully written to disk, you must force the log for each record.

### Notes to Implementers

If *fForceNow* is **TRUE**, it is recommended that you flush file buffers (for example, using the [FlushFileBuffers](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-flushfilebuffers) function) before returning from this method.

## See also

[FlushFileBuffers](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-flushfilebuffers)

[ILog](https://learn.microsoft.com/windows/desktop/api/txlogpub/nn-txlogpub-ilog)