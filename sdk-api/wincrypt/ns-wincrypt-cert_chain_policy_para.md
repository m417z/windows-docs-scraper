# CERT_CHAIN_POLICY_PARA structure

## Description

The **CERT_CHAIN_POLICY_PARA** structure contains information used in
[CertVerifyCertificateChainPolicy](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycertificatechainpolicy) to establish policy criteria for the verification of certificate chains.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `dwFlags`

A set of flags that indicate conditions that could potentially be not valid and that are to be ignored in building certificate chains.

The *pszPolicyOID* parameter of the [CertVerifyCertificateChainPolicy](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycertificatechainpolicy) function can contain one of the following values:

* **CERT_CHAIN_POLICY_BASE**
* **CERT_CHAIN_POLICY_AUTHENTICODE**
* **CERT_CHAIN_POLICY_AUTHENTICODE_TS**
* **CERT_CHAIN_POLICY_SSL**
* **CERT_CHAIN_POLICY_NT_AUTH**

If the *pszPolicyOID* parameter of the **CertVerifyCertificateChainPolicy** function contains one of the preceding values, then this member can be zero or a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_CHAIN_POLICY_IGNORE_NOT_TIME_VALID_FLAG** | Ignore not time valid errors. |
| **CERT_CHAIN_POLICY_IGNORE_CTL_NOT_TIME_VALID_FLAG** | Ignore [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) not time valid errors. |
| **CERT_CHAIN_POLICY_IGNORE_NOT_TIME_NESTED_FLAG** | Ignore time nesting errors. |
| **CERT_CHAIN_POLICY_IGNORE_ALL_NOT_TIME_VALID_FLAGS** | Ignore all time validity errors. |
| **CERT_CHAIN_POLICY_IGNORE_INVALID_BASIC_CONSTRAINTS_FLAG** | Ignore basic constraint errors. |
| **CERT_CHAIN_POLICY_ALLOW_UNKNOWN_CA_FLAG** | Allow untrusted roots. |
| **CERT_CHAIN_POLICY_IGNORE_WRONG_USAGE_FLAG** | Ignore invalid usage errors. |
| **CERT_CHAIN_POLICY_IGNORE_INVALID_NAME_FLAG** | Ignore invalid name errors. |
| **CERT_CHAIN_POLICY_IGNORE_INVALID_POLICY_FLAG** | Ignore invalid policy errors. |
| **CERT_CHAIN_POLICY_IGNORE_END_REV_UNKNOWN_FLAG** | Ignores errors in obtaining valid revocation information. |
| **CERT_CHAIN_POLICY_IGNORE_CTL_SIGNER_REV_UNKNOWN_FLAG** | Ignores errors in obtaining valid CTL revocation information. |
| **CERT_CHAIN_POLICY_IGNORE_CA_REV_UNKNOWN_FLAG** | Ignores errors in obtaining valid [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) revocation information. |
| **CERT_CHAIN_POLICY_IGNORE_ROOT_REV_UNKNOWN_FLAG** | Ignores errors in obtaining valid root revocation information. |
| **CERT_CHAIN_POLICY_IGNORE_ALL_REV_UNKNOWN_FLAGS** | Ignores errors in obtaining valid revocation information. |
| **CERT_CHAIN_POLICY_ALLOW_TESTROOT_FLAG** | Allow untrusted test roots. |
| **CERT_CHAIN_POLICY_TRUST_TESTROOT_FLAG** | Always trust test roots. |
| **CERT_CHAIN_POLICY_IGNORE_NOT_SUPPORTED_CRITICAL_EXT_FLAG** | Ignore critical extension not supported errors. |
| **CERT_CHAIN_POLICY_IGNORE_PEER_TRUST_FLAG** | Ignore peer trusts. |

If the *pszPolicyOID* parameter of the [CertVerifyCertificateChainPolicy](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycertificatechainpolicy) function contains **CERT_CHAIN_POLICY_BASIC_CONSTRAINTS**, this member can be zero or a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_CHAIN_POLICY_IGNORE_PEER_TRUST_FLAG** | Ignore peer trusts. |
| **BASIC_CONSTRAINTS_CERT_CHAIN_POLICY_CA_FLAG** | Checks if the first certificate element is a CA. |
| **BASIC_CONSTRAINTS_CERT_CHAIN_POLICY_END_ENTITY_FLAG** | Checks if the first certificate element is an end entity. |

If the *pszPolicyOID* parameter of the [CertVerifyCertificateChainPolicy](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycertificatechainpolicy) function contains **CERT_CHAIN_POLICY_MICROSOFT_ROOT**, this member can be zero or the following value.

| Value | Meaning |
| --- | --- |
| **MICROSOFT_ROOT_CERT_CHAIN_POLICY_ENABLE_TEST_ROOT_FLAG** | Also check for the Microsoft test roots in addition to the Microsoft public root. <br><br>**Note** The Windows test root certificate must be installed in the Trusted Root Certification Authorities certificate store for this to succeed. |

### `pvExtraPolicyPara`

The address of a pszPolicyOID-specific structure that provides additional validity policy conditions.