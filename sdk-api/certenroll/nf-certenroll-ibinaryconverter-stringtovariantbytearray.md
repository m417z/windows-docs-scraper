# IBinaryConverter::StringToVariantByteArray

## Description

The **StringToVariantByteArray** method creates a byte array from a Unicode encoded string. Use this method to create a [certificate BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) from an encoded string that contains a certificate.

## Parameters

### `strEncoded` [in]

A **BSTR** variable that contains the Unicode encoded string.

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the Unicode encoding applied to the input string. The default value is **XCN_CRYPT_STRING_BASE64**.

### `pvarByteArray` [out]

Pointer to a **VARIANT** array of bytes. The VARTYPE enumeration value equals **VT_ARRAY** | **VT_UI1**.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IBinaryConverter](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ibinaryconverter)