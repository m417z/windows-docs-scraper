# ISignerCertificate::put_Pin

## Description

The **Pin** property specifies a personal identification number (PIN) used to authenticate a smart card user. A user must be authenticated before accessing the private key container on the smart card.

This property is write-only.

## Parameters

## Remarks

Call this property to specify a value before calling the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-initialize) method. The **Pin** property internally sets the pin number on the [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) object. You can retrieve the private key object by calling [PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_privatekey). You can call the following properties to retrieve additional information about the signing certificate object:

* [Certificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_certificate)
* [ParentWindow](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_parentwindow)
* [SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_signatureinformation)
* [Silent](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_silent)
* [UIContextMessage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_uicontextmessage)

## See also

[ISignerCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-isignercertificate)