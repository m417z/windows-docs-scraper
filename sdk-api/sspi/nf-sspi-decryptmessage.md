# DecryptMessage function

## Description

The **DecryptMessage (Digest)** function decrypts a message. Some packages do not encrypt and decrypt messages but rather perform and check an integrity [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly).

The Digest [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSP) provides encryption and decryption confidentiality for messages exchanged between client and server as a SASL mechanism only.

**Note** [EncryptMessage (Digest)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-encryptmessage) and **DecryptMessage (Digest)** can be called at the same time from two different threads in a single [Security Support Provider Interface](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSPI) context if one thread is encrypting and the other is decrypting. If more than one thread is encrypting, or more than one thread is decrypting, each thread should obtain a unique context.

## Parameters

### `phContext` [in]

A handle to the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) to be used to decrypt the message.

### `pMessage` [in, out]

A pointer to a
[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc) structure. On input, the structure references one or more
[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structures. At least one of these must be of type SECBUFFER_DATA. That buffer contains the encrypted message. The encrypted message is decrypted in place, overwriting the original contents of its buffer.

When using the Digest SSP, on input, the structure references one or more
[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structures. One of these must be of type SECBUFFER_DATA or SECBUFFER_STREAM, and it must contain the encrypted message.

### `MessageSeqNo` [in]

The sequence number expected by the transport application, if any. If the transport application does not maintain sequence numbers, this parameter must be set to zero.

When using the Digest SSP, this parameter must be set to zero. The Digest SSP manages sequence numbering internally.

### `pfQOP` [out]

A pointer to a variable of type **ULONG** that receives package-specific flags that indicate the quality of protection.

This parameter can be one of the following flags.

| Value | Meaning |
| --- | --- |
| **SECQOP_WRAP_NO_ENCRYPT** | The message was not encrypted, but a header or trailer was produced.<br><br>**Note** KERB_WRAP_NO_ENCRYPT has the same value and the same meaning. |
| **SIGN_ONLY** | When using the Digest SSP, use this flag when the security context is set to verify the [signature](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) only. For more information, see [Quality of Protection](https://learn.microsoft.com/windows/desktop/SecAuthN/quality-of-protection). |

## Return value

If the function verifies that the message was received in the correct sequence, the function returns SEC_E_OK.

If the function fails to decrypt the message, it returns one of the following error codes.

| Return code | Description |
| --- | --- |
| **SEC_E_BUFFER_TOO_SMALL** | The message buffer is too small. Used with the Digest SSP. |
| **SEC_E_CRYPTO_SYSTEM_INVALID** | The cipher chosen for the security context is not supported. Used with the Digest SSP. |
| **SEC_E_INCOMPLETE_MESSAGE** | The data in the input buffer is incomplete. The application needs to read more data from the server and call [DecryptMessage (Digest)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-decryptmessage) again. |
| **SEC_E_INVALID_HANDLE** | A context handle that is not valid was specified in the *phContext* parameter. Used with the Digest SSP. |
| **SEC_E_MESSAGE_ALTERED** | The message has been altered. Used with the Digest SSP. |
| **SEC_E_OUT_OF_SEQUENCE** | The message was not received in the correct sequence. |
| **SEC_E_QOP_NOT_SUPPORTED** | Neither confidentiality nor [integrity](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) are supported by the security context. Used with the Digest SSP. |

## Remarks

Sometimes an application will read data from the remote party, attempt to decrypt it by using **DecryptMessage (Digest)**, and discover that **DecryptMessage (Digest)** succeeded but the output buffers are empty. This is normal behavior, and applications must be able to deal with it.

**Windows XP:** This function was also known as **UnsealMessage**. Applications should now use **DecryptMessage (Digest)** only.

## See also

[EncryptMessage (Digest)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-encryptmessage)

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)

[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer)

[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc)