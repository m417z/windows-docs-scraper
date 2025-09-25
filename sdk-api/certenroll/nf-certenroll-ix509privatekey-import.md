# IX509PrivateKey::Import

## Description

The **Import** method imports an existing private key into a key container within a cryptographic provider.

## Parameters

### `strExportType` [in]

If the key was created by using a CNG KSP (Key Storage Provider), the **Import** method passes this argument to the *pszProperty* parameter of the [NCryptSetProperty](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptsetproperty) function. That is, the value you specify will be used as the name of a property to be set on the imported key.

If the key was created by using a CryptoAPI CSP (Cryptographic Service Provider), this argument specifies how the private key is to be imported. This can be the following value.

| Value | Meaning |
| --- | --- |
| **BCRYPT_PRIVATE_KEY_BLOB** | Imports the entire private key. |

### `strEncodedKey` [in]

A **BSTR** variable that contains the key to import.

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode encoding to be applied to the string contained in the *strEncodedKey* parameter. The default value is XCN_CRYPT_STRING_BASE64.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_FILE_READ_ONLY)** | The key container is already open. You can receive this error if you have already called [Open](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-open) or [Create](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-create). |
| **HRESULT_FROM_WIN32(ERROR_CALL_NOT_IMPLEMENTED)** | The key was created by a CryptoAPI CSP and you specified a value other than BCRYPT_PRIVATE_KEY_BLOB for the *strExportType* parameter. |

## Remarks

The **Import** function automatically assumes that you are attempting to import a CNG KSP key if you specify a value other than BCRYPT_PRIVATE_KEY_BLOB for the *strExportType* parameter and you do not set any of the following properties:

* [CspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_cspstatus)
* [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_keyspec)
* [LegacyCsp](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_legacycsp)
* [ProviderName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_providername)
* [ProviderType](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_providertype)

## See also

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)