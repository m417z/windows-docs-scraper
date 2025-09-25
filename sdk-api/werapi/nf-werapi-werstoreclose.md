# WerStoreClose function

## Description

Closes the collection of stored [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) reports.

## Parameters

### `hReportStore`

The error report store to close (previously retrieved with [WerStoreOpen](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werstoreopen)).

## Return value

This function returns **S_OK** on success or an error code on failure.

## See also

[WerStoreOpen](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werstoreopen), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)