# CERT_CHAIN_PARA structure

## Description

The **CERT_CHAIN_PARA** structure establishes the searching and matching criteria to be used in building a certificate chain.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `RequestedUsage`

Structure indicating the kind of matching necessary to find issuer certificates for building a certificate chain. The structure pointed to indicates whether AND or OR logic is to be used in the matching process. The structure also includes an array of OIDs to be matched.

### `RequestedIssuancePolicy`

Optional structure that indicates the kind of issuance policy constraint matching that applies when building a certificate chain. The structure pointed to indicates whether AND or OR logic is to be used in the matching process. The structure also includes an array of OIDs to be matched.

**Note** This member can be used only if **CERT_CHAIN_PARA_HAS_EXTRA_FIELDS** is defined by using the **#define** directive before including Wincrypt.h. If this value is defined, the application must zero all unused fields.

### `dwUrlRetrievalTimeout`

Optional time, in milliseconds, before revocation checking times out. This member is optional.

**Note** This member can be used only if **CERT_CHAIN_PARA_HAS_EXTRA_FIELDS** is defined by using the **#define** directive before including Wincrypt.h. If this value is defined, the application must zero all unused fields.

### `fCheckRevocationFreshnessTime`

Optional member. When this flag is **TRUE**, an attempt is made to retrieve a new CRL if this update is greater than or equal to the current system time minus the **dwRevocationFreshnessTime** value. If this flag is not set, the CRL's next update time is used.

**Note** This member can be used only if **CERT_CHAIN_PARA_HAS_EXTRA_FIELDS** is defined by using the **#define** directive before including Wincrypt.h. If this value is defined, the application must zero all unused fields.

### `dwRevocationFreshnessTime`

The current time, in seconds, minus the CRL's update time of all elements checked.

**Note** This member can be used only if **CERT_CHAIN_PARA_HAS_EXTRA_FIELDS** is defined by using the **#define** directive before including Wincrypt.h. If this value is defined, the application must zero all unused fields.

### `pftCacheResync`

Optional member. When set to a non-**NULL** value, information cached before the time specified is considered to be not valid and cache resynchronization is performed.

**Windows Vista:** Support for this member begins.

**Note** This member can be used only if **CERT_CHAIN_PARA_HAS_EXTRA_FIELDS** is defined by using the **#define** directive before including Wincrypt.h. If this value is defined, the application must zero all unused fields.

### `pStrongSignPara`

Optional. Specify a pointer to a [CERT_STRONG_SIGN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_strong_sign_para) structure to enable strong signature checking.

**Windows 8 and Windows Server 2012:** Support for this member begins.

**Note** This member can be used only if **CERT_CHAIN_PARA_HAS_EXTRA_FIELDS** is defined by using the **#define** directive before including Wincrypt.h. If this value is defined, the application must zero all unused fields.

### `dwStrongSignFlags`

Optional flags that modify chain retrieval behavior. This can be zero or the following value.

| Value | Meaning |
| --- | --- |
| **CERT_CHAIN_STRONG_SIGN_DISABLE_END_CHECK_FLAG**<br><br>0x00000001 | If the chain is strong signed, the public key in the end certificate will be checked to verify whether it satisfies the minimum public key length requirements for a strong signature. You can specify **CERT_CHAIN_STRONG_SIGN_DISABLE_END_CHECK_FLAG** to disable default checking. |

**Windows 8 and Windows Server 2012:** Support for this property begins.

**Note** This member can be used only if **CERT_CHAIN_PARA_HAS_EXTRA_FIELDS** is defined by using the **#define** directive before including Wincrypt.h. If this value is defined, the application must zero all unused fields.

## Remarks

The following remarks apply when checking for strong signatures.

* Set the **pStrongSignPara** member to check for strong signatures when using the [CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain) or [CertSelectCertificateChains](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certselectcertificatechains) function.
* If a certificate without a strong signature is found in the chain, the **CERT_TRUST_HAS_WEAK_SIGNATURE** and **CERT_TRUST_IS_NOT_SIGNATURE_VALID** errors are set in the **dwErrorStatus** field of the [CERT_TRUST_STATUS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_trust_status) structure. The *ppChainContext* parameter of the [CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain) function and the *pprgpSelection* parameter of the [CertSelectCertificateChains](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certselectcertificatechains) function point to a [CERT_CHAIN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_context) structure which, in turn, points to the **CERT_TRUST_STATUS** structure.
* If the chain is strong signed, the public key in the end certificate is checked to determine whether it satisfies the minimum public key length requirements for a strong signature. If the condition is not satisfied, the **CERT_TRUST_HAS_WEAK_SIGNATURE** and **CERT_TRUST_IS_NOT_SIGNATURE_VALID** errors are set in the **dwErrorStatus** field of the [CERT_TRUST_STATUS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_trust_status) structure. Set the **CERT_CHAIN_STRONG_SIGN_DISABLE_END_CHECK_FLAG** value in the **dwStrongSignFlags** member to disable this check.
* If the **CERT_STRONG_SIGN_ENABLE_CRL_CHECK** or **CERT_STRONG_SIGN_ENABLE_OCSP_CHECK** flags are set in the [CERT_STRONG_SIGN_SERIALIZED_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_strong_sign_serialized_info) structure referenced by the [CERT_STRONG_SIGN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_strong_sign_para) structure pointed to by the **pStrongSignPara** member, and a CRL or OCSP response is found without a strong signature, the CRL or OCSP response will be treated as being offline. That is, the **CERT_TRUST_IS_OFFLINE_REVOCATION** and **CERT_TRUST_REVOCATION_STATUS_UNKNOWN** errors are set in the **dwErrorStatus** field of the [CERT_TRUST_STATUS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_trust_status) structure. Also, the **dwRevocationResult** member of the [CERT_REVOCATION_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_revocation_info) structure is set to **NTE_BAD_ALGID**.

## See also

[CERT_USAGE_MATCH](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_usage_match)