# ICrmFormatLogRecords::GetColumnHeaders

## Description

Retrieves the names of the fields (columns) so that they can be used as column headings when the information is presented.

## Parameters

### `pHeaders` [out]

A **Variant** array containing the field names as **Variant** strings.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_POINTER** | A **NULL** pointer was provided as an argument. |

## See also

[ICrmFormatLogRecords](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmformatlogrecords)