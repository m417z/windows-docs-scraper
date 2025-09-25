# CryptMsgOpenToEncode function

## Description

The **CryptMsgOpenToEncode** function opens a cryptographic message for encoding and returns a handle of the opened message. The message remains open until
[CryptMsgClose](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgclose) is called.

## Parameters

### `dwMsgEncodingType` [in]

Specifies the encoding type used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `dwFlags` [in]

Currently defined *dwFlags* are shown in the following table.

| Value | Meaning |
| --- | --- |
| **CMSG_BARE_CONTENT_FLAG** | The streamed output will not have an outer ContentInfo wrapper (as defined by PKCS #7). This makes it suitable to be streamed into an enclosing message. |
| **CMSG_DETACHED_FLAG** | There is detached data being supplied for the subsequent calls to [CryptMsgUpdate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgupdate). |
| **CMSG_AUTHENTICATED_ATTRIBUTES_FLAG** | Authenticated attributes are forced to be included in the SignerInfo (as defined by PKCS #7) in cases where they would not otherwise be required. |
| **CMSG_CONTENTS_OCTETS_FLAG** | Used when calculating the size of a message that has been encoded by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) and that is nested inside an enveloped message. This is particularly useful when performing streaming. |
| **CMSG_CMS_ENCAPSULATED_CONTENT_FLAG** | When set, non-data type-[inner content](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) is encapsulated within an OCTET STRING. Applicable to both signed and enveloped messages. |
| **CMSG_CRYPT_RELEASE_CONTEXT_FLAG** | If set, the **hCryptProv** that is passed to this function is released on the final [CryptMsgUpdate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgupdate). The handle is not released if the function fails.<br><br>**Note** The **hCryptProv**s of the envelope recipients are not released. |

### `dwMsgType` [in]

Indicates the message type. This must be one of the following values.

| Value | Meaning |
| --- | --- |
| **CMSG_DATA** | This value is not used. |
| **CMSG_SIGNED** | The *pvMsgEncodeInfo* parameter is the address of a [CMSG_SIGNED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signed_encode_info) structure that contains the encoding information. |
| **CMSG_ENVELOPED** | The *pvMsgEncodeInfo* parameter is the address of a [CMSG_ENVELOPED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_enveloped_encode_info) structure that contains the encoding information. |
| **CMSG_SIGNED_AND_ENVELOPED** | This value is not currently implemented. |
| **CMSG_HASHED** | The *pvMsgEncodeInfo* parameter is the address of a [CMSG_HASHED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_hashed_encode_info) structure that contains the encoding information. |

### `pvMsgEncodeInfo` [in]

The address of a structure that contains the encoding information. The type of data depends on the value of the *dwMsgType* parameter. For details, see *dwMsgType*.

### `pszInnerContentObjID` [in, optional]

If [CryptMsgCalculateEncodedLength](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcalculateencodedlength) is called and the data for
[CryptMsgUpdate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgupdate) has already been message encoded, the appropriate [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) is passed in *pszInnerContentObjID*. If *pszInnerContentObjID* is **NULL**, then the inner content type is assumed not to have been previously encoded and is therefore encoded as an octet string and given the type CMSG_DATA.

**Note** When streaming is being used, *pszInnerContentObjID* must be either **NULL** or szOID_RSA_data.

The following algorithm OIDs are commonly used. A user can define new inner content usage by ensuring that the sender and receiver of the message agree upon the semantics associated with the OID.

* szOID_RSA_data
* szOID_RSA_signedData
* szOID_RSA_envelopedData
* szOID_RSA_signEnvData
* szOID_RSA_digestedData
* szOID_RSA_encryptedData
* SPC_INDIRECT_DATA_OBJID

### `pStreamInfo` [in]

When streaming is being used, this parameter is the address of a
[CMSG_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_stream_info) structure. The callback function specified by the **pfnStreamOutput** member of the **CMSG_STREAM_INFO** structure is called when
[CryptMsgUpdate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgupdate) is executed. The callback is passed the encoded bytes that result from the encoding. For more information about how to use the callback, see
**CMSG_STREAM_INFO**.

**Note** When streaming is being used, the application must not release any data handles that are passed in the *pvMsgEncodeInfo* parameter, such as the provider handle in the **hCryptProv** member of the [CMSG_SIGNER_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signer_encode_info) structure, until after the message handle returned by this function is closed by using the [CryptMsgClose](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgclose) function.

When streaming is not being used, this parameter is set to **NULL**.

Streaming is not used with the **CMSG_HASHED** message type. When dealing with hashed data, this parameter must be set to **NULL**.

Consider the case of a signed message being enclosed in an enveloped message. The encoded output from the streamed encoding of the signed message feeds into another streaming encoding of the enveloped message. The callback for the streaming encoding calls [CryptMsgUpdate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgupdate) to encode the enveloped message. The callback for the enveloped message receives the encoded bytes of the nested signed message.

## Return value

If the function succeeds, it returns a handle to the opened message. This handle must be closed when it is no longer needed by passing it to the [CryptMsgClose](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgclose) function.

If this function fails, **NULL** is returned.

To retrieve extended error information, use the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The following table lists the error codes most commonly returned by the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

| Return code | Description |
| --- | --- |
| **CRYPT_E_INVALID_MSG_TYPE** | The message type is not valid. |
| **CRYPT_E_OID_FORMAT** | The OID is badly formatted. |
| **CRYPT_E_UNKNOWN_ALGO** | The cryptographic algorithm is unknown. |
| **E_INVALIDARG** | One or more arguments are not valid. |
| **E_OUTOFMEMORY** | There is not enough memory. |

In addition, if *dwMsgType* is CMSG_SIGNED, errors can be propagated from
[CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash).

If *dwMsgType* is CMSG_ENVELOPED, errors can be propagated from
[CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey),
[CryptImportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportkey), and
[CryptExportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportkey).

If *dwMsgType* is CMSG_HASHED, errors can be propagated from
[CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash).

## Remarks

For functions that perform encryption, the encrypted [symmetric keys](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) are reversed from [little-endian](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) format to [big-endian](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) format after
[CryptExportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportkey) is called internally. For functions that perform decryption, the encrypted symmetric keys are reversed from big-endian format to little-endian format before
[CryptImportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportkey) is called.

CRYPT_NO_SALT is specified when symmetric keys are generated and imported with
[CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey) and [CryptImportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportkey).

Messages encrypted with the RC2 encryption algorithm use KP_EFFECTIVE_KEYLEN with
[CryptGetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetkeyparam) to determine the effective [key length](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) of the RC2 key importing or exporting keys.

For messages encrypted with the RC2 encryption algorithm, encode and decode operations have been updated to handle ASN RC2 parameters for the **ContentEncryptionAlgorithm** member of the
[CMSG_ENVELOPED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_enveloped_encode_info) structure.

For messages encrypted with the RC4, DES, and 3DES encryption algorithms, encode and decode operations now handle the ASN IV octet string parameter for the **ContentEncryptionAlgorithm** member of the [CMSG_ENVELOPED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_enveloped_encode_info) structure.

#### Examples

For examples that use this function, see
[Example C Program: Signing, Encoding, Decoding, and Verifying a Message](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-signing-encoding-decoding-and-verifying-a-message),
[Alternate Code for Encoding an Enveloped Message](https://learn.microsoft.com/windows/desktop/SecCrypto/alternate-code-for-encoding-an-enveloped-message),
[Example C Program: Encoding an Enveloped, Signed Message](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-encoding-an-enveloped-signed-message), and
[Example C Program: Encoding and Decoding a Hashed Message](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-encoding-and-decoding-a-hashed-message).

## See also

[CryptMsgClose](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgclose)

[CryptMsgGetParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsggetparam)

[CryptMsgOpenToDecode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentodecode)

[CryptMsgUpdate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgupdate)

[Low-level Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)