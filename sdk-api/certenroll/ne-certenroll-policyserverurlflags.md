# PolicyServerUrlFlags enumeration

## Description

The **PolicyServerUrlFlags** enumeration contains certificate enrollment policy (CEP) server flags. It is used by the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollmentpolicyserver-initialize) method on the [ICertPropertyEnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyenrollmentpolicyserver) interface.

## Constants

### `PsfNone:0`

No flags are specified.

### `PsfLocationGroupPolicy:1`

Policy information is specified in group policy by an administrator.

### `PsfLocationRegistry:2`

Policy information is specified in the registry.

### `PsfUseClientId:4`

Specifies that certificate enrollments and renewals include client specific data in a **ClientId** attribute. Examples include the name of the cryptographic service provider, the Windows version number, the user name, the computer DNS name, and the domain controller DNS name. This flag can be set by group policy.

This flag has been included to address privacy concerns that can arise during enrollment to servers that are managed by administrators other than those who manage the forest in which the user resides. By not setting this flag, you can prevent sending personal information to non-local administrators.

### `PsfAutoEnrollmentEnabled:16`

Automatic certificate enrollment is enabled.

### `PsfAllowUnTrustedCA:32`

Specifies that the certificate of the issuing CA need not be trusted by the client to install a certificate signed by the CA.

## See also

[ICertPropertyEnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyenrollmentpolicyserver)

[Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollmentpolicyserver-initialize)