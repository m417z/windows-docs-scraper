# CryptMsgSignCTL function

## Description

The **CryptMsgSignCTL** function creates a signed message containing an encoded CTL.

## Parameters

### `dwMsgEncodingType` [in]

Specifies the encoding type used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pbCtlContent` [in]

The encoded
[CTL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_info) that can be a member of a
[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure or can be created using the
[CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) function.

### `cbCtlContent` [in]

The size, in bytes, of the content pointed to by *pbCtlContent*.

### `pSignInfo` [in]

A pointer to a
[CMSG_SIGNED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signed_encode_info) structure containing an array of a
[CMSG_SIGNER_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signer_encode_info) structures.

The message can be encoded without signers if the **cbSize** member of the structure is set to the size of the structure and all of the other members are set to zero.

### `dwFlags` [in]

If CMS_PKCS7 is defined, can be set to CMSG_CMS_ENCAPSULATED_CTL_FLAG to encode a CMS compatible V3 SignedData message.

### `pbEncoded` [out]

A pointer to a buffer to receives the encoded message.

This parameter can be **NULL** to get the size of this information for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbEncoded` [in, out]

A pointer to a **DWORD** specifying the size, in bytes, of the *pbEncoded* buffer. When the function returns, the **DWORD** contains the number of bytes stored or to be stored in the buffer.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). This function can return errors propagated from calls to
[CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode) and
[CryptMsgUpdate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgupdate).

## See also

[CMSG_SIGNED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signed_encode_info)

[CryptMsgEncodeAndSignCTL](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgencodeandsignctl)

[CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode)

[Verification Functions Using CTLs](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)