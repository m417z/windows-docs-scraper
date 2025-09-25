# SYNCMGRITEM structure

## Description

Provides information about items being enumerated by the [ISyncMgrEnumItems](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrenumitems) interface.

## Members

### `cbSize`

Type: **DWORD**

The size of the structure.

### `dwFlags`

Type: **DWORD**

One or more values from the [SYNCMGRITEMFLAGS](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgritemflags) enumeration.

### `ItemID`

Type: **GUID**

The identifier for this item.

### `dwItemState`

Type: **DWORD**

Indicates whether this item is included in synchronization operations. This member can have one of the following values.

#### SYNCMGRITEMSTATE_UNCHECKED (0)

The default is not including this item in synchronization operations.

#### SYNCMGRITEMSTATE_CHECKED (1)

The default is including this item in synchronization operations.

### `hIcon`

Type: **HICON**

The icon for this item.

### `wszItemName`

Type: **WCHAR[MAX_SYNCMGRITEMNAME]**

The name of this item.

### `ftLastUpdate`

Type: **FILETIME**

The time of the last synchronization for this item.

## See also

[SYNCMGRITEMFLAGS](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgritemflags)