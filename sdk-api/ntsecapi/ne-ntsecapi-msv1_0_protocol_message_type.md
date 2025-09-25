# MSV1_0_PROTOCOL_MESSAGE_TYPE enumeration

## Description

The **MSV1_0_PROTOCOL_MESSAGE_TYPE** enumeration lists the types of messages that can be sent to the
[MSV1_0 Authentication Package](https://learn.microsoft.com/windows/desktop/SecAuthN/msv1-0-authentication-package) by calling the
[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) function.

 Each message corresponds to a dispatch routine and causes the MSV1_0 authentication package to perform a different task.

## Constants

### `MsV1_0Lm20ChallengeRequest:0`

This dispatch routine serves as the first half of an NTLM version 2.0 protocol logon. The challenge returned by this call may be delivered to the initiating NTLM 2.0 node. When that node responds with a challenge response, a **MsV1_0Lm20Logon** message to the
[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser) function is used to complete the logon. For more information, see
[MSV1_0_LOGON_SUBMIT_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-msv1_0_logon_submit_type).

### `MsV1_0Lm20GetChallengeResponse`

This dispatch routine is used by the NTLM redirector to determine the challenge response to pass to a server when trying to establish a connection to the server.

This routine is passed a challenge from the server. It then encrypts the challenge with either the specified password or with the password implied by the specified [logon identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly). Two challenge responses are returned. One is based on the [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) password as given to the [authentication package](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly). The other is based on that password converted to a multiple-byte character set (for example, ASCII) and uppercase. The redirector should use either (or both) formats of challenge responses as it needs them. The redirector should use the returned challenge responses exactly as returned. No zero byte should be added. A challenge response is binary data and might contain zero bytes within the string.

This routine may indicate that a **NULL** session is to be used. If the redirector specifies all the RETURN_PRIMARY_DOMAINNAME, RETURN_PRIMARY_USERNAME, and USE_PRIMARY_PASSWORD flags, and the [logon ID](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) does not correspond to any interactive [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly), this function returns an empty string for the user name and both challenge responses.

### `MsV1_0EnumerateUsers`

This value is obsolete.

### `MsV1_0GetUserInfo`

This value is obsolete.

### `MsV1_0ReLogonUsers`

This value is not supported.

### `MsV1_0ChangePassword`

This dispatch routine changes the password of an account.

### `MsV1_0ChangeCachedPassword`

 This dispatch routine changes a password in the logon cache. This is used when the password is changed on the domain controller using some other mechanism and the locally cached version needs to be updated to match the new value. For example, RAS handles changing the passwords on the domain but then needs to update the cached copy so the user can still access servers.

### `MsV1_0GenericPassthrough`

 This dispatch routine passes any of the other dispatch routines to the domain controller. The authentication package on the domain controller may choose to reject certain dispatch requests.

### `MsV1_0CacheLogon`

 This dispatch routine caches logon information in the logon cache.

### `MsV1_0SubAuth`

 This dispatch routine is called to submit a buffer to a [subauthentication package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). If the subauthentication is local, use this dispatch routine. If the subauthentication needs to be processed on the domain controller, use the **MsV1_0GenericPassthrough** dispatch routine with
[MSV1_0_SUBAUTH_REQUEST](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-msv1_0_subauth_request) and
[MSV1_0_SUBAUTH_RESPONSE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-msv1_0_subauth_response) buffers.

### `MsV1_0DeriveCredential`

This dispatch routine gets the **HMAC_SHA1** hash of the one-way function password of the current logon session.

### `MsV1_0CacheLookup`

Reserved. Do not use.

### `MsV1_0SetProcessOption`

This dispatch routine sets the password policy. The **SeTcbPrivilege** is required.

### `MsV1_0ConfigLocalAliases`

This dispatch routine adds, deletes, or enumerates registered local aliases. The caller must be a service to use this message type.

**Windows Server 2003 and Windows XP:** Not supported.

### `MsV1_0ClearCachedCredentials`

This dispatch routine clears the credentials in the local NTLM logon cache. The **SeTcbPrivilege** is required.

**Windows Server 2003 and Windows XP:** Not supported.

### `MsV1_0LookupToken`

This dispatch routine looks up the authentication token. The **SeTcbPrivilege** is required.

**Windows Server 2003 with SP2, Windows Vista, Windows Server 2003 and Windows XP:** Not supported.

### `MsV1_0ValidateAuth`

This dispatch routine validates the logon authentication. The **SeTcbPrivilege** is required.

**Windows Server 2008, Windows Vista with SP1, Windows Server 2003 with SP2, Windows Vista, Windows Server 2003 and Windows XP:** Not supported.

### `MsV1_0CacheLookupEx`

This dispatch routine looks up the local logon in the cache. The **SeTcbPrivilege** is required.

**Windows Server 2008, Windows Vista with SP1, Windows Server 2003 with SP2, Windows Vista, Windows Server 2003 and Windows XP:** Not supported.

### `MsV1_0GetCredentialKey`

This dispatch routine gets the credential key of the authentication packet. The **SeTcbPrivilege** is required.

**Windows Server 2008, Windows Vista with SP1, Windows Server 2003 with SP2, Windows Vista, Windows Server 2003 and Windows XP:** Not supported.

### `MsV1_0SetThreadOption`

This dispatch routine sets the features and permissions on the calling thread. Thread options take precedence over process options and should be used in place of NTLM process options. The **SeTcbPrivilege** is required.

**Windows Server 2008, Windows Vista with SP1, Windows Server 2003 with SP2, Windows Vista, Windows Server 2003 and Windows XP:** Not supported.

### `MsV1_0DecryptDpapiMasterKey`

### `MsV1_0GetStrongCredentialKey`

### `MsV1_0TransferCred`

### `MsV1_0ProvisionTbal`

### `MsV1_0DeleteTbalSecrets`