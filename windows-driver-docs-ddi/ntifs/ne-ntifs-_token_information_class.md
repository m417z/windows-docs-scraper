# TOKEN_INFORMATION_CLASS enumeration

## Description

The **TOKEN_INFORMATION_CLASS** enumeration type contains values that specify the type of information being assigned to or retrieved from an access token.

[**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken) and [**ZwQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryinformationtoken) use **TOKEN_INFORMATION_CLASS** values to indicate the type of token information to retrieve.

## Constants

### `TokenUser`

The buffer receives a [**TOKEN_USER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_user) structure containing the token's user account.

### `TokenGroups`

The buffer receives a [**TOKEN_GROUPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_groups) structure containing the group accounts associated with the token.

### `TokenPrivileges`

The buffer receives a [**TOKEN_PRIVILEGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_privileges) structure containing the token's privileges.

### `TokenOwner`

The buffer receives a [**TOKEN_OWNER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_owner) structure containing the default owner SID for newly created objects.

### `TokenPrimaryGroup`

The buffer receives a [**TOKEN_PRIMARY_GROUP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_primary_group) structure containing the default primary group SID for newly created objects.

### `TokenDefaultDacl`

The buffer receives a [**TOKEN_DEFAULT_DACL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_default_dacl) structure containing the default discretionary ACL (DACL) for newly created objects.

### `TokenSource`

The buffer receives a [**TOKEN_SOURCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_source) structure containing the source of the token. TOKEN_QUERY_SOURCE access is needed to retrieve this information.

### `TokenType`

The buffer receives a [**TOKEN_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_type) value indicating whether the token is a primary or impersonation token.

### `TokenImpersonationLevel`

The buffer receives a [**SECURITY_IMPERSONATION_LEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_security_impersonation_level) value indicating the impersonation level of the token. If the access token is not an impersonation token, the call to [**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken) or [**ZwQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryinformationtoken) fails.

### `TokenStatistics`

The buffer receives a [**TOKEN_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_statistics) structure containing various token statistics.

### `TokenRestrictedSids`

The buffer receives a [**TOKEN_GROUPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_groups) structure containing the list of restricting SIDs in a restricted token. This value is valid starting with Windows Vista.

### `TokenSessionId`

The buffer receives a DWORD value that indicates the Terminal Services session identifier associated with the token. If the token is associated with the Terminal Server console session, the session identifier is zero. A nonzero session identifier indicates a Terminal Services client session. In a non-Terminal Services environment, the session identifier is zero. This value is valid starting with Windows Vista.

### `TokenGroupsAndPrivileges`

The buffer receives a [**TOKEN_GROUPS_AND_PRIVILEGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_groups_and_privileges) structure that contains the user SID, the group accounts, the restricted SIDs, and the authentication ID associated with the token. This value is valid starting with Windows Vista.

### `TokenSessionReference`

Reserved for system use.

### `TokenSandBoxInert`

The buffer receives a DWORD value that is nonzero if the token includes the SANDBOX_INERT flag. This value is valid starting with Windows Vista.

### `TokenAuditPolicy`

Reserved for system use.

### `TokenOrigin`

The buffer receives a [**TOKEN_ORIGIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_origin) value.

If the token resulted from a logon that used explicit credentials, such as passing a name, domain, and password to the user-mode [**LogonUser**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-logonusera) function, then the **TOKEN_ORIGIN** structure will contain the ID of the logon session that created it.

If the token resulted from network authentication, such as a call to user-mode **AcceptSecurityContext** function or a call to user-mode **LogonUser** function with dwLogonType set to LOGON32_LOGON_NETWORK or LOGON32_LOGON_NETWORK_CLEARTEXT, then this value will be zero.

 This value is valid starting with Windows Server 2003.

### `TokenElevationType`

### `TokenLinkedToken`

The buffer receives a [**TOKEN_LINKED_TOKEN**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-token_linked_token) structure that contains a handle to another token that is linked to this token. This value is valid starting with Windows Vista.

### `TokenElevation`

The buffer receives a [**TOKEN_ELEVATION**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-token_elevation) structure that specifies whether the token is elevated. This value is valid starting with Windows Vista.

### `TokenHasRestrictions`

The buffer receives a **DWORD** value that is nonzero if the token has ever been filtered. This value is valid starting with Windows Vista.

### `TokenAccessInformation`

The buffer receives a [**TOKEN_ACCESS_INFORMATION**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-token_access_information) structure that specifies security information contained in the token. This value is valid starting with Windows Vista.

### `TokenVirtualizationAllowed`

