# CryptMsgCalculateEncodedLength function

## Description

The **CryptMsgCalculateEncodedLength** function calculates the maximum number of bytes needed for an encoded cryptographic message given the message type, encoding parameters, and total length of the data to be encoded. Note that the result will always be greater than or equal to the actual number of bytes needed.

## Parameters

### `dwMsgEncodingType` [in]

Specifies the encoding type used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `dwFlags` [in]

Currently defined flags are shown in the following table.

| Value | Meaning |
| --- | --- |
| **CMSG_BARE_CONTENT_FLAG** | Indicates that streamed output will not have an outer ContentInfo wrapper (as defined by PKCS #7). This makes it suitable to be streamed into an enclosing message. |
| **CMSG_DETACHED_FLAG** | Indicates that there is detached data being supplied for the subsequent calls to [CryptMsgUpdate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgupdate). |
| **CMSG_CONTENTS_OCTETS_FLAG** | Used to calculate the size of a [DER](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) encoding of a message to be nested inside an enveloped message. This is particularly useful when streaming is being performed. |
| **CMSG_CMS_ENCAPSULATED_CONTENT_FLAG** | Non-Data type [inner content](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) is encapsulated within an OCTET STRING. This flag is applicable for both Signed and Enveloped messages. |

### `dwMsgType` [in]

Currently defined message types are shown in the following table.

| Value | Meaning |
| --- | --- |
| **CMSG_DATA** | An octet (BYTE) string. |
| **CMSG_SIGNED** | [CMSG_SIGNED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signed_encode_info) |
| **CMSG_ENVELOPED** | [CMSG_ENVELOPED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_enveloped_encode_info) |
| **CMSG_SIGNED_AND_ENVELOPED** | Not implemented. |
| **CMSG_HASHED** | [CMSG_HASHED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_hashed_encode_info) |
| **CMSG_ENCRYPTED** | Not implemented. |

### `pvMsgEncodeInfo` [in]

A pointer to the data to be encoded. The type of data pointed to depends on the value of *dwMsgType*. For details, see the *dwMsgType* table.

### `pszInnerContentObjID` [in, optional]

When calling **CryptMsgCalculateEncodedLength** with data provided to
[CryptMsgUpdate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgupdate) already encoded, the appropriate object identifier is passed in *pszInnerContentObjID*. If *pszInnerContentObjID* is **NULL**, the [inner content](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) type is assumed not to have been previously encoded, and is encoded as an octet string and given the type CMSG_DATA.

When streaming is being used, *pszInnerContentObjID* must be either **NULL** or szOID_RSA_data.

The following algorithm object identifiers are commonly used:

* szOID_RSA_data
* szOID_RSA_signedData
* szOID_RSA_envelopedData
* szOID_RSA_signEnvData
* szOID_RSA_digestedData
* szOID_RSA_encryptedData
* SPC_INDIRECT_DATA_OBJID

A user can define new [inner content](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) usage. The user must ensure that the sender and receiver of the message agree upon the semantics associated with the object identifier.

### `cbData` [in]

The size, in bytes, of the content.

## Return value

Returns the required length for an encoded cryptographic message. This length might not be the exact length but it will not be less than the required length. Zero is returned if the function fails.

To retrieve extended error information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. The following table lists the error codes most commonly returned.

| Return code | Description |
| --- | --- |
| **CRYPT_E_INVALID_MSG_TYPE** | The message type is not valid. |
| **CRYPT_E_UNKNOWN_ALGO** | The cryptographic algorithm is unknown. |
| **E_INVALIDARG** | One or more arguments are not valid. |

## See also

[CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode)

[Low-level Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)