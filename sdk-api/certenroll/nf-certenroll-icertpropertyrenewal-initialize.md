# ICertPropertyRenewal::Initialize

## Description

The **Initialize** method initializes the object from a SHA-1 hash of the new certificate.

## Parameters

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode encoding applied to the input string that contains the hash.

### `strRenewalValue` [in]

A **BSTR** variable that contains the hash.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)**** | The object is already initialized. |

## Remarks

Typically this property is initialized during the enrollment process. You can retrieve the certificate used during enrollment by calling the [Certificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-get_certificate) property on the [IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment) interface.

Call the [SetValueOnCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-setvalueoncertificate) method to associate the property with a certificate. Call the [Renewal](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyrenewal-get_renewal) property to retrieve the hash.

## See also

[ICertPropertyRenewal](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyrenewal)