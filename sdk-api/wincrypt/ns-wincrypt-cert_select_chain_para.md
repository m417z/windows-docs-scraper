# CERT_SELECT_CHAIN_PARA structure

## Description

The **CERT_SELECT_CHAIN_PARA** structure contains the parameters used for building and selecting chains. This structure is used by the [CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain) and [CertSelectCertificateChains](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certselectcertificatechains) functions.

## Members

### `hChainEngine`

The handle of the chain engine to use to build the chain. If the value of the *hChainEngine* parameter is **NULL**, the default chain engine, **HCCE_CURRENT_USER**, is used.

### `pTime`

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the time for which the chain is to be validated. If the value of the *pTime* parameter is **NULL**, the current system time is passed to this parameter.

**Note** The time does not affect trust list, revocation, or root store checking.

### `hAdditionalStore`

The handle of any additional store to search for supporting certificates and certificate trust lists (CTLs). This parameter can be **NULL** if no additional store is to be searched.

### `pChainPara`

A pointer to a [CERT_CHAIN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_para) structure that includes chain-building parameters.

### `dwFlags`

Flag values that indicate special processing during chain build.

| Value | Meaning |
| --- | --- |
| **CERT_CHAIN_REVOCATION_CHECK_CACHE_ONLY**<br><br>0x00000004 | Revocation checking only accesses cached URLs. |
| **CERT_CHAIN_CACHE_ONLY_URL_RETRIEVAL**<br><br>0x80000000 | Use only cached URLs in building a certificate chain. The Internet and intranet are not searched for URL-based objects. |

## Remarks

Trust in a particular certificate being a trusted root is based on the current state of the root store and not the state of the root store at a time passed in by this parameter. For revocation, a certificate revocation list (CRL), itself, must be valid at the current time. The value of this parameter is used to determine whether a certificate listed in a CRL has been revoked.

The following remarks apply to strong signature checking:

* You can enable strong signature checking by using the [CERT_CHAIN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_para) structure referenced by the **pChainPara** member. The **pStrongSignPara** member of the **CERT_CHAIN_PARA** structure points to a [CERT_STRONG_SIGN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_strong_sign_para) structure that can be used to determine signature strength.
* When you enable strong checking and a weak signature is encountered, the **CERT_TRUST_IS_NOT_SIGNATURE_VALID** and **CERT_TRUST_HAS_WEAK_SIGNATURE** errors are set in the **dwErrorStatus** field of the [CERT_TRUST_STATUS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_trust_status) structure.