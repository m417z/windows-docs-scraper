# WerReportCloseHandle function

## Description

Closes the specified [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) report.

## Parameters

### `hReportHandle` [in]

A handle to the report. This handle is returned by the [WerReportCreate](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportcreate) function.

## Return value

This function returns **S_OK** on success or an error code on failure.

## See also

[WerReportCreate](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportcreate), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)