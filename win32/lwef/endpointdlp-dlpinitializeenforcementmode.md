# DlpInitializeEnforcementMode function

Notifies the system of the desired enforcement modes for a set of endpoint Data Loss Prevention (DLP) operations.

## Parameters

*Count* \[in\]

A **DWORD** specifying the number of operations included in the *OperationEnforcement* array.

*OperationEnforcement* \[in\]

An array of [DLP_APP_OP_ENLIGHTENED_LEVEL](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-dlp_app_op_enlightened_level) structures that specify the enforcement level for an endpoint DLP operation.

## Return value

Returns an HRESULT including, but not limited to, the following values.

| HRESULT | Description |
|---------|-------------|
| S_OK | The function completed successfully |
| E_INVALIDARG | One or more of the function parameters are invalid. |
| E_OUTOFMEMORY | Memory allocation for the operation failed. |

## Remarks

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1809 (10.0; Build 17763) |
| DLL<br> | EndpointDlp.dll |