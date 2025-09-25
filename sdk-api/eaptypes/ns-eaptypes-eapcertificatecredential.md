## Description

The **EapCertificateCredential** structure contains information about the certificate that the EAP method uses for authentication.

## Members

### `certHash`

SHA1 hash of the certificate.

### `password`

If the certificate is present on the system and strong private key protection is turned on for this certificate, this field contains the password to access the certificate.

## See also

[EapCredential](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eapcredential)

[EapCredentialType](https://learn.microsoft.com/windows/desktop/api/eaptypes/ne-eaptypes-eapcredentialtype)