# DlpRequest structure

A wrapper structure for a DLP Request.

## Members

*id* `[in]`

The id of the request being made to Endpoint DLP.

*size* `[in]`

The size of the request structure (e.g. `sizeof(AuthGroupOverrideRequest)`). Used for versioning of individual requests types.

*union* `[in, out]`

The union of request-specific data structures.

### Union members

The following data structures can be provided as members of the union:

#### authGroupOverrideRequest

Structure containing the parameters to include in the request when `id=RequestIdAuthorizedGroupOverrideEdge`.

[AuthGroupOverrideRequest](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-authgroupoverriderequest) defines the structure of the `authGroupOverrideRequest`.

#### getFileCloudApplicationPolicyRequest

Structure containing the parameters to include in the request when `id=RequestIdGetFileCloudApplicationPolicy`.

[GetFileCloudApplicationPolicyRequest](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-getfilecloudapplicationpolicyrequest) defines the structure of the `getFileCloudApplicationPolicyRequest`.

#### getFileApplicationAccessRequest

Structure containing the parameters to include in the request when `id=RequestIdGetFileApplicationAccess`.

[GetFileApplicationAccessRequest](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-getfileapplicationaccessrequest) defines the structure of the `getFileApplicationAccessRequest`.

#### getNotificationSettingRequest

Structure containing the parameters to include in the request when `id=RequestIdGetNotificationSetting`.

[GetNotificationSettingRequest](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-getnotificationsettingrequest) defines the structure of the `getNotificationSettingRequest`.

#### sendOperationEnforcementEventRequest

Structure containing the parameters to include in the request when `id=RequestIdSendOperationEnforcementEvent`.

[SendOperationEnforcementEventRequest](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-sendoperationenforcementeventrequest) defines the structure of the `sendOperationEnforcementEventRequest`.

#### sendFileAccessEventRequest

Structure containing the parameters to include in the request when `id=RequestIdSendFileAccessEvent`.

[SendFileAccessEventRequest](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-sendfileaccesseventrequest) defines the structure of the `sendFileAccessEventRequest`.

## Remarks

Represents a specific versioned request. If `id=RequestIdGetFileCloudApplicationPolicy`, then `getFileCloudApplicationPolicyRequest` should be set, etc.

## Requirements

| Requirement | Value |
|-------------|-------|
| Minimum supported client | Windows 11, version 24H2 (Build 26100) |
| DLL | EndpointDlp.dll |