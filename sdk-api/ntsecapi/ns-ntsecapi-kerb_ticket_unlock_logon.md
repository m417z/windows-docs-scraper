# KERB_TICKET_UNLOCK_LOGON structure

## Description

The **KERB_TICKET_UNLOCK_LOGON** structure contains information to unlock a workstation.

It is used by
[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser).

## Members

### `Logon`

[KERB_TICKET_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_ticket_logon) structure. All members of the structure must be the same as the structure used in the original logon except the [KERB_LOGON_SUBMIT_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-kerb_logon_submit_type) member, which must be set to **KerbTicketUnlockLogon**.

### `LogonId`

[LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid) structure containing the logon identifier of the current [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly). This ID was previously returned from the initial logon by
[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser).