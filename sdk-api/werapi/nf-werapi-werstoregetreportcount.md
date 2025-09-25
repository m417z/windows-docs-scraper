# WerStoreGetReportCount function

## Description

Gets the number of [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) reports in the error report store.

## Parameters

### `hReportStore`

The error report store (previously retrieved with [WerStoreOpen](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werstoreopen)).

### `pdwReportCount`

The report count.

## Return value

This function returns **S_OK** on success or an error code on failure, including the following error code.

|Return code|Description|
|--- |--- |
|**E_INVALID_ARG**|One of the arguments is not a valid value.|
|**ERROR_NO_MORE_FILES**|There are no more error reports in the store.|

## Remarks

## See also

[Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)