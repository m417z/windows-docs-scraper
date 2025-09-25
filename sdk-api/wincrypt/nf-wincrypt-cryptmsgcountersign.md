# CryptMsgCountersign function

## Description

The **CryptMsgCountersign** function countersigns an existing signature in a message. [Countersignatures](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) are used to sign an existing signature's encrypted [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) of the message. Countersignatures can be used for various purposes including time stamping a message.

## Parameters

### `hCryptMsg` [in, out]

Cryptographic message handle to be used.

### `dwIndex` [in]

Zero-based index of the signer in the signed or signed-and-enveloped message to be countersigned.

### `cCountersigners` [in]

Number of countersigners in the *rgCountersigners* array.

### `rgCountersigners` [in]

Array of countersigners'
[CMSG_SIGNER_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signer_encode_info) structures.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

An error can be propagated from
[CryptMsgCountersignEncoded](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcountersignencoded).

The following error codes are returned most often.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are not valid. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **ERROR_MORE_DATA** | The specified area is not large enough to hold the returned data. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## See also

[CryptMsgCountersignEncoded](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcountersignencoded)

[CryptMsgVerifyCountersignatureEncoded](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgverifycountersignatureencoded)

[Low-level Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)