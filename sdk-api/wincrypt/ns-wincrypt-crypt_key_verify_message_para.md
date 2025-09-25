# CRYPT_KEY_VERIFY_MESSAGE_PARA structure

## Description

The **CRYPT_KEY_VERIFY_MESSAGE_PARA** structure contains information needed to verify signed messages without a certificate for the signer.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `dwMsgEncodingType`

Type of encoding used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `hCryptProv`

This member is not used and should be set to **NULL**.

**Windows Server 2003 and Windows XP:** A handle to the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) to be used to verify a signed message. The CSP identified by this handle is used for [hashing](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) and for signature verification.Unless there is a strong reason for using a specific cryptographic provider, set this member to zero to use the default RSA or DSS provider.

This member's data type is **HCRYPTPROV**.