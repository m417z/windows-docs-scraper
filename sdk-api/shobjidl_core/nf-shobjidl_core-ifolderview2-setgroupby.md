# IFolderView2::SetGroupBy

## Description

Groups the view by the given property key and direction.

## Parameters

### `key` [in]

Type: **REFPROPERTYKEY**

A [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) by which the view should be grouped.

### `fAscending` [in]

Type: **BOOL**

A value of type **BOOL** to indicate sort order of the groups.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.