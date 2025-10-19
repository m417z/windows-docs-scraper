# IX509PublicKey::InitializeFromEncodedPublicKeyInfo

## Description

The **InitializeFromEncodedPublicKeyInfo** method initializes the object from a byte array that contains a public key. The byte array is represented by a Unicode-encoded string.

## Parameters

### `strEncodedPublicKeyInfo` [in]

A **BSTR** variable that contains the key.

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode encoding applied to the key contained in the *strEncodedPublicKeyInfo* parameter. The default value is XCN_CRYPT_STRING_BASE64.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The object has already been initialized. |

## Remarks

The **InitializeFromEncodedPublicKeyInfo** method initializes the following property values from an existing public key:

* [Algorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509publickey-get_algorithm)
* [EncodedKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509publickey-get_encodedkey)
* [EncodedParameters](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509publickey-get_encodedparameters)
* [Length](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509publickey-get_length)

## See also

[IX509PublicKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509publickey)