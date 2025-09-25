# IKEEXT_CERTIFICATE_CRITERIA0 structure

## Description

The **IKEEXT_CERTIFICATE_CRITERIA0** structure contains a set of criteria to applied to an authentication method.

## Members

### `certData`

Type: [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob)

X509/ASN.1 encoded name of the root certificate. Should be empty when
specifying Enterprise or trusted root store config.

### `certHash`

Type: [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob)

 16-character hexadecimal string that represents the ID, thumbprint or HASH of the end certificate.

### `eku`

Type: [IKEEXT_CERT_EKUS0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_cert_ekus0)*

The specific extended key usage (EKU) object identifiers (OIDs) selected for the criteria on the end certificate.

### `name`

Type: [IKEEXT_CERT_NAME0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_cert_name0)*

The name/subject selected for the criteria on the end certificate.

### `flags`

Type: **UINT32**

Reserved for system use.

## Remarks

The **certData** member refers to the encoded name of the root certificate, while the **certHash**, **eku**, and **name** members refer to criteria on the end certificate.

## See also

[FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob)

[IKEEXT_CERT_EKUS0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_cert_ekus0)

[IKEEXT_CERT_NAME0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_cert_name0)