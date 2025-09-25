# ISignerCertificate::get_SignatureInformation

## Description

The **SignatureInformation** property retrieves an [IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation) object that contains information about the certificate signature.

This property is read-only.

## Parameters

## Remarks

When you call the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-initialize) method the Certificate Enrollment Control creates an [IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation) object. You can also call the following properties to retrieve information about the signing certificate object:

* [Certificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_certificate)
* [ParentWindow](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_parentwindow)
* [Pin](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-put_pin)
* [PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_privatekey)
* [Silent](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_silent)
* [UIContextMessage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_uicontextmessage)

## See also

[ISignerCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-isignercertificate)