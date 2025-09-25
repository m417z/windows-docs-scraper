# DBID structure

## Description

[Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](http://www.microsoft.com/en-us/download/details.aspx?id=18914) for server side search.]

The **DBID** structure encapsulates various ways of identifying a database object. It is used by nodes that must represent a column name, such as column_name, index_name, table_name, schema_name, catalog_name, and so forth. (For more information on these nodes, see [Catalog of DML Nodes](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/catalog-of-dml-nodes).) This structure is also used to define bindings.

## Members

### `uGuid`

### `uGuid.guid`

### `uGuid.pguid`

### `eKind`

### `uName`

### `uName.pwszName`

### `uName.ulPropid`

## Remarks

The **DBID** structure identifies the requested columns for a query. Each unique column is represented by a unique combination of GUID and number or GUID and name.