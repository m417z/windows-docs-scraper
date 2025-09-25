# LsaConnectUntrusted function

## Description

The **LsaConnectUntrusted** function establishes an untrusted connection to the LSA server.

## Parameters

### `LsaHandle` [out]

Pointer to a handle that receives the connection handle, which must be provided in future authentication services.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code. For more information, see
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

The
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function converts an NTSTATUS code to a Windows error code.

## Remarks

**LsaConnectUntrusted** returns a handle to an untrusted connection; it does not verify any information about the caller. The handle should be closed using the
[LsaDeregisterLogonProcess](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaderegisterlogonprocess) function.

If your application simply needs to query information from authentication packages, you can use the handle returned by this function in calls to
[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) and
[LsaLookupAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupauthenticationpackage).

Applications with the SeTcbPrivilege privilege may create a trusted connection by calling
[LsaRegisterLogonProcess](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaregisterlogonprocess).

## See also

[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage)

[LsaDeregisterLogonProcess](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaderegisterlogonprocess)

[LsaLookupAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupauthenticationpackage)

[LsaRegisterLogonProcess](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaregisterlogonprocess)