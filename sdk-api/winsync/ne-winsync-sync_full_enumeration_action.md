# SYNC_FULL_ENUMERATION_ACTION enumeration

## Description

Represents the action to be taken by an application in response to [ISyncCallback::OnFullEnumerationNeeded](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isynccallback).

## Constants

### `SFEA_FULL_ENUMERATION:0`

Perform a full enumeration. This is the default option when the application does not register an [ISyncCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isynccallback) interface.

### `SFEA_PARTIAL_SYNC`

Perform a partial synchronization. When this option is specified, the learned knowledge is applied as single item exceptions.

### `SFEA_ABORT`

Cancel the synchronization session. All methods will return errors as if they were canceled.

## See also

[ISyncCallback::OnFullEnumerationNeeded](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isynccallback-onfullenumerationneeded)

[Windows Sync Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/windows-sync-enumerations)