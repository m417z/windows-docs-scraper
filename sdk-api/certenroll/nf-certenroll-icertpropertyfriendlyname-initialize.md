# ICertPropertyFriendlyName::Initialize

## Description

The **Initialize** method initializes the object from the certificate display name. This method is web enabled.

## Parameters

### `strFriendlyName` [in]

A **BSTR** variable that contains the name. The string length cannot exceed 260 characters.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)**** | The object is already initialized. |
| ****HRESULT_FROM_WIN32(ERROR_FILENAME_EXCED_RANGE)**** | The string length exceeds 260 characters. |

## Remarks

Typically, you specify the display name in a user interface or from the command line before beginning the enrollment process so that the name can be associated with the dummy certificate in the request store. To retrieve that value and use it here, call the [CertificateFriendlyName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-get_certificatefriendlyname) on the [IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment) interface.

Call the [SetValueOnCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-setvalueoncertificate) method to associate the property with a certificate. Call the [FriendlyName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyfriendlyname-get_friendlyname) property to retrieve the display name.

## See also

[ICertProperties](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperties)

[ICertProperty](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperty)

[ICertPropertyDescription](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertydescription)

[ICertPropertyFriendlyName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyfriendlyname)