# IX500DistinguishedName::Decode

## Description

The **Decode** method initializes the object from a Unicode-encoded distinguished name.

## Parameters

### `strEncodedName` [in]

A **BSTR** variable that contains the encoded name.

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode encoding applied to the input string. The default value is **XCN_CRYPT_STRING_BASE64**.

### `NameFlags` [in]

An [X500NameFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x500nameflags) enumeration value that specifies the format of the decoded string.

**Note** The following flags are set automatically:

* The default value specified in Certenroll.h is **XCN_CERT_NAME_STR_NONE**.
* If you do not specify XCN_CERT_NAME_STR_FORWARD_FLAG, then XCN_CERT_NAME_STR_REVERSE_FLAG is automatically applied.
* If you do not specify XCN_CERT_NAME_STR_DISABLE_UTF8_DIR_STR_FLAG, then XCN_CERT_NAME_STR_FORCE_UTF8_DIR_STR_FLAG is automatically applied.
* XCN_CERT_NAME_STR_ENABLE_PUNYCODE_FLAG is automatically set regardless of any other flag you specify.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Memory could not be allocated for the decoded value. |
| **E_POINTER** | The *strEncodedName* parameter cannot be **NULL**. |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)** | The name could not be decoded. |

## Remarks

This method internally calls the CryptoAPI [CertNameToStr](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certnametostra) function. Call the [Name](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix500distinguishedname-get_name) property to retrieve the name as a null-terminated character string. Call the [EncodedName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix500distinguishedname-get_encodedname) property to retrieve a string containing an encoded name.

## See also

[IX500DistinguishedName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix500distinguishedname)