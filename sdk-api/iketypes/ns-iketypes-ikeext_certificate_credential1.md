# IKEEXT_CERTIFICATE_CREDENTIAL1 structure

## Description

The [IKEEXT_CERTIFICATE_CREDENTIAL0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_certificate_credential0) is available.

## Members

### `subjectName`

Encoded subject name of the certificate used for authentication. Use [CertNameToStr](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certnametostra) to convert the encoded name to string.

See [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob) for more information.

### `certHash`

SHA thumbprint of the certificate.

See [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob) for more information.

### `flags`

Possible values:

#### IKEEXT_CERT_CREDENTIAL_FLAG_NAP_CERT

### `certificate`

The encoded certificate. Use [CertCreateCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatecertificatecontext) to create a certificate context from the encoded certificate.

See [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob) for more information.

## See also

[FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)