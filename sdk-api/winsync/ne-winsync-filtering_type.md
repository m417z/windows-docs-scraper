# FILTERING_TYPE enumeration

## Description

Indicates the type of information that is included in a change batch during filtered synchronization.

## Constants

### `FT_CURRENT_ITEMS_ONLY:0`

The change batch includes data and metadata for items that are currently in the filter.

### `FT_CURRENT_ITEMS_AND_VERSIONS_FOR_MOVED_OUT_ITEMS`

## Remarks

A replica that does not keep ghosts for items that are not in the filter indicates this by using **FT_CURRENT_ITEMS_ONLY**.

**Note** An item that is excluded by the filter in one replica, but is still tracked in the other replica is known as a "ghost".

## See also

[Windows Sync Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/windows-sync-enumerations)