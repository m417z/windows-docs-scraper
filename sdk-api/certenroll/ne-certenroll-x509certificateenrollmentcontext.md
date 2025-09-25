# X509CertificateEnrollmentContext enumeration

## Description

The **X509CertificateEnrollmentContext** enumeration specifies the nature of the end entity for which the [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) is intended. This enumeration is used by the following interfaces:

* [IX509CertificateRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequest)
* [IX509CertificateRequestPkcs7](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7)
* [IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)
* [IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment)

## Constants

### `ContextNone:0`

### `ContextUser:0x1`

The certificate is intended for an end user.

### `ContextMachine:0x2`

The certificate is intended for a computer.

### `ContextAdministratorForceMachine:0x3`

The certificate is being requested by an administrator acting on the behalf of a computer.

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-interfaces)