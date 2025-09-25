# LsaLookupAuthenticationPackage function

## Description

The **LsaLookupAuthenticationPackage** function obtains the unique identifier of an authentication package.

## Parameters

### `LsaHandle` [in]

Handle obtained from a previous call to
[LsaRegisterLogonProcess](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaregisterlogonprocess) or
[LsaConnectUntrusted](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaconnectuntrusted).

### `PackageName` [in]

Pointer to an
[LSA_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_string) structure that specifies the name of the authentication package. The package name must not exceed 127 bytes in length. The following table lists the names of the Microsoft-provided authentication packages.

| Value | Meaning |
| --- | --- |
| **MSV1_0_PACKAGE_NAME** | ANSI version of the MSV1_0 authentication package name. |
| **MICROSOFT_KERBEROS_NAME_A** | ANSI version of the Kerberos authentication package name. |
| **NEGOSSP_NAME_A** | ANSI version of the Negotiate authentication package name. |

### `AuthenticationPackage` [out]

Pointer to a **ULONG** that receives the authentication package identifier.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code. The following are possible error codes.

| Return code | Description |
| --- | --- |
| **STATUS_NO_SUCH_PACKAGE** | The specified authentication package is unknown to the LSA. |
| **STATUS_NAME_TOO_LONG** | The authentication package name exceeds 127 bytes. |

For more information, see
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

The
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function converts an NTSTATUS code to a Windows error code.

## Remarks

The authentication package identifier is used in calls to authentication functions such as
[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser) and
[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage).

## See also

[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage)

[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser)