# IX509SignatureInformation::put_NullSigned

## Description

The **NullSigned** property specifies and retrieves a Boolean value that indicates whether the certificate request is null-signed.

This property is read/write.

## Parameters

## Remarks

A null-signed certificate request is not really signed. That is, the request can be digested by using a digest algorithm such as SHA-1, but it is not encrypted with a public key algorithm such as RSA. You must set this property before calling the [GetSignatureAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-getsignaturealgorithm) method.

## See also

[IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation)