# ICertPropertySHA1Hash::Initialize

## Description

The **Initialize** method initializes the object from the SHA-1 hash of a certificate.

## Parameters

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode encoding applied to the input string that contains the certificate hash.

### `strRenewalValue` [in]

A **BSTR** variable that contains the hash.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)**** | The object is already initialized. |

## Remarks

Call the [SetValueOnCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-setvalueoncertificate) method to associate the property with a certificate. Call the [SHA1Hash](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertysha1hash-get_sha1hash) property to retrieve the hash value.

## See also

[ICertPropertySHA1Hash](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertysha1hash)