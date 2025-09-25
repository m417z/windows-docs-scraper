# WerReportSetParameter function

## Description

Sets the parameters that uniquely identify an event for the specified [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) report.

## Parameters

### `hReportHandle` [in]

A handle to the report. This handle is returned by the [WerReportCreate](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportcreate) function.

### `dwparamID` [in]

The identifier of the parameter to be set. This parameter can be one of the following values.

- WER_P0
- WER_P1
- WER_P2
- WER_P3
- WER_P4
- WER_P5
- WER_P6
- WER_P7
- WER_P8
- WER_P9

### `pwzName` [in, optional]

A pointer to a Unicode string that contains the name of the parameter. If this parameter is **NULL**, the default name is P*x*, where *x* matches the integer portion of the value specified in *dwparamID*.

### `pwzValue` [in]

The parameter value.

## Return value

This function returns **S_OK** on success or an error code on failure, including the following error code.

|Return code|Description|
|--- |--- |
|**E_HANDLE**|The specified handle is not valid.|
|**WER_E_LENGTH_EXCEEDED**|The length of one or more string arguments has exceeded its limit.|

## Remarks

Each report supports parameters P0 through P9. This function sets one parameter at a time. If parameter P*x* is set, then all parameters from P0 and P*x* must be set.

## See also

[WerReportCreate](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportcreate), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)