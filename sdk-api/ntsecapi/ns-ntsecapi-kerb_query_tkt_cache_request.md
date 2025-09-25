# KERB_QUERY_TKT_CACHE_REQUEST structure

## Description

The **KERB_QUERY_TKT_CACHE_REQUEST** structure contains information used to query the ticket cache.

It is used by
[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage).

## Members

### `MessageType`

[KERB_PROTOCOL_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-kerb_protocol_message_type) value identifying the type of request being made. This member must be set to **KerbQueryTicketCacheMessage** or **KerbRetrieveTicketMessage**.

If this member is set to **KerbQueryTicketCacheMessage**, the request is for information about all of the cached tickets for the specified user logon session. If it is set to **KerbRetrieveTicketMessage**, the request is for the ticket granting ticket from the ticket cache of the specified user logon session.

### `LogonId`

[LUID](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-luid) structure containing the [logon session](https://learn.microsoft.com/windows/win32/SecGloss/l-gly) identifier. This can be zero for the current user's logon session. If not zero, the caller must have the SeTcbPrivilege privilege set. If this fails, the [Kerberos](https://learn.microsoft.com/windows/win32/SecGloss/k-gly) authentication package sets the *ProtocolStatus* parameter of [LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/win32/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) to **STATUS_PRIVILEGE_NOT_HELD**.