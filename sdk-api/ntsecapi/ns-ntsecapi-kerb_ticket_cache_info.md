# KERB_TICKET_CACHE_INFO structure

## Description

The **KERB_TICKET_CACHE_INFO** structure contains information about a cached [Kerberos](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) ticket. The Kerberos ticket is defined in Internet [RFC 4120](http://www.ietf.org/rfc/rfc4120.txt). For more information, see [http://www.ietf.org](https://www.ietf.org/).

It can be used both for retrieving tickets and querying the ticket cache. The
[KERB_QUERY_TKT_CACHE_RESPONSE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_query_tkt_cache_response) structure uses this structure.

## Members

### `ServerName`

A
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that contains the name of the server the ticket applies to. This name is combined with the **RealmName** value to create the full name **ServerName**@**RealmName**.

### `RealmName`

A [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that contains the name of the realm the ticket applies to.

### `StartTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the time at which the ticket becomes valid. If the **starttime** member of the ticket is not set, this value defaults to the time when the ticket was initially authenticated, **authtime**. The **starttime** member of a ticket is optional.

### `EndTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the time when the ticket expires.

### `RenewTime`

If KERB_TICKET_FLAGS_renewable is set in **TicketFlags**, this member is a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the time beyond which the ticket cannot be renewed.

### `EncryptionType`

The type of encryption used in the ticket.

### `TicketFlags`

The ticket flags, as defined in Internet [RFC 4120](http://www.ietf.org/rfc/rfc4120.txt). These flags can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **KERB_TICKET_FLAGS_forwardable**<br><br>0x40000000 | The ticket-granting server can issue a new ticket-granting ticket with a different network address based on the presented ticket. |
| **KERB_TICKET_FLAGS_forwarded**<br><br>0x20000000 | The ticket has either been forwarded or was issued based on authentication that involved a forwarded ticket-granting ticket. |
| **KERB_TICKET_FLAGS_hw_authent**<br><br>0x00100000 | The protocol employed for initial authentication required the use of hardware expected to be possessed solely by the named client. The hardware authentication method is selected by the KDC and the strength of the method is not indicated. |
| **KERB_TICKET_FLAGS_initial**<br><br>0x00400000 | The ticket was issued by using the Authentication Service protocol instead of being based on a ticket-granting ticket. |
| **KERB_TICKET_FLAGS_invalid**<br><br>0x01000000 | The ticket is not valid. |
| **KERB_TICKET_FLAGS_may_postdate**<br><br>0x04000000 | Indicates to the ticket-granting server that a postdated ticket can be issued based on this ticket-granting ticket. |
| **KERB_TICKET_FLAGS_ok_as_delegate**<br><br>0x00040000 | The target of the ticket is trusted by the directory service for delegation. Thus, clients may delegate their [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to the server, which lets the server act as the client when talking to other services. |
| **KERB_TICKET_FLAGS_postdated**<br><br>0x02000000 | The ticket has been postdated. The end-service can check the ticket's **authtime** member to see when the original authentication occurred. |
| **KERB_TICKET_FLAGS_pre_authent**<br><br>0x00200000 | During initial authentication, the client was authenticated by the [Key Distribution Center](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) (KDC) before a ticket was issued. The strength of the preauthentication method is not indicated, but is acceptable to the KDC. |
| **KERB_TICKET_FLAGS_proxiable**<br><br>0x10000000 | Indicates to the ticket-granting server that only nonticket-granting tickets can be issued based on this ticket but with a different network addresses. |
| **KERB_TICKET_FLAGS_proxy**<br><br>0x08000000 | The ticket is a proxy. |
| **KERB_TICKET_FLAGS_renewable**<br><br>0x00800000 | The ticket is renewable. If this flag is set, the time limit for renewing the ticket is set in **RenewTime**. A renewable ticket can be used to obtain a replacement ticket that expires at a later date. |
| **KERB_TICKET_FLAGS_reserved**<br><br>0x80000000 | Reserved for future use. Do not set this flag. |
| **KERB_TICKET_FLAGS_reserved1**<br><br>0x00000001 | Reserved. |