# IFolderViewSettings::GetGroupByProperty

## Description

Gets a grouping property.

## Parameters

### `pkey` [out]

Type: **[PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey)***

A pointer to a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure indicating the key by which content is grouped.

### `pfGroupAscending` [out]

Type: **BOOL***

A pointer to a value indicating whether grouping order is ascending.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.