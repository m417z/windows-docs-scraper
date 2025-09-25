# IOfflineFilesItemContainer::EnumItemsEx

## Description

Returns an enumerator of child items for the cache item implementing this method. Server, share, and directory entries in the Offline Files cache implement this method to expose the enumeration of their immediate children. However, a call to [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) to query a file item for **IID_IOfflineFilesItemContainer** fails with **E_NOINTERFACE**, because file items have no children.

This method is similar to [IOfflineFilesItemContainer::EnumItems](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesitemcontainer-enumitems), except that it allows filtering and flat enumeration.

## Parameters

### `pIncludeFileFilter` [in]

If provided, references the filter applied to the decision to include files. This parameter is optional and can be **NULL**.

### `pIncludeDirFilter` [in]

If provided, references the filter applied to the decision to include directories. This parameter is optional and can be **NULL**.

### `pExcludeFileFilter` [in]

If provided, references the filter applied to the decision to exclude files. This parameter is optional and can be **NULL**.

### `pExcludeDirFilter` [in]

If provided, references the filter applied to the decision to exclude directories. This parameter is optional and can be **NULL**.

### `dwEnumFlags` [in]

Flags affecting the type of enumeration performed. The parameter may contain one or more of the following flag bits.

#### OFFLINEFILES_ENUM_FLAT (0x00000001)

If this flag is set, the returned enumerator will enumerate all of the item's descendants in the offline files cache. If this flag is not set, only the item's immediate children are enumerated.

#### OFFLINEFILES_ENUM_FLAT_FILESONLY (0x00000002)

If this flag is set, only file items are returned in the enumeration. Server, share, and directory entries are not included. This flag has no effect if the **OFFLINEFILES_ENUM_FLAT** flag is not set.

### `dwQueryFlags` [in]

Flags affecting the amount of query activity at the time of enumeration. The parameter can contain one or more of the following bit flags.

#### OFFLINEFILES_ITEM_QUERY_REMOTEINFO (0x00000001)

This flag is reserved for future use.

#### OFFLINEFILES_ITEM_QUERY_CONNECTIONSTATE (0x00000002)

If this flag is set, the enumeration operation includes an extra call to the Offline Files store to obtain information about the connection state (online or offline) of the item. If this flag is not set, enumeration does not include this extra operation.

#### OFFLINEFILES_ITEM_QUERY_LOCALDIRTYBYTECOUNT (0x00000004)

If this flag is set, the find operation includes an extra call to the Offline Files store to obtain information about the amount, in bytes, of unsynchronized ("dirty") data for the associated file in the local Offline Files cache.

#### OFFLINEFILES_ITEM_QUERY_REMOTEDIRTYBYTECOUNT (0x00000008)

This flag is reserved for future use.

#### OFFLINEFILES_ITEM_QUERY_INCLUDETRANSPARENTCACHE (0x00000010)

Allows administrators to find items cached by any user. If this flag is set and the caller is not an administrator, the method call fails.

### `ppenum` [out]

Enumerator of [IOfflineFilesItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitem) interface pointers.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

To begin a top-down enumeration of the entire cache, perform the following steps:

1. Create an instance of **CLSID_OfflineFilesCache** and obtain its
   [IOfflineFilesItemContainer](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitemcontainer) interface.
2. Call the **EnumItemsEx** method to obtain an enumerator for the server entries.
3. For each entry returned, call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) for [IOfflineFilesItemContainer](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitemcontainer).
4. If [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) succeeds, the item supports children. If so, enumerate each child, calling **QueryInterface** for [IOfflineFilesItemContainer](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitemcontainer) on each. This pattern may be recursively applied to enumerate the entire cache.

It is possible to provide both inclusion and exclusion filters to the same enumeration. In such a case, the results are as follows for any particular item being evaluated.

|  | Inclusion Match | Inclusion No Match |
| --- | --- | --- |
| Exclusion Match | Excluded | Excluded |
| Exclusion No Match | Included | Excluded |

As the table illustrates, if the exclusion filter matches or the inclusion filter does not match, the item is excluded from enumeration. For an item to be included in the enumeration, the exclusion filter must not match and the inclusion filter must match.

## See also

[IOfflineFilesConnectionInfo::GetConnectState](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-getconnectstate)

[IOfflineFilesItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitem)

[IOfflineFilesItemContainer](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitemcontainer)

[IOfflineFilesItemContainer::EnumItems](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesitemcontainer-enumitems)