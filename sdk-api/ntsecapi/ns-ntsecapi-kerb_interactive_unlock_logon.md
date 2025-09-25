# KERB_INTERACTIVE_UNLOCK_LOGON structure

## Description

The **KERB_INTERACTIVE_UNLOCK_LOGON** structure contains information used to unlock a workstation that has been locked during an interactive [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly).

## Members

### `Logon`

A [KERB_INTERACTIVE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_interactive_logon) structure that specifies the interactive logon session. The **MessageType** member of the **KERB_INTERACTIVE_LOGON** structure must be set to **KerbWorkstationUnlockLogon**.

### `LogonId`

A [LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid) structure that contains the identity of the user attempting to unlock the workstation.

## See also

[KERB_INTERACTIVE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_interactive_logon)