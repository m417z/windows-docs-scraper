# IX509EnrollmentPolicyServer::Validate

## Description

The **Validate** method validates the current policy information.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_NOT_VALID_STATE** | There was a problem with the lightweight directory access protocol (LDAP) used to locate the CEP server. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_STATE)** | The [IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver) has been initialized by calling the [InitializeImport](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentpolicyserver-initializeimport) method. |

## Remarks

This method calls [LoadPolicy](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentpolicyserver-loadpolicy) with the input parameter set to **LoadOptionReload**.

## See also

[IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver)