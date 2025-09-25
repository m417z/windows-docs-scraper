# CERT_TRUST_STATUS structure

## Description

The **CERT_TRUST_STATUS** structure contains trust information about a certificate in a certificate chain, summary trust information about a simple chain of certificates, or summary information about an array of simple chains.

## Members

### `dwErrorStatus`

dwErrorStatus is a bitmask of the following error codes defined for certificates and chains.

| Value | Meaning |
| --- | --- |
| **CERT_TRUST_NO_ERROR**<br><br>0x00000000 | No error found for this certificate or chain. |
| **CERT_TRUST_IS_NOT_TIME_VALID**<br><br>0x00000001 | This certificate or one of the certificates in the certificate chain is not time valid. |
| **CERT_TRUST_IS_REVOKED**<br><br>0x00000004 | Trust for this certificate or one of the certificates in the certificate chain has been revoked. |
| **CERT_TRUST_IS_NOT_SIGNATURE_VALID**<br><br>0x00000008 | The certificate or one of the certificates in the certificate chain does not have a valid signature. |
| **CERT_TRUST_IS_NOT_VALID_FOR_USAGE**<br><br>0x00000010 | The certificate or certificate chain is not valid for its proposed usage. |
| **CERT_TRUST_IS_UNTRUSTED_ROOT**<br><br>0x00000020 | The certificate or certificate chain is based on an untrusted root. |
| **CERT_TRUST_REVOCATION_STATUS_UNKNOWN**<br><br>0x00000040 | The revocation status of the certificate or one of the certificates in the certificate chain is unknown. |
| **CERT_TRUST_IS_CYCLIC**<br><br>0x00000080 | One of the certificates in the chain was issued by a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that the original certificate had certified. |
| **CERT_TRUST_INVALID_EXTENSION**<br><br>0x00000100 | One of the certificates has an extension that is not valid. |
| **CERT_TRUST_INVALID_POLICY_CONSTRAINTS**<br><br>0x00000200 | The certificate or one of the certificates in the certificate chain has a policy constraints extension, and one of the issued certificates has a disallowed policy mapping extension or does not have a required issuance policies extension. |
| **CERT_TRUST_INVALID_BASIC_CONSTRAINTS**<br><br>0x00000400 | The certificate or one of the certificates in the certificate chain has a basic constraints extension, and either the certificate cannot be used to issue other certificates, or the chain path length has been exceeded. |
| **CERT_TRUST_INVALID_NAME_CONSTRAINTS**<br><br>0x00000800 | The certificate or one of the certificates in the certificate chain has a name constraints extension that is not valid. |
| **CERT_TRUST_HAS_NOT_SUPPORTED_NAME_CONSTRAINT**<br><br>0x00001000 | The certificate or one of the certificates in the certificate chain has a name constraints extension that contains unsupported fields. The minimum and maximum fields are not supported. Thus minimum must always be zero and maximum must always be absent. Only UPN is supported for an Other Name. The following alternative name choices are not supported:<br><br>* X400 Address<br>* EDI Party Name<br>* Registered Id |
| **CERT_TRUST_HAS_NOT_DEFINED_NAME_CONSTRAINT**<br><br>0x00002000 | The certificate or one of the certificates in the certificate chain has a name constraints extension and a name constraint is missing for one of the name choices in the end certificate. |
| **CERT_TRUST_HAS_NOT_PERMITTED_NAME_CONSTRAINT**<br><br>0x00004000 | The certificate or one of the certificates in the certificate chain has a name constraints extension, and there is not a permitted name constraint for one of the name choices in the end certificate. |
| **CERT_TRUST_HAS_EXCLUDED_NAME_CONSTRAINT**<br><br>0x00008000 | The certificate or one of the certificates in the certificate chain has a name constraints extension, and one of the name choices in the end certificate is explicitly excluded. |
| **CERT_TRUST_IS_OFFLINE_REVOCATION**<br><br>0x01000000 | The revocation status of the certificate or one of the certificates in the certificate chain is either offline or stale. |
| **CERT_TRUST_NO_ISSUANCE_CHAIN_POLICY**<br><br>0x02000000 | The end certificate does not have any resultant issuance policies, and one of the issuing [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) certificates has a policy constraints extension requiring it. |
| **CERT_TRUST_IS_EXPLICIT_DISTRUST**<br><br>0x04000000 | The certificate is explicitly distrusted.<br><br>**Windows Vista and Windows Server 2008:** Support for this flag begins. |
| **CERT_TRUST_HAS_NOT_SUPPORTED_CRITICAL_EXT**<br><br>0x08000000 | The certificate does not support a critical extension.<br><br>**Windows Vista and Windows Server 2008:** Support for this flag begins. |
| **CERT_TRUST_HAS_WEAK_SIGNATURE**<br><br>0x00100000 | The certificate has not been strong signed. Typically this indicates that the MD2 or MD5 hashing algorithms were used to create a hash of the certificate.<br><br>**Windows 8 and Windows Server 2012:** Support for this flag begins. |

