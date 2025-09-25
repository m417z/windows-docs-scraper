# ILog::ReadRecordPrefix

## Description

Reads an initial part of a record from the log.

## Parameters

### `lsnToRead` [in]

The LSN of the record to be read.

### `plsnPrev` [in, out]

A pointer to the LSN of the previous record (the record immediately preceding the record to read). You may pass **NULL** if the LSN of the previous record is not needed. This parameter is 0 if there is no previous record in the log or if an error occurs.

### `plsnNext` [in, out]

A pointer to the LSN of the next record (the record immediately following the record to read). You may pass **NULL** if the LSN of the next record is not needed. This parameter is MAXLSN (0x7FFFFFFFFFFFFFFF) if there is no next record in the log. This parameter is 0 if an error occurs.

### `pbData` [out]

A pointer to a buffer into which the record data is to be read.

### `pcbData` [in, out]

A pointer to a variable that contains the size in bytes of the buffer on input, and will contain the size in bytes of the record data read on return.

### `pcbRecord` [out]

A pointer to a variable that will contain the size in bytes of the entire record on return. You may pass **NULL** if the size of the entire record is not needed.

## Return value

This method can return the following values, as well as other **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | The record was successfully read from the log. |
| **XACT_E_INVALIDLSN** | *lsnToRead* is outside of the current limits of the log. See [ILog::GetLogLimits](https://learn.microsoft.com/windows/desktop/api/txlogpub/nf-txlogpub-ilog-getloglimits). |
| **E_INVALIDARG** | *lsnToRead* is within the current limits of the log, but it is not the LSN of a record in the log. |

## Remarks

Although records appended to the log using [ILog::AppendRecord](https://learn.microsoft.com/windows/desktop/api/txlogpub/nf-txlogpub-ilog-appendrecord) may be concatenated from multiple BLOBs, **ReadRecordPrefix** returns the record as a single opaque blob of data. [ILog](https://learn.microsoft.com/windows/desktop/api/txlogpub/nn-txlogpub-ilog) provides no method to extract individual BLOBs from the record. It is the responsibility of the caller to parse the data in records returned by **ReadRecordPrefix**.

## See also

[ILog](https://learn.microsoft.com/windows/desktop/api/txlogpub/nn-txlogpub-ilog)