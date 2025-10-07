# DlpNotifyPostStartPrint function

Provides the system with information about a document after a print operation has started.

## Parameters

*DocumentInfo* \[in\]

A pointer to a [PDLP_DOCUMENT_INFO](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-dlp_document_info) structure containing information about the document associated with the print operation.

*PrintInfo* \[in\]

A pointer to a [DLP_PRINT_INFO](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-dlp_print_info) structure containing information about the print operation.

## Return value

Return void.

## Remarks

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1809 (10.0; Build 17763) |
| DLL<br> | EndpointDlp.dll |