The following codes are defined for chains only.

| Value | Meaning |
| --- | --- |
| **CERT_TRUST_IS_PARTIAL_CHAIN**<br><br>0x00010000 | The certificate chain is not complete. |
| **CERT_TRUST_CTL_IS_NOT_TIME_VALID**<br><br>0x00020000 | A [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) used to create this chain was not time valid. |
| **CERT_TRUST_CTL_IS_NOT_SIGNATURE_VALID**<br><br>0x00040000 | A CTL used to create this chain did not have a valid signature. |
| **CERT_TRUST_CTL_IS_NOT_VALID_FOR_USAGE**<br><br>0x00080000 | A CTL used to create this chain is not valid for this usage. |

### `dwInfoStatus`

The following information status codes are defined.

| Value | Meaning |
| --- | --- |
| **CERT_TRUST_HAS_EXACT_MATCH_ISSUER**<br><br>0x00000001 | An exact match issuer certificate has been found for this certificate. This status code applies to certificates only. |
| **CERT_TRUST_HAS_KEY_MATCH_ISSUER**<br><br>0x00000002 | A key match issuer certificate has been found for this certificate. This status code applies to certificates only. |
| **CERT_TRUST_HAS_NAME_MATCH_ISSUER**<br><br>0x00000004 | A name match issuer certificate has been found for this certificate. This status code applies to certificates only. |
| **CERT_TRUST_IS_SELF_SIGNED**<br><br>0x00000008 | This certificate is self-signed. This status code applies to certificates only. |
| **CERT_TRUST_HAS_PREFERRED_ISSUER**<br><br>0x00000100 | The certificate or chain has a preferred issuer. This status code applies to certificates and chains. |
| **CERT_TRUST_HAS_ISSUANCE_CHAIN_POLICY**<br><br>0x00000400 | An issuance chain policy exists. This status code applies to certificates and chains. |
| **CERT_TRUST_HAS_VALID_NAME_CONSTRAINTS**<br><br>0x00000400 | A valid name constraints for all namespaces, including UPN. This status code applies to certificates and chains. |
| **CERT_TRUST_IS_PEER_TRUSTED**<br><br>0x00000800 | This certificate is peer trusted. This status code applies to certificates only.<br><br>**Windows Vista and Windows Server 2008:** Support for this flag begins. |
| **CERT_TRUST_HAS_CRL_VALIDITY_EXTENDED**<br><br>0x00001000 | This certificate's [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) validity has been extended. This status code applies to certificates only.<br><br>**Windows Vista and Windows Server 2008:** Support for this flag begins. |
| **CERT_TRUST_IS_FROM_EXCLUSIVE_TRUST_STORE**<br><br>0x00002000 | The certificate was found in either a store pointed to by the **hExclusiveRoot** or **hExclusiveTrustedPeople** member of the [CERT_CHAIN_ENGINE_CONFIG](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_engine_config) structure.<br><br>**Windows 7 and Windows Server 2008 R2:** Support for this flag begins. |
| **CERT_TRUST_IS_COMPLEX_CHAIN**<br><br>0x00010000 | The certificate chain created is a complex chain. This status code applies to chains only. |
| **CERT_TRUST_IS_CA_TRUSTED**<br><br>0x00004000 | A non-self-signed intermediate CA certificate was found in the store pointed to by the **hExclusiveRoot** member of the [CERT_CHAIN_ENGINE_CONFIG](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_engine_config) structure. The CA certificate is treated as a trust anchor for the certificate chain. This flag will only be set if the **CERT_CHAIN_EXCLUSIVE_ENABLE_CA_FLAG** value is set in the **dwExclusiveFlags** member of the **CERT_CHAIN_ENGINE_CONFIG** structure.<br><br>If this flag is set, the **CERT_TRUST_IS_SELF_SIGNED** and the **CERT_TRUST_IS_PARTIAL_CHAIN****dwErrorStatus** flags will not be set.<br><br>**Windows 8 and Windows Server 2012:** Support for this flag begins. |

## See also

[CERT_CHAIN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_context)

[CERT_CHAIN_ENGINE_CONFIG](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_engine_config)

[CERT_SIMPLE_CHAIN](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_simple_chain)