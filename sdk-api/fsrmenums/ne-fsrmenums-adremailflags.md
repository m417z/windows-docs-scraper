# AdrEmailFlags enumeration

## Description

Describes the options for access denied remediation (ADR) email.

## Constants

### `AdrEmailFlags_PutDataOwnerOnToLine:0x1`

The ADR email will include the owner on the To: line.

### `AdrEmailFlags_PutAdminOnToLine:0x2`

The ADR email will include the administrator on the To: line.

### `AdrEmailFlags_IncludeDeviceClaims:0x4`

The ADR email will include the device claims.

### `AdrEmailFlags_IncludeUserInfo:0x8`

The ADR email will include the user information.

### `AdrEmailFlags_GenerateEventLog:0x10`

When the ADR email is sent, an entry will be added to the event log.

## See also

[FSRM Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-enumerations)