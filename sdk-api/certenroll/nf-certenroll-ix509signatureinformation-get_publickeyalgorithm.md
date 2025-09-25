# IX509SignatureInformation::get_PublicKeyAlgorithm

## Description

The **PublicKeyAlgorithm** property specifies and retrieves an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) for the public key algorithm used in the [GetSignatureAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-getsignaturealgorithm) method.

This property is read/write.

## Parameters

## Remarks

Unless you are retrieving a signature algorithm for a null-signed certificate request, you must set this property before calling the [GetSignatureAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-getsignaturealgorithm) method. You must also set the [HashAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_hashalgorithm) property. You can also set the [AlternateSignatureAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_alternatesignaturealgorithm) and [NullSigned](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_nullsigned) properties.

The **PublicKeyAlgorithm** property validates whether the OID you specify represents a public key algorithm. If the OID is valid, the property also clears the signature property cache.

## See also

[IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation)