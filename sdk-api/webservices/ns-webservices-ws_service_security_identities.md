# WS_SERVICE_SECURITY_IDENTITIES structure

## Description

A list of Server Principal Names (SPNs) that are used to validate [Extended Protection](https://learn.microsoft.com/windows/desktop/wsw/extended-protection).

Only available on the server.

## Members

### `serviceIdentities`

A array of strings representing the SPNs accepted by the server. Wildcards are not allowed.

### `serviceIdentityCount`

The number of strings in serviceIdentities.