# SetSecurityAccessMask function

## Description

The **SetSecurityAccessMask** function creates an access mask that represents the access permissions necessary to set the specified object security information.

## Parameters

### `SecurityInformation` [in]

A [SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) structure that specifies the security information to be set.

### `DesiredAccess` [out]

A pointer to the access mask that this function creates.

## See also

[QuerySecurityAccessMask](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-querysecurityaccessmask)