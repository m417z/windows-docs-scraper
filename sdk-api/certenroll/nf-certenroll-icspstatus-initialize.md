# ICspStatus::Initialize

## Description

The **Initialize** method initializes the object from a cryptographic provider and an associated algorithm. This method is web enabled.

## Parameters

### `pCsp` [in]

Pointer to an [ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation) interface that represents information about the provider.

### `pAlgorithm` [in, optional]

Pointer to an [ICspAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspalgorithm) interface that represents an algorithm supported by the provider identified in the *pCsp* parameter. This parameter is optional and can be **NULL**.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)**** | The object is already initialized. |

## Remarks

The **Initialize** method saves the [ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation) and [ICspAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspalgorithm) objects you specify in the [CspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspstatus-get_cspinformation) and [CspAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspstatus-get_cspalgorithm) properties. The method also creates an empty [IX509EnrollmentStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentstatus) object and saves it in the [EnrollmentStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspstatus-get_enrollmentstatus) property.

An [ICspStatuses](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatuses) collection is typically initialized by an [IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10) object. The **Initialize** method has been provided so that you can create [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) objects to add to a custom collection.

## See also

[ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus)

[ICspStatuses](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatuses)