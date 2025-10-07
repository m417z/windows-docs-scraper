# DlpNotifyPrePrint function

Provides the system with information about a document before a print operation is initiated.

## Parameters

*DocumentInfo* \[in\]

A pointer to a [PDLP_DOCUMENT_INFO](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-dlp_document_info) structure containing information about the document to be printed.

*PrintInfo* \[in\]

A pointer to a [DLP_PRINT_INFO](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-dlp_print_info) structure containing information about print operation.

## Return value

Return void.

## Remarks

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1809 (10.0; Build 17763) |
| DLL<br> | EndpointDlp.dll |