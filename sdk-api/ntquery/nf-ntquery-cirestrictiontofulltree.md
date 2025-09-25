# CIRestrictionToFullTree function

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

Converts a query restriction tree with columns, sort columns, and grouping columns to a [DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree) structure.

## Parameters

### `pTree`

A pointer to a [DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree) structure that is the top node defining a **SELECT** tree for a query.

### `pwszColumns`

A pointer to a null-terminated string that specifies a comma separated list of column names returned in the query results. These columns can be bound by OLE DB accessors and are used to create the **PROJECT** part of the full tree.

### `pwszSortColumns`

A pointer to a null-terminated string that contains a comma-separated list of column names that specify the sort order for the query results. A sort direction can be appended to each column name. Use [d] for descending, and [a] for ascending. If no sort order is specified, ascending is the default. This parameter can be **NULL** for no sort order. These columns are used to create the **SORT** part of the full tree.

### `pwszGroupings`

A pointer to a null-terminated string that contains a grouping specification made up of a type (currently only [unique] is supported), a property name, and a sort order ([a] for ascending or [d] for descending). In a unique grouping, unique values of the column set form the individual categories. This parameter is optional.

The syntax for the unique grouping term is:

unique *fname* [ {[a]|[d]} ] [ , *fname2* {[a]|[d]} ... ]

where *fname* and *fname2* are the assigned friendly names.

Column names separated by a plus sign (+) are grouped in individual categories, and column names following a comma (,) are grouped together into subgroups of the preceding grouping.

### `ppTree`

A pointer to an output variable that receives a pointer to a [DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree) structure. This parameter cannot be **NULL**.

### `cProperties`

The number of properties in the *pProperties* array, or zero if *pProperties* is **NULL**.

### `pReserved`

A pointer to an array of properties that can be referred to by a friendly name in the *pwszColumns*, *pwszSortColumns*, and *pwszGroupings* parameters. Column names in the **wcsFriendlyName** member of each [CIPROPERTYDEF](https://learn.microsoft.com/windows/desktop/api/ntquery/ns-ntquery-cipropertydef) structure must be specified in uppercase. This parameter can be **NULL** if no properties are being defined and if *cProperties* is zero. Indexing Service's built-in properties do not need to be defined to be used. It is an error to define a property with the same friendly name as that of a built-in property.

### `LocaleID`

The locale identifier (LCID) used when converting properties.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was completed successfully. |
| **E_HANDLE** | The function encountered an invalid handle, probably due to a low-memory situation. |
| **E_INVALIDARG** | The function received an invalid parameter. |
| **E_OUTOFMEMORY** | The function did not have sufficient memory or other resources to complete the operation. |
| **E_FAIL** | An unknown error has occurred. |

## See also

[CIPROPERTYDEF](https://learn.microsoft.com/windows/desktop/api/ntquery/ns-ntquery-cipropertydef)

[DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree)

