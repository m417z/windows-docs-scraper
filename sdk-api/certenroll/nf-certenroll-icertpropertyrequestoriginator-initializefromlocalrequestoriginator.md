# ICertPropertyRequestOriginator::InitializeFromLocalRequestOriginator

## Description

The **InitializeFromLocalRequestOriginator** method initializes the object from the DNS name of the local computer.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Call the [SetValueOnCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-setvalueoncertificate) method to associate the property with a certificate. Call the [RequestOriginator](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyrequestoriginator-get_requestoriginator) property to retrieve the DNS name of the originating computer.

## See also

[ICertPropertyRequestOriginator](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyrequestoriginator)