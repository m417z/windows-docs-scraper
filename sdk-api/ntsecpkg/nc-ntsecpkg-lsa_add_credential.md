# LSA_ADD_CREDENTIAL callback function

## Description

[**AddCredential** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Applications should use the [LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) function with **KerbAddExtraCredentialsMessage** specified as the message type. **KerbAddExtraCredentialsMessage** is a [KERB_PROTOCOL_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-kerb_protocol_message_type) enumeration value.]

Adds credentials to a logon session. These credentials can later be referenced through a call to the
[GetCredentials](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_get_credentials) function.

## Parameters

### `LogonId` [in]

A pointer to an
[LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid) that contains the session ID of the logon session to which credentials are to be added.

### `AuthenticationPackage` [in]

The authentication package ID of the calling authentication package. This value is received in the
[LsaApInitializePackage](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_initialize_package) call during DLL initialization.

### `PrimaryKeyValue` [in]

A string that contains a value that the authentication package will later need to reference as a primary key of the credential data. This can be used, for example, to keep the name of the domain or server the credentials are related to. The format and meaning of this string are specific to the authentication package. Note that the string value does not have to be unique, even for the specified logon session. For example, there can be two passwords for the same domain, each with the passwords stored as credentials and the domain name stored as the primary key.

### `Credentials` [in]

A string that represents the user credentials. The format and meaning of this string are specific to the authentication package.

## Return value

If the function succeeds, the function returns STATUS_SUCCESS.

If the function fails, it returns an **NTSTATUS** code, which can be the following value or one of the
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

| Return code | Description |
| --- | --- |
| **STATUS_NO_SUCH_LOGON_SESSION** | The specified logon session could not be found. |

The
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function converts an **NTSTATUS** code to a Windows error code.

## Remarks

The body of the credential string must be self-relative; that is, it must contain no pointers to memory outside the credentials. Credentials are copied, and any pointers outside the credentials themselves will no longer be valid in the copy. In particular, strings referred to in credentials should have both the UNICODE_STRING header and body placed in the credential buffer. Pointers to strings in the body of credentials should be changed to offsets.

## See also

[GetCredentials](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_get_credentials)

[LSA_DISPATCH_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_dispatch_table)

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)