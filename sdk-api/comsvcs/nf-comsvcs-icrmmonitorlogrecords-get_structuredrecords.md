# ICrmMonitorLogRecords::get_StructuredRecords

## Description

Retrieves a flag indicating whether the log records written by this CRM clerk were structured.

## Parameters

### `pVal` [out]

Indicates whether the log records are structured.
If this method is called before any log records have been written, this parameter is **TRUE**.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_POINTER** | A **NULL** pointer was provided as an argument. |

## See also

[ICrmMonitorLogRecords](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmmonitorlogrecords)