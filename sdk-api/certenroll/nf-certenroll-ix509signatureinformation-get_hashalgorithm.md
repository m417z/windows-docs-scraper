# IX509SignatureInformation::get_HashAlgorithm

## Description

The **HashAlgorithm** property specifies and retrieves an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) for the hashing algorithm used in the [GetSignatureAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-getsignaturealgorithm) method.

This property is read/write.

## Parameters

## Remarks

You must set this property before calling the [GetSignatureAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-getsignaturealgorithm) method. You must also set the [PublicKeyAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_publickeyalgorithm) property unless you are retrieving a signature algorithm for a null-signed certificate request. You can also set the [NullSigned](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_nullsigned), [AlternateSignatureAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_alternatesignaturealgorithm), and [Parameters](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_parameters) properties.

The **HashAlgorithm** property validates whether the OID you specify represents a hashing algorithm. If the OID is valid, the property also clears the signature property cache.

## See also

[IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation)