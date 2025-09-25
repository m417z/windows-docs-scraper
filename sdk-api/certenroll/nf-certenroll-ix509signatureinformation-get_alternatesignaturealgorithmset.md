# IX509SignatureInformation::get_AlternateSignatureAlgorithmSet

## Description

The **AlternateSignatureAlgorithmSet** property retrieves a Boolean value that specifies whether the [AlternateSignatureAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_alternatesignaturealgorithm) property has been explicitly set by a caller.

This property is read-only.

## Parameters

## Remarks

The **AlternateSignatureAlgorithmSet** property is used by a CMC certificate request object. If the [AlternateSignatureAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_alternatesignaturealgorithm) property is explicitly set on a signer certificate, and the same property is set on the [IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc) object, the CMC request will not override the property value on the signer certificate.

## See also

[ISignerCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-isignercertificate)

[IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation)