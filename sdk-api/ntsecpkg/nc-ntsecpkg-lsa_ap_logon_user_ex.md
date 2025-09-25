# LSA_AP_LOGON_USER_EX callback function

## Description

Authenticates a user's logon credentials.

 This function is called by the [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) only for a user's initial logon. Subsequent authentication requests must use
[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage). If **LsaApLogonUserEx** succeeds, it creates a logon session and returns information used to build the token representing the newly logged on user.

This function differs from
[LsaApLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_logon_user) in that the machine name is added to the audit record for the logon attempt.

## Parameters

### `ClientRequest` [in]

Pointer to an opaque
[LSA_CLIENT_REQUEST](https://learn.microsoft.com/windows/desktop/SecAuthN/plsa-client-request) data type representing the LSA client's request.

### `LogonType` [in]

A
[SECURITY_LOGON_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-security_logon_type) structure which identifies the type of logon being attempted.

### `AuthenticationInformation` [in]

Supplies the authentication information specific to the authentication package. The LSA will free this buffer.

### `ClientAuthenticationBase` [in]

Provides the address of the authentication information within the client process. This may be necessary to remap any pointers within the *AuthenticationInformation* buffer.

### `AuthenticationInformationLength` [in]

Indicates the length of the *AuthenticationInformation* buffer.

### `ProfileBuffer` [out]

Pointer that receives the address of the profile buffer in the client process. The authentication package is responsible for allocating the *ProfileBuffer* buffer within the client process by calling the
[AllocateClientBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_client_buffer) function. However, if the LSA subsequently encounters an error which prevents a successful logon, then the LSA will take care of freeing this buffer.

The contents of this buffer are determined by the authentication package. The LSA does not alter this buffer; it simply returns the value to the
[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser) function.

### `ProfileBufferLength` [out]

Pointer to a **ULONG** that receives the length of the *ProfileBuffer* buffer, in bytes.

### `LogonId` [out]

Pointer to an
[LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid) variable that receives the new logon ID that uniquely identifies this logon session. The authentication package is responsible for allocating this **LUID** and creating the LSA logon session for this logon.

### `SubStatus` [out]

Pointer to an NTSTATUS that receives the reason for failures due to account restrictions. The values returned in *SubStatus* are determined by the authentication package.

The following are *SubStatus* values for the MSV1_0 and Kerberos authentication packages.

| Value | Meaning |
| --- | --- |
| **STATUS_INVALID_LOGON_HOURS** | The user account has time restrictions and cannot be used to log on at this time. |
| **STATUS_INVALID_WORKSTATION** | The user account has workstation restrictions and cannot be used to log on from the current workstation. |
| **STATUS_PASSWORD_EXPIRED** | The user account password has expired. |
| **STATUS_ACCOUNT_DISABLED** | The user account is currently disabled and cannot be used to log on. |

More information about NTSTATUS codes can be found in the Subauth.h header file shipped with the Platform SDK.

### `TokenInformationType` [out]

Pointer that receives the address of an
[LSA_TOKEN_INFORMATION_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ne-ntsecpkg-lsa_token_information_type) value that indicates the type of information returned for inclusion in the token to be created. The information is returned by means of the *TokenInformation* parameter.

### `TokenInformation` [out]

Pointer that receives the address of information to be included in the token. The format and content of *TokenInformation* are indicated by the *TokenInformationType* parameter. Your authentication package is responsible for allocating the memory used by *TokenInformation*; however, this memory will be freed by the LSA.

### `AccountName` [out]

Pointer to an
[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that receives the name of the user account. *AccountName* must always be returned regardless of the success or failure of the call; its string is included in the audit record for an authentication attempt. Your authentication package is responsible for allocating the memory used by *AccountName* It will be freed by the LSA.

### `AuthenticatingAuthority` [out]

Optional. Pointer to an [LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that receives the description of the authenticating authority for the logon. This parameter may be **NULL**. This string is included in the audit record for an authentication attempt. Your authentication package is responsible for allocating the memory used by *AuthenticatingAuthority*; however, this memory will be freed by the LSA.

The MSV1_0 authentication package returns the domain name of the domain validating the account. The Kerberos authentication package returns the NetBIOS domain name.

### `MachineName` [out]

Optional. Pointer that receives the address of an [LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure containing the name of the client's workstation. This information is included in the audit record for an authentication attempt. Your authentication package is responsible for allocating the memory used by *MachineName*; however, this memory will be freed by the LSA.

The MSV1_0 authentication package returns the NetBIOS name of the client's workstation.

## Return value

If the function succeeds, it should return STATUS_SUCCESS.

Otherwise, it should return an NTSTATUS error code, which can be one of the following values or one of the
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

| Return code | Description |
| --- | --- |
| **STATUS_NO_MEMORY** | The logon could not be completed because the client's memory quota is insufficient to allocate the return buffer. |
| **STATUS_NO_LOGON_SERVERS** | No domain controllers are available to service the authentication request. |
| **STATUS_LOGON_FAILURE** | The logon attempt failed. The reason for failure is not specified; typical reasons include misspelled user names and passwords. |
| **STATUS_ACCOUNT_RESTRICTION** | The user account and password are legitimate, but user account restrictions prevent successful logon at this time. |
| **STATUS_BAD_VALIDATION_CLASS** | The authentication information provided is recognized by the authentication package. |

Calling applications can use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the NTSTATUS code to a Windows error code.

## Remarks

Authentication packages must implement one of the following functions:
[LsaApLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_logon_user), **LsaApLogonUserEx**, or
[LsaApLogonUserEx2](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_logon_user_ex2).

**LsaApLogonUserEx** was added for C2 certification. C2 is a security classification defined by the United States government.

## See also

[LSA_CLIENT_REQUEST](https://learn.microsoft.com/windows/desktop/SecAuthN/plsa-client-request)

[LSA_TOKEN_INFORMATION_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ne-ntsecpkg-lsa_token_information_type)

[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string)

[LsaApLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_logon_user)

[LsaApLogonUserEx2](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_logon_user_ex2)

[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage)