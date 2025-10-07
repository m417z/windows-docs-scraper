# DlpNotifyPostPasteFromClipboard function

Provides the system with information about a document after a paste from clipboard operation is completed.

## Parameters

*DocumentInfo* \[in\]

A pointer to a [PDLP_DOCUMENT_INFO](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-dlp_document_info) structure containing information about the document into which content was copied.

*OpStatus* \[in\]

A pointer to a [DLP_POSTOP_STATUS](https://learn.microsoft.com/windows/win32/lwef/enpointdlp-dlp_postop_status) structure containing status information about the paste from clipboard operation.

## Return value

Return void.

## Remarks

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1809 (10.0; Build 17763) |
| DLL<br> | EndpointDlp.dll |