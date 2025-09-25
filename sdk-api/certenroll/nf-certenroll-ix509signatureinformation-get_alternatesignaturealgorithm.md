# IX509SignatureInformation::get_AlternateSignatureAlgorithm

## Description

The **AlternateSignatureAlgorithm** property specifies and retrieves a Boolean value that specifies whether the [GetSignatureAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-getsignaturealgorithm) method should retrieve a discrete or combined algorithm [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) for a PKCS #10 certificate request.

This property is read/write.

## Parameters

## Remarks

PKCS #7 and CMC certificate requests always use a discrete signature algorithm OID and a separate hashing algorithm OID. Only PKCS #10 certificate requests use combined algorithm OIDs. You can set the **AlternateSignatureAlgorithm** property to retrieve a discrete signature algorithm OID from the [GetSignatureAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-getsignaturealgorithm) method for a PKCS #10 request. If you set this property, the hashing algorithm OID can be retrieved from the [Parameters](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_parameters) property, and the [AlternateSignatureAlgorithmSet](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_alternatesignaturealgorithmset) property is also set. For examples of discrete and combined OIDs, see [IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation)

## See also

[IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation)