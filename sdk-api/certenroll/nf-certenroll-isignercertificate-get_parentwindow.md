# ISignerCertificate::get_ParentWindow

## Description

The **ParentWindow** property specifies or retrieves the ID of the window used to display signing certificate information.

This property is read/write.

## Parameters

## Remarks

Call this property to specify a window ID before calling the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-initialize) method. The **ParentWindow** property internally sets the window ID on the [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) object. You can retrieve the private key object by calling the [PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_privatekey) property. You can call the following properties to retrieve additional information about the signing certificate object:

* [Certificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_certificate)
* [Pin](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-put_pin)
* [SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_signatureinformation)
* [Silent](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_silent)
* [UIContextMessage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_uicontextmessage)

## See also

[ISignerCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-isignercertificate)