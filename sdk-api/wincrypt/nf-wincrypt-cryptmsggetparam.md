# CryptMsgGetParam function

## Description

The **CryptMsgGetParam** function acquires a message parameter after a cryptographic message has been encoded or decoded. This function is called after the final
[CryptMsgUpdate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgupdate) call.

## Parameters

### `hCryptMsg` [in]

Handle of a cryptographic message.

### `dwParamType` [in]

Indicates the parameter types of data to be retrieved. The type of data to be retrieved determines the type of structure to use for *pvData*.

For an encoded message, only the CMSG_BARE_CONTENT, CMSG_ENCODE_SIGNER, CMSG_CONTENT_PARAM and CMSG_COMPUTED_HASH_PARAM *dwParamType*s are valid.

| Value | Meaning |
| --- | --- |
| **CMSG_ATTR_CERT_COUNT_PARAM** | *pvData* data type: pointer to a **DWORD**<br><br> Returns the count of the attribute certificates in a SIGNED or ENVELOPED message. |
| **CMSG_ATTR_CERT_PARAM** | *pvData* data type: pointer to a **BYTE** array<br><br>Retrieves an attribute certificate. To get all the attribute certificates, call **CryptMsgGetParam** varying *dwIndex* set to 0 the number of attributes minus one. |
| **CMSG_BARE_CONTENT_PARAM** | *pvData* data type: pointer to a **BYTE** array<br><br>Retrieves the encoded content of an encoded cryptographic message, without the outer layer of the CONTENT_INFO structure. That is, only the encoding of the PKCS #7 defined ContentInfo.content field is returned. |
| **CMSG_CERT_COUNT_PARAM** | *pvData* data type: pointer to **DWORD**<br><br>Returns the number of certificates in a received SIGNED or ENVELOPED message. |
| **CMSG_CERT_PARAM** | *pvData* data type: pointer to a **BYTE** array<br><br>Returns a signer's certificate. To get all of the signer's certificates, call **CryptMsgGetParam**, varying *dwIndex* from 0 to the number of available certificates minus one. |
| **CMSG_COMPUTED_HASH_PARAM** | *pvData* data type: pointer to a **BYTE** array<br><br>Returns the hash calculated of the data in the message. This type is applicable to both encode and decode. |
| **CMSG_CONTENT_PARAM** | *pvData* data type: pointer to a **BYTE** array<br><br> <br><br>Returns the whole PKCS #7 message from a message opened to encode. Retrieves the inner content of a message opened to decode. If the message is enveloped, the inner type is data, and [CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol) has been called to decrypt the message, the decrypted content is returned. If the inner type is not data, the encoded BLOB that requires further decoding is returned. If the message is not enveloped and the inner content is DATA, the returned data is the octets of the inner content. This type is applicable to both encode and decode.<br><br>For decoding, if the type is CMSG_DATA, the content's octets are returned; else, the encoded inner content is returned. |
| **CMSG_CRL_COUNT_PARAM** | *pvData* data type: pointer to **DWORD**<br><br>Returns the count of CRLs in a received, SIGNED or ENVELOPED message. |
| **CMSG_CRL_PARAM** | *pvData* data type: pointer to a **BYTE** array<br><br>Returns a CRL. To get all the CRLs, call **CryptMsgGetParam**, varying *dwIndex* from 0 to the number of available CRLs minus one. |
| **CMSG_ENCODED_MESSAGE** | *pvData* data type: pointer to a **BYTE** array<br><br>Changes the contents of an already encoded message. The message must first be decoded with a call to [CryptMsgOpenToDecode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentodecode). Then the change to the message is made through a call to [CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol), [CryptMsgCountersign](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcountersign), or [CryptMsgCountersignEncoded](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcountersignencoded). The message is then encoded again with a call to **CryptMsgGetParam**, specifying CMSG_ENCODED_MESSAGE to get a new encoding that reflects the changes made. This can be used, for instance, to add a time-stamp attribute to a message. |
| **CMSG_ENCODED_SIGNER** | *pvData* data type: pointer to a **BYTE** array<br><br>Returns the encoded CMSG_SIGNER_INFO signer information for a message signer. |
| **CMSG_ENCRYPTED_DIGEST** | *pvData* data type: pointer to a **BYTE** array<br><br>Returns the encrypted hash of a signature. Typically used for performing time-stamping. |
| **CMSG_ENCRYPT_PARAM** | *pvData* data type: pointer to a **BYTE** array for a [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure.<br><br> Returns the encryption algorithm used to encrypted the message. |
| **CMSG_ENVELOPE_ALGORITHM_PARAM** | *pvData* data type: pointer to a **BYTE** array for a [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure.<br><br> Returns the encryption algorithm used to encrypt an ENVELOPED message. |
| **CMSG_HASH_ALGORITHM_PARAM** | *pvData* data type: pointer to a **BYTE** array for a [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure.<br><br> Returns the hash algorithm used to hash the message when it was created. |
| **CMSG_HASH_DATA_PARAM** | *pvData* data type: pointer to a **BYTE** array<br><br>Returns the hash value stored in the message when it was created. |
| **CMSG_INNER_CONTENT_TYPE_PARAM** | *pvData* data type: pointer to a **BYTE** array to receive a **null**-terminated [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) string.<br><br>Returns the inner content type of a received message. This type is not applicable to messages of type DATA. |
| **CMSG_RECIPIENT_COUNT_PARAM** | *pvData* data type: pointer to a **DWORD**<br><br>Returns the number of key transport recipients of an ENVELOPED received message. |
| **CMSG_CMS_RECIPIENT_COUNT_PARAM** | *pvData* data type: pointer to **DWORD**<br><br>Returns the total count of all message recipients including key agreement and mail list recipients. |
| **CMSG_RECIPIENT_INDEX_PARAM** | *pvData* data type: pointer to a **DWORD**<br><br>Returns the index of the key transport recipient used to decrypt an ENVELOPED message. This value is available only after a message has been decrypted. |
| **CMSG_CMS_RECIPIENT_INDEX_PARAM** | *pvData* data type: pointer to a **DWORD**<br><br>Returns the index of the key transport, key agreement, or mail list recipient used to decrypt an ENVELOPED message. |
| **CMSG_CMS_RECIPIENT_ENCRYPTED_KEY_INDEX_PARAM** | *pvData* data type: pointer to a **DWORD**<br><br>Returns the index of the encrypted key of a key agreement recipient used to decrypt an ENVELOPED message. |
| **CMSG_RECIPIENT_INFO_PARAM** | *pvData* data type: pointer to a **BYTE** array to receive a [CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure.<br><br> Returns certificate information about a key transport message's recipient. To get certificate information on all key transport message's recipients, repetitively call **CryptMsgGetParam**, varying *dwIndex* from 0 to the number of recipients minus one. Only the Issuer, SerialNumber, and PublicKeyAlgorithm members of the [CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure returned are available and valid. |
| **CMSG_CMS_RECIPIENT_INFO_PARAM** | *pvData* data type: pointer to a **BYTE** array to receive a [CMSG_CMS_RECIPIENT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_cms_recipient_info) structure.<br><br>Returns information about a key transport, key agreement, or mail list recipient. It is not limited to key transport message recipients. To get information on all of a message's recipients, repetitively call **CryptMsgGetParam**, varying *dwIndex* from 0 to the number of recipients minus one. |
| **CMSG_SIGNER_AUTH_ATTR_PARAM** | *pvData* data type: pointer to a **BYTE** array to receive a [CRYPT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attributes) structure.<br><br> Returns the authenticated attributes of a message signer. To retrieve the authenticated attributes for a specified signer, call **CryptMsgGetParam** with *dwIndex* equal to that signer's index. |
| **CMSG_SIGNER_CERT_INFO_PARAM** | *pvData* data type: pointer to a **BYTE** array to receive the [CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure.<br><br> Returns information on a message signer needed to identify the signer's certificate. A certificate's Issuer and SerialNumber can be used to uniquely identify a certificate for retrieval. To retrieve information for all the signers, repetitively call **CryptMsgGetParam** varying *dwIndex* from 0 to the number of signers minus one. Only the Issuer and SerialNumber fields in the [CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure returned contain available, valid data. |
| **CMSG_SIGNER_CERT_ID_PARAM** | *pvData* data type: pointer to a **BYTE** array to receive a [CERT_ID](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_id) structure.<br><br>Returns information on a message signer needed to identify the signer's public key. This could be a certificate's Issuer and SerialNumber, a KeyID, or a HashId. To retrieve information for all the signers, call **CryptMsgGetParam** varying *dwIndex* from 0 to the number of signers minus one. |
| **CMSG_SIGNER_COUNT_PARAM** | *pvData* data type: pointer to a **DWORD**<br><br>Returns the number of signers of a received SIGNED message. |
| **CMSG_SIGNER_HASH_ALGORITHM_PARAM** | *pvData* data type: pointer to a **BYTE** array to receive the [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure.<br><br> Returns the hash algorithm used by a signer of the message. To get the hash algorithm for a specified signer, call **CryptMsgGetParam** with *dwIndex* equal to that signer's index. |
| **CMSG_SIGNER_INFO_PARAM** | *pvData* data type: pointer to a **BYTE** array to receive a [CMSG_SIGNER_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signer_info) structure.<br><br> Returns information on a message signer. This includes the issuer and serial number of the signer's certificate and authenticated and unauthenticated attributes of the signer's certificate. To retrieve signer information on all of the signers of a message, call **CryptMsgGetParam** varying *dwIndex* from 0 to the number of signers minus one. |
| **CMSG_CMS_SIGNER_INFO_PARAM** | *pvData* data type: pointer to a **BYTE** array to receive a [CMSG_CMS_SIGNER_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_cms_signer_info) structure.<br><br> Returns information on a message signer. This includes a signerId and authenticated and unauthenticated attributes. To retrieve signer information on all of the signers of a message, call **CryptMsgGetParam** varying *dwIndex* from 0 to the number of signers minus one. |
| **CMSG_SIGNER_UNAUTH_ATTR_PARAM** | *pvData* data type: pointer to a **BYTE** array to receive a [CRYPT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attributes) structure.<br><br> Returns a message signer's unauthenticated attributes. To retrieve the unauthenticated attributes for a specified signer, call **CryptMsgGetParam** with *dwIndex* equal to that signer's index. |
| **CMSG_TYPE_PARAM** | *pvData* data type: pointer to a **DWORD**<br><br>Returns the message type of a decoded message of unknown type. The retrieved message type can be compared to supported types to determine whether processing can continued. For supported message types, see the *dwMessageType* parameter of [CryptMsgOpenToDecode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentodecode). |
| **CMSG_UNPROTECTED_ATTR_PARAM** | *pvData* data type: pointer to a **BYTE** array to receive a [CMSG_ATTR](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attributes) structure.<br><br> Returns the unprotected attributes in an enveloped message. |
| **CMSG_VERSION_PARAM** | *pvData* data type: pointer to a **DWORD**<br><br> Returns the version of the decoded message. For more information, see the table in the Remarks section. |

### `dwIndex` [in]

Index for the parameter being retrieved, where applicable. When a parameter is not being retrieved, this parameter is ignored and is set to zero.

### `pvData` [out]

A pointer to a buffer that receives the data retrieved. The form of this data will vary depending on the value of the *dwParamType* parameter.

This parameter can be **NULL** to set the size of this information for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

When processing the data returned in this buffer, applications need to use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. (On input, buffer sizes are usually specified large enough to ensure that the largest possible output data will fit in the buffer.) On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

### `pcbData` [in, out]

A pointer to a variable that specifies the size, in bytes, of the buffer pointed to by the *pvData* parameter. When the function returns, the variable pointed to by the *pcbData* parameter contains the number of bytes stored in the buffer.

## Return value

If the function succeeds, the return value is nonzero (TRUE).

If the function fails, the return value is zero (FALSE). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following table lists the error codes most commonly returned by the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

| Return code | Description |
| --- | --- |
| **CRYPT_E_ATTRIBUTES_MISSING** | The message does not contain the requested attributes. |
| **CRYPT_E_INVALID_INDEX** | The index value is not valid. |
| **CRYPT_E_INVALID_MSG_TYPE** | The message type is not valid. |
| **CRYPT_E_NOT_DECRYPTED** | The message content has not been decrypted yet. |
| **CRYPT_E_OID_FORMAT** | The object identifier is badly formatted. |
| **CRYPT_E_UNEXPECTED_ENCODING** | The message is not encoded as expected. |
| **E_INVALIDARG** | One or more arguments are not valid. |
| **ERROR_MORE_DATA** | The specified buffer is not large enough to hold the returned data. |

For *dwParamType* CMSG_COMPUTED_HASH_PARAM, an error can be propagated from
[CryptGetHashParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgethashparam).

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## Remarks

The following version numbers are returned by calls to **CryptMsgGetParam** with *dwParamType* set to CMSG_VERSION_PARAM are defined:

* CMSG_SIGNED_DATA_V1
* CMSG_SIGNED_DATA_V3
* CMSG_SIGNED_DATA_PKCS_1_5_VERSION
* CMSG_SIGNED_DATA_CMS_VERSION
* CMSG_SIGNER_INFO_V1
* CMSG_SIGNER_INFO_V3
* CMSG_SIGNER_INFO_PKCS_1_5_VERSION
* CMSG_SIGNER_INFO_CMS_VERSION
* CMSG_HASHED_DATA_V0
* CMSG_HASHED_DATA_V2
* CMSG_HASHED_DATA_PKCS_1_5_VERSION
* CMSG_HASHED_DATA_CMS_VERSION
* CMSG_ENVELOPED_DATA_V0
* CMSG_ENVELOPED_DATA_V2
* CMSG_ENVELOPED_DATA_PKCS_1_5_VERSION
* CMSG_ENVELOPED_DATA_CMS_VERSION

#### Examples

For an example that uses this function, see
[Example C Program: Signing, Encoding, Decoding, and Verifying a Message](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-signing-encoding-decoding-and-verifying-a-message),
[Alternate Code for Encoding an Enveloped Message](https://learn.microsoft.com/windows/desktop/SecCrypto/alternate-code-for-encoding-an-enveloped-message),
[Example C Program: Encoding an Enveloped, Signed Message](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-encoding-an-enveloped-signed-message), and
[Example C Program: Encoding and Decoding a Hashed Message](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-encoding-and-decoding-a-hashed-message).

## See also

[CryptMsgOpenToDecode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentodecode)

[CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode)

[CryptMsgUpdate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgupdate)

[Low-level Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)