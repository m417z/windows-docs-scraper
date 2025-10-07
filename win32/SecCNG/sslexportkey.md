# SslExportKey function

The **SslExportKey** function returns an [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) [*session key*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) or public ephemeral key into a serialized [*BLOB*](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly).

## Parameters

*hSslProvider* \[in\]

The handle of the SSL protocol provider instance.

*hKey* \[in\]

The handle of the key to export.

When you are not specifying a key, set this parameter to **NULL**.

> [!Note]
> A *hKey* handle is obtained by calling the [**SslOpenPrivateKey**](https://learn.microsoft.com/windows/win32/seccng/sslopenprivatekey) function. Handles obtained from the [**NCryptOpenKey**](https://learn.microsoft.com/windows/desktop/api/Ncrypt/nf-ncrypt-ncryptopenkey) function are not supported.

*pszBlobType* \[in\]

A null-terminated Unicode string that contains an identifier that specifies the type of BLOB to export. This can be one of the following values.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**BCRYPT\_DH\_PUBLIC\_BLOB**

| Export a Diffie-Hellman [*public key*](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). The *pbOutput* buffer receives a [**BCRYPT\_DH\_KEY\_BLOB**](https://learn.microsoft.com/windows/desktop/api/Bcrypt/ns-bcrypt-bcrypt_dh_key_blob) structure immediately followed by the key data.<br> |
|

**BCRYPT\_ECCPUBLIC\_BLOB**

| Export an [*elliptic curve cryptography*](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) (ECC) public key. The *pbOutput* buffer receives a [**BCRYPT\_ECCKEY\_BLOB**](https://learn.microsoft.com/windows/desktop/api/Bcrypt/ns-bcrypt-bcrypt_ecckey_blob) structure immediately followed by the key data.<br> |
|

**BCRYPT\_OPAQUE\_KEY\_BLOB**

| Export a symmetric key in a format that is specific to a single [*cryptographic service provider*](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP). Opaque BLOBs are not transferable and must be imported by using the same *cryptographic service provider* (CSP) that generated the BLOB.<br> |
|

**BCRYPT\_RSAPUBLIC\_BLOB**

| Export an RSA public key. The *pbOutput* buffer receives a [**BCRYPT\_RSAKEY\_BLOB**](https://learn.microsoft.com/windows/desktop/api/Bcrypt/ns-bcrypt-bcrypt_rsakey_blob) structure immediately followed by the key data.<br> |

*pbOutput* \[out, optional\]

The address of a buffer that receives the [*key BLOB*](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly). The *cbOutput* parameter contains the size of this buffer. If this parameter is **NULL**, this function will place the required size, in bytes, in the **DWORD** pointed to by the *pcbResult* parameter.

*cbOutput* \[in\]

The size, in bytes, of the *pbOutput* buffer.

*pcbResult* \[out\]

The address of a **DWORD** variable that receives the number of bytes copied to the *pbOutput* buffer. If the *pbOutput* parameter is set to **NULL** when the function is called, the required size for the *pbOutput* buffer, in bytes, is returned in the **DWORD** pointed to by this parameter.

*dwFlags* \[in\]

Reserved for future use.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------|
| **NTE\_INVALID\_HANDLE**

0x80090026L | One of the provided handles is not valid.\ | ## Remarks The **SslExportKey** function facilitates transporting session keys from one process to another as well as exporting the public portion an ephemeral key. When exporting session keys, the BLOB type is opaque, meaning that the format of the BLOB is irrelevant as long as both the **SslExportKey** and [**SslImportKey**](https://learn.microsoft.com/windows/win32/seccng/sslimportkey) functions can interpret it. When exporting the public portion of an ephemeral key the BLOB type must be the appropriate type, such as **NCRYPT\_DH\_PUBLIC\_BLOB** or **NCRYPT\_ECCPUBLIC\_BLOB**. ## Requirements | Requirement | Value | |-------------------------------------|------------------------------------------------------------------------------------------| | Minimum supported client\ | Windows Vista \[desktop apps only\]\ | | Minimum supported server\ | Windows Server 2008 \[desktop apps only\]\ | | Header\ | Sslprovider.h | | DLL\ | Ncrypt.dll |