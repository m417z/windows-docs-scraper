# KERB_EXTERNAL_TICKET structure

## Description

The **KERB_EXTERNAL_TICKET** structure contains information about an external ticket.

An external ticket is a [Kerberos](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) ticket exported to external users. The Kerberos ticket is defined in Internet [RFC 4120](http://www.ietf.org/rfc/rfc4120.txt). For more information, see [http://www.ietf.org](https://www.ietf.org/). This structure is used by the
[KERB_RETRIEVE_TKT_RESPONSE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_retrieve_tkt_response) structure.

## Members

### `ServiceName`

A [KERB_EXTERNAL_NAME](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_external_name) structure that contains a multiple part, canonical, returned service name.

### `TargetName`

A [KERB_EXTERNAL_NAME](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_external_name) structure that contains the multiple part [service principal name](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SPN).

### `ClientName`

A [KERB_EXTERNAL_NAME](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_external_name) structure that contains the client name in the ticket. This name is relative to the current domain.

### `DomainName`

A
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that contains the name of the domain that corresponds to the **ServiceName** member. This is the domain that issued the ticket.

### `TargetDomainName`

A [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that contains the name of the domain in which the ticket is valid. For an interdomain ticket, this is the destination domain.

### `AltTargetDomainName`

A [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that contains a synonym for the destination domain. Every domain has two names: a DNS name and a NetBIOS name. If the name returned in the ticket is different from the name used to request the ticket (the Kerberos [Key Distribution Center](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) (KDC) may do name mapping), this string contains the original name.

### `SessionKey`

A [KERB_CRYPTO_KEY](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_crypto_key) structure that contains the [session key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) for the ticket.

### `TicketFlags`

Ticket flags, as defined in Internet [RFC 4120](http://www.ietf.org/rfc/rfc4120.txt). This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **KERB_TICKET_FLAGS_forwardable (0x40000000)** | The ticket-granting server can issue a new ticket-granting ticket with a different network address, based on the presented ticket. |
| **KERB_TICKET_FLAGS_forwarded (0x20000000)** | The ticket has either been forwarded or was issued based on authentication that involved a forwarded ticket-granting ticket. |
| **KERB_TICKET_FLAGS_hw_authent (0x00100000)** | The protocol employed for initial authentication required the use of hardware expected to be possessed solely by the named client. The hardware authentication method is selected by the KDC, and the strength of the method is not indicated. |
| **KERB_TICKET_FLAGS_initial (0x00400000)** | The ticket was issued by using the Authentication Service protocol instead of being based on a ticket-granting ticket. |
| **KERB_TICKET_FLAGS_invalid (0x01000000)** | The ticket is not valid. |
| **KERB_TICKET_FLAGS_may_postdate (0x04000000)** | Indicates to the ticket-granting server that a postdated ticket can be issued based on this ticket-granting ticket. |
| **KERB_TICKET_FLAGS_ok_as_delegate (0x00040000)** | The target of the ticket is trusted by the directory service for delegation. Thus, the clients may delegate their [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to the server, which lets the server act as the client when talking to other services. |
| **KERB_TICKET_FLAGS_postdated (0x02000000)** | The ticket has been postdated. The end service can check the ticket's **authtime** member to determine when the original authentication occurred. |
| **KERB_TICKET_FLAGS_pre_authent (0x00200000)** | During initial authentication, the client was authenticated by the KDC before a ticket was issued. The strength of the preauthentication method is not indicated but is acceptable to the KDC. |
| **KERB_TICKET_FLAGS_proxiable (0x10000000)** | Indicates to the ticket-granting server that only nonticket-granting tickets can be issued with different network addresses. |
| **KERB_TICKET_FLAGS_proxy (0x08000000)** | The ticket is a proxy. |
| **KERB_TICKET_FLAGS_renewable (0x00800000)** | The ticket is renewable. If this flag is set, the time limit for renewing the ticket is set in the **RenewTime** member of a [KERB_TICKET_CACHE_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_ticket_cache_info) structure. A renewable ticket can be used to obtain a replacement ticket that expires at a later date. |
| **KERB_TICKET_FLAGS_reserved (0x80000000)** | Reserved for future use. Do not set this flag. |
| **KERB_TICKET_FLAGS_reserved1 (0x00000001)** | Reserved. |

### `Flags`

Reserved for future use. Set this member to zero.

### `KeyExpirationTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the time at which the key expires.

### `StartTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the time at which the ticket becomes valid.

### `EndTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the time at which the ticket expires.

### `RenewUntil`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the latest time a ticket can be renewed. Renewal requests sent after this time will be rejected.

### `TimeSkew`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the measured time difference between the current time on the computer issuing the ticket and the computer where the ticket will be used.

### `EncodedTicketSize`

The size, in bytes, of the encoded ticket.

### `EncodedTicket`

A buffer that contains the [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1)-encoded ticket.