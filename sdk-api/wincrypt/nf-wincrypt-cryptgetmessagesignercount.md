# CryptGetMessageSignerCount function

## Description

The **CryptGetMessageSignerCount** function returns the number of signers of a signed message.

> [!NOTE]
> This function may return a count of duplicate signers and therefore may not be sufficient to avert attacks. We recommend using the sid (SignerIdentifier) field from SignerInfo to identify duplicate signers in a message.

## Parameters

### `dwMsgEncodingType` [in]

Specifies the encoding type used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pbSignedBlob` [in]

A pointer to a buffer containing the signed message.

### `cbSignedBlob` [in]

The size, in bytes, of the signed message.

## Return value

Returns the number of signers of a signed message, zero when there are no signers, and minus one (–1) for an error.

For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following error code is most commonly returned.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid [message encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly). Currently only PKCS_7_ASN_ENCODING is supported. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## See also

[CryptVerifyMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifymessagesignature)

[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)