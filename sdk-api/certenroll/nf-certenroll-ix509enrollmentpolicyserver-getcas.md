# IX509EnrollmentPolicyServer::GetCAs

## Description

The **GetCAs** method retrieves a collection of certification enrollment servers included in the policy.

## Parameters

### `ppCAs` [out, retval]

Address of a variable that receives a pointer to an [ICertificationAuthorities](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertificationauthorities) interface that represents the collection.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **OLE_E_BLANK** | The [IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver) object has not been initialized. |

## See also

[IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver)