# DLP_PRINT_INFO structure

Specifies information about a document that is associated with an endpoint DLP print operation.

## Members

*Version* \[in\]

A DWORD specifying the API version. This value should always be **DLP_PRINT_INFO_V_LATEST**. This constant is defined in the endpointdlp.h sample header file listing in the article [Endpoint data loss prevention](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-endpoint-data-loss-prevention).

*PrinterName* \[in\]

A LPCWSTR identifying the destination printer.

*JobName* \[in\]

A LPCWSTR specifying print job name.

*OutputFileName* \[in\]

A LPCWSTR specifying the path to the output file, when printing to a file.

## Remarks

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1809 (10.0; Build 17763) |