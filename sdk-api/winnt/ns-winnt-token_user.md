# TOKEN_USER structure

## Description

The **TOKEN_USER** structure identifies the user associated with an [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly).

## Members

### `User`

Specifies a
[SID_AND_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_and_attributes) structure representing the user associated with the access token. There are currently no attributes defined for user [security identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIDs).

## See also

[GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation)

[SID_AND_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_and_attributes)

[TOKEN_CONTROL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_control)

[TOKEN_DEFAULT_DACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_default_dacl)

[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups)

[TOKEN_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_information_class)

[TOKEN_OWNER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_owner)

[TOKEN_PRIMARY_GROUP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_primary_group)

[TOKEN_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_privileges)

[TOKEN_SOURCE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_source)

[TOKEN_STATISTICS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_statistics)

[TOKEN_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_type)