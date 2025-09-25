# InstallResponseRestrictionFlags enumeration

## Description

The **InstallResponseRestrictionFlags** enumeration contains flags that identify the restrictions placed on the local installation of a certificate chain. This enumeration is used by the [InstallResponse](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-installresponse) method on the [IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment) interface.

## Constants

### `AllowNone:0`

Does not allow the installation of untrusted certificates or certificates for which there is no corresponding request.

### `AllowNoOutstandingRequest:0x1`

Creates the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) from the certificate response rather than from the dummy certificate. This makes the dummy certificate optional. If this value is not set, the dummy certificate must exist, and the private key is extracted from it.

### `AllowUntrustedCertificate:0x2`

Installs untrusted end entity and [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) certificates. Certification authority certificates include root and subordinate certification authority certificates. End entity certificates are installed to the personal store, and certification authority certificates are installed to the certification authority store.

### `AllowUntrustedRoot:0x4`

Performs the same action as the **AllowUntrustedCertificate** flag but also installs the certificate even if the certificate chain cannot be built because the root is not trusted.

**Note** On Windows Vista, the behavior of this flag is the same as that defined for the **AllowUntrustedCertificate** flag. You can install an untrusted root beginning with Windows Vista with SP1.

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-interfaces)

[InstallResponse](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-installresponse)