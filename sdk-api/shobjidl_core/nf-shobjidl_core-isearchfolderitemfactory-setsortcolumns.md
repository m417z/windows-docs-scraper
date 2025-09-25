# ISearchFolderItemFactory::SetSortColumns

## Description

Creates a list of sort column directions, as specified.

## Parameters

### `cSortColumns` [in]

Type: **UINT**

The number of sort columns.

### `rgSortColumns` [in]

Type: **[SORTCOLUMN](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-sortcolumn)***

A pointer to an array of [SORTCOLUMN](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-sortcolumn) structures containing sort direction. The default is **PKEY_ItemNameDisplay**.

## Return value

Type: **HRESULT**

Returns a success value if successful, or an error value otherwise.