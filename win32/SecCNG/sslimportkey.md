# SslImportKey function

The **SslImportKey** function imports a key into the [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) protocol provider.

## Parameters

*hSslProvider* \[in\]

The handle to the SSL protocol provider instance.

*phKey* \[out\]

A pointer to the handle of the [*cryptographic key*](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to receive the imported key.

*pszBlobType* \[in\]

A null-terminated Unicode string that contains an identifier that specifies the type of [*BLOB*](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) that is contained in the *pbInput* buffer. This can be one of the following values.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**BCRYPT\_DH\_PUBLIC\_BLOB**

| Export a Diffie-Hellman [*public key*](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). The *pbOutput* buffer receives a [**BCRYPT\_DH\_KEY\_BLOB**](https://learn.microsoft.com/windows/desktop/api/Bcrypt/ns-bcrypt-bcrypt_dh_key_blob) structure immediately followed by the key data.<br> |
|

**BCRYPT\_ECCPUBLIC\_BLOB**

| Export an [*elliptic curve cryptography*](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) (ECC) [*public key*](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). The *pbOutput* buffer receives a [**BCRYPT\_ECCKEY\_BLOB**](https://learn.microsoft.com/windows/desktop/api/Bcrypt/ns-bcrypt-bcrypt_ecckey_blob) structure immediately followed by the key data.<br> |
|

**BCRYPT\_OPAQUE\_KEY\_BLOB**

| Export a [*symmetric key*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) in a format that is specific to a single [*cryptographic service provider*](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP). Opaque BLOBs are not transferable and must be imported by using the same CSP that generated the BLOB.<br> |
|

**BCRYPT\_RSAPUBLIC\_BLOB**

| Export an [*RSA*](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) public key. The *pbOutput* buffer receives a [**BCRYPT\_RSAKEY\_BLOB**](https://learn.microsoft.com/windows/desktop/api/Bcrypt/ns-bcrypt-bcrypt_rsakey_blob) structure immediately followed by the key data.<br> |

*pbKeyBlob* \[in\]

A pointer to the buffer that contains the [*key BLOB*](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly).

*cbKeyBlob* \[in\]

The size, in bytes, of the *pbKeyBlob* buffer.

*dwFlags* \[in\]

This parameter is reserved for future use.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------|
| **NTE\_NO\_MEMORY**

0x8009000EL | Not enough memory is available to allocate necessary buffers.\ | | **NTE\_INVALID\_HANDLE**

0x80090026L | The *hSslProvider* handle is not valid.\ | | **NTE\_INVALID\_PARAMETER**

0x80090027L | The *phKey* parameter is **NULL**.\ | ## Remarks You can use the **SslImportKey** function to import session keys as a part of the process of transferring session keys from one process to another. ## Requirements | Requirement | Value | |-------------------------------------|------------------------------------------------------------------------------------------| | Minimum supported client\ | Windows Vista \[desktop apps only\]\ | | Minimum supported server\ | Windows Server 2008 \[desktop apps only\]\ | | Header\ | Sslprovider.h | | DLL\ | Ncrypt.dll |