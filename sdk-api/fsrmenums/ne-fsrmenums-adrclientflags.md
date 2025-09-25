# AdrClientFlags enumeration

## Description

Enumerates flags for indicating why an access denied remediation (ADR) client operation could not be
performed.

## Constants

### `AdrClientFlags_None:0`

No ADR client flags are specified.

### `AdrClientFlags_FailForLocalPaths:0x1`

ADR client operations should fail when local paths are specified.

### `AdrClientFlags_FailIfNotSupportedByServer:0x2`

ADR client operations should fail if the operation is not supported by the server.

### `AdrClientFlags_FailIfNotDomainJoined:0x4`

ADR client operations should fail if the computer is not joined to a domain.

## See also

[FSRM Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-enumerations)