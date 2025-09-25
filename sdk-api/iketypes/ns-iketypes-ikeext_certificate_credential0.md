# IKEEXT_CERTIFICATE_CREDENTIAL0 structure

## Description

The **IKEEXT_CERTIFICATE_CREDENTIAL0** structure is used to store credential information specific to certificate authentication.
[IKEEXT_CERTIFICATE_CREDENTIAL1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_certificate_credential1) is available.

## Members

### `subjectName`

Encoded subject name of the certificate used for authentication.

See [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob) for more information.

### `certHash`

SHA thumbprint of the certificate.

See [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob) for more information.

### `flags`

Possible values:

#### IKEEXT_CERT_CREDENTIAL_FLAG_NAP_CERT

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)