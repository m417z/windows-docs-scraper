# IX509CertificateRequest::put_AlternateSignatureAlgorithm

## Description

The **AlternateSignatureAlgorithm** property specifies and retrieves a Boolean value that indicates whether the signature algorithm [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) for a PKCS #10 request or certificate signature is discrete or combined. A PKCS #10 object can be a stand-alone request or it can be contained in a CMC or PKCS #7 request object.

This property is read/write.

## Parameters

## Remarks

Discrete algorithms are represented by separate [object identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OIDs) for the hashing algorithm and the signing algorithm. Examples include the following values.

| Discrete algorithm OID | Description |
| --- | --- |
| XCN_OID_NIST_sha256<br><br>(2.16.840.1.101.3.4.2.1) | National Institute of Standards and Technologies (NIST) 256-bit SHA hashing algorithm. |
| XCN_OID_OIWSEC_rsaSign<br><br>(1.3.14.3.2.11) | NIST OSE Implementer Workshop Security (OIWSEC) RSA signing algorithm. |

Combined algorithms are represented by a single OID that identifies both the hashing and the signing algorithm. Examples include the following values.

| Combined algorithm OID | Description |
| --- | --- |
| XCN_OID_RSA_MD2RSA<br><br>(1.2.840.113549.1.1.2) | MD2 hashing algorithm combined with the RSA encryption algorithm from RSA Laboratories. |
| XCN_OID_OIWSEC_md5RSA<br><br>(1.3.14.3.2.3) | OIWSEC MD5 hashing algorithm combined with the RSA encryption algorithm. |

If the certificate request contains nested requests and you set the **AlternateSignatureAlgorithm** property on the top level request, it is automatically propagated to all of the inner requests. You can, however, set the property manually on each of the inner objects.

For a PKCS #7 or a CMC request, this property retrieves a Boolean value for the primary signature on the inner PKCS #10 request. On input, all signer certificates are updated with the specified property value.

For a PKCS #10 request or certificate signature using the RSA public key algorithm, a property value of False (which indicates a combined OID) implies a version 1.5 signature and True (discrete OID) implies a version 2.1 signature.

You must initialize the request object before calling this property. You can call this property before calling the [Encode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-encode) method.

## See also

[IX509CertificateRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequest)

[IX509CertificateRequestCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcertificate)

[IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc)

[IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)

[IX509CertificateRequestPkcs7](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7)

[IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation)