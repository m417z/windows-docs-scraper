# CRYPT_SIGN_MESSAGE_PARA structure

## Description

The **CRYPT_SIGN_MESSAGE_PARA** structure contains information for signing messages using a specified signing [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

## Members

### `cbSize`

Size of this structure in bytes.

### `dwMsgEncodingType`

Type of encoding used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pSigningCert`

A pointer to the
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) to be used in the signing.

Either the CERT_KEY_PROV_INFO_PROP_ID, or CERT_KEY_CONTEXT_PROP_ID property must be set for the context to provide access to the [private signature key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

### `HashAlgorithm`

CRYPT_ALGORITHM_IDENTIFIER containing the hashing algorithm used to hash the data to be signed.

### `pvHashAuxInfo`

Not currently used, and must be set to **NULL**.

### `cMsgCert`

Number of elements in the **rgpMsgCert** array of
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structures. If set to zero no certificates are included in the signed message.

### `rgpMsgCert`

Array of pointers to [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structures to be included in the signed message. If the **pSigningCert** is to be included, a pointer to it must be in the **rgpMsgCert** array.

### `cMsgCrl`

Number of elements in the **rgpMsgCrl** array of pointers to
[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) structures. If set to zero, no **CRL_CONTEXT** structures are included in the signed message.

### `rgpMsgCrl`

Array of pointers to [CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) structures to be included in the signed message.

### `cAuthAttr`

Number of elements in the **rgAuthAttr** array. If no authenticated attributes are present in **rgAuthAttr**, this member is set to zero.

### `rgAuthAttr`

Array of pointers to
[CRYPT_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute) structures, each holding authenticated attribute information. If there are authenticated attributes present, the PKCS #9 standard dictates that there must be at least two attributes present, the content type [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID), and the hash of the message itself. These attributes are automatically added by the system.

### `cUnauthAttr`

Number of elements in the **rgUnauthAttr** array. If no unauthenticated attributes are present in **rgUnauthAttr**, this member is zero.

### `rgUnauthAttr`

Array of pointers to
[CRYPT_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute) structures each holding an unauthenticated attribute information. Unauthenticated attributes can be used to contain [countersignatures](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), among other uses.

### `dwFlags`

Normally zero. If the encoded output is to be a CMSG_SIGNED [inner content](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) of an outer cryptographic message such as a CMSG_ENVELOPED message, the CRYPT_MESSAGE_BARE_CONTENT_OUT_FLAG must be set. If it is not set, the message will be encoded as an *inner content* type of CMSG_DATA.

CRYPT_MESSAGE_ENCAPSULATED_CONTENT_OUT_FLAG can be set to encapsulate non-data [inner content](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) into an OCTET STRING. CRYPT_MESSAGE_KEYID_SIGNER_FLAG can be set to identify signers by their Key Identifier and not their Issuer and Serial Number.

CRYPT_MESSAGE_SILENT_KEYSET_FLAG can be set to suppress any UI by the CSP. For more information about the CRYPT_SILENT flag, see
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta).

### `dwInnerContentType`

Normally zero. Set to the encoding type of the input message if that input to be signed is the encoded output of another cryptographic message.

### `HashEncryptionAlgorithm`

A
[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier). If present and not **NULL**, it is used instead of the signer's certificate **PublicKeyInfo.Algorithm** member. Note that for RSA, the hash encryption algorithm is normally the same as the public key algorithm. For DSA, the hash encryption algorithm is normally a DSS signature algorithm. This member can only be used if CRYPT_SIGN_MESSAGE_PARA_HAS_CMS_FIELDS is defined.

### `pvHashEncryptionAuxInfo`

Currently not used and must be set to **NULL**. This member can only be used if CRYPT_SIGN_MESSAGE_PARA_HAS_CMS_FIELDS is defined.

## Remarks

The **HashEncryptionAlgorithm** and **pvHashEncryptionAuxInfo** members can only be used if CRYPT_SIGN_MESSAGE_PARA_HAS_CMS_FIELDS is defined.

## See also

[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context)

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier)

[CRYPT_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute)

[CryptSignAndEncryptMessage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignandencryptmessage)

[CryptSignMessage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignmessage)