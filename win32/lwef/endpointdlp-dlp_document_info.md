# DLP_DOCUMENT_INFO structure

Specifies information about a document that is associated with an endpoint DLP operation.

## Members

*Version* \[in\]

A DWORD specifying the API version. This value should always be **DLP_DOCUMENT_INFO_V_LATEST**. This constant is defined in the endpointdlp.h sample header file listing in the article [Endpoint data loss prevention](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-endpoint-data-loss-prevention).

*PersistentFileName* \[in\]

A LPCWSTR specifying the original path of the document.

*LocalFileName* \[in\]

A LPCWSTR specifying the path to the real backing file of the document.

## Remarks

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1809 (10.0; Build 17763) |