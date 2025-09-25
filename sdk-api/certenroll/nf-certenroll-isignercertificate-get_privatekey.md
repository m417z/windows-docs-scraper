# ISignerCertificate::get_PrivateKey

## Description

The **PrivateKey** property retrieves the private key associated with the [ISignerCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-isignercertificate) object.

This property is read-only.

## Parameters

## Remarks

When you call the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-initialize) method the Certificate Enrollment Control retrieves the signing certificate from the personal store and uses it to find an associated private key. You can also call the following properties to retrieve information about the signing certificate object:

* [Certificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_certificate)
* [ParentWindow](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_parentwindow)
* [Pin](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-put_pin)
* [SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_signatureinformation)
* [Silent](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_silent)
* [UIContextMessage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_uicontextmessage)

## See also

[ISignerCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-isignercertificate)