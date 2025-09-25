# IX509CertificateRequestCmc::get_NullSigned

## Description

The **NullSigned** property retrieves a Boolean value that specifies whether the primary signature on the certificate request is null-signed.

This property is read-only.

## Parameters

## Remarks

A null-signed certificate request is not really signed. That is, the request can be digested by using a digest algorithm such as SHA-1, but it is not encrypted with a public key algorithm such as RSA. This can be used when a private key is not available as is often the case when [certification authorities](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) are being cross-certified.

You must initialize the CMC request object before calling this property. For more information, see the following topics:

* [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-initialize)
* [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializedecode)
* [InitializeFromCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefromcertificate)
* [InitializeFromInnerRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefrominnerrequest)
* [InitializeFromInnerRequestTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-initializefrominnerrequesttemplatename)
* [InitializeFromTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefromtemplatename)

## See also

[IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc)