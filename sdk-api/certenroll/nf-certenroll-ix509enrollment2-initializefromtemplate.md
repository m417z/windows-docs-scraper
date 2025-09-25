# IX509Enrollment2::InitializeFromTemplate

## Description

The **InitializeFromTemplate** method initializes the enrollment object by using a template.

## Parameters

### `context` [in]

An [X509CertificateEnrollmentContext](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509certificateenrollmentcontext) enumeration value that indicates whether the requested enrollment is for a user, a computer, or an administrator acting on behalf of a computer. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ContextUser** | The certificate is being requested for an end user. |
| **ContextMachine** | The certificate is being requested for a computer. |
| **ContextAdministratorForceMachine** | The certificate is being requested by an administrator acting on the behalf of a computer. |

### `pPolicyServer` [in]

Pointer to an [IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver) object that represents the certificate enrollment policy (CEP) server that contains the template specified by the *pTemplate* parameter.

### `pTemplate` [in]

Pointer to an [IX509CertificateTemplate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificatetemplate) object that represents the template to use during initialization.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **E_POINTER** | The *pPolicyServer* and *pTemplate* parameters cannot be **NULL**. |
| ****HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)**** | The enrollment object has already been initialized. |

## Remarks

The **InitializeFromTemplate** method:

* Examines the template to determine the type of request needed.
* Creates the appropriate type of request object (PKCS #10, PKCS #7, or CMC).
* Sets the following properties on the request if values currently exist:
  + [CspInformations](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_cspinformations)
  + [ParentWindow](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_parentwindow)
  + [Silent](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_silent)
* Initializes the request object by using the template.
* Retrieves the signature count, issuance policies, and application policies from the template.

## See also

[IX509Enrollment2](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment2)