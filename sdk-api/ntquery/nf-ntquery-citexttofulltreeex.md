# CITextToFullTreeEx function

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

Creates a full command tree using the Query Language Dialect that you specify.

## Parameters

### `pwszRestriction`

A pointer to a null-terminated string that specifies an Indexing Service query. The syntax for queries is described in [Query Languages for Indexing Service](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/query-languages-for-indexing-service).

### `ulDialect`

A value from [ISQLANG_*](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/isqlang-constants) constants that specifies a specific version of the Indexing Service query language to be used.

### `pwszColumns`

A pointer to a null-terminated string that specifies a comma-separated list of column names returned in the query results. These columns can be bound by OLE DB accessors.

### `pwszSortColumns`

A pointer to a null-terminated string that contains a comma-separated list of column names that specify the sort order for the query results. A sort direction can be appended to each column name. Use [d] for descending, and [a] for ascending. If no sort order is specified, ascending is the default. Can be **NULL** for no sort order.

### `pwszGroupings`

A pointer to a null-terminated string that contains a grouping specification made up of a type (currently only [unique] is supported), a property name, and a sort order ([a] for ascending or [d] for descending). In a unique grouping, unique values of the column set form the individual categories. This parameter is optional.

The syntax for the unique grouping term is:

unique *fname* [ {[a]|[d]} ] [ , *fname2* {[a]|[d]} ... ]

where *fname* and *fname2* are the assigned friendly names.

Column names separated by a plus sign (+) are grouped in individual categories, and column names following a comma (,) are grouped together into subgroups of the preceding grouping.

### `ppTree`

A pointer to the address of the location to receive the [DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree) structure for the command tree.

### `cProperties`

The number of properties in the *pProperties* array, or zero if *pProperties* is **NULL**.

### `pProperties`

A pointer to an array of properties that can be referred to by a friendly name in the *pwszColumns*, *pwszSortColumns*, *pwszGroupings*, and *pwszRestriction* parameters. Column names in the **wcsFriendlyName** member of each [CIPROPERTYDEF](https://learn.microsoft.com/windows/desktop/api/ntquery/ns-ntquery-cipropertydef) structure must be specified in uppercase. This parameter can be **NULL** if no properties are being defined and *cProperties* is zero. Indexing Service's built-in properties do not need to be defined to be used. It is an error to define a property with the same friendly name as that of a built-in property.

### `LocaleID`

The locale identifier (LCID) used for nodes in *ppTree* that contain an LCID member, including nodes such as content restrictions, sort order, and other locale properties.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was completed successfully. |
| **E_HANDLE** | The function encountered an invalid handle, probably due to a low-memory situation. |
| **E_INVALIDARG** | The function received an invalid parameter. |
| **E_OUTOFMEMORY** | The function did not have sufficient memory or other resources to complete the operation. |
| **E_FAIL** | An unknown error has occurred. |

## Remarks

The query tree allocated by the **CITextToFullTreeEx** function must be freed either with the [ICommandTree::FreeCommandTree](https://learn.microsoft.com/previous-versions/windows/desktop/api/cmdtree/nf-cmdtree-icommandtree-freecommandtree) method or passed to the [ICommandTree::SetCommandTree](https://learn.microsoft.com/previous-versions/windows/desktop/api/cmdtree/nf-cmdtree-icommandtree-setcommandtree) method with the *fCopy* parameter set to **FALSE**.

Be sure to include the following #define directive before your #include \<oledberr.h> to access the command tree definitions.

```
#define DBINITCONSTANTS
#include <oledberr.h>
#include <oledb.h>
#include <cmdtree.h>
```

## See also

[CIPROPERTYDEF](https://learn.microsoft.com/windows/desktop/api/ntquery/ns-ntquery-cipropertydef)

[DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree)

[ICommandTree](https://learn.microsoft.com/previous-versions/windows/desktop/api/cmdtree/nn-cmdtree-icommandtree)

