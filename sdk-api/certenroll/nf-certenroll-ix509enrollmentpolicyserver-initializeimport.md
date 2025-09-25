# IX509EnrollmentPolicyServer::InitializeImport

## Description

The **InitializeImport** method initializes the certificate enrollment policy (CEP) server from a collection of templates and object identifiers.

## Parameters

### `val` [in]

A **VARIANT** of type **VT_ARRAY|VT_UI1** that contains the templates and object identifiers.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The [IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver) object has already been initialized. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_PARAMETER)** | The **VARIANT** in the *val* parameter is not of type **VT_ARRAY**. |

## Remarks

Call this method to import templates and OIDs previously written to a buffer by the [Export](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentpolicyserver-export) method.

## See also

[IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver)