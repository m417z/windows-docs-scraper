# IX509CertificateRequestCertificate::get_SignerCertificate

## Description

The **SignerCertificate** property specifies or retrieves the [ISignerCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-isignercertificate) object used to sign the certificate.

This property is read/write.

## Parameters

## Remarks

You can set this property if you are not creating a self-signed certificate. If you do not specify the property value before calling [Encode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-encode), the private key associated with the [IX509CertificateRequestCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcertificate) object is used to sign the certificate, and the name of the issuer is set, by default, to the subject name.

You must initialize the request object before calling this property. For more information, see any of the following methods:

* [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-initialize)
* [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializedecode)
* [InitializeFromCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefromcertificate)
* [InitializeFromPrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefromprivatekey)
* [InitializeFromPublicKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefrompublickey)
* [InitializeFromTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefromtemplatename)

## See also

[ISignerCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-isignercertificate)

[IX509CertificateRequestCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcertificate)