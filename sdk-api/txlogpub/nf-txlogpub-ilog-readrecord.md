# ILog::ReadRecord

## Description

Read a record from the log.

## Parameters

### `lsnToRead` [in]

The LSN of the record to be read.

### `plsnPrev` [in, out]

A pointer to the LSN of the previous record (the record immediately preceding the record to be read). This parameter can be **NULL** if the LSN of the previous record is not needed. This parameter is 0 if there is no previous record in the log, or if an error occurs.

### `plsnNext` [in, out]

A pointer to the LSN of the next record (the record immediately following the record to read). This parameter can be **NULL** if the LSN of the next record is not needed. This parameter is MAXLSN (0x7FFFFFFFFFFFFFFF) if there is no next record in the log. This parameter is 0 if an error occurs.

### `ppbData` [out]

A pointer to a variable that will contain a pointer to the record data on return. The memory for this data is allocated by **ReadRecord** and freed by the caller (see [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree)). This parameter is **NULL** if an error occurs.

### `pcbData` [out]

A pointer to a variable that receives the size of the record data, in bytes, on return.

## Return value

This method can return the following values, as well as other **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | The record was successfully read from the log. |
| **XACT_E_INVALIDLSN** | *lsnToRead* is outside of the current limits of the log. See [ILog::GetLogLimits](https://learn.microsoft.com/windows/desktop/api/txlogpub/nf-txlogpub-ilog-getloglimits). |
| **E_INVALIDARG** | *lsnToRead* is within the current limits of the log, but it is not the LSN of a record in the log. |
| **E_OUTOFMEMORY** | The record was not returned due to a lack of memory. |

## Remarks

Although records appended to the log using [ILog::AppendRecord](https://learn.microsoft.com/windows/desktop/api/txlogpub/nf-txlogpub-ilog-appendrecord) may be concatenated from multiple BLOBs, **ReadRecord** returns the record as a single opaque blob of data. [ILog](https://learn.microsoft.com/windows/desktop/api/txlogpub/nn-txlogpub-ilog) provides no method to extract individual BLOBs from the record. It is the responsibility of the caller to parse the data in records returned by **ReadRecord**.

### Notes to Callers

If the log contains very large records, this method may fail because **ReadRecord** was unable to allocate sufficient memory for the record data. If the size of records is bounded or if you only need an initial part of the record, it may be more efficient to call [ILog::ReadRecordPrefix](https://learn.microsoft.com/windows/desktop/api/txlogpub/nf-txlogpub-ilog-readrecordprefix).

## See also

[ILog](https://learn.microsoft.com/windows/desktop/api/txlogpub/nn-txlogpub-ilog)