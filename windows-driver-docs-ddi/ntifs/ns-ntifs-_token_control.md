# _TOKEN_CONTROL structure

## Description

The TOKEN_CONTROL structure contains information that identifies an access token.

## Members

### `TokenId`

Specifies a locally unique identifier (LUID) identifying this instance of the token object.

### `AuthenticationId`

Specifies an LUID assigned to the session this token represents. There can be many tokens representing a single logon session.

### `ModifiedId`

Specifies an LUID that changes each time the token is modified. An application can use this value as a test of whether a security context has changed since it was last used.

### `TokenSource`

Specifies a [TOKEN_SOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_source) structure identifying the source that issued the token. This information is used in audit logging.

## See also

[LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)

[LUID_AND_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_luid_and_attributes)

[TOKEN_DEFAULT_DACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_default_dacl)

[TOKEN_GROUPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_groups)

[TOKEN_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_information_class)

[TOKEN_OWNER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_owner)

[TOKEN_PRIMARY_GROUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_primary_group)

[TOKEN_PRIVILEGES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_privileges)

[TOKEN_SOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_source)

[TOKEN_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_statistics)

[TOKEN_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_type)

[TOKEN_USER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_user)