# WerStoreQueryReportMetadataV1 function

## Description

Retrieves metadata about a [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) report in the store.

## Parameters

### `hReportStore`

The error report store (previously retrieved with [WerStoreOpen](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werstoreopen)).

### `pszReportKey`

The string identifying which report is being queried (previously retrieved with [WerStoreGetFirstReportKey](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werstoregetfirstreportkey) or [WerStoreGetNextReportKey](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werstoregetnextreportkey)).

### `pReportMetadata`

A pointer to the report store metadata in the form of a [WER_REPORT_METADATA_V1](https://learn.microsoft.com/windows/win32/api/werapi/ns-werapi-wer_report_metadata_v1) structure.

## Return value

This function returns **S_OK** on success or an error code on failure, including the following error code.

|Return code|Description|
|--- |--- |
|**E_INVALID_ARG**|One of the arguments is not a valid value.|
|**ERROR_INSUFFICIENT_BUFFER**|There is not enough memory available to retrieve the metadata. |

## Remarks

## See also

[WER_REPORT_METADATA_V1](https://learn.microsoft.com/windows/win32/api/werapi/ns-werapi-wer_report_metadata_v1), [WerStoreGetFirstReportKey](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werstoregetfirstreportkey), [WerStoreGetNextReportKey](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werstoregetnextreportkey), [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/)