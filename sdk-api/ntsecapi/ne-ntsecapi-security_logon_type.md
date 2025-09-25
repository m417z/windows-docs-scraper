# SECURITY_LOGON_TYPE enumeration

## Description

The **SECURITY_LOGON_TYPE** enumeration indicates the type of logon requested by a logon process.

## Constants

### `UndefinedLogonType:0`

### `Interactive:2`

The [security principal](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) is logging on interactively.

### `Network`

The security principal is logging using a network.

### `Batch`

The logon is for a batch process.

### `Service`

The logon is for a service account.

### `Proxy`

Not supported.

### `Unlock`

The logon is an attempt to unlock a workstation.

### `NetworkCleartext`

The logon is a network logon with plaintext credentials.

### `NewCredentials`

Allows the caller to clone its current token and specify new credentials for outbound connections. The new logon session has the same local identity but uses different credentials for other network connections.

### `RemoteInteractive`

A terminal server session that is both remote and interactive.

### `CachedInteractive`

Attempt to use the cached credentials without going out across the network.

### `CachedRemoteInteractive`

Same as **RemoteInteractive**, except used internally for auditing purposes.

### `CachedUnlock`

The logon is an attempt to unlock a workstation.