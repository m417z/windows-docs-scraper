# IX509CertificateRequest::put_SuppressDefaults

## Description

The **SuppressDefaults** property specifies or retrieves a Boolean value that indicates whether the default extensions and attributes are included in the request. The defaults are represented by their [object identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OIDs).

This property is read/write.

## Parameters

## Remarks

You must initialize the request object before calling this property. Set this property before calling the [Encode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-encode) method to suppress inclusion and encoding of default extensions and attributes in the certificate request.

## See also

[IX509CertificateRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequest)

[IX509CertificateRequestCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcertificate)

[IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc)

[IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)

[IX509CertificateRequestPkcs7](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7)

[IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation)