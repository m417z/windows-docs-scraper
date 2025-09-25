# Msv1_0SubAuthenticationRoutineGeneric function

## Description

Performs [Remote Access Service](https://learn.microsoft.com/windows/desktop/RRAS/portal) authentication when subauthentication is requested by calling the [LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) function.

The [security principal's](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) credentials and information from the [Security Accounts Manager](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SAM) database are passed to this function for authentication.

This function is implemented by custom subauthentication package DLLs for use with the MSV1_0 authentication package.

This function is called only for a
[noninteractive authentication](https://learn.microsoft.com/windows/desktop/SecAuthN/noninteractive-authentication), only on the authenticating server where the account resides, and only if a subauthentication DLL is registered under the correct key in the registry.

## Parameters

### `SubmitBuffer`

A pointer to a buffer that contains a [MSV1_0_SUBAUTH_REQUEST](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-msv1_0_subauth_request) structure that contains the authentication information to be submitted.

### `SubmitBufferLength`

The size, in bytes, of the *SubmitBuffer* buffer.

### `ReturnBufferLength` [out]

The size, in bytes, of the *ReturnBuffer* buffer.

### `ReturnBuffer` [out]

A pointer to a buffer that contains a [MSV1_0_SUBAUTH_RESPONSE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-msv1_0_subauth_response) structure that contains the response from the subauthentication package.

## Return value

If the function succeeds, the return value is **STATUS_SUCCESS**.

If the function fails, the return value is an NTSTATUS code.

## See also

[Msv1_0SubAuthenticationRoutine](https://learn.microsoft.com/windows/desktop/api/subauth/nf-subauth-msv1_0subauthenticationroutine)