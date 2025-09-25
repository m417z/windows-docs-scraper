# AUTHZ_CONTEXT_INFORMATION_CLASS enumeration

## Description

The **AUTHZ_CONTEXT_INFORMATION_CLASS** enumeration specifies the type of information to be retrieved from an existing AuthzClientContext. This enumeration is used by the [AuthzGetInformationFromContext](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzgetinformationfromcontext) function.

## Constants

### `AuthzContextInfoUserSid:1`

Retrieves a [TOKEN_USER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_user) structure that contains a user [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) and its attribute.

### `AuthzContextInfoGroupsSids`

Retrieves a [TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure that contains the group SIDs to which the user belongs and their attributes.

### `AuthzContextInfoRestrictedSids`

Retrieves a [TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure that contains the restricted group SIDs in the context and their attributes.

### `AuthzContextInfoPrivileges`

Retrieves a [TOKEN_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_privileges) structure that contains the privileges held by the user.

### `AuthzContextInfoExpirationTime`

Retrieves the expiration time set on the context.

### `AuthzContextInfoServerContext`

This constant is reserved. Do not use it.

### `AuthzContextInfoIdentifier`

Retrieves an [LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid) structures used by the resource manager to identify the context.

### `AuthzContextInfoSource`

This constant is reserved. Do not use it.

### `AuthzContextInfoAll`

This constant is reserved. Do not use it.

### `AuthzContextInfoAuthenticationId`

This constant is reserved. Do not use it.

### `AuthzContextInfoSecurityAttributes`

Retrieves an [AUTHZ_SECURITY_ATTRIBUTES_INFORMATION](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_security_attributes_information) structure that contains security attributes.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported.

### `AuthzContextInfoDeviceSids`

Retrieves a [TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure that contains device SIDs and their attributes.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported.

### `AuthzContextInfoUserClaims`

Retrieves a [AUTHZ_SECURITY_ATTRIBUTES_INFORMATION](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_security_attributes_information) structure that contains user claims.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported.

### `AuthzContextInfoDeviceClaims`

Retrieves a [AUTHZ_SECURITY_ATTRIBUTES_INFORMATION](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_security_attributes_information) structure that contains device claims.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported.

### `AuthzContextInfoAppContainerSid`

Retrieves a [TOKEN_APPCONTAINER_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_appcontainer_information) structure that contains the app container SID.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported.

### `AuthzContextInfoCapabilitySids`

Retrieves a [TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure that contains capability SIDs.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported.

## See also

[Authorization Enumerations](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-enumerations)

[AuthzGetInformationFromContext](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzgetinformationfromcontext)

[SECURITY_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_capabilities)

[TOKEN_APPCONTAINER_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_appcontainer_information)

[TOKEN_DEVICE_CLAIMS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_device_claims)

[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups)

[TOKEN_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_privileges)

[TOKEN_USER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_user)

[TOKEN_USER_CLAIMS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_user_claims)