# IX509SignatureInformation::get_Parameters

## Description

The **Parameters** property retrieves a byte array that contains the parameters associated with the signature algorithm. The byte array is represented by a Unicode-encoded string.

This property is read/write.

## Parameters

## Remarks

The AlgorithmIdentifier ASN.1 object that is used in various fields of an [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) version 3 certificate contains an algorithm [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and optional parameters.

``` syntax

AlgorithmIdentifier  ::=  SEQUENCE
{
   algorithm               OBJECT IDENTIFIER,
   parameters              ANY DEFINED BY algorithm OPTIONAL
}

```

 The format and content of the parameters differs by algorithm. The Certificate Enrollment Control generates parameter information as required. Parameter values generated for various algorithms are discussed in the following sections.

**PKCS #1 version 1.5 signature algorithms:**

The following OIDs must have a **NULL** parameter value.

* XCN_OID_RSA_MD2RSA (1.2.840.113549.1.1.2)
* XCN_OID_RSA_MD5RSA (1.2.840.113549.1.1.4)
* XCN_OID_RSA_SHA1RSA (1.2.840.113549.1.1.5)
* XCN_OID_RSA_SHA256RSA (1.2.840.113549.1.1.11)
* XCN_OID_RSA_SHA384RSA (1.2.840.113549.1.1.12)
* XCN_OID_RSA_SHA512RSA (1.2.840.113549.1.1.13)

The ASN.1 **NULL** value is represented by two bytes. The tag number is 0x05 and the value associated with the tag, representing the parameter length, is 0x00. This is shown by the following certificate example.

``` syntax

...
Public Key Algorithm:
    Algorithm ObjectId: 1.2.840.113549.1.1.1 RSA (RSA_SIGN)
    Algorithm Parameters:
    05 00
...

```

**RSASSA-PSS signatures:**

The RSASSA-PSS (RSA Signature Scheme with Appendix - Probabilistic Signature Scheme), XCN_OID_RSA_SSA_PSS (1.2.840.113549.1.1.10), generates the following parameter information. A signature scheme with appendix consists of signature generation and signature verification operations. Verification of the signature requires the original certificate request on which the signature was generated. For more information, see the PKCS #1 v2.1 cryptography standard from RSA laboratories.

``` syntax

RSASSA-PSS-params ::= SEQUENCE
{
   hashAlgorithm     [0] HashAlgorithm DEFAULT sha1,
   maskGenAlgorithm  [1] MaskGenAlgorithm DEFAULT mgf1SHA1,
   saltLength        [2] INTEGER DEFAULT 20,
   trailerField      [3] TrailerField DEFAULT trailerFieldBC
}

```

**ECDSA-SHA1 signature algorithms:** When the XCN_OID_ECDSA_SHA1 (1.2.840.10045.4.1) is used to create a signature, the parameters contains the OID of the hash algorithm. The following OIDs are supported:

* XCN_OID_ECDSA_SHA256 (1.2.840.10045.4.3.2)
* XCN_OID_ECDSA_SHA384 (1.2.840.10045.4.3.3)
* XCN_OID_ECDSA_SHA512 (1.2.840.10045.4.3.4)

## See also

[IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation)