# IX509MachineEnrollmentFactory::CreateObject

## Description

The **CreateObject** method creates an [IX509EnrollmentHelper](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmenthelper) object on a webpage. This method is web enabled.

## Parameters

### `strProgID` [in]

A **BSTR** variable that contains the ProgID value. This must be "X509Enrollment.CX509EnrollmentHelper".

### `ppIHelper` [out, retval]

Address of a pointer to a variable that receives a pointer to an [IX509EnrollmentHelper](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmenthelper) interface.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *strProgID* parameter cannot be **NULL** or empty. |
| **E_NOINTERFACE** | The *strProgID* parameter must contain "X509Enrollment.CX509EnrollmentHelper". |
| **E_POINTER** | The *ppIHelper* parameter cannot be **NULL**. |
| **HRESULT_FROM_WIN32(ERROR_ARITHMETIC_OVERFLOW)** | The *strProgID* parameter exceed 64,000 characters or contains embedded null characters. |

## Remarks

This method calls [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmenthelper-initialize) on the [IX509EnrollmentHelper](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmenthelper) interface by using the **ContextAdministratorForceMachine** context value, thereby specifying that all certificates to be enrolled by the [IX509Enrollment2](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment2) object will be requested by an administrator acting on behalf of a computer. To enroll a user certificate, call [CreateObject](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentwebclassfactory-createobject) on the [IX509EnrollmentWebClassFactory](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentwebclassfactory) interface.

## See also

[IX509MachineEnrollmentFactory](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509machineenrollmentfactory)