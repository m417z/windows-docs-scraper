# WerStoreGetFirstReportKey function

## Description

Gets a reference to the first [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) report in the report store.

## Parameters

### `hReportStore`

The error report store (previously retrieved with [WerStoreOpen](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werstoreopen)).

### `ppszReportKey`

A pointer to the report key string. On a successful call, this will point to the retrieved report key.

## Return value

This function returns **S_OK** on success or an error code on failure, including the following error code.

|Return code|Description|
|--- |--- |
|**E_INVALID_ARG**|One of the arguments is not a valid value.|
|**ERROR_NO_MORE_FILES**|There are no error reports in the store.|

## See also

[WerStoreGetNextReportKey](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werstoregetnextreportkey), [WerStoreOpen](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werstoreopen), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)