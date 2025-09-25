# IX509EnrollmentPolicyServer::QueryChanges

## Description

The **QueryChanges** method retrieves a value that specifies whether the template or certification authority collections have changed in Active Directory.

## Parameters

### `pValue` [out, retval]

Pointer to a Boolean value that specifies whether the collections have changed.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_NOT_VALID_STATE** | LoadOptionRegisterForADChanges was not specified in the *option* parameter of the [LoadPolicy](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentpolicyserver-loadpolicy) method. |
| **E_POINTER** | The *pValue* parameter cannot be **NULL**. |
| **OLE_E_BLANK** | The [IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver) object has not been initialized. |

## Remarks

The **QueryChanges** method is relevant only when you specify **LoadOptionRegisterForADChanges** in the *option* parameter of the [LoadPolicy](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentpolicyserver-loadpolicy) method. The method returns **VARIANT_TRUE** for either of the following cases:

* The template collection in Active Directory has changed since the last time [GetTemplates](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentpolicyserver-gettemplates) was called.
* The certification authority collection in Active Directory has changed since the last time [GetCAs](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentpolicyserver-getcas) was called.

## See also

[IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver)