# SpValidateTargetInfoFn callback function

## Description

Validates that the specified [SECPKG_TARGETINFO](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_targetinfo) structure represents a valid target.

## Parameters

### `ClientRequest` [in, optional]

A pointer to an opaque
[LSA_CLIENT_REQUEST](https://learn.microsoft.com/windows/desktop/SecAuthN/plsa-client-request) data structure that contains information about the LSA client's authentication request. A custom authentication package should pass in the value received during the client's call to the function, such as
[LsaApCallPackage](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_call_package) or
[LsaApLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_logon_user), that returns the output parameter.

### `ProtocolSubmitBuffer` [in]

A pointer to the input buffer sent by the client.

### `ClientBufferBase` [in]

The base address of the input buffer, in the client's address space.

### `SubmitBufferLength` [in]

The size, in bytes, of the *ProtocolSubmitBuffer* buffer.

### `TargetInfo` [in]

A pointer to a [SECPKG_TARGETINFO](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_targetinfo) structure that specifies the target to validate.

## Return value

If the function succeeds and the specified target is a valid target, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed.

## Remarks

SSP/APs must implement the **SpValidateTargetInfo** function; however, the actual name given to the implementation is up to the developer.

A pointer to the **SpValidateTargetInfo** function is available in the
[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table) structure received from the
[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn) function.

## See also

[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table)