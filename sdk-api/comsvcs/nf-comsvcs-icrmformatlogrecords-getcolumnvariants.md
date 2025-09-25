# ICrmFormatLogRecords::GetColumnVariants

## Description

Formats one structured log record into an array of viewable fields.

## Parameters

### `LogRecord` [in]

The structured log record to be formatted.

### `pFormattedLogRecord` [out]

A **Variant** array of the fields in this log record as **Variant** strings.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_POINTER** | A **NULL** pointer was provided as an argument. |
| **E_FAIL** | The log record could not be formatted. |

## See also

[ICrmFormatLogRecords](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmformatlogrecords)