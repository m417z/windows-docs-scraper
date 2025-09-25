# MSV1_0_LM20_LOGON_PROFILE structure

## Description

The **MSV1_0_LM20_LOGON_PROFILE** structure contains information about a network [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly).

It is used by
[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser).

## Members

### `MessageType`

[MSV1_0_PROFILE_BUFFER_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-msv1_0_profile_buffer_type) value identifying the type of logon requested. The type of logon determines the format and content of the profile data returned. This member must be set to **MsV1_0LM20LogonProfile**.

### `KickOffTime`

Time when the system should force user logoff. This is an absolute-format Windows standard time value.

### `LogoffTime`

Time when the user should log off. This is an absolute-format Windows standard time value.

### `UserFlags`

Specifies the way the user established the session. **UserFlags** can contain one or more of the following values.

| Value | Meaning |
| --- | --- |
| **LOGON_GUEST** | The user logged onto a guest account. |
| **LOGON_NOENCRYPTION** | The user logged on without using password encryption. |
| **LOGON_CACHED_ACCOUNT** | The user logged on using cached [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). |
| **LOGON_USED_LM_PASSWORD** | The user logged on using an LM password instead of a Windows password. An LM password is the [hashed](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) version of the MBCS upper-cased password.<br><br>The Windows password is the hashed version of the [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) password.<br><br>The caller may need to know which type of password was used to determine the corresponding [session key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (**LanmanSessionKey** or UserSessionKey). |
| **LOGON_EXTRA_SIDS** | SIDs from a domain other than the user's logon domain were sent back from the user's domain controller. This information is used internally by the LSA. |
| **LOGON_SUBAUTH_SESSION_KEY** | The user logged on using a [subauthentication](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) session key. |
| **LOGON_SERVER_TRUST_ACCOUNT** | The user logged on using a trusted server account. |
| **LOGON_PROFILE_PATH_RETURNED** | The profile path in the profile in the **UserParameters** member is valid. |
| **LOGON_RESOURCE_GROUPS** | The user logged on using resource groups. |

**Note** The high-order byte of **UserFlags** is reserved for return flags from [subauthentication packages](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). The flags returned by a subauthentication package are package specific. For more information, see the documentation for the subauthentication package.

### `UserSessionKey`

Contains a [session key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) specific to the session and user. This session key can be used to encrypt and decrypt information sent between the client and server. This string is MSV1_0_USER_SESSION_KEY_LENGTH characters long. The array is not null-terminated and can contain embedded null characters.

### `LogonDomainName`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the name of the logon domain.

### `LanmanSessionKey`

Contains the Lanman session key. This string is MSV1_0_LANMAN_SESSION_KEY_LENGTH characters long. It is not null-terminated and can contain embedded null characters.

### `LogonServer`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the name of the server that processed the logon request.

### `UserParameters`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing user parameters. These parameters are primarily used by RAS to store RAS dial-in permissions for the user. In general, developers should not modify this member.

## See also

[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser)

[MSV1_0_PROFILE_BUFFER_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-msv1_0_profile_buffer_type)