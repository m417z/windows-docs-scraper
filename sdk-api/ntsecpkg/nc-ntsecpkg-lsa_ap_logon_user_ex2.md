# LSA_AP_LOGON_USER_EX2 callback function

## Description

Used to authenticate a user logon attempt on the user's initial logon.
A new logon session is established for the user, and validation information for the user is returned.

## Parameters

### `ClientRequest` [in]

Pointer to a
[LSA_CLIENT_REQUEST](https://learn.microsoft.com/windows/desktop/SecAuthN/plsa-client-request) opaque buffer representing the client's request.

### `LogonType` [in]

[SECURITY_LOGON_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-security_logon_type) value that identifies the type of logon.

### `ProtocolSubmitBuffer` [in]

Buffer that supplies the authentication information specific to the authentication package.

### `ClientBufferBase` [in]

Buffer that provides the address within the client process at which the authentication information was resident. This might be necessary to fix any pointers within the authentication information buffer.

### `SubmitBufferSize` [in]

A **ULONG** value that indicates the size, in bytes, of the authentication information buffer.

### `ProfileBuffer` [out]

Pointer that receives the address of the profile buffer in the client process. The authentication package is responsible for allocating *ProfileBuffer* within the client process by calling the
[AllocateClientBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_client_buffer) function. However, if the LSA subsequently encounters an error which prevents a successful logon, then the LSA will take care of freeing this buffer.

The contents of this buffer are determined by the authentication package. The LSA does not alter this buffer; it simply returns the value to the
[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser) function.

### `ProfileBufferSize` [out]

Pointer to a **ULONG** that receives the size of the *ProfileBuffer* buffer.

### `LogonId` [out]

Pointer to an
[LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid) variable that receives the new logon ID that uniquely identifies this logon session. The authentication package is responsible for allocating this **LUID** and creating the LSA logon session for this logon.

### `SubStatus` [out]

Pointer to an NTSTATUS that receives the reason for failures due to account restrictions. The values returned in *SubStatus* are determined by the authentication package.

The following table lists the *SubStatus* values for the MSV1_0 and Kerberos authentication packages.

| Value | Meaning |
| --- | --- |
| **STATUS_INVALID_LOGON_HOURS** | The user account has time restrictions; it cannot be used to log on at this time. |
| **STATUS_INVALID_WORKSTATION** | The user account has workstation restrictions; it cannot be used to log on to the current workstation. |
| **STATUS_PASSWORD_EXPIRED** | The user account password has expired. |
| **STATUS_ACCOUNT_DISABLED** | The user account is currently disabled and cannot be used to log on. |

More information about NTSTATUS codes can be found in the Subauth.h header file shipped with the Platform SDK.

The
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function converts an NTSTATUS code to a Windows error code.

### `TokenInformationType` [out]

Pointer that receives the address of an
[LSA_TOKEN_INFORMATION_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ne-ntsecpkg-lsa_token_information_type) value that indicates the type of information returned for inclusion in the token to be created. The information is returned by means of the *TokenInformation* parameter.

### `TokenInformation` [out]

Pointer that receives the address of information to be included in the token. The format and content of *TokenInformation* are indicated by the *TokenInformationType* parameter. Your authentication package is responsible for allocating the memory used by *TokenInformation*; however, this memory will be freed by the LSA.

### `AccountName` [out]

Pointer to an
[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that receives the name of the user account. *AccountName* must always be returned regardless of the success or failure of the call; its string is included in the audit record for an authentication attempt. Your authentication package is responsible for allocating the memory used by *AccountName*; however, this memory will be freed by the LSA.

### `AuthenticatingAuthority` [out]

Optional. Pointer to an
[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that receives the description of the authenticating authority for the logon. This parameter may be **NULL**. This string is included in the audit record for an authentication attempt. Your authentication package is responsible for allocating the memory used by *AuthenticatingAuthority*; however, this memory will be freed by the LSA.

The MSV1_0 authentication package returns the domain name of the domain validating the account. The Kerberos authentication package returns the NetBIOS domain name.

### `MachineName` [out]

Optional. Pointer that receives the address of a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure containing the name of the client's computer. This string may optionally be omitted. This string is included in the audit record for this authentication attempt. Your authentication package is responsible for allocating the memory used by *MachineName*; however, this memory will be freed by the LSA.

The MSV1_0 authentication package returns the NetBIOS name of the client's workstation.

### `PrimaryCredentials` [out]

Pointer to a
[SECPKG_PRIMARY_CRED](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_primary_cred) structure that returns primary credentials for handing to other packages.

### `SupplementalCredentials` [out]

Pointer to a
[SECPKG_SUPPLEMENTAL_CRED_ARRAY](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_supplemental_cred_array) array of supplemental credentials for other packages.

## Return value

If the function succeeds, it should return STATUS_SUCCESS.

Otherwise, it should return an NTSTATUS error code, which can be one of the following values or one of the
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

| Return code | Description |
| --- | --- |
| **STATUS_QUOTA_EXCEEDED** | The logon could not be completed because the client's memory quota is insufficient to allocate the return buffer. |
| **STATUS_NO_LOGON_SERVERS** | No domain controllers are available to service the authentication request. |
| **STATUS_LOGON_FAILURE** | The logon attempt failed. The reason for failure is not specified; typical reasons include misspelled user names and passwords. |
| **STATUS_ACCOUNT_RESTRICTION** | The user account and password were legitimate, but user account restrictions preventing successful logon at this time. For additional information see the *SubStatus* parameter. |
| **STATUS_BAD_VALIDATION_CLASS** | The authentication information provided is not recognized by the authentication package. |
| **STATUS_INVALID_LOGON_TYPE** | *LogonType* was not valid. |
| **STATUS_LOGON_SESSION_COLLISION** | The logon ID selected for this logon session (in the *LogonId* parameter) already exists. |
| **STATUS_NETLOGON_NOT_STARTED** | The SAM database or Netlogon service is required, but is not available. |
| **STATUS_NO_MEMORY** | The client's virtual memory or pagefile quotas are insufficient to allocate the return buffer. |

Calling applications can use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the NTSTATUS code to a Windows error code.

## Remarks

Authentication packages must implement one of the following functions:
[LsaApLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_logon_user),
[LsaApLogonUserEx](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_logon_user_ex), or **LsaApLogonUserEx2**.

## See also

[LSA_CLIENT_REQUEST](https://learn.microsoft.com/windows/desktop/SecAuthN/plsa-client-request)

[LSA_TOKEN_INFORMATION_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ne-ntsecpkg-lsa_token_information_type)

[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string)

[LsaApLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_logon_user)

[LsaApLogonUserEx](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_logon_user_ex)

[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage)