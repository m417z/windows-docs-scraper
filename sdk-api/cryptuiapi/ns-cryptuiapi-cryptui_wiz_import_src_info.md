# CRYPTUI_WIZ_IMPORT_SRC_INFO structure

## Description

[The **CRYPTUI_WIZ_IMPORT_SRC_INFO** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPTUI_WIZ_IMPORT_SRC_INFO** structure contains the subject to import into the [CryptUIWizImport](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuiwizimport) function. The subject can be a [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), a [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL), or a [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL).

## Members

### `dwSize`

The size, in bytes, of this structure.

### `dwSubjectChoice`

Indicates the type of subject to import. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPTUI_WIZ_IMPORT_SUBJECT_FILE** | Import the certificate stored in the file referenced in the **pwszFileName** member. |
| **CRYPTUI_WIZ_IMPORT_SUBJECT_CERT_CONTEXT** | Import the certificate referenced in the **pCertContext** member. |
| **CRYPTUI_WIZ_IMPORT_SUBJECT_CTL_CONTEXT** | Import the CTL referenced in the **pCTLContext** member. |
| **CRYPTUI_WIZ_IMPORT_SUBJECT_CRL_CONTEXT** | Import the CRL referenced in the **pCRLContext** member. |
| **CRYPTUI_WIZ_IMPORT_SUBJECT_CERT_STORE** | Import the certificate store referenced in the **hCertStore** member. |

### `pwszFileName`

A pointer to a null-terminated Unicode string that contains the path and file name of the file that contains the certificate to import. This member is used if the **dwSubjectChoice** member contains **CRYPTUI_WIZ_IMPORT_SUBJECT_FILE**.

### `pCertContext`

A pointer to the [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that contains the certificate to import. This member is used if the **dwSubjectChoice** member contains **CRYPTUI_WIZ_IMPORT_SUBJECT_CERT_CONTEXT**.

### `pCTLContext`

A pointer to the [CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure that contains the CTL to import. This member is used if the **dwSubjectChoice** member contains **CRYPTUI_WIZ_IMPORT_SUBJECT_CTL_CONTEXT**.

### `pCRLContext`

A pointer to the [CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) structure that contains the CRL to import. This member is used if the **dwSubjectChoice** member contains **CRYPTUI_WIZ_IMPORT_SUBJECT_CRL_CONTEXT**.

### `hCertStore`

A handle to the certificate store to import. This member is used if the **dwSubjectChoice** member contains **CRYPTUI_WIZ_IMPORT_SUBJECT_CERT_STORE**.

### `dwFlags`

Contains flags that modify the import operation. This member is required if **pwszFileName** contains a Personal Information Exchange (PFX) [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly). Otherwise, this member is ignored. This member can be zero or a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_EXPORTABLE** | Imported keys are marked as exportable. If this flag is not used, calls to the [CryptExportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportkey) function with the key handle fail. |
| **CRYPT_USER_PROTECTED** | The user is to be notified by means of a dialog box or some other manner when certain actions are attempting to use this key. The precise behavior is specified by the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) that is being used.<br><br>Prior to Internet Explorer 4.0, Microsoft CSPs ignored this flag. Starting with Internet Explorer 4.0, Microsoft CSPs support this flag.<br><br>If the provider context was opened with the **CRYPT_SILENT** flag set, using this flag causes a failure, and the last error is set to **NTE_SILENT_CONTEXT**. |
| **CRYPT_MACHINE_KEYSET** | The private keys are stored under the local computer and not under the current user. |
| **CRYPT_USER_KEYSET** | The private keys are stored under the current user and not under the local computer, even if the PFX BLOB specifies that they should go under the local computer. |

### `pwszPassword`

Pointer to a null-terminated Unicode string that contains the password used to access the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). A password is required if **pwszFileName** contains a PFX BLOB. If a password is not required, the variable can be an empty string. This member cannot be **NULL**.

## See also

[CRYPTUI_WIZ_EXPORT_INFO](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/ns-cryptuiapi-cryptui_wiz_export_info)

[CryptUIWizExport](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuiwizexport)