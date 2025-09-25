# ICertPropertyRequestOriginator::Initialize

## Description

The **Initialize** method initializes the object from a string that contains the DNS name of the originating computer.

## Parameters

### `strRequestOriginator` [in]

A **BSTR** variable that contains the name.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)**** | The object is already initialized. |

## Remarks

Call the [SetValueOnCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-setvalueoncertificate) method to associate the property with a certificate. Call the [RequestOriginator](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyrequestoriginator-get_requestoriginator) property to retrieve the DNS name of the originating computer.

## See also

[ICertPropertyRequestOriginator](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyrequestoriginator)