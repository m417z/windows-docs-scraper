# ICertPropertyAutoEnroll::Initialize

## Description

The **Initialize** method initializes the object by specifying the name of the template to be used for autoenrollment.

## Parameters

### `strTemplateName` [in]

A **BSTR** variable that contains the template name or object identifier.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)**** | The object is already initialized. |

## Remarks

 Call the [SetValueOnCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-setvalueoncertificate) method to associate the property with a certificate. Call the [TemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyautoenroll-get_templatename) property to retrieve the template name.

## See also

[ICertProperty](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperty)

[ICertPropertyAutoEnroll](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyautoenroll)