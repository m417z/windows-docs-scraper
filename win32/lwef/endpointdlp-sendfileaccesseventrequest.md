# SendFileAccessEventRequest structure

A request structure for sending file access events. The request is responsible for generating an ETW event for file access DLP.

## Members

*filePath* `[IN]`

The fully qualified file path as defined [here](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

*url* `[IN]`

The target URL to trace. This parameter can be `NULL` for some operations like print or copy to clipboard.

*policyInfo* `[IN]`

The policy info obtained from a `GetFileCloudApplicationPolicyRequest` or `GetFileApplicationAccessRequest` policy request.

*enforcementLevel* `[IN]`

The enforcement level of the file.

*userBypass* `[IN]`

Indicates the user decision on `DlpEnforcementLevel::Warn`. `TRUE` indicates the user allow the operation. Otherwise, it's `FALSE`.

*businessJustification* `[IN][OPTIONAL]`

The business justification for the operation.

## Returns

Returns **S_OK** if it succeeds, or a **FAILED** HRESULT otherwise.

## Remarks

Corresponds to **RequestIdSendFileAccessEvent** in [DlpRequestId](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-dlprequestid). Note that this function can be called from multiple threads.

## Requirements

| Requirement | Value |
|-------------|-------|
| Minimum supported client | Windows 11, version 24H2 (Build 26100) |
| DLL | EndpointDlp.dll |

## Related content

- [DlpRequest](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-dlprequest)