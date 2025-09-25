# IX509EnrollmentPolicyServer::GetCAsForTemplate

## Description

The **GetCAsForTemplate** method retrieves a collection of certificate enrollment servers that support a specified template.

## Parameters

### `pTemplate` [in]

Pointer to an [IX509CertificateTemplate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificatetemplate) interface that represents the template.

### `ppCAs` [out, retval]

Address of a variable that receives a pointer to an [ICertificationAuthorities](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertificationauthorities) interface that represents the server collection.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **OLE_E_BLANK** | The [IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver) object has not been initialized. |

## See also

[IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver)