# CRYPT_PROVIDER_DATA structure

## Description

[The **CRYPT_PROVIDER_DATA** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPT_PROVIDER_DATA** structure is used to pass data between [WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust) and trust providers.

## Members

### `cbStruct`

The size, in bytes, of this structure.

### `pWintrustData`

A pointer to a [WINTRUST_DATA](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-wintrust_data) structure that contains the information to verify.

### `fOpenedFile`

A Boolean value that indicates whether the trust provider opened the file handle, if applicable.

### `hWndParent`

A handle to the parent window. If not specified, a handle to the desktop window is used.

### `pgActionID`

A pointer to a **GUID** structure that identifies an action and the trust provider that supports that action.

### `hProv`

A handle to the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP). If this parameter is **NULL**, then the operating system will provide a default CSP.

### `dwError`

An error level if a low-level system error was encountered.

### `dwRegSecuritySettings`

The registry security settings.

### `dwRegPolicySettings`

The registry policy settings.

### `psPfns`

A pointer to a [CRYPT_PROVIDER_FUNCTIONS](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_functions) structure.

### `cdwTrustStepErrors`

The number of elements in the **padwTrustStepErrors** array.

### `padwTrustStepErrors`

An array of **DWORD** values that specify trust step errors.

### `chStores`

The number of elements in the **pahStores** array.

### `pahStores`

An array of certificate store handles.

### `dwEncoding`

A value that specifies the encoding type.

### `hMsg`

A handle to the cryptographic message.

### `csSigners`

The number of elements in the **pasSigners** array.

### `pasSigners`

A pointer to an array of [CRYPT_PROVIDER_SGNR](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_sgnr) structures.

### `csProvPrivData`

The number of elements in the **pasProvPrivData** array.

### `pasProvPrivData`

A pointer to an array of [CRYPT_PROVIDER_PRIVDATA](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_privdata) structures.

### `dwSubjectChoice`

A value that specifies the subject choice.

### `pPDSip`

A pointer to a **_PROVDATA_SIP** structure.

### `pszUsageOID`

A pointer to a null-terminated string that contains the usage [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID).

### `fRecallWithState`

A Boolean value that indicates whether state was maintained for catalog files.

### `sftSystemTime`

The system time.

### `pszCTLSignerUsageOID`

A pointer to a null-terminated string that represents the [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) signer usage OID.

### `dwProvFlags`

A bitwise combination of one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **CPD_USE_NT5_CHAIN_FLAG**<br><br>0x80000000 | Use Windows 2000 chaining. |
| **CPD_REVOCATION_CHECK_NONE**<br><br>0x00010000 | No revocation checking is performed. |
| **CPD_REVOCATION_CHECK_END_CERT**<br><br>0x00020000 | Revocation checking for the end certificate is performed. |
| **CPD_REVOCATION_CHECK_CHAIN**<br><br>0x00040000 | Revocation checking for the certificate chain is performed. |
| **CPD_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT**<br><br>0x00080000 | Revocation checking for the certificate chain, excluding the root certificate, is performed. |

### `dwFinalError`

A value for the final error.

### `pRequestUsage`

A pointer to a [CERT_USAGE_MATCH](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_usage_match) structure.

### `dwTrustPubSettings`

A value for the trust publisher settings.

### `dwUIStateFlags`

A **DWORD** value that specifies state data that is passed between a trust provider and the user interface.

**Windows XP with SP1 and Windows XP:** This member is ignored.

### `pSigState`

### `pSigSettings`