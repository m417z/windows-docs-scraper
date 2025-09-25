# KERB_RETRIEVE_TKT_RESPONSE structure

## Description

The **KERB_RETRIEVE_TKT_RESPONSE** structure contains the response from retrieving a ticket.

It is used by
[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage).

## Members

### `Ticket`

[KERB_EXTERNAL_TICKET](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_external_ticket) structure containing the requested ticket.