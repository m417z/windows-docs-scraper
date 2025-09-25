# CryptMsgCountersignEncoded function

## Description

The **CryptMsgCountersignEncoded** function countersigns an existing PKCS #7 message signature. The *pbCountersignature* **BYTE** buffer it creates is a PKCS #7 encoded SignerInfo that can be used as an unauthenticated [Countersignature](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) attribute of a PKCS #9 signed-data or signed-and-enveloped-data message.

## Parameters

### `dwEncodingType` [in]

Specifies the encoding type used. Currently, only X509_ASN_ENCODING and PKCS_7_ASN_ENCODING are being used; however, additional encoding types may be added in the future. For either current encoding type, use:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING.

### `pbSignerInfo` [in]

A pointer to the encoded SignerInfo that is to be countersigned.

### `cbSignerInfo` [in]

Count, in bytes, of the encoded SignerInfo data.

### `cCountersigners` [in]

Number of countersigners in the *rgCountersigners* array.

### `rgCountersigners` [in]

Array of countersigners'
[CMSG_SIGNER_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signer_encode_info) structures.

### `pbCountersignature` [out]

A pointer to a buffer to receive an encoded PKCS #9 [countersignature](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) attribute.

On input, this parameter can be **NULL** to set the size of this information for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbCountersignature` [in, out]

A pointer to a variable that specifies the size, in bytes, of the buffer pointed to by the *pbCountersignature* parameter. When the function returns, the variable pointed to by the *pcbCountersignature* parameter contains the number of bytes stored in the buffer.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following table lists the error codes most commonly returned by the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

| Return code | Description |
| --- | --- |
| **CRYPT_E_OID_FORMAT** | The object identifier is badly formatted. |
| **E_INVALIDARG** | One or more arguments are not valid. |
| **E_OUTOFMEMORY** | Ran out of memory. |

Propagated errors might be returned from one of the following functions:

* [CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash)
* [CryptHashData](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashdata)
* [CryptGetHashParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgethashparam)
* [CryptSignHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignhasha)
* [CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode)
* [CryptMsgUpdate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgupdate)
* [CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol)

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## See also

[CryptMsgCountersign](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcountersign)

[CryptMsgVerifyCountersignatureEncoded](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgverifycountersignatureencoded)

[Low-level Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)