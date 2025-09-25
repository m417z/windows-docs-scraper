# TOKEN_CONTROL structure

## Description

The **TOKEN_CONTROL** structure contains information that identifies an [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly).

## Members

### `TokenId`

Specifies a [locally unique identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LUID) identifying this instance of the token object.

### `AuthenticationId`

Specifies an LUID assigned to the [session](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) this token represents. There can be many tokens representing a single [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly).

### `ModifiedId`

Specifies an LUID that changes each time the token is modified. An application can use this value as a test of whether a [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) has changed since it was last used.

### `TokenSource`

Specifies a [TOKEN_SOURCE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_source) structure identifying the agency that issued the token. This information is used in audit trails.

## See also

[LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid)

[TOKEN_DEFAULT_DACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_default_dacl)

[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups)

[TOKEN_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_information_class)

[TOKEN_OWNER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_owner)

[TOKEN_PRIMARY_GROUP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_primary_group)

[TOKEN_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_privileges)

[TOKEN_SOURCE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_source)

[TOKEN_STATISTICS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_statistics)

[TOKEN_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_type)

[TOKEN_USER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_user)