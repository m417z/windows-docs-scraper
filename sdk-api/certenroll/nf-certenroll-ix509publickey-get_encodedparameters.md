# IX509PublicKey::get_EncodedParameters

## Description

The **EncodedParameters** property retrieves a byte array that contains the parameters associated with the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) algorithm. The byte array is represented by a Unicode-encoded string.

This property is read-only.

## Parameters

## Remarks

Call the [InitializeFromEncodedPublicKeyInfo](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509publickey-initializefromencodedpublickeyinfo) method or the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509publickey-initialize) method to initialize the public key object before calling this property.

The AlgorithmIdentifier [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) object that is referenced by the SubjectPublicKeyInfo object in an [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) version 3 certificate contains an algorithm [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and optional parameters.

``` syntax

SubjectPublicKeyInfo  ::=  SEQUENCE
{
   algorithm            AlgorithmIdentifier,
   subjectPublicKey     BIT STRING
}

AlgorithmIdentifier  ::=  SEQUENCE
{
   algorithm            OBJECT IDENTIFIER,
   parameters           ANY DEFINED BY algorithm OPTIONAL
}

```

 The format and content of the parameters differs by algorithm. The [Certificate Enrollment Control](https://learn.microsoft.com/windows/desktop/SecCrypto/certificate-enrollment-control) generates parameter values for various algorithms as required. For more information, see the following sections:

* **RSA Public Key Algorithm**
* **Key Transport Using RSA-OAEP**
* **Key Agreement Using ECDH**
* **Content Encryption Using AES**

### RSA Public Key Algorithm

RSA is often used to encrypt a [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) and send it to a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) for archival. The XCN_OID_RSA_RSA (1.2.840.113549.1.1.1) algorithm OID must have a **NULL** parameter value. The ASN.1 **NULL** value is represented by two bytes. The tag number is 0x05 and the value associated with the tag is 0x00. This is shown by the following certificate example.

``` syntax

...
Public Key Algorithm:
    Algorithm ObjectId: 1.2.840.113549.1.1.1 RSA (RSA_KEYX)
    Algorithm Parameters:
    05 00
...

```

### Key Transport Using RSA-OAEP

The RSA-OAEP algorithm, XCN_OID_RSAES_OAEP (1.2.840.113549.1.1.7), is also supported for key transport. The parameters field has the following syntax.

``` syntax

RSAES-OAEP-params  ::=  SEQUENCE
{
   hashFunc    [0] AlgorithmIdentifier DEFAULT sha1OID,
   maskGenFunc [1] AlgorithmIdentifier DEFAULT mgf1SHA1OID,
   pSourceFunc [2] AlgorithmIdentifier DEFAULT pSpecifiedEmptyOID
}

```

### Key Agreement Using ECDH

The single pass Elliptic Curve Diffie-Hellman algorithm, XCN_OID_DH_SINGLE_PASS_STDDH_SHA1_KDF (1.3.133.16.840.63.0.2), is supported for key agreement. Key agreement uses two levels of encryption:

* The message is encrypted by using a content encryption key (CEK) and a [symmetric encryption](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) algorithm.
* The CEK is encrypted (wrapped) by using a [symmetric key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) encryption key (KEK).

The KEK is computed from a shared secret number that is computed from the private key of one party and the public key of the other party. The parameters field contains the OID of the KEK algorithm used to wrap or encrypt the CEK. The following wrap algorithms are supported:

* XCN_OID_RSA_SMIMEalgCMS3DESwrap (1.2.840.113549.1.9.16.3.)
* XCN_OID_RSA_SMIMEalgCMSRC2wrap (1.2.840.113549.1.9.16.3.7)
* XCN_OID_NIST_AES128_WRAP (2.16.840.1.101.3.4.1.5)
* XCN_OID_NIST_AES192_WRAP (2.16.840.1.101.3.4.1.25)
* XCN_OID_NIST_AES256_WRAP (2.16.840.1.101.3.4.1.45)

### Content Encryption Using AES

The Advanced Encryption Standard (AES) is used to encrypt content. The following algorithms are supported:

* XCN_OID_NIST_AES128_CBC (2.16.840.1.101.3.4.1.2)
* XCN_OID_NIST_AES192_CBC (2.16.840.1.101.3.4.1.22)
* XCN_OID_NIST_AES256_CBC (2.16.840.1.101.3.4.1.42)

The parameters field contains a random initialization vector, AES-IV.

``` syntax

AES-IV ::= OCTET STRING (SIZE(16))

```

## See also

[IX509PublicKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509publickey)