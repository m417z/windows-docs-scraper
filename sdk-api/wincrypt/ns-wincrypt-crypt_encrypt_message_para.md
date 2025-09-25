# CRYPT_ENCRYPT_MESSAGE_PARA structure

## Description

The **CRYPT_ENCRYPT_MESSAGE_PARA** structure contains information used to encrypt messages.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `dwMsgEncodingType`

The type of encoding used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `hCryptProv`

This member is not used and should be set to **NULL**.

**Windows Server 2003 and Windows XP:** The handle to the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) to be used for encryption. The CSP identified by **hCryptProv** is used to do content encryption, recipient key encryption, and recipient key export. Its private key is not used.

Unless there is a strong reason for passing in a specific [cryptographic provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) in **hCryptProv**, pass zero to use the default RSA or DSS provider.

This member's data type is **HCRYPTPROV**.

### `ContentEncryptionAlgorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that contains the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) of the encryption algorithm to use. The CSP specified by the **hCryptProv** must support this encryption algorithm.

The **szOID_OIWSEC_desCBC** (CALG_DES) and **szOID_RSA_DES_EDE3_CBC** (CALG_3DES) encryption algorithms require the **Parameters** member of this structure to contain an encoded eight-byte [initialization vector](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) (IV). If the **cbData** member of the **Parameters** member is zero, an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1)-encoded OCTET STRING that contains the IV is generated using
[CryptGenRandom](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenrandom). For more information about the KP_IV parameter, see
[CryptSetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetkeyparam).

The **szOID_NIST_AES128_CBC** (BCRYPT_AES_ALGORITHM, 128 bit), **szOID_NIST_AES192_CBC** (BCRYPT_AES_ALGORITHM, 192 bit), and **szOID_NIST_AES256_CBC** (BCRYPT_AES_ALGORITHM, 256 bit) encryption algorithms require the **Parameters** member of this structure to contain an encoded sixteen-byte initialization vector (IV). If the **cbData** member of the Parameters member is zero, an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1)-encoded OCTET STRING that contains the IV is generated.

The **szOID_RSA_RC2CBC** (CALG_RC2) algorithm requires the **pbData** member of the **Parameters** member of this structure to be a
[CRYPT_RC2_CBC_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_rc2_cbc_parameters) structure. If the **cbData** member of the **Parameters** member is zero, an ASN.1-encoded **CRYPT_RC2_CBC_PARAMETERS** structure that contains the IV is generated as the **pbData** member. This generated **pbData** uses the default **dwVersion** that corresponds to the 40-bit key length. To override the default 40-bit key length, **pvEncryptionAuxInfo** can be set to point to a
[CMSG_RC2_AUX_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_rc2_aux_info) structure that contains a key bit length.

**Note** When a message is decrypted, if it has an [initialization vector](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) parameter, the cryptographic message functions call
[CryptSetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetkeyparam) with the *initialization vector* before decrypting.

### `pvEncryptionAuxInfo`

A pointer to a
[CMSG_RC2_AUX_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_rc2_aux_info) structure for RC2 encryption or a
[CMSG_SP3_COMPATIBLE_AUX_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_sp3_compatible_aux_info) structure for SP3-compatible encryption. For other than RC2 or SP3-compatible encryption, this member must be set to **NULL**.

If the **ContentEncryptionAlgorithm** member contains **szOID_RSA_RC4**, this member points to a [CMSG_RC4_AUX_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_rc4_aux_info) structure that specifies the number of [salt bytes](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) to be included.

### `dwFlags`

Normally set to zero. However, if the encoded output is to be a CMSG_ENVELOPED [inner content](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) of an outer cryptographic message, such as a CMSG_SIGNED message, the CRYPT_MESSAGE_BARE_CONTENT_OUT_FLAG must be set. If it is not set, content will be encoded as an *inner content* type of CMSG_DATA.

CRYPT_MESSAGE_ENCAPSULATED_CONTENT_OUT_FLAG can be set to encapsulate non-data [inner content](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) within an OCTET STRING before encrypting.

CRYPT_MESSAGE_KEYID_RECIPIENT_FLAG can be set to identify recipients by their Key Identifier and not their Issuer and Serial Number.

### `dwInnerContentType`

Normally set to zero. The **dwInnerContentType** member must be set to set the cryptographic message types if the input to be encrypted is the encoded output of another cryptographic message such as CMSG_SIGNED.

## See also

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier)

[CryptEncryptMessage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencryptmessage)

[CryptSignAndEncryptMessage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignandencryptmessage)