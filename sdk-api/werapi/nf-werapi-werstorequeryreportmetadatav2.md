# WerStoreQueryReportMetadataV2 function

## Description

Retrieves metadata about a [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) report in the store.

## Parameters

### `hReportStore`

The error report store (previously retrieved with [WerStoreOpen](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werstoreopen)).

### `pszReportKey`

The string identifying which report is being queried (previously retrieved with [WerStoreGetFirstReportKey](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werstoregetfirstreportkey) or [WerStoreGetNextReportKey](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werstoregetnextreportkey)).

### `pReportMetadata`

A pointer to the report store metadata in the form of a [WER_REPORT_METADATA_V2](https://learn.microsoft.com/windows/desktop/api/werapi/ns-werapi-wer_report_metadata_v2) structure. The field **SizeOfFileNames** should be set to 0 during the first call. The function updates this field with the required size to hold the file names associated with the report. The field **FileNames** should then be allocated with **SizeOfFileNames** bytes and the function should be called again to get all of the file names.

## Return value

This function returns **S_OK** on success or an error code on failure, including the following error code.

|Return code|Description|
|--- |--- |
|**E_INVALID_ARG**|One of the arguments is not a valid value.|
|**ERROR_INSUFFICIENT_BUFFER**|There is not enough memory available to retrieve the metadata. In this case, the caller should allocate memory of size **SizeOfFileNames** for the **FileNames** field, found in the [WER_REPORT_METADATA_V2](https://learn.microsoft.com/windows/desktop/api/werapi/ns-werapi-wer_report_metadata_v2) structure, and call the function again.|

## See also

[WER_REPORT_METADATA_V2](https://learn.microsoft.com/windows/desktop/api/werapi/ns-werapi-wer_report_metadata_v2), [WerStoreGetFirstReportKey](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werstoregetfirstreportkey), [WerStoreGetNextReportKey](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werstoregetnextreportkey), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)