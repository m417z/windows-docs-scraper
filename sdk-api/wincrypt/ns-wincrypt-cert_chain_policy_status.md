# CERT_CHAIN_POLICY_STATUS structure

## Description

The **CERT_CHAIN_POLICY_STATUS** structure holds certificate chain status information returned by
the [CertVerifyCertificateChainPolicy](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycertificatechainpolicy) function when the certificate chains are validated.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `dwError`

A value that indicates that an error or invalid condition was encountered during the validation process. The values of this member are specific to the policy type as specified by the value of the *pszPolicyOID* parameter of the [CertVerifyCertificateChainPolicy](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycertificatechainpolicy) function.

Base Policy errors (**CERT_CHAIN_POLICY_BASE**)

| Value | Meaning |
| --- | --- |
| **TRUST_E_CERT_SIGNATURE**<br><br>0x80096004L | The signature of the certificate cannot be verified. |
| **CRYPT_E_REVOKED**<br><br>0x80092010L | The certificate or signature has been revoked. |
| **CERT_E_UNTRUSTEDROOT**<br><br>0x800B0109L | A certification chain processed correctly but terminated in a root certificate that is not trusted by the [trust provider](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly). |
| **CERT_E_UNTRUSTEDTESTROOT**<br><br>0x800B010DL | The root certificate is a testing certificate, and policy settings disallow test certificates. |
| **CERT_E_CHAINING**<br><br>0x800B010AL | A chain of certificates was not correctly created. |
| **CERT_E_WRONG_USAGE**<br><br>0x800B0110L | The certificate is not valid for the requested usage. |
| **CERT_E_EXPIRED**<br><br>0x800B0101L | A required certificate is not within its validity period. |
| **CERT_E_INVALID_NAME**<br><br>0x800B0114L | The certificate has an invalid name. Either the name is not included in the permitted list, or it is explicitly excluded. |
| **CERT_E_INVALID_POLICY**<br><br>0x800B0113L | The certificate has an invalid policy. |
| **TRUST_E_BASIC_CONSTRAINTS**<br><br>0x80096019L | The basic constraints of the certificate are not valid, or they are missing. |
| **CERT_E_CRITICAL**<br><br>0x800B0105L | The certificate is being used for a purpose other than the purpose specified by its CA. |
| **CERT_E_VALIDITYPERIODNESTING**<br><br>0x800B0102L | The validity periods of the certification chain do not nest correctly. |
| **CRYPT_E_NO_REVOCATION_CHECK**<br><br>0x80092012L | The revocation function was unable to check revocation for the certificate. |
| **CRYPT_E_REVOCATION_OFFLINE**<br><br>0x80092013L | The revocation function was unable to check revocation because the revocation server was offline. |

Basic Constraints Policy errors (**CERT_CHAIN_POLICY_BASIC_CONSTRAINTS**).

| Value | Meaning |
| --- | --- |
| **TRUST_E_BASIC_CONSTRAINTS**<br><br>0x80096019L | The basic constraints of the certificate are not valid, or they are missing. |

Authenticode Policy errors (**CERT_CHAIN_POLICY_AUTHENTICODE** and **CERT_CHAIN_POLICY_AUTHENTICODE_TS**).

These errors are in addition to the Base Policy errors.

| Value | Meaning |
| --- | --- |
| **CERT_E_PURPOSE**<br><br>0x800B0106L | The certificate is being used for a purpose other than one specified by the issuing CA. |
| **CERT_E_REVOKED**<br><br>0x800B010CL | The certificate has been explicitly revoked by the issuer. |
| **CERT_E_REVOCATION_FAILURE**<br><br>0x800B010EL | The revocation process could not continue, and the certificate could not be checked. |

SSL Policy errors (**CERT_CHAIN_POLICY_SSL**).

These errors are in addition to the Base Policy errors.

| Value | Meaning |
| --- | --- |
| **CERT_E_UNTRUSTEDROOT**<br><br>0x800B0109L | A certification chain processed correctly but terminated in a root certificate that is not trusted by the [trust provider](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly). |
| **CERT_E_CN_NO_MATCH**<br><br>0x800B010FL | The certificate's CN name does not match the passed value. |
| **CERT_E_PURPOSE**<br><br>0x800B0106L | The certificate is being used for a purpose other than the purposes specified by its CA. |
| **CERT_E_ROLE**<br><br>0x800B0103L | A certificate that can only be used as an end-entity is being used as a CA or vice versa. |

Microsoft Root Policy errors (**CERT_CHAIN_POLICY_MICROSOFT_ROOT**).

| Value | Meaning |
| --- | --- |
| **CERT_E_UNTRUSTEDROOT**<br><br>0x800B0109L | A certification chain processed correctly but terminated in a root certificate that is not trusted by the [trust provider](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly). |

EV Policy errors.

| Value | Meaning |
| --- | --- |
| **CERT_E_CHAINING**<br><br>0x800B010AL | The certificate chain to a trusted root authority could not be built. |
| **CERT_E_WRONG_USAGE**<br><br>0x800B0110L | The certificate is not valid for the requested usage. |

### `lChainIndex`

Index that indicates the chain in which an error or condition that is not valid was found. For more information, see Remarks.

### `lElementIndex`

Index that indicates the element in a chain where an error or condition that is not valid was found. For more information, see Remarks.

### `pvExtraPolicyStatus`

A pointer to a structure. The structure type is determined by the value of the **pszPolicyOID** parameter of the [CertVerifyCertificateChainPolicy](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycertificatechainpolicy) function. In addition to **dwError** errors, policy OID–specific extra status can also be returned here to provide additional chain status information. This pointer can be optionally set to point to an
[AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-authenticode_extra_cert_chain_policy_status) structure.

## Remarks

If both **lChainIndex** and **lElementIndex** are set to –1, the error or condition that is not valid applies to the whole chain context. If only **lElementIndex** is set to –1, the error or condition that is not valid applies to the chain indexed by **lChainIndex**. Otherwise, the error or condition that is not valid applies to the certificate element at pChainContext->rgpChain[**lChainIndex**]->rgpElement[**lElementIndex**].