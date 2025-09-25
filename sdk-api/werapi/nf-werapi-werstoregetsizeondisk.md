# WerStoreGetSizeOnDisk function

## Description

Gets the size of the [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) error report store, in bytes.

## Parameters

### `hReportStore`

The error report store (previously retrieved with [WerStoreOpen](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werstoreopen)).

### `pqwSizeInBytes`

The error report store size, in bytes.

## Return value

|Return code|Description|
|--- |--- |
|**E_INVALID_ARG**|One of the arguments is not a valid value.|
|**ERROR_NO_MORE_FILES**|There are no more error reports in the store.|

## Remarks

## See also