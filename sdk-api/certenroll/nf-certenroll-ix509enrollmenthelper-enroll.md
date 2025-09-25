# IX509EnrollmentHelper::Enroll

## Description

The **Enroll** method enrolls a certificate request and retrieves the issued certificate. This method is web enabled.

## Parameters

### `strEnrollmentPolicyServerURI` [in]

A **BSTR** that contains the certificate enrollment policy server URL.

### `strTemplateName` [in]

A **BSTR** variable that contains the Common Name (CN) of the template as it appears in Active Directory or the dotted decimal [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly).

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of encoding applied to a byte array for display purposes.

### `enrollFlags` [in]

A [WebEnrollmentFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-webenrollmentflags) enumeration value that specifies web enrollment behavior. This can be the following value.

| Value | Meaning |
| --- | --- |
| **EnrollPrompt** | If this flag is set and no authentication credential is available for the certificate enrollment server, the certificate service prompts for a credential. If there is no authentication credential and this flag is not set, the **Enroll** method fails. |

### `pstrCertificate` [out, retval]

A **BSTR** that contains the issued certificate.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *strEnrollmentPolicyServerURI* and *strTemplateName* parameters cannot be **NULL**. |
| **HRESULT_FROM_WIN32(ERROR_ARITHMETIC_OVERFLOW)** | The *strEnrollmentPolicyServerURI* and *strTemplateName* parameters exceed 64,000 characters or contain embedded null characters. |

## Remarks

The **Enroll** method retrieves the appropriate template, calls [InitializeFromTemplate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment2-initializefromtemplate), and then calls [Enroll](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-enroll) on the [IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment) object.

This method does not installed the issued certificate.

## See also

[IX509EnrollmentHelper](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmenthelper)