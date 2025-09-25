# IX509Enrollment::Enroll

## Description

The **Enroll** method encodes a request, submits it to an appropriate certification authority (CA), and installs the response.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****OLE_E_BLANK**** | The enrollment object has not been initialized. |

## Remarks

The method may create a key pair if necessary. Depending on how you initialize the enrollment object and on what properties you set, there may be no need to create a key pair. For example, if you are renewing a certificate by using an existing key, or if the [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) object associated with the certificate request represents an existing key, this method does not create a new key pair.

Before enrolling, you must initialize the [IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment) object by calling one of the following methods.

* [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-initialize)
* [InitializeFromRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-initializefromrequest)
* [InitializeFromTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-initializefromtemplatename)

If the enrollment operation succeeds, the function returns **S_OK**. However, this does not necessarily mean that the response from the CA was installed. Call the [Status](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollment-get_status) property to determine the enrollment status.

## See also

[IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment)