# QuerySecurityAccessMask function

## Description

The **QuerySecurityAccessMask** function creates an access mask that represents the access permissions necessary to query the specified object security information.

## Parameters

### `SecurityInformation` [in]

A [SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) structure that specifies the security information to be queried.

### `DesiredAccess` [out]

A pointer to the access mask that this function creates.

## See also

[SetSecurityAccessMask](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecurityaccessmask)