# ICertPropertyArchived::Initialize

## Description

The **Initialize** method initializes the object from a Boolean value that specifies whether the certificate has been archived.

## Parameters

### `ArchivedValue` [in]

A **VARIANT_BOOL** variable that identifies whether the certificate has been archived.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)**** | The object is already initialized. |

## Remarks

 Call the [SetValueOnCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-setvalueoncertificate) method to associate the property with a certificate. Call the [Archived](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyarchived-get_archived) property to retrieve the Boolean value.

## See also

[ICertProperty](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperty)

[ICertPropertyArchived](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyarchived)