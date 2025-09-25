# TOKEN_OWNER structure

## Description

The **TOKEN_OWNER** structure contains the default owner [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) that will be applied to newly created objects.

## Members

### `Owner`

A pointer to a [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure representing a user who will become the owner of any objects created by a process using this [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly). The SID must be one of the user or group SIDs already in the token.

## See also

[GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[SetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-settokeninformation)

[TOKEN_CONTROL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_control)

[TOKEN_DEFAULT_DACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_default_dacl)

[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups)

[TOKEN_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_information_class)

[TOKEN_PRIMARY_GROUP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_primary_group)

[TOKEN_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_privileges)

[TOKEN_SOURCE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_source)

[TOKEN_STATISTICS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_statistics)

[TOKEN_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_type)

[TOKEN_USER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_user)