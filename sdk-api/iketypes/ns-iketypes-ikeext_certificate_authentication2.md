# IKEEXT_CERTIFICATE_AUTHENTICATION2 structure

## Description

The **IKEEXT_CERTIFICATE_AUTHENTICATION2** structure is used to specify various parameters for authentication with certificates.
[IKEEXT_CERTIFICATE_AUTHENTICATION0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_certificate_authentication0) is available.

## Members

### `inboundConfigType`

Type: [IKEEXT_CERT_CONFIG_TYPE](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_cert_config_type)

Certificate configuration type for inbound peer certificate verification.

### `inboundRootArraySize`

Type: **UINT32**

Number of elements in the **inboundRootCriteria** member.

Available when **inboundConfigType** is **IKEEXT_CERT_CONFIG_EXPLICIT_TRUST_LIST**.

### `inboundRootCriteria`

Type: [IKEEXT_CERTIFICATE_CRITERIA0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_certificate_criteria0)*

List of certificate criteria containing explicit trusted authorities that should be used to verify the peer certificate chain.

Available when **inboundConfigType** is **IKEEXT_CERT_CONFIG_EXPLICIT_TRUST_LIST**.

### `inboundEnterpriseStoreArraySize`

Type: **UINT32**

Number of elements in the **inboundEnterpriseStoreCriteria** member.

Available when **inboundConfigType** is **IKEEXT_CERT_CONFIG_ENTERPRISE_STORE**.

### `inboundEnterpriseStoreCriteria`

Type: [IKEEXT_CERTIFICATE_CRITERIA0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_certificate_criteria0)*

List of enterprise store criteria that should be used to verify the peer certificate chain.

Available when **inboundConfigType** is **IKEEXT_CERT_CONFIG_ENTERPRISE_STORE**.

### `inboundRootStoreArraySize`

Type: **UINT32**

Number of elements in the **inboundTrustedRootStoreCriteria** member.

Available when **inboundConfigType** is **IKEEXT_CERT_CONFIG_TRUSTED_ROOT_STORE**.

### `inboundTrustedRootStoreCriteria`

Type: [IKEEXT_CERTIFICATE_CRITERIA0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_certificate_criteria0)*

List of trusted root store criteria that should be used to verify the peer certificate chain.

Available when **inboundConfigType** is **IKEEXT_CERT_CONFIG_TRUSTED_ROOT_STORE**.

### `outboundConfigType`

Type: [IKEEXT_CERT_CONFIG_TYPE](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_cert_config_type)

Certificate configuration type for outbound local certificate verification.

### `outboundRootArraySize`

Type: **UINT32**

Number of elements in the **outboundRootCriteria** member.

Available when **outboundConfigType** is **IKEEXT_CERT_CONFIG_EXPLICIT_TRUST_LIST**.

### `outboundRootCriteria`

Type: [IKEEXT_CERTIFICATE_CRITERIA0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_certificate_criteria0)*

List of certificate criteria containing explicit trusted authorities that should be used to select the certificate chain that will be sent to the peer.

Available when **outboundConfigType** is **IKEEXT_CERT_CONFIG_EXPLICIT_TRUST_LIST**.

### `outboundEnterpriseStoreArraySize`

Type: **UINT32**

Number of elements in the **outboundEnterpriseStoreCriteria** member.

Available when **outboundConfigType** is **IKEEXT_CERT_CONFIG_ENTERPRISE_STORE**.

### `outboundEnterpriseStoreCriteria`

Type: [IKEEXT_CERTIFICATE_CRITERIA0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_certificate_criteria0)*

List of enterprise store criteria that should be used to select the certificate chain that will be sent to the peer.

Available when **outboundConfigType** is **IKEEXT_CERT_CONFIG_ENTERPRISE_STORE**.

### `outboundRootStoreArraySize`

Type: **UINT32**

Number of elements in the **outboundRootStoreArraySize** member.

Available when **outboundConfigType** is **IKEEXT_CERT_CONFIG_TRUSTED_ROOT_STORE**.

### `outboundTrustedRootStoreCriteria`

Type: [IKEEXT_CERTIFICATE_CRITERIA0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_certificate_criteria0)*

List of trusted root store criteria that should be used to select the certificate chain that will be sent to the peer.

Available when **outboundConfigType** is **IKEEXT_CERT_CONFIG_TRUSTED_ROOT_STORE**.

### `flags`

Type: **UINT32**

A combination of the following values that specifies the certificate authentication characteristics.

| IKE/AuthIP certificate authentication flag | Meaning |
| --- | --- |
| **IKEEXT_CERT_AUTH_FLAG_SSL_ONE_WAY** | Enable SSL one-way authentication.<br><br> Applicable only to AuthIP. |
| **IKEEXT_CERT_AUTH_FLAG_DISABLE_CRL_CHECK** | Disable CRL checking. By default weak CRL checking is enabled. Weak checking means that a certificate will be rejected if and only if CRL is successfully looked up and the certificate is found to be revoked. |
| **IKEEXT_CERT_AUTH_ENABLE_CRL_CHECK_STRONG** | Enable strong CRL checking. Strong checking means that a certificate will be rejected if certificate is found to be revoked, or if any other error (for example, CRL could not be retrieved) takes place while performing the revocation checking. |
| **IKEEXT_CERT_AUTH_DISABLE_SSL_CERT_VALIDATION** | Disables the SSL server authentication extended key usage (EKU) check. Other types of AuthIP validation are still performed.<br><br>Applicable only to AuthIP. |
| **IKEEXT_CERT_AUTH_ALLOW_HTTP_CERT_LOOKUP** | Allow lookup of peer certificate information from an HTTP URL.<br><br> Applicable only to IKEv2. |
| **IKEEXT_CERT_AUTH_URL_CONTAINS_BUNDLE** | The URL specified in the certificate authentication policy points to an encoded certificate-bundle. If this flag is not specified, IKEv2 will assume that the URL points to an encoded certificate.<br><br>Applicable only to IKEv2. |

### `localCertLocationUrl`

Type: [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob)

HTTP URL pointing to an encoded certificate or certificate-bundle, that
will be used by IKEv2 for authenticating local machine to a peer.

Applicable only to IKEv2.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)