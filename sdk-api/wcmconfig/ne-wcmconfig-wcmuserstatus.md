# WcmUserStatus enumeration

## Description

Describes the status of the user.

## Constants

### `UnknownStatus:0`

Indicates a problem with the store.

### `UserRegistered:1`

Indicates that the store is registered, but is not currently loaded for use.

### `UserUnregistered:2`

Indicates that the store does not currently exist.

### `UserLoaded:3`

Indicates that the store is registered, loaded, and ready for use.

### `UserUnloaded:4`

This has the same semantics as **UserRegistered**.

## Remarks

**UserUnloaded**, **UserUnregistered**, and **UnknownStatus** should not appear in typical use.