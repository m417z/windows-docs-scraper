# ICertPropertyDescription::Initialize

## Description

The **Initialize** method initializes the object from a string that contains descriptive information about the certificate. Use this property to create a string that can be displayed in user interfaces that enumerate certificate properties. This method is web enabled.

## Parameters

### `strDescription` [in]

A **BSTR** variable that contains a description. The string length cannot exceed 260 characters.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The object is already initialized. |
| **HRESULT_FROM_WIN32(ERROR_FILENAME_EXCED_RANGE)** | The string length exceeds 260 characters. |

## Remarks

Call the [SetValueOnCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-setvalueoncertificate) method to associate the property with a certificate. Call the [Description](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertydescription-get_description) property to retrieve the description string.

## See also

[ICertProperties](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperties)

[ICertProperty](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperty)

[ICertPropertyDescription](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertydescription)

[ICertPropertyFriendlyName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyfriendlyname)