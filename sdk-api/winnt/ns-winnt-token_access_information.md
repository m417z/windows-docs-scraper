# TOKEN_ACCESS_INFORMATION structure

## Description

The **TOKEN_ACCESS_INFORMATION** structure specifies all the information in a token that is necessary to perform an access check.

**Note** This structure doesn't contain token claim information. Applications that support conditional expression [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs) should not use this structure for verifying access. For information about access validation support for conditional expressions, see the [AuthzAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzaccesscheck) and [AccessCheckAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckandauditalarma) functions.

## Members

### `SidHash`

A pointer to a [SID_AND_ATTRIBUTES_HASH](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_and_attributes_hash) structure that specifies a hash of the token's [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID).

### `RestrictedSidHash`

A pointer to a [SID_AND_ATTRIBUTES_HASH](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_and_attributes_hash) structure that specifies a hash of the token's restricted SID.

### `Privileges`

A pointer to a [TOKEN_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_privileges) structure that specifies information about the token's privileges.

### `AuthenticationId`

A [LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid) structure that specifies the token's identity.

### `TokenType`

A value of the [TOKEN_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_type) enumeration that specifies the token's type.

### `ImpersonationLevel`

A value of the [SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-security_impersonation_level) enumeration that specifies the token's impersonation level.

### `MandatoryPolicy`

A [TOKEN_MANDATORY_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_mandatory_policy) structure that specifies the token's mandatory integrity policy.

### `Flags`

Reserved. Must be set to zero.

### `AppContainerNumber`

The app container number for the token or zero if this is not an app container token.

**Windows Server 2008 R2, Windows 7, Windows Server 2008 and Windows Vista:** This member is not available.

### `PackageSid`

The app container SID or **NULL** if this is not an app container token.

**Windows Server 2008 R2, Windows 7, Windows Server 2008 and Windows Vista:** This member is not available.

### `CapabilitiesHash`

Pointer to a [SID_AND_ATTRIBUTES_HASH](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_and_attributes_hash) structure that specifies a hash of the token's capability SIDs.

**Windows Server 2008 R2, Windows 7, Windows Server 2008 and Windows Vista:** This member is not available.

### `TrustLevelSid`

The protected process trust level of the token.

### `SecurityAttributes`

Reserved. Must be set to **NULL**.

**Prior to Windows 10:** This member is not available.

## See also

[TOKEN_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_information_class)