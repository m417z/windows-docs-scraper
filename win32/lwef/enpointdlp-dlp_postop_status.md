# DLP_POSTOP_STATUS structure

Specifies status information about an endpoint DLP operation.

## Members

*Version* \[in\]

A DWORD specifying the API version. This value should always be **DLP_POSTOP_STATUS_V_LATEST**. This constant is defined in the endpointdlp.h sample header file listing in the article [Endpoint data loss prevention](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-endpoint-data-loss-prevention)

*OperationSuccess* \[in\]

A BOOL indicating whether the open operation was successful.

## Remarks

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1809 (10.0; Build 17763) |