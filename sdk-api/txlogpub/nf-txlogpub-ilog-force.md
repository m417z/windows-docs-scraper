# ILog::Force

## Description

Forces the contents of the log to disk, at least up through the specified LSN.

## Parameters

### `lsnMinToForce` [in]

At the very least, all records that have not yet been written to disk with an LSN less than or equal to *lsnMinToForce* must be written to disk now. An implementation may, however, choose to write more records than what is strictly required. For example, an implementation is allowed to force all records to disk, regardless of the value of *lsnMinToForce*. Passing 0 as *lsnMinToForce* indicates that the entire log is to be forced to disk.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The log may also be forced to disk after appending individual records. See [ILog::AppendRecord](https://learn.microsoft.com/windows/desktop/api/txlogpub/nf-txlogpub-ilog-appendrecord).

### Notes to Callers

A failure return value indicates that any records appended to the log since the last time it was successfully forced are not guaranteed to be on disk. The [ILog](https://learn.microsoft.com/windows/desktop/api/txlogpub/nn-txlogpub-ilog) interface does not provide a method to determine which records have been successfully written to disk. If you need to know which records were successfully written to disk, you must force the log for each record. See [ILog::AppendRecord](https://learn.microsoft.com/windows/desktop/api/txlogpub/nf-txlogpub-ilog-appendrecord).

### Notes to Implementers

It is recommended that you flush file buffers (for example, using the [FlushFileBuffers](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-flushfilebuffers) function) before returning from this method.

## See also

[FlushFileBuffers](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-flushfilebuffers)

[ILog](https://learn.microsoft.com/windows/desktop/api/txlogpub/nn-txlogpub-ilog)