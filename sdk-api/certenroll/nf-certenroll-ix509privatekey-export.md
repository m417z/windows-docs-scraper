# IX509PrivateKey::Export

## Description

The **Export** method copies the private key to a byte array. The byte array is represented by a Unicode-encoded string.

## Parameters

### `strExportType` [in]

A **BSTR** value that specifies how the private key is exported.

If the key was created by using a CNG KSP (Key Storage Provider), you can specify one of the values allowed by the *pszBlobType* parameter in the [NCryptExportKey](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptexportkey) function.

If the key was created by using a CryptoAPI CSP (Cryptographic Service Provider), you can specify one of the following values from the Bcrypt.h header file included with Wincrypt.h.

| Value | Meaning |
| --- | --- |
| **BCRYPT_PUBLIC_KEY_BLOB** | Exports only the public portion of the private key. |
| **BCRYPT_PRIVATE_KEY_BLOB** | Exports the entire private key. |

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode encoding to be applied to the string contained in the *pstrEncodedKey* parameter. The default value is XCN_CRYPT_STRING_BASE64.

### `pstrEncodedKey` [out]

Pointer to a **BSTR** variable that contains the private key.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_CALL_NOT_IMPLEMENTED)** | The key was created by a CryptoAPI CSP and you specified a value other than BCRYPT_PRIVATE_KEY_BLOB or BCRYPT_PUBLIC_KEY_BLOB for the *strExportType* parameter. |

## See also

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)