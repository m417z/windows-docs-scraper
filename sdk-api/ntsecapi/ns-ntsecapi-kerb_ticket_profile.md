# KERB_TICKET_PROFILE structure

## Description

The **KERB_TICKET_PROFILE** structure contains information about an interactive logon profile.

This structure is returned by
[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser).

## Members

### `Profile`

[KERB_INTERACTIVE_PROFILE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_interactive_profile) structure containing logon information.

### `SessionKey`

[KERB_CRYPTO_KEY](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_crypto_key) structure containing the [session key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) for the Kerberos ticket.