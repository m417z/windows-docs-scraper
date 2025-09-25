# CryptMsgUpdate function

## Description

The **CryptMsgUpdate** function adds contents to a cryptographic message. The use of this function allows messages to be constructed piece by piece through repetitive calls of **CryptMsgUpdate**. The added message content is either encoded or decoded depending on whether the message was opened with
[CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode) or
[CryptMsgOpenToDecode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentodecode).

## Parameters

### `hCryptMsg` [in]

Cryptographic message handle of the message to be updated.

### `pbData` [in]

A pointer to the buffer holding the data to be encoded or decoded.

### `cbData` [in]

Number of bytes of data in the *pbData* buffer.

### `fFinal` [in]

Indicates that the last block of data for encoding or decoding is being processed. Correct usage of this flag is dependent upon whether the message being processed has detached data. The inclusion of detached data in a message is indicated by setting *dwFlags* to CMSG_DETACHED_FLAG in the call to the function that opened the message.

If CMSG_DETACHED_FLAG was not set and the message was opened using either
[CryptMsgOpenToDecode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentodecode) or
[CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode), *fFinal* is set to **TRUE**, and **CryptMsgUpdate** is only called once.

If the CMSG_DETACHED_FLAG flag was set and a message is opened using [CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode), *fFinal* is set to **TRUE** only on the last call to **CryptMsgUpdate**.

If the CMSG_DETACHED_FLAG flag was set and a message is opened using [CryptMsgOpenToDecode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentodecode), *fFinal* is set to **TRUE** when the header is processed by a single call to **CryptMsgUpdate**. It is set to **FALSE** while processing the detached data in subsequent calls to **CryptMsgUpdate** until the last detached data block is to be processed. On the last call to **CryptMsgUpdate**, it is set to **TRUE**.

When detached data is decoded, the header and the content of a message are contained in different BLOBs. Each BLOB requires that *fFinal* be set to **TRUE** when the last call to the function is made for that BLOB.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Errors encountered in the application defined callback function specified by *pStreamInfo* in
[CryptMsgOpenToDecode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentodecode) and
[CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode) might be propagated to **CryptMsgUpdate** if streaming is used. If this happens, [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) is not called by **CryptMsgUpdate** after the callback function returns, which preserves any errors encountered under the control of the application. It is the responsibility of the callback function (or one of the APIs that it calls) to call **SetLastError** if an error occurs while the application is processing the streamed data.

The following table lists the error codes most commonly returned by the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

| Return code | Description |
| --- | --- |
| **CRYPT_E_INVALID_MSG_TYPE** | The message type is not valid. |
| **CRYPT_E_MSG_ERROR** | An error was encountered doing a cryptographic operation. |
| **CRYPT_E_OID_FORMAT** | The object identifier is badly formatted. |
| **CRYPT_E_UNEXPECTED_ENCODING** | The message is not encoded as expected. |
| **CRYPT_E_UNKNOWN_ALGO** | The cryptographic algorithm is unknown. |
| **E_INVALIDARG** | One or more arguments are not valid. |
| **E_OUTOFMEMORY** | Ran out of memory. |

Propagated errors might be encountered from any of the following functions:

* [CryptHashData](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashdata)
* [CryptGetHashParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgethashparam)
* [CryptSignHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignhasha)
* [CryptGetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetkeyparam)
* [CryptEncrypt](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencrypt)
* [CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash)

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## See also

[CryptMsgGetParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsggetparam)

[CryptMsgOpenToDecode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentodecode)

[CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode)

[Low-level Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)