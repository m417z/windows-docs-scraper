# PFXImportCertStore function

## Description

The **PFXImportCertStore** function imports a PFX BLOB and returns the handle of a store that contains certificates and any associated [private keys](https://learn.microsoft.com/windows/win32/SecGloss/p-gly).

## Parameters

### `pPFX` [in]

A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains a PFX packet with the exported and encrypted certificates and keys.

### `szPassword` [in]

A string password used to decrypt and verify the PFX packet. Whether set to a string of length greater than zero or set to an empty string or to **NULL**, this value must be exactly the same as the value that was used to encrypt the packet.

Beginning with Windows 8 and Windows Server 2012, if the PFX packet was created in the [PFXExportCertStoreEx](https://learn.microsoft.com/windows/win32/api/wincrypt/nf-wincrypt-pfxexportcertstoreex) function by using the **PKCS12_PROTECT_TO_DOMAIN_SIDS** flag, the **PFXImportCertStore** function attempts to decrypt the password by using the Active Directory (AD) principal that was used to encrypt it. The AD principal is specified in the *pvPara* parameter. If the *szPassword* parameter in the **PFXExportCertStoreEx** function was an empty string or **NULL** and the *dwFlags* parameter was set to **PKCS12_PROTECT_TO_DOMAIN_SIDS**, that function randomly generated a password and encrypted it to the AD principal specified in the *pvPara* parameter. In that case you should set the password to the value, empty string or **NULL**, that was used when the PFX packet was created. The **PFXImportCertStore** function will use the AD principal to decrypt the random password, and the randomly generated password will be used to decrypt the PFX certificate.

When you have finished using the password, clear it from memory by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function. For more information about protecting passwords, see [Handling Passwords](https://learn.microsoft.com/windows/win32/SecBP/handling-passwords).

### `dwFlags` [in]

The *dwFlags* parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| **CRYPT_EXPORTABLE**<br><br>0x00000001 | Imported keys are marked as exportable. If this flag is not used, calls to the [CryptExportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportkey) function with the key handle fail. |
| **CRYPT_USER_PROTECTED**<br><br>0x00000002 | The user is to be notified through a dialog box or other method when certain attempts to use this key are made. The precise behavior is specified by the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) being used.<br><br>Prior to Internet Explorer 4.0, Microsoft cryptographic service providers ignored this flag. Starting with Internet Explorer 4.0, Microsoft providers support this flag.<br><br>If the provider context was opened with the CRYPT_SILENT flag set, using this flag causes a failure and the last error is set to NTE_SILENT_CONTEXT. |
| **CRYPT_MACHINE_KEYSET**<br><br>0x00000020 | The private keys are stored under the local computer and not under the current user. |
| **CRYPT_USER_KEYSET**<br><br>0x00001000 | The private keys are stored under the current user and not under the local computer even if the PFX BLOB specifies that they should go into the local computer. |
| **PKCS12_PREFER_CNG_KSP**<br><br>0x00000100 | Indicates that the CNG [key storage provider](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) (KSP) is preferred. If the CSP is specified in the PFX file, then the CSP is used, otherwise the KSP is preferred. If the CNG KSP is unavailable, the **PFXImportCertStore** function will fail.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **PKCS12_ALWAYS_CNG_KSP**<br><br>0x00000200 | Indicates that the CNG KSP is always used. When specified, **PFXImportCertStore** attempts to use the CNG KSP irrespective of provider information in the PFX file. If the CNG KSP is unavailable, the import will not fail.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **PKCS12_ALLOW_OVERWRITE_KEY**<br><br>0x00004000 | Allow overwrite of the existing key. Specify this flag when you encounter a scenario in which you must import a PFX file that contains a key name that already exists. For example, when you import a PFX file, it is possible that a container of the same name is already present because there is no unique namespace for key containers. If you have created a "TestKey" on your computer, and then you import a PFX file that also has "TestKey" as the key container, the **PKCS12_ALLOW_OVERWRITE_KEY** setting allows the key to be overwritten.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **PKCS12_NO_PERSIST_KEY**<br><br>0x00008000 | Do not persist the key. Specify this flag when you do not want to persist the key. For example, if it is not necessary to store the key after verification, then instead of creating a container and then deleting it, you can specify this flag to dispose of the key immediately.<br><br>**Note** If the **PKCS12_NO_PERSIST_KEY** flag is *not* set, keys are persisted on disk. If you do not want to persist the keys beyond their usage, you must delete them by calling the [CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) function with the **CRYPT_DELETEKEYSET** flag set in the *dwFlags* parameter.<br><br>**Note** Some other considerations:<br><br>* When using PKCS12_NO_PERSIST_KEY, the property CERT_KEY_CONTEXT_PROP_ID is set internally on the certificate, and contains the key.<br><br>* If the PKCS12_NO_PERSIST_KEY is not used, the CERT_KEY_PROV_INFO_PROP_ID property is set.<br><br>* If the certificate with the non-persisting key is marshaled to another process, the CERT_KEY_CONTEXT_PROP_ID property will not be marshalled.<br><br>* For NO_PERSIST to work, it must be in same process *and* the user of the PCCERT_CONTEXT must support the CERT_KEY_CONTEXT_PROP_ID. This typically applies during a TLS handshake: if the handshake is performed externally to the calling process in LSASS.exe, it is not possible to use PKCS12_NO_PERSIST_KEY when moving from the calling process to LSASS (because the NCRYPT_KEY_HANDLE is a pointer to a data structure and not a kernel handle).<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **PKCS12_INCLUDE_EXTENDED_PROPERTIES**<br><br>0x0010 | Import all extended properties on the certificate that were saved on the certificate when it was exported.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| 0x10000000 | Unpack but do not persist the results. |

## Return value

If the function succeeds, the function returns a handle to a certificate store that contains the imported certificates, including available private keys.

If the function fails, that is, if the password parameter does not contain an exact match with the password used to encrypt the exported packet or if there were any other problems decoding the PFX BLOB, the function returns **NULL**, and an error code can be found by calling the [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

The **PFXImportCertStore** function opens a temporary store. If the function succeeds, you should close the handle to the store by calling the [CertCloseStore](https://learn.microsoft.com/windows/win32/api/wincrypt/nf-wincrypt-certclosestore) function.

When you import a certificate from the PFX packet, the CSP/KSP container name is determined by using the AttributeId with OID 1.3.6.1.4.1.311.17.1 of the PKCS8ShroudedKeyBag SafeBag [bagId: 1.2.840.113549.1.12.10.1.2] (see [PKCS #12](https://www.rfc-editor.org/rfc/rfc7292) for details about the ASN.1 structure of this).

* **AttributeId:** 1.3.6.1.4.1.311.17.1
* **Value:** The KSP name or CSP name

If the AttributeId is not present and the PREFER_CNG flag is passed, MS_KEY_STORAGE_PROVIDER is picked. If the AttributeId is not present and the PREFER_CNG flag is not passed, the provider name is determined based on the public key algorithm (that is, the public key algorithm is determined by the AlgorithmIdentifier in PKCS #8):

* **RSA:** MS_ENHANCED_PROV_W
* **DSA:** MS_DEF_DSS_DH_PROV_W

Similarly, the key specification is determined by using the AttributeId with OID 2.5.29.15 (szOID_KEY_USAGE) as follows:

**If a CAPI key is used:**

* If KEY_ENCIPHERMENT or DATA_ENCIPHERMENT is set, then the key specification is set to AT_KEYEXCHANGE.
* If DIGITAL_SIGNATURE or CERT_SIGN or CRL_SIGN is set, then the key specification is set to AT_SIGNATURE.

**If a CNG key is used:**

* If KEY_ENCIPHERMENT or DATA_ENCIPHERMENT or ENCIPHER_ONLY or DECIPHER_ONLY is set, then ncrypt key usage is set to ALLOW_DECRYPT.
* If DIGITAL_SIGNATURE or CERT_SIGN or CRL_SIGN is set, ncrypt key usage is set to ALLOW_SIGN.
* If KEY_AGREEMENT is set, then ncrypt key usage is set to ALLOW_KEY_AGREEMENT.

If the AttributeId is not present, then the CAPI key value is set to AT_KEYEXCHANGE for RSA or DH and the algorithm is determined by the AlgorithmIdentifier in PKCS #8; otherwise, the algorithm is set to AT_SIGNATURE. For the CNG key value, all ncrypt key usage is set.

>[!NOTE]
>If an invalid provider name is present in the PFX packet, or the base or enhanced cryptography provider is not present in this registry key: **HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Cryptography\\Defaults\\Provider**, then a provider lookup is performed by the provider type using this registry subkey: **HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Cryptography\\Defaults\\Provider Types**.

Microsoft only supports two encryption/hash algorithms for importing a PFX:

* TripleDES-SHA1
* AES256-SHA256

For either of the above algorithms, encryption of the certificates is optional.

Microsoft can export a PFX from a certificate store via the `All Tasks` \> `Yes, export the private key` selection. There you can select the encryption/hash algorithm to match one of these two choices.

You can use PowerShell to export a PFX via the following:

```powershell
Export-PfxCertificate
[-CryptoAlgorithmOption <CryptoAlgorithmOptions>]
```

`-CryptoAlgorithmOption` specifies the algorithm for encrypting private keys within the PFX file. If this parameter is not specified, the default is `TripleDES_SHA1`. The acceptable values for this parameter are:

| Value | Description |
|--------|--------|
| `TripleDES_SHA1` | Private keys will be encrypted in the PFX file using Triple DES encryption. |
| `AES256_SHA256` | Private keys will be encrypted in the PFX file using AES-256 encryption. |

OpenSSL supports the above two algorithms via the following commands:

* `openssl pkcs12 -keypbe PBE-SHA1-3DES -certpbe PBE-SHA1-3DES -in in.pem -export -out out.pfx -password file:password.txt -passin file:password.txt`
* `openssl pkcs12 -keypbe AES-256-CBC -certpbe AES-256-CBC -macalg sha256 -in in.pem -export -out out.pfx -password file:password.txt -passin file:password.txt`

The following commands are equivalent to the previous two, but they do not encrypt the certificates:

* `openssl pkcs12 -keypbe PBE-SHA1-3DES -certpbe NONE -in in.pem -export -out out.pfx -password file:password.txt -passin file:password.txt`
* `openssl pkcs12 -keypbe AES-256-CBC -certpbe NONE -macalg sha256 -in in.pem -export -out out.pfx -password file:password.txt -passin file:password.txt`

## See also

[PFXExportCertStore](https://learn.microsoft.com/windows/win32/api/wincrypt/nf-wincrypt-pfxexportcertstore)

[PFXExportCertStoreEx](https://learn.microsoft.com/windows/win32/api/wincrypt/nf-wincrypt-pfxexportcertstoreex)