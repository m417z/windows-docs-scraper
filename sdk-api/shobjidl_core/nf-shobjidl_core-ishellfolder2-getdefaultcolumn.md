# IShellFolder2::GetDefaultColumn

## Description

Gets the default sorting and display columns.

## Parameters

### `dwRes` [in]

Type: **DWORD**

Reserved. Set to zero.

### `pSort` [out]

Type: **ULONG***

A pointer to a value that receives the index of the default sorted column.

### `pDisplay` [out]

Type: **ULONG***

A pointer to a value that receives the index of the default display column.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM error value otherwise.

## Remarks

### Notes to Users

Both column indexes returned by this method are intended for use by an application that is presenting a folder view of this folder.

The column specified by
*pSort* is the one that should be used for sorting the items in the folder. To determine the sorting order of any pair of items, pass their PIDLs to [CompareIDs](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-compareids). Specify the column by setting the
*lParam* parameter of **CompareIDs** to the value pointed to by
*pSort*.

If a view will display only one string to represent an item, it should be taken from the column specified by
*pDisplay*. Pass the column index and the item's PIDL to [IShellFolder2::GetDetailsOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder2-getdetailsof) to retrieve the string.

### Notes to Implementers

This method is part of a namespace extension's folder object implementation. It is typically called by a folder view object to ask the folder object which column in Microsoft Windows Explorer Details view should be used to sort the items in the folder. For example, a folder object that represents a transaction log might set
*pSort* to the column that displays the transaction time. The items will then be sorted by the time the transaction took place, rather than by name.

Some clients might call this method to request the index of the column with the names that should be displayed in tree view. Set
*pDisplay* to the appropriate column index. The client will then obtain the display names by calling [IShellFolder2::GetDetailsOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder2-getdetailsof).