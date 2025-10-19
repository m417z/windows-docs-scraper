# IX509SignatureInformation::GetSignatureAlgorithm

## Description

The **GetSignatureAlgorithm** method retrieves the signing algorithm [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID).

## Parameters

### `Pkcs7Signature` [in]

A **VARIANT_BOOL** variable that specifies whether the algorithm will be used to sign a PKCS #7 or CMC certificate request.

### `SignatureKey` [in]

A **VARIANT_BOOL** variable that specifies whether an algorithm that is only used for signing is preferred when an algorithm OID is associated with more than one purpose. For example, XCN_OID_RSA_RSA (1.2.840.113549.1.1.1) can be used for both signing and key exchange.

### `ppValue` [out]

Address of a variable that receives a pointer to an [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) interface that represents the algorithm OID.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **CERTSRV_E_PROPERTY_EMPTY** | The hashing algorithm OID, or the [NullSigned](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_nullsigned) property has not been specified but the signing algorithm OID cannot be found. |
| **CRYPT_E_UNKNOWN_ALGO** | The combined signature algorithm could not be found. |

## Remarks

This method searches for a cached signing algorithm that is consistent with the input parameters. If none is found, the method uses the input parameters plus the values assigned to various [IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation) properties as indicated by the following list.

* *Pkcs7Signature* = true, [NullSigned](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_nullsigned) = true

  This case represents a null-signed PKCS #7 certificate request. The method returns the XCN_OID_PKIX_NO_SIGNATURE (1.3.6.1.5.5.7.6.2) OID.
* *Pkcs7Signature* = true, [NullSigned](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_nullsigned) = false

  This case retrieves a discrete signature algorithm OID for a PKCS #7 request that is not null-signed. The discrete signature requires that the [HashAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_hashalgorithm) and [PublicKeyAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_publickeyalgorithm) properties be set. In the special case where the public key algorithm is XCN_OID_X957_DSA and the hashing algorithm is not XCN_OID_OIWSEC_sha1, the signature algorithm OID retrieved is XCN_OID_X957_SHA1DSA (1.2.840.10040.4.3).
* *Pkcs7Signature* = false, [NullSigned](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_nullsigned) = false, [AlternateSignatureAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_alternatesignaturealgorithm) = true

  This case retrieves a discrete signature algorithm OID for a PKCS #10 request and encodes the hash algorithm OID in the [Parameters](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_parameters) property. The [HashAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_hashalgorithm) and [PublicKeyAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_publickeyalgorithm) properties must be set.
* *Pkcs7Signature* = false, [NullSigned](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_nullsigned) = false, [AlternateSignatureAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_alternatesignaturealgorithm) = false

  This case retrieves a discrete signature algorithm OID for a PKCS #7 request. The [HashAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_hashalgorithm) and [PublicKeyAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509signatureinformation-get_publickeyalgorithm) properties must be set.

## See also

[IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation)