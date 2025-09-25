# KERB_PURGE_TKT_CACHE_REQUEST structure

## Description

The **KERB_PURGE_TKT_CACHE_REQUEST** structure contains information used to delete entries from the ticket cache.

It is used by
[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage).

## Members

### `MessageType`

[KERB_PROTOCOL_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-kerb_protocol_message_type) value identifying the type of request being made. This member must be set to **KerbPurgeTicketCacheMessage**.

### `LogonId`

[LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid) structure containing the [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) identifier. This can be zero for the current user's logon session. If not zero, the caller must have the SeTcbPrivilege privilege set. If this fails, the [Kerberos](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) authentication package sets the *ProtocolStatus* parameter of [LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) to **STATUS_ACCESS_DENIED**.

### `ServerName`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the name of the service whose tickets should be deleted from the cache.

### `RealmName`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the name of the realm whose tickets should be deleted from the cache.

## Remarks

If both **ServerName** and **RealmName** are of zero length, [LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) will delete all tickets for the logon session identified by **LogonId**. Otherwise, **LsaCallAuthenticationPackage** will search the cache tickets for **ServerName**@**RealmName**, and will delete all such tickets.

[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) does not return this buffer. It returns STATUS_SUCCESS if one or more tickets are deleted. If no tickets are found, the function returns SEC_E_NO_CREDENTIALS.