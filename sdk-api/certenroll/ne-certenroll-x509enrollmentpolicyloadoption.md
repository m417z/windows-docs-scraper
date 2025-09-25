# X509EnrollmentPolicyLoadOption enumeration

## Description

The **X509EnrollmentPolicyLoadOption** enumeration is used by the [LoadPolicy](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentpolicyserver-loadpolicy) method on the [IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver) interface to specify how to retrieve policy from the policy server.

## Constants

### `LoadOptionDefault:0`

Reload if the cache has expired.

### `LoadOptionCacheOnly:1`

Always load from the cache even if it has expired.

### `LoadOptionReload:2`

Always reload.

### `LoadOptionRegisterForADChanges:4`

Registers a thread to update a sequence number if there are changes to the template or the certification authority container. This value applies only to an Active Directory policy server.

## See also

[LoadPolicy](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentpolicyserver-loadpolicy)