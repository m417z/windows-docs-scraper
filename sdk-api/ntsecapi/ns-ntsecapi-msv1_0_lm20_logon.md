# MSV1_0_LM20_LOGON structure

## Description

The **MSV1_0_LM20_LOGON** structure contains logon information used in network logons.

It is used by
[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser).

## Members

### `MessageType`

A [MSV1_0_LOGON_SUBMIT_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-msv1_0_logon_submit_type) value that specifies the type of logon being requested. This member must be set to **MsV1_0Lm20Logon** or **MsV1_0NetworkLogon**.

If this member is set to **MsV1_0Lm20Logon**, the MSV1_0 package ignores the **ParameterControl** member.

### `LogonDomainName`

A [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that contains the name of the logon domain. The specified domain name must be a Windows domain (or mixed domain) that is in the trusted domain list of this computer. If the logon domain name is not known (for example, for clients that do not supply this information), this member should be passed in as a zero-length string. This domain is the authenticating authority.

### `UserName`

A [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that represents the account name of the user. The name can be up to 255 bytes long. The name is treated as case insensitive.

### `Workstation`

A [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that contains the computer name of the client workstation from which the user logon request was initiated.

### `ChallengeToClient`

Contains the challenge returned from a previous call to
[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage), when **MsV1_0Lm20ChallengeRequest** was specified as the message type. For more information, see the description of **MsV1_0Lm20ChallengeRequest** in
[MSV1_0_PROTOCOL_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-msv1_0_protocol_message_type). This enables the [authentication package](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) to determine whether the challenge response is correct.

### `CaseSensitiveChallengeResponse`

Contains some function of the case-sensitive [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) password of the client. Typically, it will be the **ChallengeToClient** member encrypted by a case-sensitive version of the password.

Some clients will simply supply the [plaintext](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) case-sensitive [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) password. In that case, this member points to that *plaintext* password. The
[MSV1_0 Authentication Package](https://learn.microsoft.com/windows/desktop/SecAuthN/msv1-0-authentication-package) may accept this nonencrypted form depending on a configuration option.

Some clients do not support case-sensitive [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) passwords. In that case, this member should contain a zero-length string.

### `CaseInsensitiveChallengeResponse`

Contains some function of the case-insensitive multiple-byte character set (MBCS) password of the client. Typically, it will be the **ChallengeToClient** member encrypted by a case-insensitive version of the password.

Clients that support only MBCS and not [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) supply a [plaintext](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) case-insensitive MBCS password. In that case, this member points to that *plaintext* password. The MSV1_0 authentication package will accept this nonencrypted form depending on a configuration option.

### `ParameterControl`

Specifies attributes of the other parameters. This can be one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **MSV1_0_CLEARTEXT_PASSWORD_ALLOWED**<br><br>02 | LanMan2.0 or LanMan1.0 send a [plaintext](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) password instead of a challenge response. To allow plaintext passwords to be used in the NetworkLogon message, an application must supply this flag. |
| **MSV1_0_UPDATE_LOGON_STATISTICS**<br><br>04 | Update the logon statistics for the account. If this flag is not set, the bad password count is set to zero upon successful logon. |
| **MSV1_0_RETURN_USER_PARAMETERS**<br><br>08 | If this flag is specified, the **UserParameters** member of the [MSV1_0_LM20_LOGON_PROFILE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-msv1_0_lm20_logon_profile) return buffer is valid. |
| **MSV1_0_DONT_TRY_GUEST_ACCOUNT**<br><br>10 | Prevents the user from logging on with a guest account. |
| **MSV1_0_ALLOW_SERVER_TRUST_ACCOUNT**<br><br>20 | If this flag is set, domain controller accounts can be used for authentication; otherwise, only user accounts can be used. |
| **MSV1_0_RETURN_PASSWORD_EXPIRY**<br><br>40 | Causes the password expiration time to be returned in the **LogoffTime** member of the [MSV1_0_LM20_LOGON_PROFILE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-msv1_0_lm20_logon_profile) structure returned in the output buffer. |
| **MSV1_0_USE_CLIENT_CHALLENGE**<br><br>80 | Denotes that the CaseInsensitiveChallengeResponse contains a client challenge in the first 8 bytes. |
| **MSV1_0_TRY_GUEST_ACCOUNT_ONLY**<br><br>100 | Causes the user to log on using the guest account. |
| **MSV1_0_RETURN_PROFILE_PATH**<br><br>200 | Returns the profile path for [Encrypting File System](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) (EFS). The profile path is used by EFS to locate the profile of the user and find the user's keys for encrypting and decrypting files. This information is not returned to the caller; it is stored within the LSA and used by internal processes. |
| **MSV1_0_TRY_SPECIFIED_DOMAIN_ONLY**<br><br>400 | In normal operation, the **LogonDomainName** member is used as a suggestion. The package (using the NetLogon service) will continue passing the logon request to domain controllers higher in the trusted domain path until one authoritatively rejects the logon.<br><br>This flag overrides that behavior so that only the specified domain controller will attempt to process the logon. If **LogonDomainName** is blank, the logon will not be attempted. |
| **MSV1_0_ALLOW_WORKSTATION_TRUST_ACCOUNT**<br><br>800 | Permits remote-boot clients to log on using a computer account. |
| **MSV1_0_CLEARTEXT_PASSWORD_SUPPLIED**<br><br>4000 | Permits the user of a clear text password.<br><br>**Windows XP and Windows Server 2003:** Not supported. |
| **MSV1_0_USE_DOMAIN_FOR_ROUTING_ONLY**<br><br>8000 | Permits the domain to be used for routing only. <br><br>**Windows XP and Windows Server 2003:** Not supported. |
| **MSV1_0_ALLOW_MSVCHAPV2**<br><br>10000 | Permits SubAuthentication log on.<br><br>**Windows XP and Windows Server 2003:** Not supported. |
| **MSV1_0_S4U2SELF**<br><br>20000 | Permits S4U clients to log on without a password.<br><br>**Windows Vista, Windows Server 2003 with SP2, Windows XP and Windows Server 2003:** Not supported. |
| **MSV1_0_CHECK_LOGONHOURS_FOR_S4U**<br><br>40000 | Check the log on hours for a S4U log on client.<br><br>**Windows Vista, Windows Server 2003 with SP2, Windows XP and Windows Server 2003:** Not supported. |
| **MSV1_0_INTERNET_DOMAIN**<br><br>80000 | Permits log on for Internet users. This flag should be used by calls from authentication packages directly and not from netlogon.<br><br>**Windows 7, Windows Server 2008 R2, Windows Vista, Windows Server 2008, Windows XP and Windows Server 2003:** Not supported. |

## Remarks

If the **UserName**, **CaseSensitiveChallengeResponse**, and **CaseInsensitiveChallengeResponse** members all contain zero-length strings, an anonymous token will be generated for the logon. This anonymous token gives the user no ability to access protected system resources but does allow access to nonprotected system resources. The server uses this method to support a **NULL** session.

## See also

[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage)

[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser)

[MSV1_0_LM20_LOGON_PROFILE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-msv1_0_lm20_logon_profile)

[MSV1_0_LOGON_SUBMIT_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-msv1_0_logon_submit_type)

[MSV1_0_PROTOCOL_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-msv1_0_protocol_message_type)