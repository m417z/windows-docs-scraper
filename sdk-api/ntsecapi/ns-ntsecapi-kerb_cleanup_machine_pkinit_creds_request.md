# KERB_CLEANUP_MACHINE_PKINIT_CREDS_REQUEST structure

## Description

The **KERB_CLEANUP_MACHINE_PKINIT_CREDS_REQUEST** structure cleans up the PKINIT device credentials from the computer.

## Members

### `MessageType`

The type of the message. You should set this to **KerbCleanupMachinePkinitCredsMessage**.

### `LogonId`

The logon session identifier. You should set this to SYSTEM LUID or NETWORKSERVICE LUID. TCB is required if this field is different from the caller's LUID.

## Remarks

You must clean up PKINIT device credentials for LOCAL_SYSTEM or NETWORK_SERVICE. When the PKINIT device credential is cleaned up, only the password credentials remain.