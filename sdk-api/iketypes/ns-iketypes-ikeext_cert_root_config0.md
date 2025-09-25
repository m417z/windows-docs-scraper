# IKEEXT_CERT_ROOT_CONFIG0 structure

## Description

The **IKEEXT_CERT_ROOT_CONFIG0** structure stores the IKE, AuthIP, or IKEv2 certificate root configuration.

## Members

### `certData`

X509/ASN.1 encoded name of the certificate root.

See [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob) for more information.

### `flags`

A combination of the following values.

| IKE/AuthIP/IKEv2 certificate flag | Meaning |
| --- | --- |
| **IKEEXT_CERT_FLAG_ENABLE_ACCOUNT_MAPPING** | Enable certificate-to-account mapping for the end-host certificate that chains to this root. |
| **IKEEXT_CERT_FLAG_DISABLE_REQUEST_PAYLOAD** | Do not send a Cert request payload for this root. |
| **IKEEXT_CERT_FLAG_USE_NAP_CERTIFICATE** | Enable Network Access Protection (NAP) certificate handling. |
| **IKEEXT_CERT_FLAG_INTERMEDIATE_CA** | The corresponding Certification Authority (CA) can be an intermediate CA and does not have to be a ROOT CA.<br><br>If this flag is not specified, the name will have to refer to a ROOT CA. |
| **IKEEXT_CERT_FLAG_IGNORE_INIT_CERT_MAP_FAILURE** | Ignore mapping failures on the initiator. Available only for IKE and IKEv2.<br><br>Can be set only if **IKEEXT_CERT_FLAG_ENABLE_ACCOUNT_MAPPING** is also specified. By default, IKE and IKEv2 will not ignore certificate to account mapping failures, even on the initiator.<br><br>Available only on Windows 7, Windows Server 2008 R2, and later. |
| **IKEEXT_CERT_FLAG_PREFER_NAP_CERTIFICATE_OUTBOUND** | NAP certificates will be preferred for local certificate selection. |
| **IKEEXT_CERT_FLAG_SELECT_NAP_CERTIFICATE** | Select a NAP certificate for outbound.<br><br>Available only on Windows 8 and Windows Server 2012. |
| **IKEEXT_CERT_FLAG_VERIFY_NAP_CERTIFICATE** | Verify that the inbound certificate is NAP.<br><br>Available only on Windows 8 and Windows Server 2012. |
| **IKEEXT_CERT_FLAG_FOLLOW_RENEWAL_CERTIFICATE** | Follow the renewal property on the certificate when selecting local certificate for outbound.<br><br>Only applicable when the hash of the certificate is specified.<br><br>Available only on Windows 8 and Windows Server 2012. |

## Remarks

**IKEEXT_CERT_ROOT_CONFIG0** is a specific implementation of IKEEXT_CERT_ROOT_CONFIG. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)