# KERB_LOGON_SUBMIT_TYPE enumeration

## Description

The **KERB_LOGON_SUBMIT_TYPE** enumeration identifies the type of logon being requested.

## Constants

### `KerbInteractiveLogon:2`

Perform an interactive logon.

### `KerbSmartCardLogon:6`

Logon using a smart card.

### `KerbWorkstationUnlockLogon:7`

Unlock a workstation.

### `KerbSmartCardUnlockLogon:8`

Unlock a workstation using a smart card.

### `KerbProxyLogon:9`

Logon using a proxy server.

### `KerbTicketLogon:10`

Logon using a valid [Kerberos](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) ticket as a credential.

### `KerbTicketUnlockLogon:11`

Unlock a workstation by using a Kerberos ticket.

### `KerbS4ULogon:12`

Perform a service for user logon.

### `KerbCertificateLogon:13`

Logon interactively using a certificate stored on a smart card.

### `KerbCertificateS4ULogon:14`

Perform a service for user logon using a certificate stored on a smart card.

### `KerbCertificateUnlockLogon:15`

Unlock a workstation using a certificate stored on a smart card.

### `KerbNoElevationLogon:83`

### `KerbLuidLogon:84`