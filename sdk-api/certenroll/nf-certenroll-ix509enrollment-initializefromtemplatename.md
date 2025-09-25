# IX509Enrollment::InitializeFromTemplateName

## Description

The **InitializeFromTemplateName** method initializes the enrollment object from a template common name (CN).

## Parameters

### `Context` [in]

An [X509CertificateEnrollmentContext](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509certificateenrollmentcontext) enumeration value that indicates whether the requested enrollment is for a user, a computer, or an administrator acting on behalf of a computer.

### `strTemplateName` [in]

A **BSTR** variable that contains the Common Name (CN) of the template as it appears in Active Directory or the dotted decimal [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly).

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)**** | The enrollment object has already been initialized. |

## Remarks

The **InitializeFromTemplateName** method:

* Examines the template to determine the type of request needed.
* Creates the appropriate type of request object (PKCS #10, PKCS #7, or CMC).
* Sets the following properties on the request if values currently exist:
  + [CspInformations](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_cspinformations)
  + [ParentWindow](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_parentwindow)
  + [Silent](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_silent)
* Initializes the request object by using the template.
* Retrieves the signature count, issuance policies, and application policies from the template.

## See also

[IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment)