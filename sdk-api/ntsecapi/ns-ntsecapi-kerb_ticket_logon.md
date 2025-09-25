# KERB_TICKET_LOGON structure

## Description

The **KERB_TICKET_LOGON** structure contains profile information for a network logon.

It is used by the
[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser) function.

## Members

### `MessageType`

[KERB_LOGON_SUBMIT_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-kerb_logon_submit_type) value identifying the type of logon request being made. This member must be set to **KerbTicketLogon**.

### `Flags`

**ULONG** that can be set to KERB_LOGON_FLAG_ALLOW_EXPIRED_TICKET to allow a locked workstation to re-logon with expired ticket. Other values are ignored.

### `ServiceTicketLength`

Indicates the length of the **ServiceTicket** buffer.

### `TicketGrantingTicketLength`

Indicates the length of the **TicketGrantingTicket** buffer. Must be set to zero for an empty buffer.

### `ServiceTicket`

Required ticket for service "host" or the computer account [service principal name](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SPN) in the form of an [ASN.1](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) encoded Kerberos ticket. Expired tickets are acceptable if the **Flags** member is set to KERB_LOGON_FLAG_ALLOW_EXPIRED_TICKET.

### `TicketGrantingTicket`

Optional buffer containing an ASN.1-encoded KRB_CRED message containing the user's Kerberos ticket-granting ticket (KRBTGT) to be used to initialize the credential cache. The ticket must have the "forwarded" flag set in the ticket options. The KRB_CRED message is defined in Section 5.8 of Internet [RFC 4120](http://www.ietf.org/rfc/rfc4120.txt). For more information, see [http://www.ietf.org](https://www.ietf.org/).

## Remarks

The service ticket must be for the host SPN of the computer. If the ticket includes a Windows Privilege Attribute Certificate (PAC), it will be used to construct the user's logon token. Otherwise, an anonymous token will be created using the client principal name in the ticket.

If a ticket-granting ticket (TGT) is supplied as a KRB_CRED message, it is placed in the [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) credentials cache. If the TGT is omitted, the logon will be only for the local machine.