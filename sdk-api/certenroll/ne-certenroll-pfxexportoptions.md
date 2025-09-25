# PFXExportOptions enumeration

## Description

The **PFXExportOptions** enumeration specifies how much of a certificate chain is included when creating a Personal Information Exchange (PFX) message. The PFX message syntax is defined by the PKCS #12 standard. PFX is a transfer syntax for personal identity information, including [private keys](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) and [certificates](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). The enumeration is used by the [CreatePFX](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-createpfx) method on the [IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment) interface.

## Constants

### `PFXExportEEOnly:0`

Includes only the end entity certificate.

### `PFXExportChainNoRoot:1`

Includes the certificate chain without the root [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) certificate.

### `PFXExportChainWithRoot:2`

Includes the entire certificate chain, including the root certification authority certificate.

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-interfaces)

[CreatePFX](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-createpfx)