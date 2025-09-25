# IX509CertificateRequestPkcs10::get_NullSigned

## Description

The **NullSigned** property retrieves a Boolean value that indicates whether the certificate request is null-signed.

This property is read-only.

## Parameters

## Remarks

A null-signed PKCS #10 certificate request is not really signed. That is, the signature is a hash created by using a digest algorithm such as SHA-1, but the request is not encrypted with a public key algorithm such as RSA. This can be used when a private key is not available as is often the case when [certification authorities](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) are being cross-certified. For more information, see the [InitializeFromPublicKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefrompublickey) method.

 You must initialize the [IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10) object before calling this property. For more information, see any of the following methods:

* [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializedecode)
* [InitializeFromCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefromcertificate)
* [InitializeFromPrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefromprivatekey)
* [InitializeFromPublicKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefrompublickey)
* [InitializeFromTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefromtemplatename)

## See also

[IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)