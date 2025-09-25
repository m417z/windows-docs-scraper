# IBinaryConverter::VariantByteArrayToString

## Description

The **VariantByteArrayToString** method creates a Unicode encoded string from a byte array. You can use this method to create a printable string from a [certificate BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

## Parameters

### `pvarByteArray` [in]

Pointer to a **VARIANT** array of bytes to be encoded. Each byte in the array must be an unsigned integer. That is, the VARTYPE enumeration value must equal **VT_ARRAY** | **VT_UI1**.

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the Unicode encoding applied to the input string. The default value is **XCN_CRYPT_STRING_BASE64**.

### `pstrEncoded` [out]

Pointer to a **BSTR** variable that contains the Unicode-encoded certificate.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IBinaryConverter](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ibinaryconverter)