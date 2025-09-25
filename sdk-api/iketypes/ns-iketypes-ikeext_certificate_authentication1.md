# IKEEXT_CERTIFICATE_AUTHENTICATION1 structure

## Description

The [IKEEXT_CERTIFICATE_AUTHENTICATION2](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_certificate_authentication2) is available. For Windows Vista, [IKEEXT_CERTIFICATE_AUTHENTICATION0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_certificate_authentication0) is available.

## Members

### `inboundConfigType`

Certificate configuration type for inbound peer certificate verification.

See [IKEEXT_CERT_CONFIG_TYPE](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_cert_config_type) for more information.

### `inboundRootArraySize`

Number of elements in the **inboundRootArray** member.

Available when **inboundConfigType** is **IKEEXT_CERT_CONFIG_EXPLICIT_TRUST_LIST**.

### `inboundRootArray`

Explicit trust list for verifying the peer certificate chain.

Available when **inboundConfigType** is **IKEEXT_CERT_CONFIG_EXPLICIT_TRUST_LIST**.

See [IKEEXT_CERT_ROOT_CONFIG0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_cert_root_config0) for more information.

### `inboundEnterpriseStoreConfig`

Enterprise store configuration for verifying the peer certificate chain.

Available when **inboundConfigType** is **IKEEXT_CERT_CONFIG_ENTERPRISE_STORE**.

See [IKEEXT_CERT_ROOT_CONFIG0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_cert_root_config0) for more information.

### `inboundTrustedRootStoreConfig`

Trusted root store configuration for verifying the peer certificate chain.

Available when **inboundConfigType** is **IKEEXT_CERT_CONFIG_TRUSTED_ROOT_STORE**.

See [IKEEXT_CERT_ROOT_CONFIG0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_cert_root_config0) for more information.

### `outboundConfigType`

Certificate configuration type for outbound local certificate verification.

See [IKEEXT_CERT_CONFIG_TYPE](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_cert_config_type) for more information.

### `outboundRootArraySize`

Number of elements in the **outboundRootArray** member.

Available when **outboundConfigType** is **IKEEXT_CERT_CONFIG_EXPLICIT_TRUST_LIST**.

### `outboundRootArray`

Explicit trust list for selecting a certificate chain to send to the peer.

Available when **outboundConfigType** is **IKEEXT_CERT_CONFIG_EXPLICIT_TRUST_LIST**.

See [IKEEXT_CERT_ROOT_CONFIG0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_cert_root_config0) for more information.

### `outboundEnterpriseStoreConfig`

Enterprise store configuration for selecting the certificate chain.

Available when **outboundConfigType** is **IKEEXT_CERT_CONFIG_ENTERPRISE_STORE**.

See [IKEEXT_CERT_ROOT_CONFIG0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_cert_root_config0) for more information.

### `outboundTrustedRootStoreConfig`

Trusted root store configuration for selecting the certificate chain.

Available when **outboundConfigType** is **IKEEXT_CERT_CONFIG_ROOT_STORE**.

See [IKEEXT_CERT_ROOT_CONFIG0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_cert_root_config0) for more information.

### `flags`

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

HTTP URL pointing to an encoded certificate or certificate-bundle, that
will be used by IKEv2 for authenticating local machine to a peer.

Applicable only to IKEv2.

See [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob) for more information.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)