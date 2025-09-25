# IX509CertificateRequest::get_CspInformations

## Description

The **CspInformations** property specifies and retrieves a collection of cryptographic providers available for use by the request object.

This property is read/write.

## Parameters

## Remarks

If you want to specify a collection of providers, you must set this property before calling the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-initialize) method. The collection that you specify must contain all providers currently installed on the computer. If you specify a subset or a superset, the behavior of this property is undefined.

If you do not specify a collection, the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-initialize) method sets the property value to a collection of all providers installed on the computer.

The **CspInformations** property exists so that the caller can avoid forcing the request object to fill the collection. This is useful when the caller is creating multiple requests in one session.

## See also

[IX509CertificateRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequest)

[IX509CertificateRequestCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcertificate)

[IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc)

[IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)

[IX509CertificateRequestPkcs7](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7)

[IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation)