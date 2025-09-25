# IX509EnrollmentPolicyServer::GetAllowUnTrustedCA

## Description

The **GetAllowUnTrustedCA** method retrieves a value that specifies whether to allow an untrusted certification authority certificate. This value is set by the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentpolicyserver-initialize) method.

## Parameters

### `pValue` [out, retval]

Pointer to a Boolean value that specifies whether to allow the certificate.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *pValue* parameter cannot be **NULL**. |

## See also

[IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver)