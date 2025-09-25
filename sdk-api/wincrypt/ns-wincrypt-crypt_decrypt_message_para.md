# CRYPT_DECRYPT_MESSAGE_PARA structure

## Description

The **CRYPT_DECRYPT_MESSAGE_PARA** structure contains information for decrypting messages.

## Members

### `cbSize`

Size of this structure in bytes.

### `dwMsgAndCertEncodingType`

Type of encoding used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `cCertStore`

Number of elements in the **rghCertStore** array.

### `rghCertStore`

Array of [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) handles.

These certificate store handles are used to obtain the [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to use for decrypting a message. For more information, see the decryption functions
[CryptDecryptMessage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecryptmessage), and
[CryptDecryptAndVerifyMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecryptandverifymessagesignature). An encrypted message can have one or more recipients. The recipients are identified by a unique certificate identifier, often the [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) of the certificate issuer and serial number. The certificate stores are searched to find a certificate context corresponding to the unique identifier.

Recipients can also be identified by their KeyId. Both Key Agreement (Diffie-Hellman) and Key Transport (RSA) recipients are supported.

Only certificate contexts in the store with one of the following properties, CERT_KEY_PROV_INFO_PROP_ID, or CERT_KEY_CONTEXT_PROP_ID can be used. These properties specify the location of a needed private exchange key.

### `dwFlags`

The CRYPT_MESSAGE_SILENT_KEYSET_FLAG can be set to suppress any UI by the CSP. For more information about the CRYPT_SILENT flag, see
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta).

## See also

[CryptDecryptAndVerifyMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecryptandverifymessagesignature)

[CryptDecryptMessage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecryptmessage)