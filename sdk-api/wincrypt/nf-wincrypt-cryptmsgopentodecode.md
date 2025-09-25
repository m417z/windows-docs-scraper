# CryptMsgOpenToDecode function

## Description

The **CryptMsgOpenToDecode** function opens a cryptographic message for decoding and returns a handle of the opened message. The message remains open until
the [CryptMsgClose](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgclose) function is called.

Important changes that affect the handling of enveloped messages have been made to CryptoAPI to support [Secure/Multipurpose Internet Mail Extensions](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (S/MIME) email interoperability. For details, see the Remarks section of
[CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode).

## Parameters

### `dwMsgEncodingType` [in]

Specifies the encoding type used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `dwFlags` [in]

This parameter can be one of the following flags.

| Value | Meaning |
| --- | --- |
| **CMSG_DETACHED_FLAG** | Indicates that the message to be decoded is detached. If this flag is not set, the message is not detached. |
| **CMSG_CRYPT_RELEASE_CONTEXT_FLAG** | If set, the *hCryptProv* passed to this function is released on the final [CryptMsgUpdate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgupdate). The handle is not released if the function fails. |

### `dwMsgType` [in]

Specifies the type of message to decode. In most cases, the message type is determined from the message header and zero is passed for this parameter. In some cases, notably with Internet Explorer 3.0, messages do not have headers and the type of message to be decoded must be supplied in this function call. If the header is missing and zero is passed for this parameter, the function fails.

This parameter can be one of the following predefined message types.

| Value | Meaning |
| --- | --- |
| **CMSG_DATA** | The message is encoded data. |
| **CMSG_ENVELOPED** | The message is an enveloped message. |
| **CMSG_HASHED** | The message is a hashed message. |
| **CMSG_SIGNED** | The message is a signed message. |
| **CMSG_SIGNED_AND_ENVELOPED** | The message is a signed and enveloped message. |

### `hCryptProv` [in]

This parameter is not used and should be set to **NULL**.

**Windows Server 2003 and Windows XP:** Specifies a handle for the cryptographic provider to use for [hashing](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) the message. For signed messages, *hCryptProv* is used for signature verification.This parameter's data type is **HCRYPTPROV**.

Unless there is a strong reason for passing in a specific cryptographic provider in *hCryptProv*, set this parameter to **NULL**. Passing in **NULL** causes the default RSA or DSS provider to be acquired before performing hash, signature verification, or recipient encryption operations.

### `pRecipientInfo` [in]

This parameter is reserved for future use and must be **NULL**.

### `pStreamInfo` [in, optional]

When streaming is not being used, this parameter must be set to **NULL**.

**Note** Streaming is not used with CMSG_HASHED messages. When dealing with hashed data, this parameter must be set to **NULL**.

When streaming is being used, the *pStreamInfo* parameter is a pointer to a
[CMSG_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_stream_info) structure that contains a pointer to a callback to be called when
[CryptMsgUpdate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgupdate) is executed or when
[CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol) is executed when decoding a streamed enveloped message.

For a signed message, the callback is passed a block of the decoded bytes from the [inner content](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) of the message.

For an enveloped message, after each call to [CryptMsgUpdate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgupdate), you must check to determine whether the CMSG_ENVELOPE_ALGORITHM_PARAM property is available by calling
the [CryptMsgGetParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsggetparam) function. **CryptMsgGetParam** will fail and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return CRYPT_E_STREAM_MSG_NOT_READY until
**CryptMsgUpdate** has processed enough of the message to make the CMSG_ENVELOPE_ALGORITHM_PARAM property available. When the CMSG_ENVELOPE_ALGORITHM_PARAM property is available, you can iterate through the recipients, retrieving a
[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure for each recipient by using the **CryptMsgGetParam** function to retrieve the CMSG_RECIPIENT_INFO_PARAM property. To prevent a denial of service attack from an enveloped message that has an artificially large header block, you must keep track of the amount of memory that has been passed to the **CryptMsgUpdate** function during this process. If the amount of data exceeds an application defined limit before the CMSG_ENVELOPE_ALGORITHM_PARAM property is available, you must stop processing the message and call the [CryptMsgClose](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgclose) function to cause the operating system to release any memory that has been allocated for the message. A suggested limit is the maximum allowable size of a message. For example, if the maximum message size is 10 MB, the limit for this test should be 10 MB.

The [CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure is used to find a matching certificate in a previously opened [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) by using
the [CertGetSubjectCertificateFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetsubjectcertificatefromstore) function. When the correct certificate is found,
the [CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty) function with a CERT_KEY_PROV_INFO_PROP_ID parameter is called to retrieve a
[CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info) structure. The structure contains the information necessary to acquire the recipient's private key by calling
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta), using the **pwszContainerName**, **pwszProvName**, **dwProvType**, and **dwFlags** members of the **CRYPT_KEY_PROV_INFO** structure. The **hCryptProv** acquired and the **dwKeySpec** member of the **CRYPT_KEY_PROV_INFO** structure are passed to
the [CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol) structure as a member of the
[CMSG_CTRL_DECRYPT_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_ctrl_decrypt_para) structure to permit the start of the decryption of the [inner content](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly). The streaming code will then perform the decryption as the data is input. The resulting blocks of [plaintext](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) are passed to the callback function specified by the **pfnStreamOutput** member of the [CMSG_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_stream_info) structure to handle the output of the decrypted message.

**Note** Streamed decoding of an enveloped message queues the [ciphertext](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) in memory until [CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol) is called to start the decryption. The application must initiate decrypting in a timely manner so that the data can be saved to disk or routed elsewhere before the accumulated *ciphertext* becomes too large and the system runs out of memory.

In the case of a signed message enclosed in an enveloped message, the [plaintext](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) output from the streaming decode of the enveloped message can be fed into another streaming decode to process the signed message.

## Return value

If the function succeeds, the function returns the handle of the opened message.

If the function fails, it returns **NULL**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following table lists the error codes most commonly returned by the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

| Value | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are not valid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## See also

[CryptMsgClose](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgclose)

[CryptMsgGetParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsggetparam)

[CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode)

[CryptMsgUpdate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgupdate)

[Low-level Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)