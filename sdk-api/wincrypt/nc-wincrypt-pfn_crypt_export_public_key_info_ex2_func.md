# PFN_CRYPT_EXPORT_PUBLIC_KEY_INFO_EX2_FUNC callback function

## Description

The **PFN_CRYPT_EXPORT_PUBLIC_KEY_INFO_EX2_FUNC** callback function is called by [CryptExportPublicKeyInfoEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportpublickeyinfoex) to export a public key BLOB and encode it.

## Parameters

### `hNCryptKey` [in]

A handle of the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) to use when exporting the public key information. This handle must be an **NCRYPT_KEY_HANDLE** handle that has been created by using the [NCryptOpenKey](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptopenkey) function.

### `dwCertEncodingType` [in]

A value that specifies the encoding type used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pszPublicKeyObjId` [in]

A pointer to a string that contains the [public key algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

### `dwFlags` [in]

A value that indicates how the public key information is exported. This can be zero.

### `pvAuxInfo` [in, optional]

This parameter is reserved for future use and must be set to **NULL**.

### `pInfo` [out, optional]

A pointer to a
[CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure to receive the public key information to be exported.

This parameter can be **NULL** to set the size of this information for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbInfo` [in, out]

A pointer to a **DWORD** that contains the size, in bytes, of the buffer pointed to by the *pInfo* parameter. When the function returns, the **DWORD** contains the number of bytes stored in the buffer.

**Note** When processing the data returned in the buffer, applications need to use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. (On input, buffer sizes are usually specified large enough to ensure that the largest possible output data will fit in the buffer.) On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If this callback function does not support the signature algorithm, it must return **FALSE** and call [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) with **ERROR_NOT_SUPPORTED**.

## Remarks

You can use [OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions) to deploy this callback function. Wincrypt.h defines the following constant for this purpose.

| Constant | Definition |
| --- | --- |
| CRYPT_OID_EXPORT_PUBLIC_KEY_INFO_EX2_FUNC | "CryptDllExportPublicKeyInfoEx2" |