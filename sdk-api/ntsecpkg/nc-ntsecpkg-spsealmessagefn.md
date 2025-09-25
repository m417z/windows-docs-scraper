# SpSealMessageFn callback function

## Description

Encrypts a message exchanged between a client and server.

The **SpSealMessage** function is the dispatch function for the
[EncryptMessage (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-encryptmessage) function of the
[Security Support Provider Interface](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi).

## Parameters

### `ContextHandle` [in]

Handle of the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) used to sign the message.

### `QualityOfProtection` [in]

Specifies package-specific flags that indicate the quality of protection. An SSP/AP can use this parameter to enable the selection of cryptographic algorithms.

### `MessageBuffers` [in, out]

Pointer to a
[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc) structure that contains message buffers. Only one of these message buffers can be of type SECBUFFER_DATA, and it contains the message to be encrypted. The buffer cannot have the SECBUFFER_READONLY attribute because the encryption is done in-place.

### `MessageSequenceNumber` [in]

Sequence number to assign to the message. Sequence numbers are optional and are used as protection against loss and insertion of messages. A value of zero indicates that sequence numbers are not in use.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed. The following table lists common reasons for failure and the error codes that the function should return.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_HANDLE** | The context could not be found or was not configured for message integrity. |
| **STATUS_INVALID_PARAMETER** | The signature buffer could not be found or was too small. |

## Remarks

Messages encrypted by the sender using the **SpSealMessage** function are decrypted using the
[SpUnsealMessage](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spunsealmessagefn) function.

SSP/APs must implement the **SpSealMessage** function; however, the actual name given to the implementation is up to the developer.

A pointer to the **SpSealMessage** function is available in the
[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table) structure received from the
[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn) function.

## See also

[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table)

[SpUnsealMessage](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spunsealmessagefn)

[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn)