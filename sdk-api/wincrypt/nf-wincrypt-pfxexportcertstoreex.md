# PFXExportCertStoreEx function

## Description

The **PFXExportCertStoreEx** function exports the certificates and, if available, their associated private keys from the referenced certificate store. This function replaces the older
[PfxExportCertStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-pfxexportcertstore) function. It should be used for its enhanced private key security. The PFX BLOB created by this function is protected by a password.

## Parameters

### `hStore` [in]

Handle of the certificate store containing the certificates to be exported.

### `pPFX` [in, out]

A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure to contain the PFX packet with the exported certificates and keys. If *pPFX*->*pbData* is **NULL**, the function calculates the number of bytes needed for the encoded BLOB and returns this in *pPFX*->*cbData*. When the function is called with *pPFX*->*pbData* pointing to an allocated buffer of the needed size, the function copies the encoded bytes into the buffer and updates *pPFX*->*cbData* with the encode byte length.

### `szPassword` [in]

String password used to encrypt and verify the PFX packet. When you have finished using the password, clear the password from memory by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function. For more information about protecting passwords, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

### `pvPara` [in]

This parameter must be **NULL** if the *dwFlags* parameter does not contain **PKCS12_PROTECT_TO_DOMAIN_SIDS** or **PKCS12_EXPORT_PBES2_PARAMS**. Prior to Windows 8 and Windows Server 2012, therefore, this parameter must be **NULL**.

Beginning with Windows 8 and Windows Server 2012, if the *dwFlags* parameter contains **PKCS12_PROTECT_TO_DOMAIN_SIDS**, you can set the *pvPara* parameter to point to an **NCRYPT_DESCRIPTOR_HANDLE** value to identify which Active Directory principal the PFX password will be protected to inside of the PFX BLOB. Currently, the password can be protected to an Active Directory user, computer, or group. For more information about protection descriptors, see [NCryptCreateProtectionDescriptor](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptcreateprotectiondescriptor).

Beginning with Windows 10 1709 (Fall Creators update) and Windows Server 2019, if the *dwFlags* parameter contains **PKCS12_EXPORT_PBES2_PARAMS**, you should set the *pvPara* to an **[PKCS12_EXPORT_PBES2_PARAMS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-pkcs12_pbes2_export_params)** value to select the password-based encryption algorithm to use.

### `dwFlags` [in]

Flag values can be set to any combination of the following.

| Value | Meaning |
| --- | --- |
| **EXPORT_PRIVATE_KEYS**<br><br>0x0004 | Private keys are exported as well as the certificates. |
| **REPORT_NO_PRIVATE_KEY**<br><br>0x0001 | If a certificate is encountered that has no associated private key, the function returns FALSE with the last error set to either CRYPT_E_NOT_FOUND or NTE_NO_KEY. |
| **REPORT_NOT_ABLE_TO_EXPORT_PRIVATE_KEY**<br><br>0x0002 | If a certificate is encountered that has a non-exportable private key, the function returns FALSE and the last error set to NTE_BAD_KEY, NTE_BAD_KEY_STATE, or NTE_PERM. |
| **PKCS12_INCLUDE_EXTENDED_PROPERTIES**<br><br>0x0010 | Export all extended properties on the certificate.<br><br> <br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **PKCS12_PROTECT_TO_DOMAIN_SIDS**<br><br>0x0020 | The PFX BLOB contains an embedded password that will be protected to the Active Directory (AD) protection descriptor pointed to by the *pvPara* parameter. If the *szPassword* parameter is not **NULL** or empty, the specified password is protected. If, however, the *szPassword* parameter is **NULL** or an empty string, a random forty (40) character password is created and protected.<br><br>[PFXImportCertStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-pfximportcertstore) uses the specified protection descriptor to decrypt the embedded password, whether specified by the user or randomly generated, and then uses the password to decrypt the PFX BLOB.<br><br>**Windows 8 and Windows Server 2012:** Support for this flag begins. |
| **PKCS12_EXPORT_PBES2_PARAMS**<br><br>0x0080 | Export using the passowrd-based encryption algorithm specified by the **[PKCS12_EXPORT_PBES2_PARAMS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-pkcs12_pbes2_export_params)** value passed as *pvPara*.<br><br>**Windows 10 1709 (Fall Creators update) and Windows Server 2019:** Support for this flag begins. |

## Return value

Returns **TRUE** (nonzero) if the function succeeds, and **FALSE** (zero) if the function fails. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Beginning with Windows 8 and Windows Server 2012, you can protect the PFX password to an Active Directory user, computer, or group. If you choose to do so but do not create a password, a temporary password will be randomly selected. The password is encrypted by using the Active Directory principal and then embedded in the PFX BLOB. For more information, see the *pvPara* parameter and the **PKCS12_PROTECT_TO_DOMAIN_SIDS** flag.

Beginning with Windows 10 1709 (Fall Creators update) and Windows Server 2019, you can control the number of iterations of the hash function over the password done by the **PFXExportCertStoreEx** function using the following registry key. The value in this key is of type **REG_DWORD**.

**HKEY_LOCAL_MACHINE**\**Software**\**Microsoft**\**Windows**\**CurrentVersion**\**PFX**\**PasswordIterationCount**

## See also

[PFXExportCertStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-pfxexportcertstore)

[PFXImportCertStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-pfximportcertstore)