The buffer receives a **DWORD** value that is nonzero if [**virtualization**](https://learn.microsoft.com/previous-versions/windows/hardware/design/dn614617(v=vs.85)) is allowed for the token. This value is valid starting with Windows Vista.

### `TokenVirtualizationEnabled`

The buffer receives a **DWORD** value that is nonzero if [**virtualization**](https://learn.microsoft.com/previous-versions/windows/hardware/design/dn614617(v=vs.85)) is enabled for the token. This value is valid starting with Windows Vista.

### `TokenIntegrityLevel`

The buffer receives a [**TOKEN_MANDATORY_LABEL**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-token_mandatory_label) structure that specifies the token's integrity level. This value is valid starting with Windows Vista. For [**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken) the output is the actual integrity level (**DWORD**).

### `TokenUIAccess`

The buffer receives a **DWORD** value that is nonzero if the token has the UIAccess flag set. This value is valid starting with Windows Vista.

### `TokenMandatoryPolicy`

The buffer receives a [**TOKEN_MANDATORY_POLICY**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-token_mandatory_policy) structure that specifies the token's mandatory integrity policy. This value is valid starting with Windows Vista.

### `TokenLogonSid`

The buffer receives a [**TOKEN_GROUPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_groups) structure that specifies the token's logon SID. This value is valid starting with Windows Vista.

### `TokenIsAppContainer`

The buffer receives a **DWORD** value that is nonzero if the token has the application container flag set. This value is valid starting with Windows 8.

### `TokenCapabilities`

The buffer receives a **TOKEN_GROUPS** structure and an array of **SID_AND_ATTRIBUTES** structures for each token capability. This value is valid starting with Windows 8.

### `TokenAppContainerSid`

The buffer receives a **TOKEN_APPCONTAINER_INFORMATION** structure that contains the AppContainerSid associated with the token. If the token is not associated with an app container, the TokenAppContainer member of the **TOKEN_APPCONTAINER_INFORMATION** structure points to NULL. This value is valid starting with Windows 8.

### `TokenAppContainerNumber`

The buffer receives a **DWORD** value that is the application container number. This value is valid starting with Windows 8.

### `TokenUserClaimAttributes`

The buffer receives a [**CLAIM_SECURITY_ATTRIBUTES_INFORMATION**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-token_mandatory_policy) structure that specifies the user's claim attributes. This value is valid starting with Windows 8.

### `TokenDeviceClaimAttributes`

The buffer receives a [**CLAIM_SECURITY_ATTRIBUTES_INFORMATION**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-token_mandatory_policy) structure that specifies the device's claim attributes. This value is valid starting with Windows 8.

### `TokenRestrictedUserClaimAttributes`

Reserved for system use.

### `TokenRestrictedDeviceClaimAttributes`

Reserved for system use.

### `TokenDeviceGroups`

The buffer receives a **TOKEN_GROUPS** structure and an array of **SID_AND_ATTRIBUTES** structures for each device group. This value is valid starting with Windows 8.

### `TokenRestrictedDeviceGroups`

Reserved for system use.

### `TokenSecurityAttributes`

Reserved for system use.

### `TokenIsRestricted`

Reserved for system use.

### `TokenProcessTrustLevel`

Reserved for system use.

### `TokenPrivateNameSpace`

Reserved for system use.

### `TokenSingletonAttributes`

Reserved for system use.

### `TokenBnoIsolation`

Reserved for system use.

### `TokenChildProcessFlags`

Reserved for system use.

### `TokenIsLessPrivilegedAppContainer`

Returns a **DWORD** value that is nonzero if the token is for a less privileged app container.

### `TokenIsSandboxed`

Returns a **DWORD** value that is nonzero if the token is for a sandboxed process or app.

### `TokenIsAppSilo`

Returns a **DWORD** value that is nonzero if the token is associated with an app silo.

### `TokenLoggingInformation`

The buffer receives a **TOKEN_LOGGING_INFORMATION** structure with logging information associated with the token.

### `MaxTokenInfoClass`

The maximum value for this enumeration.

## See also

[**ACL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[**SECURITY_IMPERSONATION_LEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_security_impersonation_level)

[**SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[**SeFilterToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sefiltertoken)

[**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken)

[**SeTokenIsRestricted**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-setokenisrestricted)

[**TOKEN_DEFAULT_DACL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_default_dacl)

[**TOKEN_GROUPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_groups)

[**TOKEN_ORIGIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_origin)

[**TOKEN_OWNER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_owner)

[**TOKEN_PRIMARY_GROUP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_primary_group)

[**TOKEN_PRIVILEGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_privileges)

[**TOKEN_SOURCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_source)

[**TOKEN_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_statistics)

[**TOKEN_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_type)

[**TOKEN_USER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_user)

[**ZwQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryinformationtoken)

[**ZwSetInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetinformationtoken)