# TOKEN_SOURCE structure

## Description

The **TOKEN_SOURCE** structure identifies the source of an [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly).

## Members

### `SourceName`

Specifies an 8-byte character string used to identify the source of an access token. This is used to distinguish between such sources as Session Manager, LAN Manager, and RPC Server. A string, rather than a constant, is used to identify the source so users and developers can make extensions to the system, such as by adding other networks, that act as the source of access tokens.

### `SourceIdentifier`

Specifies a locally unique identifier ([LUID](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly)) provided by the source component named by the **SourceName** member. This value aids the source component in relating context blocks, such as session-control structures, to the token. This value is typically, but not necessarily, an LUID.

## See also

[GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation)

[LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid)

[TOKEN_CONTROL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_control)

[TOKEN_DEFAULT_DACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_default_dacl)

[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups)

[TOKEN_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_information_class)

[TOKEN_OWNER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_owner)

[TOKEN_PRIMARY_GROUP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_primary_group)

[TOKEN_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_privileges)

[TOKEN_STATISTICS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_statistics)

[TOKEN_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_type)

[TOKEN_USER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_user)