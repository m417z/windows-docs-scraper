# ICrmFormatLogRecords::GetColumnCount

## Description

Retrieves the number of fields (columns) in a log record of the type used by this CRM Compensator.

## Parameters

### `plColumnCount` [out]

The number of fields (columns) in the log record.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_POINTER** | A **NULL** pointer was provided as an argument. |

## See also

[ICrmFormatLogRecords](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmformatlogrecords)