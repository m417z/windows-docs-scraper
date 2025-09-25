# IX509CertificateRequest::put_HashAlgorithm

## Description

The **HashAlgorithm** property specifies and retrieves the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) of the hash algorithm used to sign the certificate request. This property is web enabled for both input and output.

This property is read/write.

## Parameters

## Remarks

If the certificate request contains nested requests and you set the **HashAlgorithm** property on the top level request, it is automatically propagated to all of the inner requests, overwriting values that may have been previously set. You can, however, set the property manually on each of the inner objects.

You must initialize the request object before calling this property. You can call this property before calling the [Encode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-encode) method.

## See also

[IX509CertificateRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequest)

[IX509CertificateRequestCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcertificate)

[IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc)

[IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)

[IX509CertificateRequestPkcs7](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7)

[IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation)