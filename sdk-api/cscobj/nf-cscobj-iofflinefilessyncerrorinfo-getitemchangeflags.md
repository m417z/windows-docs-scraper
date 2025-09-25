# IOfflineFilesSyncErrorInfo::GetItemChangeFlags

## Description

Retrieves a value containing a set of flags that describe what changes were encountered during the sync operation associated with the sync error.

## Parameters

### `pdwItemChangeFlags` [out]

Receives a set of flags describing what changes were encountered during the sync operation. This parameter can be one or more of the following flag values:

#### OFFLINEFILES_SYNC_ITEM_CHANGE_NONE (0x00000000)

No changes were detected.

#### OFFLINEFILES_SYNC_ITEM_CHANGE_CHANGETIME (0x00000001)

The item's last-change time was found to be different between client and server.

#### OFFLINEFILES_SYNC_ITEM_CHANGE_WRITETIME (0x00000002)

The item's write time was found to be different between client and server.

#### OFFLINEFILES_SYNC_ITEM_CHANGE_FILESIZE (0x00000004)

The item's size was found to be different between client and server.

#### OFFLINEFILES_SYNC_ITEM_CHANGE_ATTRIBUTES (0x00000008)

One or more of the item's attributes were found to be different between client and server.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## See also

[IOfflineFilesSyncErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessyncerrorinfo)