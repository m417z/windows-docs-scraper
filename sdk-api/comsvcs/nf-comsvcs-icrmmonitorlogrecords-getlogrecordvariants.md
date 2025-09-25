# ICrmMonitorLogRecords::GetLogRecordVariants

## Description

Retrieves a structured log record given its numeric index.

## Parameters

### `IndexNumber` [in]

The index of the required log record.

### `pLogRecord` [out]

The log record. See [ICrmCompensatorVariants::PrepareRecordVariants](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-icrmcompensatorvariants-preparerecordvariants) for the format.

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