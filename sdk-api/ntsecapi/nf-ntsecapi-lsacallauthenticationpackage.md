# LsaCallAuthenticationPackage function

## Description

The **LsaCallAuthenticationPackage** function is used by a logon application to communicate with an authentication package.

This function is typically used to access services provided by the authentication package.

## Parameters

### `LsaHandle` [in]

A handle obtained from a previous call to
[LsaRegisterLogonProcess](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaregisterlogonprocess) or
[LsaConnectUntrusted](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaconnectuntrusted).

### `AuthenticationPackage` [in]

Supplies the identifier of the authentication package. This value is obtained by calling
[LsaLookupAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupauthenticationpackage).

### `ProtocolSubmitBuffer` [in]

An authentication package–specific message buffer passed to the authentication package.

For information about the format and content of this buffer, see the documentation for the individual authentication package.

### `SubmitBufferLength` [in]

Indicates the length, in bytes, of the *ProtocolSubmitBuffer* buffer.

### `ProtocolReturnBuffer` [out]

A pointer that receives the address of the buffer returned by the authentication package.

For information about the format and content of this buffer, see the documentation for the individual authentication package.

This buffer is allocated by this function. When you have finished using this buffer, free the memory by calling the [LsaFreeReturnBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreereturnbuffer) function.

### `ReturnBufferLength` [out]

A pointer to a **ULONG** that receives the length of the returned buffer, in bytes.

### `ProtocolStatus` [out]

If the function succeeds, this parameter receives an **NTSTATUS** code that indicates the completion status of the authentication package.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS. Check the *ProtocolStatus* parameter to obtain the status returned by the authentication package.

If the function fails, the return value is an **NTSTATUS** code. The following are possible error codes.

| Return code | Description |
| --- | --- |
| **STATUS_QUOTA_EXCEEDED** | The call could not be completed because the client's memory quota is not sufficient to allocate the return buffer. |
| **STATUS_NO_SUCH_PACKAGE** | The specified authentication package is not recognized by the LSA. |
| **STATUS_PKINIT_FAILURE** | The Kerberos client received a KDC certificate that is not valid. For device logon, strict KDC validation is required, so the KDC must have certificates that use the "Kerberos Authentication" template or equivalent. Also the KDC certificate could be expired, revoked, or the client is under active attack of sending requests to the wrong server. |
| **STATUS_PKINIT_CLIENT_FAILURE** | The Kerberos client is using a system certificate that is not valid. For device logon, there must be a DNS name. Also, the system certificate could be expired or the wrong one could be selected. |

For more information, see
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

The
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function converts an **NTSTATUS** code to a Windows error code.

## Remarks

Logon applications can call **LsaCallAuthenticationPackage** to communicate with an authentication package. There are several reasons why an application may do this:

* To implement multiple-message authentication protocols, such as the NTLM Challenge-Response protocol.
* To pass state change information to the authentication package. For example, the NTLM might notify the MSV1_0 package that a previously unreachable domain controller is now reachable. The authentication package would then re-logon any users logged on to that domain controller.

Typically, this function is used to exchange information with a custom authentication package. This function is not needed by an application that is using one of the authentication packages supplied with Windows, such as MSV1_0 or Kerberos.

You must call **LsaCallAuthenticationPackage** to clean up PKINIT device credentials for LOCAL_SYSTEM and NETWORK_SERVICE. When there is no PKINIT device credential, a successful call does no operation. When there is a PKINIT device credential, a successful call cleans up the PKINIT device credential so that only the password credential remains.

## See also

[LsaFreeReturnBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreereturnbuffer)

[LsaLookupAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupauthenticationpackage)

[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror)