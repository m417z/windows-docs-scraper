# CertVerifyCertificateChainPolicy function

## Description

The **CertVerifyCertificateChainPolicy** function checks a certificate chain to verify its validity, including its compliance with any specified validity policy criteria.

## Parameters

### `pszPolicyOID` [in]

Current predefined verify chain policy structures are listed in the following table.

| Value | Meaning |
|-------|---------|
| **CERT_CHAIN_POLICY_BASE**<br>(LPCSTR) 1 | Implements the base chain policy verification checks. The **dwFlags** member of the structure pointed to by *pPolicyPara* can be set to alter the default policy checking behavior. |
| **CERT_CHAIN_POLICY_AUTHENTICODE**(LPCSTR) 2 | Implements the Authenticode chain policy verification checks. The **pvExtraPolicyPara** member of the structure pointed to by *pPolicyPara* can be set to point to an [AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-authenticode_extra_cert_chain_policy_para) structure.<br><br>The **pvExtraPolicyStatus** member of the structure pointed to by *pPolicyStatus* can be set to point to an [AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-authenticode_extra_cert_chain_policy_status) structure. |
| **CERT_CHAIN_POLICY_AUTHENTICODE_TS**<br>(LPCSTR) 3 | Implements Authenticode Time Stamp chain policy verification checks. The **pvExtraPolicyPara** member of the data structure pointed to by *pPolicyPara* can be set to point to an [AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-authenticode_ts_extra_cert_chain_policy_para) structure.<br><br>The **pvExtraPolicyStatus** member of the data structure pointed to by *pPolicyStatus* is not used and must be set to `NULL`. |
| **CERT_CHAIN_POLICY_SSL**<br>(LPCSTR) 4 | Implements the SSL client/server chain policy verification checks. The **pvExtraPolicyPara** member in the data structure pointed to by *pPolicyPara* can be set to point to an [SSL_EXTRA_CERT_CHAIN_POLICY_PARA](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-httpspolicycallbackdata) structure initialized with additional policy criteria.<br><br>**Note:** To differentiate between server and client authorization certificates, the call to the [CertGetCertificateChain](https://learn.microsoft.com/windows/win32/api/wincrypt/nf-wincrypt-certgetcertificatechain) function to get the chain context should specify the certificate type by setting the expected usage. Set the expected usage by setting the **RequestedUsage** member of the [CERT_CHAIN_PARA](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_chain_para) structure passed in the *pChainPara* input parameter of the **CertGetCertificateChain** function. |
| **CERT_CHAIN_POLICY_BASIC_CONSTRAINTS**<br>(LPCSTR) 5 | Implements the basic constraints chain policy. Iterates through all the certificates in the chain checking for either a **szOID_BASIC_CONSTRAINTS** or a **szOID_BASIC_CONSTRAINTS2** extension. If neither extension is present, the certificate is assumed to have valid policy. Otherwise, for the first certificate element, checks if it matches the expected CA_FLAG or END_ENTITY_FLAG specified in the **dwFlags** member of the [CERT_CHAIN_POLICY_PARA](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_chain_policy_para) structure pointed to by the *pPolicyPara* parameter. If neither or both flags are set, then, the first element can be either a CA or END_ENTITY. All other elements must be a [certification authority](https://learn.microsoft.com/windows/win32/SecGloss/c-gly) (CA). If the PathLenConstraint is present in the extension, it is checked.<br><br>The first elements in the remaining simple chains (that is, the certificates used to sign the CTL) are checked to be an END_ENTITY. If this verification fails, **dwError** will be set to TRUST_E_BASIC_CONSTRAINTS. |
| **CERT_CHAIN_POLICY_NT_AUTH**<br>(LPCSTR) 6 | Implements the Windows NT Authentication chain policy, which consists of three distinct chain verifications in the following order: <br><br>- CERT_CHAIN_POLICY_BASE: Implements the base chain policy verification checks. The LOWORD of *dwFlags* can be set in *pPolicyPara* to alter the default policy checking behavior. For more information, see CERT_CHAIN_POLICY_BASE.<br>- CERT_CHAIN_POLICY_BASIC_CONSTRAINTS: Implements the basic constraints chain policy. The HIWORD of *dwFlags* can be set to specify if the first element must be either a CA or END_ENTITY. For more information, see CERT_CHAIN_POLICY_BASIC_CONSTRAINTS.<br>- Checks if the second element in the chain, the CA that issued the end certificate, is a trusted CA for Windows NT Authentication. A CA is considered to be trusted if it exists in the "NTAuth" system registry store found in the CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE store location. If this verification fails, the CA is untrusted, and *dwError* is set to CERT_E_UNTRUSTEDCA. If CERT_PROT_ROOT_DISABLE_NT_AUTH_REQUIRED_FLAG is set in the **Flags** value of the **HKEY_LOCAL_MACHINE** policy **ProtectedRoots** subkey, defined by CERT_PROT_ROOT_FLAGS_REGPATH and the above check fails, the chain is checked for CERT_TRUST_HAS_VALID_NAME_CONSTRAINTS set in *dwInfoStatus*. This is set if there was a valid name constraint for all namespaces including UPN. If the chain does not have this info status set, *dwError* is set to CERT_E_UNTRUSTEDCA. |
| **CERT_CHAIN_POLICY_MICROSOFT_ROOT**<br>(LPCSTR) 7 | Checks the last element of the first simple chain for a Microsoft root public key. If that element does not contain a Microsoft root public key, the **dwError** member of the [CERT_CHAIN_POLICY_STATUS](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_chain_policy_status) structure pointed to by the *pPolicyStatus* parameter is set to **CERT_E_UNTRUSTEDROOT**.<br><br>The **dwFlags** member of the [CERT_CHAIN_POLICY_PARA](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_chain_policy_para) structure pointed to by the *pPolicyStatus* parameter can contain the **MICROSOFT_ROOT_CERT_CHAIN_POLICY_CHECK_APPLICATION_ROOT_FLAG** flag, which causes this function to instead check for the Microsoft application root "Microsoft Root Certificate Authority 2011".<br><br>The **dwFlags** member of the [CERT_CHAIN_POLICY_PARA](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_chain_policy_para) structure pointed to by the *pPolicyPara* parameter can contain the **MICROSOFT_ROOT_CERT_CHAIN_POLICY_ENABLE_TEST_ROOT_FLAG** flag, which causes this function to also check for the Microsoft test roots.<br><br>**Note:**<br>This policy [object identifier](https://learn.microsoft.com/windows/win32/SecGloss/o-gly) (OID) does not perform any policy verification checks by itself, it is meant to be used in conjunction with other policies. |
| **CERT_CHAIN_POLICY_EV**<br>(LPCSTR) 8 | Specifies that extended validation of certificates is performed.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |
| **CERT_CHAIN_POLICY_SSL_F12**<br>(LPCSTR) 9 | Checks if any certificates in the chain have weak crypto or if third party root certificate compliance and provide an error string. The **pvExtraPolicyStatus** member of the CERT_CHAIN_POLICY_STATUS structure pointed to by the *pPolicyStatus* parameter must point to [SSL_F12_EXTRA_CERT_CHAIN_POLICY_STATUS](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-ssl_f12_extra_cert_chain_policy_status), which is updated with the results of the weak crypto and root program compliance checks.<br><br>Before calling, the **cbSize** member of the CERT_CHAIN_POLICY_STATUS structure pointed to by the *pPolicyStatus* parameter must be set to a value greater than or equal to sizeof(SSL_F12_EXTRA_CERT_CHAIN_POLICY_STATUS).<br><br>The **dwError** member in CERT_CHAIN_POLICY_STATUS structure pointed to by the *pPolicyStatus* parameter will be set to **TRUST_E_CERT_SIGNATURE** for potential weak crypto and set to **CERT_E_UNTRUSTEDROOT** for Third Party Roots not in compliance with the Microsoft Root Program.<br><br>**Windows 10, version 1607, Windows Server 2016, Windows 10, version 1511 with KB3172985, Windows 10 RTM with KB3163912, Windows 8.1 and Windows Server 2012 R2 with KB3163912, and Windows 7 with SP1 and Windows Server 2008 R2 SP1 with KB3161029** |

### `pChainContext` [in]

A pointer to a [CERT_CHAIN_CONTEXT](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_chain_context) structure that contains a chain to be verified.

### `pPolicyPara` [in]

A pointer to a [CERT_CHAIN_POLICY_PARA](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_chain_policy_para) structure that provides the policy verification criteria for the chain. The **dwFlags** member of that structure can be set to change the default policy checking behavior.

In addition, policy-specific parameters can also be passed in the **pvExtraPolicyPara** member of the structure.

### `pPolicyStatus` [in, out]

A pointer to a [CERT_CHAIN_POLICY_STATUS](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_chain_policy_status) structure where status information on the chain is returned. OID-specific extra status can be returned in the **pvExtraPolicyStatus** member of this structure.

## Return value

The return value indicates whether the function was able to check for the policy, it does not indicate whether the policy check failed or passed.

If the chain can be verified for the specified policy, `TRUE` is returned and the **dwError** member of the *pPolicyStatus* is updated. A *dwError* of `0` (**ERROR_SUCCESS** or **S_OK**) indicates the chain satisfies the specified policy.

If the chain cannot be validated, the return value is `TRUE` and you need to verify the *pPolicyStatus* parameter for the actual error.

A value of `FALSE` indicates that the function wasn't able to check for the policy.

## Remarks

A **dwError** member of the [CERT_CHAIN_POLICY_STATUS](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_chain_policy_status) structure pointed to by *pPolicyStatus* can apply to a single chain element, to a simple chain, or to an entire chain context. If **dwError** applies to the entire chain context, both the **lChainIndex** and the **lElementIndex** members of the **CERT_CHAIN_POLICY_STATUS** structure are set to `–1`. If **dwError** applies to a complete simple chain, **lElementIndex** is set to `–1` and **lChainIndex** is set to the index of the first chain that has an error. If **dwError** applies to a single certificate element, **lChainIndex** and **lElementIndex** index the first certificate that has the error.

To get the certificate element use this syntax:

```
pChainContext->rgpChain[lChainIndex]->rgpElement[lElementIndex];
```

Use the [CertGetCertificateChain](https://learn.microsoft.com/windows/win32/api/wincrypt/nf-wincrypt-certgetcertificatechain) function to enable and perform certificate revocation checking. The **CertVerifyCertificateChainPolicy** function does not check if certificates in the certificate chain are revoked.

## See also

[AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-authenticode_extra_cert_chain_policy_para)

[AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-authenticode_extra_cert_chain_policy_status)

[AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-authenticode_ts_extra_cert_chain_policy_para)

[CERT_CHAIN_CONTEXT](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_chain_context)

[CERT_CHAIN_POLICY_PARA](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_chain_policy_para)

[CERT_CHAIN_POLICY_STATUS](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_chain_policy_status)

[CertGetCertificateChain](https://learn.microsoft.com/windows/win32/api/wincrypt/nf-wincrypt-certgetcertificatechain)

[Certificate Chain Verification Functions](https://learn.microsoft.com/windows/win32/SecCrypto/cryptography-functions)