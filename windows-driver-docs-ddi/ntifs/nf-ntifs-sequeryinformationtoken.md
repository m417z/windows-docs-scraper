# SeQueryInformationToken function

## Description

The **SeQueryInformationToken** routine retrieves a specified type of information about an access token. The calling process must have appropriate access rights to obtain the information.

## Parameters

### `Token` [in]

A pointer to an access token from which information is to be retrieved. If *TokenInformationClass* is set to *TokenSource*, the handle must have TOKEN_QUERY_SOURCE access. For all other *TokenInformationClass* values, the handle must have TOKEN_QUERY access.

### `TokenInformationClass` [in]

A value from the [TOKEN_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_information_class) enumerated type that identifies the type of information to be retrieved.

### `TokenInformation` [out]

If STATUS_SUCCESS is returned,
*TokenInformation* receives a pointer to a
location that contains the address of a buffer that holds the requested
information. The format of this information buffer depends upon the
value of *TokenInformationClass*, as shown in
the following table. Be aware that the buffer is allocated by
**SeQueryInformationToken**
from paged pool. This buffer must eventually be freed by the caller by
using
[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool).

| Value | Description |
| --- | --- |
| **TokenDefaultDacl** | The buffer receives a [TOKEN_DEFAULT_DACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_default_dacl) structure that contains the default DACL for newly created objects. |
| **TokenGroups** | The buffer receives a [TOKEN_GROUPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_groups) structure that contains the group accounts associated with the token. |
| **TokenImpersonationLevel** | The buffer receives a [SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_security_impersonation_level) value which indicates the impersonation level of the token. If the access token is not an impersonation token, the call to **SeQueryInformationToken** fails. |
| **TokenOwner** | The buffer receives a [TOKEN_OWNER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_owner) structure that contains the default owner security identifier ([SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)) for newly created objects. |
| **TokenPrimaryGroup** | The buffer receives a [TOKEN_PRIMARY_GROUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_primary_group) structure that contains the default primary group SID for newly created objects. |
| **TokenPrivileges** | The buffer receives a [TOKEN_PRIVILEGES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_privileges) structure that contains the token's privileges. |
| **TokenSessionId** | The buffer receives a **DWORD** value (not a pointer to it) that indicates the Terminal Services session identifier that is associated with the token. If the token is associated with the Terminal Server console session, the session identifier is zero. A nonzero session identifier indicates a Terminal Services client session. In a non-Terminal Services environment, the session identifier is zero. |
| **TokenSource** | The buffer receives a [TOKEN_SOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_source) structure that contains the source of the token. TOKEN_QUERY_SOURCE access is needed to retrieve this information. |
| **TokenStatistics** | The buffer receives a [TOKEN_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_statistics) structure that contains various token statistics. |
| **TokenType** | The buffer receives a [TOKEN_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_type) value that indicates whether the token is a primary or impersonation token. |
| **TokenUser** | The buffer receives a [TOKEN_USER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_user) structure that contains the token's user account. |
| **TokenIntegrityLevel** | The buffer receives a **DWORD** value (not a pointer to it) that specifies the token’s integrity level. |

## Return value

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The call to [SeQueryInformationToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken) succeeded. |
| **STATUS_INVALID_INFO_CLASS** | An invalid value was supplied for *TokenInformationClass*. |

## Remarks

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[PsDereferenceImpersonationToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psdereferenceimpersonationtoken)

[PsDereferencePrimaryToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psdereferenceprimarytoken)

[SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_security_impersonation_level)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[SeQueryAuthenticationIdToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryauthenticationidtoken)

[SeQuerySubjectContextToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequerysubjectcontexttoken)

[SeTokenIsAdmin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-setokenisadmin)

[SeTokenIsRestricted](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-setokenisrestricted)

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