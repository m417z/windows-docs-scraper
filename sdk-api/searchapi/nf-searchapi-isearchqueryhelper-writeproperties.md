# ISearchQueryHelper::WriteProperties

## Description

Not implemented.

## Parameters

### `itemID` [in]

Type: **int**

The ItemID that is to be affected. The ItemID is used to store the items unique identifier, such as a DocID.

### `dwNumberOfColumns` [in]

Type: **DWORD**

The number of properties being written.

### `pColumns` [in]

Type: **[PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey)***

 Pointer to an array of [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structures that represent the properties.

### `pValues` [in]

Type: **[SEARCH_COLUMN_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-search_column_properties)***

Pointer to an array of [SEARCH_COLUMN_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-search_column_properties) structures that hold the property values.

### `pftGatherModifiedTime` [in]

Type: **[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)***

A pointer to the last modified time for the item being written. This time stamp is used later to see if an item has been changed and requires updating.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper)

[ISearchQueryHelper::put_QueryContentProperties](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-put_querycontentproperties)

[Querying the Index Programmatically](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-qryidx-overview)

[Querying the Index with Windows Search SQL Syntax](https://learn.microsoft.com/windows/desktop/search/-search-sql-windowssearch-entry)

[System Properties](https://msdn.microsoft.com/library/ff518152(v=VS.85).aspx)