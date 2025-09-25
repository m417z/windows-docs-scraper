# ICertProperties::InitializeFromCertificate

## Description

The **InitializeFromCertificate** method initializes the collection from the properties contained in a certificate.

## Parameters

### `MachineContext` [in]

A **VARIANT_BOOL** variable that identifies the certificate store context. Specify **VARIANT_TRUE** for the computer and **VARIANT_FALSE** for the user.

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode encoding applied to the certificate contained in the *strCertificate* parameter.

### `strCertificate` [in]

A **BSTR** variable that contains the DER-encoded certificate.

Beginning with Windows 7 and Windows Server 2008 R2, you can specify a certificate thumb print or serial number rather than an encoded certificate. Doing so causes the function to search the appropriate local stores for the matching certificate. Keep in mind the following points:

* The **BSTR** must be an even number of hexadecimal digits.
* Whitespace between hexadecimal pairs is ignored.
* The *Encoding* parameter must be set to **XCN_CRYPT_STRING_HEXRAW**.
* The *MachineContext* parameter determines whether the user or computer stores or both are searched.
* If a private key is needed, only the personal and request stores are searched.
* If a private key is not needed, the root and intermediate CA stores are also searched.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****CRYPT_E_NOT_FOUND**** | The certificate could not be found. |
| ****CRYPT_E_UNEXPECTED_MSG_TYPE**** | The certificate was found but the private key could not be loaded. |

## See also

[ICertProperties](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperties)

[ICertProperty](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperty)