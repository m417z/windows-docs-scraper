# LsaLogonUser function

## Description

The **LsaLogonUser** function authenticates a [security principal's](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) logon data by using stored credentials information.

If the authentication is successful, this function creates a new logon session and returns a user token.

When a new ticket granting ticket (TGT) is obtained by using new certificate credentials, then all of the system's TGTs and service tickets are purged. Any user service tickets that are of a compound identity are also purged.

## Parameters

### `LsaHandle` [in]

A handle obtained from a previous call to
[LsaRegisterLogonProcess](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaregisterlogonprocess).

The caller is required to have **SeTcbPrivilege** only if one or more of the following is true:

* A Subauthentication package is used.
* [KERB_S4U_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_s4u_logon) is used, and the caller requests an impersonation token.
* The *LocalGroups* parameter is not **NULL**.

If **SeTcbPrivilege** is not required, call [LsaConnectUntrusted](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaconnectuntrusted) to obtain the handle.

### `OriginName` [in]

A string that identifies the origin of the logon attempt. For more information, see Remarks.

### `LogonType` [in]

A
value of the [SECURITY_LOGON_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-security_logon_type) enumeration that specifies the type of logon requested. If *LogonType* is Interactive or Batch, a primary token is generated to represent the new user. If *LogonType* is Network, an impersonation token is generated.

### `AuthenticationPackage` [in]

An identifier of the authentication package to use for the authentication. You can obtain this value by calling
[LsaLookupAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupauthenticationpackage).

### `AuthenticationInformation` [in]

A pointer to an input buffer that contains authentication information, such as user name and password. The format and content of this buffer are determined by the authentication package.

This parameter can be one of the following input buffer structures for the MSV1_0 and Kerberos authentication packages.

| Value | Meaning |
| --- | --- |
| **[MSV1_0_INTERACTIVE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-msv1_0_interactive_logon)**<br><br>MSV1_0 | Authenticating an interactive user logon.<br><br>The **LogonDomainName**, **UserName**, and **Password**  members of the [MSV1_0_INTERACTIVE_LOGON](https://learn.microsoft.com/windows/win32/api/ntsecapi/ns-ntsecapi-msv1_0_interactive_logon) structure must point to buffers in memory that are contiguous to the structure itself. The value of the *AuthenticationInformationLength* parameter must take into account the length of these buffers. |
| **[KERB_INTERACTIVE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_interactive_logon)**<br><br>Kerberos | Authenticating an interactive user logon. |
| **[KERB_TICKET_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_ticket_logon)**<br><br>Kerberos | Authenticating a user on initial network logon or disconnect. |
| **[KERB_TICKET_UNLOCK_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_ticket_unlock_logon)**<br><br>Kerberos | Authenticating a user on ticket refresh, a variation of the normal workstation unlock logon. |
| **[KERB_CERTIFICATE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_certificate_logon)**<br><br>Kerberos | Authenticating a user using an interactive smart card logon. |
| **[KERB_CERTIFICATE_S4U_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_certificate_s4u_logon)**<br><br>Kerberos | Authenticating a user using a service for user (S4U) logon. |
| **[KERB_CERTIFICATE_UNLOCK_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_certificate_unlock_logon)**<br><br>Kerberos | Authenticating a user to unlock a workstation that has been locked during an interactive smart card logon session. |
| **[KERB_SMARTCARD_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_smart_card_logon)**<br><br>Kerberos | Authenticating a user smart card logon using LOGON32_PROVIDER_WINNT50 or LOGON32_PROVIDER_DEFAULT. |
| **[KERB_SMARTCARD_UNLOCK_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_smart_card_unlock_logon)**<br><br>Kerberos | Authenticating a user to unlock a workstation that has been locked during a smart card logon session. |
| **[KERB_S4U_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_s4u_logon)**<br><br>Kerberos | Authenticating a user using S4U client requests. For [constrained delegation](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), a call to LsaLogonUser is not necessary if the client logged on using an LSA-mode authentication package. On Windows operating systems, these include [Kerberos](https://learn.microsoft.com/windows/desktop/SecAuthN/microsoft-kerberos), [NTLM](https://learn.microsoft.com/windows/desktop/SecAuthN/microsoft-ntlm), [Secure Channel](https://learn.microsoft.com/windows/desktop/SecAuthN/secure-channel), and [Digest](https://learn.microsoft.com/windows/desktop/SecAuthN/microsoft-digest-ssp). For this call to succeed, the following must be true:<br><br>* The caller must be a domain account (this includes LOCAL_SYSTEM if the computer is a domain member).<br>* If using a service account, the account must have **SeTcbPrivilege** set on the local computer to get an impersonation token. Otherwise, the identity token is used.<br>* The caller must be a member of the **Pre-Windows 2000 Compatible Access** or have read access to the group memberships of the client. Membership in the Windows Authorization Access group guarantees read access to group membership of the client. For information about how to configure the Windows Authorization Access group, see the Microsoft Knowledge Base.<br><br>The **ClientUpn** and **ClientRealm** members of the [KERB_S4U_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_s4u_logon) structure must point to buffers in memory that are contiguous to the structure itself. The value of the *AuthenticationInformationLength* parameter must take into account the length of these buffers. |
| **[MSV1_0_LM20_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-msv1_0_lm20_logon)**<br><br>MSV1_0 | Processing the second half of an NTLM 2.0 protocol logon. The first half of this type of logon is performed by calling [LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) with the **MsV1_0Lm20ChallengeRequest** message. For more information, see the description of **MsV1_0Lm20ChallengeRequest** in [MSV1_0_PROTOCOL_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-msv1_0_protocol_message_type).<br><br>This type of logon can use a subauthentication package. |
| **[MSV1_0_SUBAUTH_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-msv1_0_subauth_logon)**<br><br>MSV1_0 | Authenticating a user with subauthentication. |

For more information about the buffer used by other authentication packages, see the documentation for those authentication packages.

### `AuthenticationInformationLength` [in]

The length, in bytes, of the *AuthenticationInformation* buffer.

### `LocalGroups` [in, optional]

A list of additional group identifiers to add to the token of the authenticated user. These group identifiers will be added, along with the default group WORLD and the logon type group (Interactive, Batch, or Network), which are automatically included in every user token.

### `SourceContext` [in]

A [TOKEN_SOURCE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_source) structure that identifies the source module—for example, the session manager—and the context that may be useful to that module. This information is included in the user token and can be retrieved by calling
[GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation).

### `ProfileBuffer` [out]

A pointer to a void pointer that receives the address of an output buffer that contains authentication information, such as the logon shell and home directory.

This parameter can be one of the following output buffer structures for the MSV1_0 and Kerberos authentication packages.

| Value | Meaning |
| --- | --- |
| **MSV1_0_INTERACTIVE_PROFILE**<br><br>MSV1_0 | An interactive user's logon profile. |
| **KERB_TICKET_PROFILE**<br><br>Kerberos | Logon, disconnect, and ticket refresh authentication output. |
| **MSV1_0_LM20_LOGON**<br><br>MSV1_0 | Output when processing the second half of a NTLM 2.0 protocol logon. |
| **MSV1_0_LM20_LOGON_PROFILE**<br><br>MSV1_0 | Output when using authentication with subauthentication. |

For more information about the buffer used by other authentication packages, see the documentation for that authentication package.

When this buffer is no longer needed, the calling application must free this buffer by calling
the [LsaFreeReturnBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreereturnbuffer) function.

### `ProfileBufferLength` [out]

A pointer to a **ULONG** that receives the length, in bytes, of the returned profile buffer.

### `LogonId` [out]

A pointer to a buffer that receives an
[LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid) that uniquely identifies the logon session. This **LUID** is assigned by the domain controller that authenticated the logon information.

### `Token` [out]

A pointer to a handle that receives the new user token created for this session. When you have finished using the token, release it by calling the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function.

### `Quotas` [out]

When a primary token is returned, this parameter receives a
[QUOTA_LIMITS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-quota_limits) structure that contains the process quota limits assigned to the newly logged on user's initial process.

### `SubStatus` [out]

If the logon failed due to account restrictions, this parameter receives information about why the logon failed. This value is set only if the account information of the user is valid and the logon is rejected.

This parameter can be one of the following *SubStatus* values for the MSV1_0 authentication package.

| Value | Meaning |
| --- | --- |
| **STATUS_INVALID_LOGON_HOURS** | The user account has time restrictions and cannot be used to log on at this time. |
| **STATUS_INVALID_WORKSTATION** | The user account has workstation restrictions and cannot be used to log on from the current workstation. |
| **STATUS_PASSWORD_EXPIRED** | The user-account password has expired. |
| **STATUS_ACCOUNT_DISABLED** | The user account is currently disabled and cannot be used to log on. |

## Return value

If the function succeeds, the function returns STATUS_SUCCESS.

If the function fails, it returns an **NTSTATUS** code, which can be one of the following values.

| Value | Description |
| --- | --- |
| **STATUS_QUOTA_EXCEEDED** | The caller's memory quota is insufficient to allocate the output buffer returned by the authentication package. |
| **STATUS_ACCOUNT_RESTRICTION** | The user account and password are legitimate, but the user account has a restriction that prevents logon at this time. For more information, see the value stored in the *SubStatus* parameter. |
| **STATUS_BAD_VALIDATION_CLASS** | The authentication information provided is not recognized by the authentication package. |
| **STATUS_LOGON_FAILURE** | The logon attempt failed. The reason for the failure is not specified, but typical reasons include misspelled user names and misspelled passwords. |
| **STATUS_NO_LOGON_SERVERS** | No domain controllers are available to service the authentication request. |
| **STATUS_NO_SUCH_PACKAGE** | The specified authentication package is not recognized by the LSA. |
| **STATUS_PKINIT_FAILURE** | The Kerberos client received a KDC certificate that is not valid. For device logon, strict KDC validation is required, so the KDC must have certificates that use the "Kerberos Authentication" template or equivalent. Also, the KDC certificate could be expired, revoked, or the client is under active attack of sending requests to the wrong server. |
| **STATUS_PKINIT_CLIENT_FAILURE** | The Kerberos client is using a system certificate that is not valid. For device logon, there must be a DNS name. Also, the system certificate could be expired or the wrong one could be selected. |

For more information, see
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

The
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function converts an **NTSTATUS** code to a Windows error code.

## Remarks

The *OriginName* parameter should specify meaningful information. For example, it might contain "TTY1" to indicate terminal one or "NTLM - remote node JAZZ" to indicate a network logon that uses NTLM through a remote node called "JAZZ".

You must call **LsaLogonUser** separately to update PKINIT device credentials for LOCAL_SYSTEM and NETWORK_SERVICE. When there is no PKINIT device credential, a successful call does no operation. When there is a PKINIT device credential, a successful call cleans up the PKINIT device credential so that only the password credential remains.

## See also

[Allowing Anonymous Access](https://learn.microsoft.com/windows/desktop/SecAuthZ/allowing-anonymous-access)

[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage)

[LsaFreeReturnBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreereturnbuffer)

[LsaLookupAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupauthenticationpackage)