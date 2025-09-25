# ISearchFolderItemFactory::SetVisibleColumns

## Description

Creates a new column list whose columns are all visible, given an array of [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structures. The default is based on **FolderTypeID**.

## Parameters

### `cVisibleColumns` [in]

Type: **UINT**

The number of array elements.

### `rgKey` [in]

Type: **const [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey)***

A pointer to an array of [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structures.

## Return value

Type: **HRESULT**

Returns a success value if successful, or an error value otherwise.