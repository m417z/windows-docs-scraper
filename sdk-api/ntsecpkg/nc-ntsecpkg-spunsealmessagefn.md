# SpUnsealMessageFn callback function

## Description

Decrypts a message that was previously encrypted with the
[SpSealMessage](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spsealmessagefn) function.

The **SpUnsealMessage** function is the dispatch function for the
[DecryptMessage (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-decryptmessage) function of the
[Security Support Provider Interface](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi).

## Parameters

### `ContextHandle` [in]

Handle of the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) used to seal the message.

### `MessageBuffers` [in]

Pointer to a
[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc) structure that contains the message buffers and a signature buffer.

### `MessageSequenceNumber` [in]

Sequence number to assign to the message. Sequence numbers are optional and are used as protection against loss and insertion of messages. A value of zero indicates that sequence numbers are not in use.

### `QualityOfProtection` [out]

Not used.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed.

## Remarks

SSP/APs must implement the **SpUnsealMessage** function; however, the actual name given to the implementation is up to the developer.

A pointer to the **SpUnsealMessage** function is available in the
[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table) structure received from the
[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn) function.

## See also

[DecryptMessage (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-decryptmessage)

[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table)

[SpSealMessage](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spsealmessagefn)

[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn)