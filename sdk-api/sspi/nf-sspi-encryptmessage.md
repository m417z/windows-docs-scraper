# EncryptMessage function

## Description

The **EncryptMessage (Digest)** function encrypts a message to provide [privacy](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). **EncryptMessage (Digest)** allows the application to choose among [cryptographic algorithms](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) supported by the chosen mechanism. The **EncryptMessage (Digest)** function uses the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) referenced by the context handle. Some packages do not have messages to be encrypted or decrypted but rather provide an integrity [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) that can be checked.

This function is available as a SASL mechanism only.

**Note** **EncryptMessage (Digest)** and [DecryptMessage (Digest)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-decryptmessage) can be called at the same time from two different threads in a single [Security Support Provider Interface](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSPI) context if one thread is encrypting and the other is decrypting. If more than one thread is encrypting, or more than one thread is decrypting, each thread should obtain a unique context.

## Parameters

### `phContext` [in]

A handle to the security [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to be used to encrypt the message.

### `fQOP` [in]

Package-specific flags that indicate the quality of protection. A [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) can use this parameter to enable the selection of cryptographic algorithms.

When using the Digest SSP, this parameter must be set to zero.

### `pMessage` [in, out]

A pointer to a
[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc) structure. On input, the structure references one or more
[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structures that can be of type SECBUFFER_DATA. That buffer contains the message to be encrypted. The message is encrypted in place, overwriting the original contents of the structure.

The function does not process buffers with the SECBUFFER_READONLY attribute.

The length of the
[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structure that contains the message must be no greater than **cbMaximumMessage**, which is obtained from the
[QueryContextAttributes (Digest)](https://learn.microsoft.com/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig) (SECPKG_ATTR_STREAM_SIZES) function.

When using the Digest SSP, there must be a second buffer of type SECBUFFER_PADDING or SEC_BUFFER_DATA to hold [signature](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) information. To get the size of the output buffer, call the
[QueryContextAttributes (Digest)](https://learn.microsoft.com/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig) function and specify SECPKG_ATTR_SIZES. The function will return a
[SecPkgContext_Sizes](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_sizes) structure. The size of the output buffer is the sum of the values in the **cbMaxSignature** and **cbBlockSize** members.

Applications that do not use SSL must supply a [SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) of type SECBUFFER_PADDING.

### `MessageSeqNo` [in]

The sequence number that the transport application assigned to the message. If the transport application does not maintain sequence numbers, this parameter must be zero.

When using the Digest SSP, this parameter must be set to zero. The Digest SSP manages sequence numbering internally.

## Return value

If the function succeeds, the function returns SEC_E_OK.

If the function fails, it returns one of the following error codes.

| Return code | Description |
| --- | --- |
| **SEC_E_BUFFER_TOO_SMALL** | The output buffer is too small. For more information, see Remarks. |
| **SEC_E_CONTEXT_EXPIRED** | The application is referencing a context that has already been closed. A properly written application should not receive this error. |
| **SEC_E_CRYPTO_SYSTEM_INVALID** | The [cipher](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) chosen for the security context is not supported. |
| **SEC_E_INSUFFICIENT_MEMORY** | There is not enough memory available to complete the requested action. |
| **SEC_E_INVALID_HANDLE** | A context handle that is not valid was specified in the *phContext* parameter. |
| **SEC_E_INVALID_TOKEN** | No SECBUFFER_DATA type buffer was found. |
| **SEC_E_QOP_NOT_SUPPORTED** | Neither confidentiality nor [integrity](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) are supported by the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). |

## Remarks

The **EncryptMessage (Digest)** function encrypts a message based on the message and the [session key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) from a [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

If the transport application created the security context to support sequence detection and the caller provides a sequence number, the function includes this information with the encrypted message. Including this information protects against replay, insertion, and suppression of messages. The [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) incorporates the sequence number passed down from the transport application.

When you use the Digest SSP, get the size of the output buffer by calling the [QueryContextAttributes (Digest)](https://learn.microsoft.com/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig) function and specifying SECPKG_ATTR_SIZES. The function will return a [SecPkgContext_Sizes](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_sizes) structure. The size of the output buffer is the sum of the values in the **cbMaxSignature** and **cbBlockSize** members.

**Note** These buffers must be supplied in the order shown.

| Buffer type | Description |
| --- | --- |
| SECBUFFER_STREAM_HEADER | Used internally. No initialization required. |
| SECBUFFER_DATA | Contains the [plaintext](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) message to be encrypted. |
| SECBUFFER_STREAM_TRAILER | Used internally. No initialization required. |
| SECBUFFER_EMPTY | Used internally. No initialization required. Size can be zero. |

For optimal performance, the *pMessage* structures should be allocated from contiguous memory.

**Windows XP:** This function was also known as **SealMessage**. Applications should now use **EncryptMessage (Digest)** only.

## See also

[AcceptSecurityContext (Digest)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext)

[DecryptMessage (Digest)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-decryptmessage)

[InitializeSecurityContext (Digest)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta)

[QueryContextAttributes (Digest)](https://learn.microsoft.com/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig)

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)

[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer)

[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc)