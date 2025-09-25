# KERB_QUERY_TKT_CACHE_RESPONSE structure

## Description

The **KERB_QUERY_TKT_CACHE_RESPONSE** structure contains the results of querying the ticket cache.

It is used by
[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage).

## Members

### `MessageType`

[KERB_PROTOCOL_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-kerb_protocol_message_type) value identifying the type of request being made. This member must be set to **KerbQueryTicketCacheMessage**.

### `CountOfTickets`

Number of tickets in **Tickets** array. This can be zero if no tickets are available for the specified logon session.

### `Tickets`

Array of length **CountOfTickets** of
[KERB_TICKET_CACHE_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_ticket_cache_info) structures.

## Remarks

This buffer is allocated by the [Kerberos](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) authentication package and should be deleted by the application that called [LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage), using
[LsaFreeReturnBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreereturnbuffer).