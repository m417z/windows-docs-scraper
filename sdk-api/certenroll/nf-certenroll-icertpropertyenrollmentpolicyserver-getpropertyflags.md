# ICertPropertyEnrollmentPolicyServer::GetPropertyFlags

## Description

The **GetPropertyFlags** method retrieves a value that specifies the default policy server URL. This value is set by the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollmentpolicyserver-initialize) method.

## Parameters

### `pValue` [out, retval]

Pointer to an [EnrollmentPolicyServerPropertyFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-enrollmentpolicyserverpropertyflags) enumeration value that contains the flag. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DefaultNone** | No default policy server URL has been specified. |
| **DefaultPolicyServer** | The policy server URL returned by [GetPolicyServerUrl](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollmentpolicyserver-getpolicyserverurl) is the default value when an URL has not been specified. |

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **E_POINTER** | The *pValue* parameter cannot be **NULL**. |

## See also

[ICertPropertyEnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyenrollmentpolicyserver)