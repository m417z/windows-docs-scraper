# MSV1_0_SUBAUTH_LOGON structure

## Description

The **MSV1_0_SUBAUTH_LOGON** structure is used by [subauthentication](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) DLLs.

## Members

### `MessageType`

A
[MSV1_0_LOGON_SUBMIT_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-msv1_0_logon_submit_type) value that indicates the type of logon being requested. This value must be set to **MsV1_0SubAuthLogon**.

### `LogonDomainName`

A [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that contains the name of the logon domain. The specified domain name must be a Windows domain or a mixed domain that is trusted by this computer. If the logon domain name is not known (for example, for clients that do not supply this information), this member should be passed in as a zero-length string. This is the authenticating authority.

### `UserName`

A [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that contains the account name of the user. The name can be up to 255 bytes long. The name is treated as case insensitive.

### `Workstation`

A [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that contains the computer name of the workstation where the user logon request was initiated.

### `ChallengeToClient`

Contains the challenge returned from a previous call to
[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage), when **MsV1_0Lm20ChallengeRequest** was specified as the message type. For more information, see the description of **MsV1_0Lm20ChallengeRequest** in
[MSV1_0_PROTOCOL_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-msv1_0_protocol_message_type). This enables the [authentication package](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) to determine whether the challenge response is correct.

### `AuthenticationInfo1`

Contains [subauthentication package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly)–specific information. For more information, see the subauthentication package documentation.

### `AuthenticationInfo2`

Contains subauthentication package specific information. For more information, see the subauthentication package documentation.

### `ParameterControl`

Specifies additional information about how the logon should be processed. This member can contain one or more of the following values.

| Value | Meaning |
| --- | --- |
| **MSV1_0_CLEARTEXT_PASSWORD_ALLOWED** | LanMan2.0 or LanMan1.0 send a [plaintext](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) password instead of a challenge response. To allow plaintext passwords to be used in the NetworkLogon message, an application must supply this flag. |
| **MSV1_0_UPDATE_LOGON_STATISTICS** | Update the logon statistics for the account. If this flag is not set, the bad password count is set to zero upon successful logon. |
| **MSV1_0_RETURN_USER_PARAMETERS** | Causes the user parameters to be returned in the **HomeDirectoryDrive** member of the [MSV1_0_INTERACTIVE_PROFILE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-msv1_0_interactive_profile) structure. |
| **MSV1_0_DONT_TRY_GUEST_ACCOUNT** | Prevents the user from logging on with a guest account. |
| **MSV1_0_ALLOW_SERVER_TRUST_ACCOUNT** | If this flag is set, domain controller accounts can be used for authentication; otherwise, only user accounts can be used. |
| **MSV1_0_RETURN_PASSWORD_EXPIRY** | Causes the password expiration time to be returned in the **LogoffTime** member of the [MSV1_0_LM20_LOGON_PROFILE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-msv1_0_lm20_logon_profile) structure returned in the output buffer. |
| **MSV1_0_ALLOW_WORKSTATION_TRUST_ACCOUNT** | Permits remote-boot clients to log on using a computer account. |
| **MSV1_0_TRY_GUEST_ACCOUNT_ONLY** | Causes the user to log on using the guest account. |
| **MSV1_0_RETURN_PROFILE_PATH** | Returns the profile path associated with the logged on user. |
| **MSV1_0_TRY_SPECIFIED_DOMAIN_ONLY** | Only a domain controller associated with the specified domain will attempt to validate the logon request. |

### `SubAuthPackageId`

Contains the subauthentication package identifier. This value is set by the subauthentication package vendor.

## See also

[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage)

[MSV1_0_INTERACTIVE_PROFILE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-msv1_0_interactive_profile)

[MSV1_0_LM20_LOGON_PROFILE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-msv1_0_lm20_logon_profile)

[MSV1_0_LOGON_SUBMIT_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-msv1_0_logon_submit_type)

[MSV1_0_PROTOCOL_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-msv1_0_protocol_message_type)