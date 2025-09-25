# TOKEN_STATISTICS structure

## Description

The **TOKEN_STATISTICS** structure contains information about an access token. A driver can retrieve this information by calling [**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken) or [**ZwQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryinformationtoken).

## Members

### `TokenId`

Specifies a locally unique identifier ([**LUID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)) that identifies this instance of the token object.

### `AuthenticationId`

Specifies an LUID assigned to the session this token represents. There can be many tokens representing a single logon session.

### `ExpirationTime`

Specifies the time at which this token expires. Expiration times for access tokens are not currently supported.

### `TokenType`

Specifies a [**TOKEN_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_type) enumerated type indicating whether the token is a primary or impersonation token.

### `ImpersonationLevel`

Specifies a [**SECURITY_IMPERSONATION_LEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_security_impersonation_level) enumerated type indicating the impersonation level of the token. This member is valid only if the **TokenType** is TokenImpersonation.

### `DynamicCharged`

Specifies the amount, in bytes, of memory allocated for storing a default access-control list (DACL) and primary group identifier.

### `DynamicAvailable`

Specifies the portion of the memory allocated for storing a DACL and primary group identifier that is not already in use. This value is returned as a count of free bytes.

### `GroupCount`

Specifies the number of supplemental group security identifiers ([**SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)) included in the token.

### `PrivilegeCount`

Specifies the number of privileges included in the token.

### `ModifiedId`

Specifies an LUID that changes each time the token is modified. An application can use this value as a test of whether a security context has changed since it was last used.

## See also

[**ACL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[**LUID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)

[**SECURITY_IMPERSONATION_LEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_security_impersonation_level)

[**SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken)

[**TOKEN_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_information_class)

[**TOKEN_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_type)

[**ZwQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryinformationtoken)

[**ZwSetInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetinformationtoken)