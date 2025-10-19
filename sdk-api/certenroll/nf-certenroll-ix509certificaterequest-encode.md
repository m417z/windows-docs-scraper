# IX509CertificateRequest::Encode

## Description

The **Encode** method signs and encodes a certificate request and creates a key pair if one does not exist. The request is encoded by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) as defined by the [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) standard. The encoding process creates a byte array. You can retrieve the byte array by calling the [RawData](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_rawdata) property.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **CERTSRV_E_ARCHIVED_KEY_REQUIRED** | The [ArchivePrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-get_archiveprivatekey) property has been set for a CMC request but a key exchange certificate could not be found. |
| **OLE_E_BLANK** | The object is not initialized. |

## Remarks

For a PKCS #10 request, this method:

* Updates the private key or creates the key if necessary.
* Populates the public key from the private key.
* Updates the extensions, adding any default extensions and taking account of the suppressed OID collection and critical extension OID collection.
* Updates the attributes, adding default attributes and taking account of the suppressed OID collection.
* Assembles and encodes the unsigned updated request.
* Creates and encodes a signature.
* Encodes the signature and the unsigned request.

For a CMC request, this method:

* Encodes all inner request objects.
* Updates the extensions for the outer request object, adding any default extensions and taking account of the suppressed OID collection and critical extension OID collection.
* Updates the attributes for the outer request object, adding default attributes and taking account of the suppressed OID collection.
* Updates the name-value pair collection.
* Encodes the CMC content that consists of the encoded inner request and the updated outer request.
* Creates and encodes a signature for each signing certificate.
* Creates and encodes a primary signature.
* Assembles the encoded CMC content (including the inner request and the updated outer request) and the encoded signatures.
* Encodes the assembled content into a PKCS #7 message.

## See also

[IX509CertificateRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequest)

[IX509CertificateRequestCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcertificate)

[IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc)

[IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)

[IX509CertificateRequestPkcs7](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7)

[IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation)