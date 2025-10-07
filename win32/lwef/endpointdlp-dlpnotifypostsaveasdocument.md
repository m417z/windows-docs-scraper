# DlpNotifyPostSaveAsDocument function

Provides the system with information about a document after the save as operation is completed.

## Parameters

*DocumentInfo* \[in\]

A pointer to a [PDLP_DOCUMENT_INFO](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-dlp_document_info) structure containing information about the document that was saved.

*Destination* \[in\]

A **LPCWSTR** containing the destination path the document that was saved.

*OpStatus* \[in\]

A pointer to a [DLP_POSTOP_STATUS](https://learn.microsoft.com/windows/win32/lwef/enpointdlp-dlp_postop_status) structure containing status information about the save as operation.

## Return value

Return void.

## Remarks

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1809 (10.0; Build 17763) |
| DLL<br> | EndpointDlp.dll |