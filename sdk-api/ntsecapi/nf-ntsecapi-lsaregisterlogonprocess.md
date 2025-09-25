# LsaRegisterLogonProcess function

## Description

The **LsaRegisterLogonProcess** function establishes a connection to the LSA server and verifies that the caller is a logon application.

## Parameters

### `LogonProcessName` [in]

Pointer to an
[LSA_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_string) structure identifying the logon application. This should be a printable name suitable for display to administrators. For example, the Windows logon application might use the name "User32LogonProcess". This name is used by the LSA during auditing. **LsaRegisterLogonProcess** does not check whether the name is already in use.

This string must not exceed 127 bytes.

### `LsaHandle` [out]

Pointer that receives a handle used in future authentication function calls.

### `SecurityMode` [out]

The value returned is not meaningful and should be ignored.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code. The following are possible error codes.

| Return code | Description |
| --- | --- |
| **STATUS_PORT_CONNECTION_REFUSED** | The caller does not have the SeTcbPrivilege privilege, which is required to call this function. <br><br>You can set this privilege by calling [LsaAddAccountRights](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaaddaccountrights). |
| **STATUS_NAME_TOO_LONG** | The specified logon process name exceeds 127 bytes. |

For more information, see
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

The
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function converts an NTSTATUS code to a Windows error code.

## Remarks

This function must be called before a logon process may use any other logon authentication functions provided by the LSA.

The **LsaRegisterLogonProcess** function verifies that the application making the function call is a logon process by checking that it has the SeTcbPrivilege privilege set. It also opens the application's process for PROCESS_DUP_HANDLE access in anticipation of future LSA authentication calls. For more information, see
[DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle).

When you have finished using the connection to the LSA server, delete the caller's logon application context and close the connection by calling the [LsaDeregisterLogonProcess](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaderegisterlogonprocess) function.

## See also

[LsaAddAccountRights](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaaddaccountrights)

[LsaConnectUntrusted](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaconnectuntrusted)

[LsaDeregisterLogonProcess](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaderegisterlogonprocess)