# IX509EnrollmentPolicyServer::GetCachePath

## Description

The **GetCachePath** method retrieves the path of the policy cache file on the certificate enrollment policy (CEP) server.

## Parameters

### `pValue` [out, retval]

Pointer to a **BSTR** that receives the path.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **CERTSRV_E_PROPERTY_EMPTY** | The cache path could not be found. |
| **E_POINTER** | The *pValue* parameter must not be **NULL**. |
| **OLE_E_BLANK** | The [IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver) has not been initialized. |

## See also

[IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver)