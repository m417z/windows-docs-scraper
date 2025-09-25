# IX509CertificateRequestCmc::get_SignerCertificates

## Description

The **SignerCertificates** property retrieves a collection of certificates used to sign the request.

This property is read-only.

## Parameters

## Remarks

A CMC request can have a primary signature plus zero or more certificate-based signatures. Certificate-based signatures can be included in a request if, for example, one or more additional parties must vouch for the identity of the entity requesting the new certificate. Call the **SignerCertificates** property to retrieve a collection of these additional certificate-based signatures.

The primary signature is typically created by using the private key that matches the public key in the inner PKCS #10 request object. Because the private key is usually created to enroll a new request in a certificate hierarchy, the primary signature is not certificate-based, and you must call the [SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-get_signatureinformation) property to retrieve it.

You must initialize the CMC request object before calling this property. For more information, see the following topics:

* [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-initialize)
* [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializedecode)
* [InitializeFromCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefromcertificate)
* [InitializeFromInnerRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefrominnerrequest)
* [InitializeFromInnerRequestTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-initializefrominnerrequesttemplatename)
* [InitializeFromTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefromtemplatename)

## See also

[IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc)