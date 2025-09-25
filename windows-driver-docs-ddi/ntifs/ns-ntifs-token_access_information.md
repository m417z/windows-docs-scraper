## Description

The **TOKEN_ACCESS_INFORMATION** structure specifies all the information in a token that is necessary to perform an access check.

## Members

### `SidHash`

Pointer to a [**SID_AND_ATTRIBUTES_HASH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-sid_and_attributes_hash) structure that specifies a hash of the token's security identifier (SID).

### `RestrictedSidHash`

Pointer to a [**SID_AND_ATTRIBUTES_HASH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-sid_and_attributes_hash) structure that specifies a hash of the token's restricted SID.

### `Privileges`

Pointer to a [**TOKEN_PRIVILEGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_privileges) structure that specifies information about the token's privileges.

### `AuthenticationId`

A [**LUID**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-luid) structure that specifies the token's identity.

### `TokenType`

A [**TOKEN_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_type) enumeration value that specifies the token's type.

### `ImpersonationLevel`

A [**SECURITY_IMPERSONATION_LEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_security_impersonation_level) enumeration value that specifies the token's impersonation level.

### `MandatoryPolicy`

A [**TOKEN_MANDATORY_POLICY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-token_mandatory_policy) structure that specifies the token's mandatory integrity policy.

### `Flags`

Reserved. Must be set to zero.

### `AppContainerNumber`

The app container number for the token or zero if this is not an app container token.

### `PackageSid`

The app container [**SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid) or NULL if this is not an app container token.

### `CapabilitiesHash`

Pointer to a [**SID_AND_ATTRIBUTES_HASH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-sid_and_attributes_hash) structure that specifies a hash of the token's capability SIDs.

### `TrustLevelSid`

Pointer to a [**SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid) value that specifies the protected process trust level of the token.

### `SecurityAttributes`

Reserved. Must be set to NULL.

## Remarks

## See also

[**SeAccessCheckFromState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seaccesscheckfromstate)