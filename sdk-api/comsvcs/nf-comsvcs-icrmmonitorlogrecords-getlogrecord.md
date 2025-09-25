# ICrmMonitorLogRecords::GetLogRecord

## Description

Retrieves an unstructured log record given its numeric index.

## Parameters

### `dwIndex` [in]

The index of the required log record.

### `pCrmLogRec` [in, out]

The log record, as a [CrmLogRecordRead](https://learn.microsoft.com/windows/desktop/api/comsvcs/ns-comsvcs-crmlogrecordread) structure.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_POINTER** | A **NULL** pointer was provided as an argument. |
| **E_INVALIDARG** | The index is out of range. |
| **XACT_E_WRONGSTATE** | Attempting to read unstructured records but written records are structured. |
| **XACT_E_TRANSACTIONCLOSED** | The transaction has completed, and the log records have been discarded from the log file. They are no longer available. |

## See also

[ICrmMonitorLogRecords](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmmonitorlogrecords)