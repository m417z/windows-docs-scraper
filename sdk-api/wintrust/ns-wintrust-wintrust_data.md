# WINTRUST_DATA structure

## Description

[The **WINTRUST_DATA** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **WINTRUST_DATA** structure is used when calling
[WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust) to pass necessary information into the [trust providers](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly).

## Members

### `cbStruct`

The size, in bytes, of this structure.

### `pPolicyCallbackData`

A pointer to a data buffer used to pass policy-specific data to a policy provider. This member can be **NULL**.

### `pSIPClientData`

A pointer to a data buffer used to pass [subject interface package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIP)-specific data to a SIP provider. This member can be **NULL**.

### `dwUIChoice`

Specifies the kind of user interface (UI) to be used. This member must be one of the following values.

| Value | Meaning |
| --- | --- |
| **WTD_UI_ALL**<br><br>1 | Display all UI. |
| **WTD_UI_NONE**<br><br>2 | Display no UI. |
| **WTD_UI_NOBAD**<br><br>3 | Do not display any negative UI. |
| **WTD_UI_NOGOOD**<br><br>4 | Do not display any positive UI. |

### `fdwRevocationChecks`

Certificate revocation check options. This member can be set to add revocation checking to that done by the selected policy provider. This member must be one of the following values.

| Value | Meaning |
| --- | --- |
| **WTD_REVOKE_NONE**<br><br>0 | No additional revocation checking will be done when the **WTD_REVOKE_NONE** flag is used in conjunction with the **HTTPSPROV_ACTION** value set in the *pgActionID* parameter of the [WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust) function. To ensure the **WinVerifyTrust** function does not attempt any network retrieval when verifying code signatures, **WTD_CACHE_ONLY_URL_RETRIEVAL** must be set in the *dwProvFlags* parameter. |
| **WTD_REVOKE_WHOLECHAIN**<br><br>1 | Revocation checking will be done on the whole chain. |

### `dwUnionChoice`

Specifies the union member to be used and, thus, the type of object for which trust will be verified. This member must be one of the following values.

| Value | Meaning |
| --- | --- |
| **WTD_CHOICE_FILE**<br><br>1 | Use the file pointed to by **pFile**. |
| **WTD_CHOICE_CATALOG**<br><br>2 | Use the catalog pointed to by **pCatalog**. |
| **WTD_CHOICE_BLOB**<br><br>3 | Use the [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) pointed to by **pBlob**. |
| **WTD_CHOICE_SIGNER**<br><br>4 | Use the [WINTRUST_SGNR_INFO](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-wintrust_sgnr_info) structure pointed to by **pSgnr**. |
| **WTD_CHOICE_CERT**<br><br>5 | Use the certificate pointed to by **pCert**. |

### `pFile`

A pointer to a
[WINTRUST_FILE_INFO](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-wintrust_file_info) structure.

### `pCatalog`

A pointer to a
[WINTRUST_CATALOG_INFO](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-wintrust_catalog_info) structure.

### `pBlob`

A pointer to a
[WINTRUST_BLOB_INFO](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-wintrust_blob_info) structure.

### `pSgnr`

A pointer to a
[WINTRUST_SGNR_INFO](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-wintrust_sgnr_info) structure.

### `pCert`

A pointer to a
[WINTRUST_CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-wintrust_cert_info) structure.

### `dwStateAction`

Specifies the action to be taken. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **WTD_STATEACTION_IGNORE**<br><br>0x00000000 | Ignore the **hWVTStateData** member. |
| **WTD_STATEACTION_VERIFY**<br><br>0x00000001 | Verify the trust of the object (typically a file) that is specified by the **dwUnionChoice** member. The **hWVTStateData** member will receive a handle to the state data. This handle must be freed by specifying the **WTD_STATEACTION_CLOSE** action in a subsequent call. |
| **WTD_STATEACTION_CLOSE**<br><br>0x00000002 | Free the **hWVTStateData** member previously allocated with the **WTD_STATEACTION_VERIFY** action. This action must be specified for every use of the **WTD_STATEACTION_VERIFY** action. |
| **WTD_STATEACTION_AUTO_CACHE**<br><br>0x00000003 | Write the catalog data to a **WINTRUST_DATA** structure and then cache that structure. This action only applies when the **dwUnionChoice** member contains **WTD_CHOICE_CATALOG**. |
| **WTD_STATEACTION_AUTO_CACHE_FLUSH**<br><br>0x00000004 | Flush any cached catalog data. This action only applies when the **dwUnionChoice** member contains **WTD_CHOICE_CATALOG**. |

### `hWVTStateData`

A handle to the state data. The contents of this member depends on the value of the **dwStateAction** member.

### `pwszURLReference`

Reserved for future use. Set to **NULL**.

### `dwProvFlags`

**DWORD** value that specifies trust provider settings. This can be a bitwise combination of zero or more of the following values.

| Value | Meaning |
| --- | --- |
| **WTD_USE_IE4_TRUST_FLAG**<br><br>1 (0x1) | The trust is verified in the same manner as implemented by Internet Explorer 4.0. |
| **WTD_NO_IE4_CHAIN_FLAG**<br><br>2 (0x2) | The Internet Explorer 4.0 chain functionality is not used. |
| **WTD_NO_POLICY_USAGE_FLAG**<br><br>4 (0x4) | The default verification of the policy provider, such as code signing for [Authenticode](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly), is not performed, and the certificate is assumed valid for all usages. |
| **WTD_REVOCATION_CHECK_NONE**<br><br>16 (0x10) | Revocation checking is not performed. |
| **WTD_REVOCATION_CHECK_END_CERT**<br><br>32 (0x20) | Revocation checking is performed on the end certificate only. |
| **WTD_REVOCATION_CHECK_CHAIN**<br><br>64 (0x40) | Revocation checking is performed on the entire certificate chain. |
| **WTD_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT**<br><br>128 (0x80) | Revocation checking is performed on the entire certificate chain, excluding the root certificate. |
| **WTD_SAFER_FLAG**<br><br>256 (0x100) | Not supported. |
| **WTD_HASH_ONLY_FLAG**<br><br>512 (0x200) | Only the hash is verified. |
| **WTD_USE_DEFAULT_OSVER_CHECK**<br><br>1024 (0x400) | The default operating system version checking is performed. This flag is only used for verifying catalog-signed files. |
| **WTD_LIFETIME_SIGNING_FLAG**<br><br>2048 (0x800) | If this flag is not set, all time stamped signatures are considered valid forever. Setting this flag limits the valid lifetime of the signature to the lifetime of the signing certificate. This allows time stamped signatures to expire. |
| **WTD_CACHE_ONLY_URL_RETRIEVAL**<br><br>4096 (0x1000) | Use only the local cache for revocation checks. Prevents revocation checks over the network. <br><br>**Windows XP:** This value is not supported. |
| **WTD_DISABLE_MD2_MD4**<br><br>8192 (0x2000) | Disable the use of MD2 and MD4 hashing algorithms. If a file is signed by using MD2 or MD4 and if this flag is set, an NTE_BAD_ALGID error is returned.<br><br>**Note** This flag is supported on Windows 7 with SP1 and later operating systems. |
| **WTD_MOTW**<br><br>16384 (0x4000) | If this flag is specified it is assumed that the file being verified has been downloaded from the web and has the Mark of the Web attribute. Policies that are meant to apply to Mark of the Web files will be enforced.<br><br>**Note** This flag is supported on Windows 8.1 and later operating systems or on systems that have installed KB2862966. |

### `dwUIContext`

A **DWORD** value that specifies the user interface context for the [WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust) function. This causes the text in the Authenticode dialog box to match the action taken on the file. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **WTD_UICONTEXT_EXECUTE**<br><br>0 | Use when calling [WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust) for a file that is to be run. This is the default value. |
| **WTD_UICONTEXT_INSTALL**<br><br>1 | Use when calling [WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust) for a file that is to be installed. |

### `pSignatureSettings`

Pointer to a [WINTRUST_SIGNATURE_SETTINGS](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-wintrust_signature_settings) structure.

**Windows 7 with KB3033929, Windows 8, and Windows Server 2012:** Support for this member begins.