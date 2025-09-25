# SYNC_SERIALIZATION_VERSION enumeration

## Description

Represents the version of Microsoft Sync Framework that a particular component is compatible with. For an overview see [Options for Building a Synchronization Provider](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/options-for-building-a-synchronization-provider). Note: this documentation is no longer updated and may contain out of date information.

## Constants

### `SYNC_SERIALIZATION_VERSION_V1:1`

Indicates a component is compatible with Sync Framework 1.0.

### `SYNC_SERIALIZATION_VERSION_V2:4`

Indicates a component is compatible with Sync Framework 2.0.

### `SYNC_SERIALIZATION_VERSION_V3:5`

## Remarks

A component that is designed to work with a particular version of Sync Framework can indicate the version for which it is designed. This way, when Sync Framework changes in later versions, a component designed for an earlier version will continue to function as expected.

## See also

[Windows Sync Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/windows-sync-enumerations)