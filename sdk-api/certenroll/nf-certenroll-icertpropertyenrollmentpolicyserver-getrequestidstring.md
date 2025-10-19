# ICertPropertyEnrollmentPolicyServer::GetRequestIdString

## Description

The **GetRequestIdString** method retrieves a unique string identifier for the certificate request sent to the certification authority during enrollment.

## Parameters

### `pValue` [out, retval]

Pointer to a **BSTR** that receives the ID string.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **CERTSRV_E_PROPERTY_EMPTY** | The property value is empty. |
| **E_OUTOFMEMORY** | There was insufficient memory available to create the URL string. |
| **HRESULT_FROM_WIN32(OLE_E_BLANK)** | The property value has not been initialized. |

## Remarks

The string can contain any information that uniquely identifies the certificate request. This value is set when you call the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollmentpolicyserver-initialize) method.

## See also

[ICertPropertyEnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyenrollmentpolicyserver)