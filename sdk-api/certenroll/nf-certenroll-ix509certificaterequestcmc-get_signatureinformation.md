# IX509CertificateRequestCmc::get_SignatureInformation

## Description

The **SignatureInformation** property retrieves the [IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation) object that contains information about the primary signature used to sign the certificate request. This property is web enabled.

This property is read-only.

## Parameters

## Remarks

The [IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation) object contains information about the hash, public key and signature algorithms used for the primary signature that signs the certificate request. A CMC request can have a primary signature plus zero or more certificate-based signatures. Certificate-based signatures can be included in a request if, for example, one or more additional parties must vouch for the identity of the entity requesting the new certificate. You can call the [SignerCertificates](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-get_signercertificates) property to retrieve a collection of these additional certificate-based signatures.

The primary signature is typically created by using the private key that matches the public key in the inner PKCS #10 request object. Because the private key is usually created to enroll a new request in a certificate hierarchy, the primary signature is not certificate-based, and you must call the **SignatureInformation** property to retrieve it.

 If the [IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation) object does not exist when the **SignatureInformation** property is called or creation of the signature was deferred during initialization, this property:

* Retrieves the innermost PKCS #10 request object.
* Retrieves and duplicates the signature information from the inner request.
* Attempts to retrieve the private key associated with the inner PKCS #10 and sets the [NullSigned](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-get_nullsigned) property if no private key can be found.
* Retrieves the hash algorithm, if one is specified, from the template associated with the inner request and sets the [HashAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_hashalgorithm) property.
* Retrieves the asymmetric algorithm, if one is specified, from the private key associated with the inner request and sets the [PublicKeyAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_publickeyalgorithm) property.
* Retrieves the private key flags from the template and sets the [AlternateSignatureAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_alternatesignaturealgorithm) if appropriate

You must initialize the CMC request object before calling this property. For more information, see the following topics:

* [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-initialize)
* [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializedecode)
* [InitializeFromCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefromcertificate)
* [InitializeFromInnerRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefrominnerrequest)
* [InitializeFromInnerRequestTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-initializefrominnerrequesttemplatename)
* [InitializeFromTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefromtemplatename)

## See also

[IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc)

[IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)