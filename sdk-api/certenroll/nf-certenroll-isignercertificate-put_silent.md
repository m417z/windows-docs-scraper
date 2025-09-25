# ISignerCertificate::put_Silent

## Description

The **Silent** property specifies or retrieves a Boolean value that indicates whether the user is notified when the private key is used to sign a certificate request.

This property is read/write.

## Parameters

## Remarks

Call this property to specify a value before calling the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-initialize) method. Setting this property also sets the [Silent](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_silent) property on the [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) object. You can retrieve the private key object by calling [PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_privatekey). You can call the following properties to retrieve additional information about the signing certificate object:

* [Certificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_certificate)
* [ParentWindow](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_parentwindow)
* [Pin](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-put_pin)
* [SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_signatureinformation)
* [UIContextMessage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_uicontextmessage)

## See also

[ISignerCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-isignercertificate)