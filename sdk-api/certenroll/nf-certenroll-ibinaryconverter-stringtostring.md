# IBinaryConverter::StringToString

## Description

The **StringToString** method modifies the type of Unicode encoding applied to a string.

## Parameters

### `strEncodedIn` [in]

A **BSTR** variable that contains the string to modify.

### `EncodingIn` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the Unicode encoding applied to the input string.

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode encoding to apply to the output string. The default value is **XCN_CRYPT_STRING_BASE64**.

### `pstrEncoded` [out]

Pointer to a **BSTR** variable that contains the encoded output string.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IBinaryConverter](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ibinaryconverter)