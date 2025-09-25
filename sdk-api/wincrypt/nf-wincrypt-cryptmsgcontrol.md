# CryptMsgControl function

## Description

The **CryptMsgControl** function performs a control operation after a message has been decoded by a final
call to the [CryptMsgUpdate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgupdate) function. The control operations provided by this function are used for decryption, signature and hash verification, and the addition and deletion of certificates, [certificate revocation lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRLs), signers, and unauthenticated attributes.

Important changes that affect the handling of enveloped messages have been made to CryptoAPI to support [Secure/Multipurpose Internet Mail Extensions](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (S/MIME) email interoperability. For more information, see the Remarks for
the [CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode) function.

## Parameters

### `hCryptMsg` [in]

A handle of a cryptographic message for which a control is to be applied.

### `dwFlags` [in]

The following value is defined when the *dwCtrlType* parameter is one of the following:

* CMSG_CTRL_DECRYPT
* CMSG_CTRL_KEY_TRANS_DECRYPT
* CMSG_CTRL_KEY_AGREE_DECRYPT
* CMSG_CTRL_MAIL_LIST_DECRYPT

| Value | Meaning |
| --- | --- |
| **CMSG_CRYPT_RELEASE_CONTEXT_FLAG** | The handle to the cryptographic provider is released on the final call to the [CryptMsgClose](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgclose) function. This handle is not released if the **CryptMsgControl** function fails. |

If the *dwCtrlType* parameter does not specify a decrypt operation, set this value to zero.

### `dwCtrlType` [in]

The type of operation to be performed. Currently defined message control types and the type of structure that should be passed to the *pvCtrlPara* parameter are shown in the following table.

| Value | Meaning |
| --- | --- |
| **CMSG_CTRL_ADD_ATTR_CERT**<br><br>14 (0xE) | A [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) that contains the encoded bytes of attribute certificate. |
| **CMSG_CTRL_ADD_CERT**<br><br>10 (0xA) | A [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the encoded bytes of the certificate to be added to the message. |
| **CMSG_CTRL_ADD_CMS_SIGNER_INFO**<br><br>20 (0x14) | A [CMSG_CMS_SIGNER_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_cms_signer_info) structure that contains signer information. This operation differs from **CMSG_CTRL_ADD_SIGNER** because the signer information contains the signature. |
| **CMSG_CTRL_ADD_CRL**<br><br>12 (0xC) | A BLOB that contains the encoded bytes of the CRL to be added to the message. |
| **CMSG_CTRL_ADD_SIGNER**<br><br>6 (0x6) | A [CMSG_SIGNER_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signer_encode_info) structure that contains the signer information to be added to the message. |
| **CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR**<br><br>8 (0x8) | A [CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cmsg_ctrl_add_signer_unauth_attr_para) structure that contains the index of the signer and a BLOB that contains the unauthenticated attribute information to be added to the message. |
| **CMSG_CTRL_DECRYPT**<br><br>2 (0x2) | A [CMSG_CTRL_DECRYPT_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_ctrl_decrypt_para) structure used to decrypt the message for the specified key transport recipient. This value is applicable to RSA recipients. This operation specifies that the **CryptMsgControl** function search the recipient index to obtain the key transport recipient information. If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return **CRYPT_E_INVALID_INDEX** if no key transport recipient is found. |
| **CMSG_CTRL_DEL_ATTR_CERT**<br><br>15 (0xF) | The index of the attribute certificate to be removed. |
| **CMSG_CTRL_DEL_CERT**<br><br>11 (0xB) | The index of the certificate to be deleted from the message. |
| **CMSG_CTRL_DEL_CRL**<br><br>13 (0xD) | The index of the CRL to be deleted from the message. |
| **CMSG_CTRL_DEL_SIGNER**<br><br>7 (0x7) | The index of the signer to be deleted. |
| **CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR**<br><br>9 (0x9) | A [CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cmsg_ctrl_del_signer_unauth_attr_para) structure that contains an index that specifies the signer and the index that specifies the signer's unauthenticated attribute to be deleted. |
| **CMSG_CTRL_ENABLE_STRONG_SIGNATURE**<br><br>21 (0x15) | A [CERT_STRONG_SIGN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_strong_sign_para) structure used to perform strong signature checking.<br><br>To check for a strong signature, specify this control type before calling [CryptMsgGetAndVerifySigner](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsggetandverifysigner) or before calling **CryptMsgControl** with the following control types set:<br><br>* **CMSG_CTRL_VERIFY_SIGNATURE**<br>* **CMSG_CTRL_VERIFY_SIGNATURE_EX**<br><br>After the signature is successfully verified, this function checks for a strong signature. If the signature is not strong, the operation will fail and the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) value will be set to **NTE_BAD_ALGID**. |
| **CMSG_CTRL_KEY_AGREE_DECRYPT**<br><br>17 (0x11) | A [CMSG_CTRL_KEY_AGREE_DECRYPT_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_ctrl_key_agree_decrypt_para) structure used to decrypt the message for the specified key agreement session key. Key agreement is used with Diffie-Hellman encryption/decryption. |
| **CMSG_CTRL_KEY_TRANS_DECRYPT**<br><br>16 (0x10) | A [CMSG_CTRL_KEY_TRANS_DECRYPT_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_ctrl_key_trans_decrypt_para) structure used to decrypt the message for the specified key transport recipient. Key transport is used with RSA encryption/decryption. |
| **CMSG_CTRL_MAIL_LIST_DECRYPT**<br><br>18 (0x12) | A [CMSG_CTRL_MAIL_LIST_DECRYPT_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_ctrl_mail_list_decrypt_para) structure used to decrypt the message for the specified recipient using a previously distributed key-encryption key (KEK). |
| **CMSG_CTRL_VERIFY_HASH**<br><br>5 (0x5) | This value is not used. |
| **CMSG_CTRL_VERIFY_SIGNATURE**<br><br>1 (0x1) | A [CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure that identifies the signer of the message whose signature is to be verified. |
| **CMSG_CTRL_VERIFY_SIGNATURE_EX**<br><br>19 (0x13) | A [CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cmsg_ctrl_verify_signature_ex_para) structure that specifies the signer index and public key to verify the message signature. The signer public key can be a [CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure, a certificate context, or a certificate chain context. |

### `pvCtrlPara` [in]

A pointer to a structure determined by the value of *dwCtrlType*.

| *dwCtrlType* value | Meaning |
| --- | --- |
| **CMSG_CTRL_DECRYPT, CMSG_CTRL_KEY_TRANS_DECRYPT, CMSG_CTRL_KEY_AGREE_DECRYPT, or CMSG_CTRL_MAIL_LIST_DECRYPT, and the streamed enveloped message is being decoded** | Decoding will be done as if the streamed content were being decrypted. If any encrypted streamed content has accumulated prior to this call, some or all of the [plaintext](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) that results from the decryption of the cipher text is passed back to the application through the callback function specified in the call to the [CryptMsgOpenToDecode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentodecode) function.<br><br>**Note** When streaming an enveloped message, the **CryptMsgControl** function is not called until the polling for the availability of the CMSG_ENVELOPE_ALGORITHM_PARAM succeeds. If the polling does not succeed, an error results. For a description of that polling, see the [CryptMsgOpenToDecode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentodecode) function. |
| **CMSG_CTRL_VERIFY_HASH** | The [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) computed from the content of the message is compared against the hash contained in the message. |
| **CMSG_CTRL_ADD_SIGNER** | *pvCtrlPara* points to a [CMSG_SIGNER_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signer_encode_info) structure that contains the signer information to be added to the message. |
| **CMSG_CTRL_DEL_SIGNER** | After a deletion is made, any other signer indices in use for this message are no longer valid and must be reacquired by calling the [CryptMsgGetParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsggetparam) function. |
| **CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR** | After a deletion is made, any other unauthenticated attribute indices in use for this signer are no longer valid and must be reacquired by calling the [CryptMsgGetParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsggetparam) function. |
| **CMSG_CTRL_DEL_CERT** | After a deletion is made, any other certificate indices in use for this message are no longer valid and must be reacquired by calling the [CryptMsgGetParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsggetparam) function. |
| **CMSG_CTRL_DEL_CRL** | After a deletion is made, any other CRL indices in use for this message are no longer valid and will need to be reacquired by calling the [CryptMsgGetParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsggetparam) function. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero and the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

When a streamed, enveloped message is being decoded, errors encountered in the application-defined callback function specified by the *pStreamInfo* parameter of the
[CryptMsgOpenToDecode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentodecode) function might be propagated to the **CryptMsgControl** function. If this happens, the [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) function is not called by the **CryptMsgControl** function after the callback function returns. This preserves any errors encountered under the control of the application. It is the responsibility of the callback function (or one of the APIs that it calls) to call the **SetLastError** function if an error occurs while the application is processing the streamed data.

Propagated errors might be encountered from the following functions:

* [CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash)
* [CryptDecrypt](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecrypt)
* [CryptGetHashParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgethashparam)
* [CryptGetUserKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetuserkey)
* [CryptHashData](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashdata)
* [CryptImportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportkey)
* [CryptSignHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignhasha)
* [CryptVerifySignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifysignaturea)

The following error codes are most commonly returned.

| Return code | Description |
| --- | --- |
| **CRYPT_E_ALREADY_DECRYPTED** | The message content has already been decrypted. This error can be returned if the *dwCtrlType* parameter is set to CMSG_CTRL_DECRYPT. |
| **CRYPT_E_AUTH_ATTR_MISSING** | The message does not contain an expected authenticated attribute. This error can be returned if the *dwCtrlType* parameter is set to CMSG_CTRL_VERIFY_SIGNATURE. |
| **CRYPT_E_BAD_ENCODE** | An error was encountered while encoding or decoding. This error can be returned if the *dwCtrlType* parameter is set to CMSG_CTRL_VERIFY_SIGNATURE. |
| **CRYPT_E_CONTROL_TYPE** | The control type is not valid. |
| **CRYPT_E_HASH_VALUE** | The hash value is incorrect. |
| **CRYPT_E_INVALID_INDEX** | The index value is not valid. |
| **CRYPT_E_INVALID_MSG_TYPE** | The message type is not valid. |
| **CRYPT_E_OID_FORMAT** | The object identifier is badly formatted. This error can be returned if the *dwCtrlType* parameter is set to CMSG_CTRL_ADD_SIGNER. |
| **CRYPT_E_RECIPIENT_NOT_FOUND** | The enveloped data message does not contain the specified recipient. This error can be returned if the *dwCtrlType* parameter is set to CMSG_CTRL_DECRYPT. |
| **CRYPT_E_SIGNER_NOT_FOUND** | The specified signer for the message was not found. This error can be returned if the *dwCtrlType* parameter is set to CMSG_CTRL_VERIFY_SIGNATURE. |
| **CRYPT_E_UNKNOWN_ALGO** | The cryptographic algorithm is unknown. |
| **CRYPT_E_UNEXPECTED_ENCODING** | The message is not encoded as expected. This error can be returned if the *dwCtrlType* parameter is set to CMSG_CTRL_VERIFY_SIGNATURE. |
| **E_INVALIDARG** | One or more arguments are not valid. This error can be returned if the *dwCtrlType* parameter is set to CMSG_CTRL_DECRYPT. |
| **E_OUTOFMEMORY** | Not enough memory was available to complete the operation. |

## See also

[Low-level Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)