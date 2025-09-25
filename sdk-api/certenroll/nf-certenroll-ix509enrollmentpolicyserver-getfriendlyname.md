# IX509EnrollmentPolicyServer::GetFriendlyName

## Description

The **GetFriendlyName** method retrieves a display name for the certificate enrollment policy (CEP) server.

## Parameters

### `pValue` [out, retval]

Pointer to a **BSTR** variable that contains the display name.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **CERTSRV_E_PROPERTY_EMPTY** | The display name could not be found. |
| **E_OUTOFMEMORY** | There was not sufficient memory available for the string specified in the *pValue* parameter. |
| **E_POINTER** | The *pValue* parameter cannot be **NULL**. |

## See also

[IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver)