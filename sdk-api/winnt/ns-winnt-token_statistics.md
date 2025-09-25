# TOKEN_STATISTICS structure

## Description

The **TOKEN_STATISTICS** structure contains information about an [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly). An application can retrieve this information by calling the
[GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation) function.

## Members

### `TokenId`

Specifies a locally unique identifier ([LUID](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly)) that identifies this instance of the token object.

### `AuthenticationId`

Specifies an LUID assigned to the [session](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) this token represents. There can be many tokens representing a single [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly).

### `ExpirationTime`

Specifies the time at which this token expires. Expiration times for access tokens are not currently supported.

### `TokenType`

Specifies a [TOKEN_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_type) enumeration type indicating whether the token is a [primary](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) or [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly).

### `ImpersonationLevel`

Specifies a [SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-security_impersonation_level) enumeration type indicating the impersonation level of the token. This member is valid only if the **TokenType** is TokenImpersonation.

### `DynamicCharged`

Specifies the amount, in bytes, of memory allocated for storing default protection and a primary group identifier.

### `DynamicAvailable`

Specifies the portion of memory allocated for storing default protection and a primary group identifier not already in use. This value is returned as a count of free bytes.

### `GroupCount`

Specifies the number of supplemental group [security identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIDs) included in the token.

### `PrivilegeCount`

Specifies the number of privileges included in the token.

### `ModifiedId`

Specifies an LUID that changes each time the token is modified. An application can use this value as a test of whether a [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) has changed since it was last used.

## See also

[GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation)

[LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid)

[SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-security_impersonation_level)

[TOKEN_CONTROL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_control)

[TOKEN_DEFAULT_DACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_default_dacl)

[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups)

[TOKEN_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_information_class)

[TOKEN_OWNER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_owner)

[TOKEN_PRIMARY_GROUP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_primary_group)

[TOKEN_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_privileges)

[TOKEN_SOURCE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_source)

[TOKEN_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_type)

[TOKEN_USER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_user)