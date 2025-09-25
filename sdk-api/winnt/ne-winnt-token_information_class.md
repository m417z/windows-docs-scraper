## Description

The **TOKEN_INFORMATION_CLASS** enumeration contains values that specify the type of information being assigned to or retrieved from an [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly).

The [GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation) function uses these values to indicate the type of token information to retrieve.

The [SetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-settokeninformation) function uses these values to set the token information.

## Constants

### `TokenUser:1`

The buffer receives a
[TOKEN_USER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_user) structure that contains the user account of the token.

### `TokenGroups`

The buffer receives a
[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure that contains the group accounts associated with the token.

### `TokenPrivileges`

The buffer receives a
[TOKEN_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_privileges) structure that contains the privileges of the token.

### `TokenOwner`

The buffer receives a
[TOKEN_OWNER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_owner) structure that contains the default owner [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) for newly created objects.

### `TokenPrimaryGroup`

The buffer receives a
[TOKEN_PRIMARY_GROUP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_primary_group) structure that contains the default primary group SID for newly created objects.

### `TokenDefaultDacl`

The buffer receives a
[TOKEN_DEFAULT_DACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_default_dacl) structure that contains the default DACL for newly created objects.

### `TokenSource`

The buffer receives a
[TOKEN_SOURCE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_source) structure that contains the source of the token. **TOKEN_QUERY_SOURCE** access is needed to retrieve this information.

### `TokenType`

The buffer receives a
[TOKEN_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_type) value that indicates whether the token is a [primary](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) or [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly).

### `TokenImpersonationLevel`

The buffer receives a
[SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-security_impersonation_level) value that indicates the impersonation level of the token. If the access token is not an [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly), the function fails.

### `TokenStatistics`

The buffer receives a
[TOKEN_STATISTICS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_statistics) structure that contains various token statistics.

### `TokenRestrictedSids`

The buffer receives a
[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure that contains the list of restricting SIDs in a
[restricted token](https://learn.microsoft.com/windows/desktop/SecAuthZ/restricted-tokens).

### `TokenSessionId`

The buffer receives a **DWORD** value that indicates the Terminal Services session identifier that is associated with the token.

If the token is associated with the terminal server client session, the session identifier is nonzero.

**Windows Server 2003 and Windows XP:** If the token is associated with the terminal server console session, the session identifier is zero.

In a non-Terminal Services environment, the session identifier is zero.

If **TokenSessionId** is set with [SetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-settokeninformation), the application must have the **Act As Part Of the Operating System** privilege, and the application must be enabled to set the session ID in a token.

### `TokenGroupsAndPrivileges`

The buffer receives a [TOKEN_GROUPS_AND_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups_and_privileges) structure that contains the user SID, the group accounts, the restricted SIDs, and the authentication ID associated with the token.

### `TokenSessionReference`

Reserved.

### `TokenSandBoxInert`

The buffer receives a **DWORD** value that is nonzero if the token includes the **SANDBOX_INERT** flag.

### `TokenAuditPolicy`

Reserved.

### `TokenOrigin`

The buffer receives a [TOKEN_ORIGIN](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_origin) value.

If the token resulted from a logon that used explicit credentials, such as passing a name, domain, and password to the [LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera) function, then the [TOKEN_ORIGIN](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_origin) structure will contain the ID of the [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) that created it.

If the token resulted from network authentication, such as a call to [AcceptSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) or a call to [LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera) with *dwLogonType* set to **LOGON32_LOGON_NETWORK** or **LOGON32_LOGON_NETWORK_CLEARTEXT**, then this value will be zero.

### `TokenElevationType`

The buffer receives a [TOKEN_ELEVATION_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_elevation_type) value that specifies the elevation level of the token.

### `TokenLinkedToken`

The buffer receives a [TOKEN_LINKED_TOKEN](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_linked_token) structure that contains a handle to another token that is linked to this token.

### `TokenElevation`

The buffer receives a [TOKEN_ELEVATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_elevation) structure that specifies whether the token is elevated.

### `TokenHasRestrictions`

The buffer receives a **DWORD** value that is nonzero if the token has ever been filtered.

### `TokenAccessInformation`

The buffer receives a [TOKEN_ACCESS_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_access_information) structure that specifies security information contained in the token.

### `TokenVirtualizationAllowed`

The buffer receives a **DWORD** value that is nonzero if [virtualization](https://learn.microsoft.com/windows/desktop/SecGloss/v-gly) is allowed for the token.

### `TokenVirtualizationEnabled`

The buffer receives a **DWORD** value that is nonzero if [virtualization](https://learn.microsoft.com/windows/desktop/SecGloss/v-gly) is enabled for the token.

### `TokenIntegrityLevel`

The buffer receives a [TOKEN_MANDATORY_LABEL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_mandatory_label) structure that specifies the token's integrity level.

### `TokenUIAccess`

The buffer receives a **DWORD** value that is nonzero if the token has the UIAccess flag set.

### `TokenMandatoryPolicy`

The buffer receives a [TOKEN_MANDATORY_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_mandatory_policy) structure that specifies the token's mandatory integrity policy.

### `TokenLogonSid`

The buffer receives a [TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure that specifies the token's logon SID.

### `TokenIsAppContainer`

The buffer receives a **DWORD** value that is nonzero if the token is an app container token. Any callers who check the **TokenIsAppContainer** and have it return 0 should also verify that the caller token is not an identify level impersonation token. If the current token is not an app container but is an identity level token, you should return **AccessDenied**.

### `TokenCapabilities`

The buffer receives a [TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure that contains the capabilities associated with the token.

### `TokenAppContainerSid`

The buffer receives a [TOKEN_APPCONTAINER_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_appcontainer_information) structure that contains the AppContainerSid associated with the token. If the token is not associated with an app container, the **TokenAppContainer** member of the **TOKEN_APPCONTAINER_INFORMATION** structure points to **NULL**.

### `TokenAppContainerNumber`

The buffer receives a **DWORD** value that includes the app container number for the token. For tokens that are not app container tokens, this value is zero.

### `TokenUserClaimAttributes`

The buffer receives a [CLAIM_SECURITY_ATTRIBUTES_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-claim_security_attributes_information) structure that contains the user claims associated with the token.

### `TokenDeviceClaimAttributes`

The buffer receives a [CLAIM_SECURITY_ATTRIBUTES_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-claim_security_attributes_information) structure that contains the device claims associated with the token.

### `TokenRestrictedUserClaimAttributes`

This value is reserved.

### `TokenRestrictedDeviceClaimAttributes`

This value is reserved.

### `TokenDeviceGroups`

The buffer receives a [TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure that contains the device groups that are associated with the token.

### `TokenRestrictedDeviceGroups`

The buffer receives a [TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure that contains the restricted device groups that are associated with the token.

### `TokenSecurityAttributes`

This value is reserved.

### `TokenIsRestricted`

This value is reserved.

### `TokenProcessTrustLevel`

### `TokenPrivateNameSpace`

### `TokenSingletonAttributes`

### `TokenBnoIsolation`

### `TokenChildProcessFlags`

### `TokenIsLessPrivilegedAppContainer`

Refers to a Least Privileged AppContainer (LPAC). An LPAC is effectively an AppContainer that's disregarded by the **ALL_APPLICATION_PACKAGES** SID. For info about what an AppContainer is, see [AppContainer for legacy apps](https://learn.microsoft.com/windows/win32/secauthz/appcontainer-for-legacy-applications-).

Many resources across Windows are ACL'd with **ALL_APPLICATION_PACKAGES**, as described in [DoNotAddAllApplicationPackagesToRestrictions](https://learn.microsoft.com/windows/win32/com/donotaddallapplicationpackagestorestrictions). In scenarios where you want a process running with no rights to any resources except what you explicitly grant (for example, a web browser sandboxing a child worker process), an AppContaoiner has too much access to the system because of **ALL_APPLICATION_PACKAGES**. That's where an LPAC comes in. You can create an LPAC only imperatively via APIs; not declaratively via `appxmanifest.xml`.

### `MaxTokenInfoClass`

The maximum value for this enumeration.

## See also

[Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Authorization Enumerations](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-enumerations)

[GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation)

[SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-security_impersonation_level)

[SetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-settokeninformation)

[TOKEN_CONTROL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_control)

[TOKEN_DEFAULT_DACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_default_dacl)

[TOKEN_DEVICE_CLAIMS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_device_claims)

[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups)

[TOKEN_GROUPS_AND_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups_and_privileges)

[TOKEN_ORIGIN](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_origin)

[TOKEN_OWNER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_owner)

[TOKEN_PRIMARY_GROUP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_primary_group)

[TOKEN_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_privileges)

[TOKEN_SOURCE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_source)

[TOKEN_STATISTICS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_statistics)

[TOKEN_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_type)

[TOKEN_USER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_user)

[TOKEN_USER_CLAIMS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_user_claims)