# IX509EnrollmentPolicyServer::GetCacheDir

## Description

The **GetCacheDir** method retrieves the name of the directory on the certificate enrollment policy (CEP) server that contains the policy cache file.

## Parameters

### `pValue` [out, retval]

Pointer to a **BSTR** that receives the directory name.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **CERTSRV_E_PROPERTY_EMPTY** | The cache directory could not be found. |
| **E_POINTER** | The *pValue* parameter must not be **NULL**. |
| **OLE_E_BLANK** | The [IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver) has not been initialized. |

## See also

[IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver)