# FWP_TOKEN_INFORMATION structure

## Description

The **FWP_TOKEN_INFORMATION** structure defines a set of security identifiers that are used for user-mode classification.

## Members

### `sidCount`

The number of [SID_AND_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_and_attributes) structures stored in the **sids** array.

### `sids`

An array of [SID_AND_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_and_attributes) structures containing user and group security information.

### `restrictedSidCount`

The number of [SID_AND_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_and_attributes) structures stored in the **restrictedSids** array.

### `restrictedSids`

An array of [SID_AND_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_and_attributes) structures containing restricted SIDs security information.