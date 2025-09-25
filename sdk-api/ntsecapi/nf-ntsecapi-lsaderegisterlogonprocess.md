# LsaDeregisterLogonProcess function

## Description

The **LsaDeregisterLogonProcess** function deletes the caller's logon application context and closes the connection to the LSA server.

## Parameters

### `LsaHandle` [in]

Handle obtained from a
[LsaRegisterLogonProcess](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaregisterlogonprocess) or
[LsaConnectUntrusted](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaconnectuntrusted) call.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code. For more information, see
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

The
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function converts an NTSTATUS code to a Windows error code.

## Remarks

If your logon application references the connection handle after calling the **LsaDeregisterLogonProcess** function, unexpected behavior can result.

## See also

[LsaConnectUntrusted](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaconnectuntrusted)

[LsaRegisterLogonProcess](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaregisterlogonprocess)