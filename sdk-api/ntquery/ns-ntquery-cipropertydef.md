# CIPROPERTYDEF structure

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

Represents the friendly name, type, and property identifier (ID) information.

## Members

### `wcsFriendlyName`

The friendly name for a property. The friendly name can be used in an Indexing Service query, column list, or sort order parsed by the [CITextToSelectTree](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/ntquery/nf-ntquery-citexttoselecttree.md) function and the [CITextToFullTree](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/ntquery/nf-ntquery-citexttofulltree.md) function. Friendly names must be entered in uppercase.

### `dbType`

The data type for the property. This type is used when building a [DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree) structure for a restriction node. The same property with different friendly names can have different types. Its value must be either an OLE DB **DBTYPE** type or a **PROPVARIANT** variant type.

### `dbCol`

The property ID for the property. Indexing Service properties must be either DBKIND_GUID_NAME or DBKIND_GUID_PROPID. See [DBID](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbid).

## See also

[CITextToFullTree](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/ntquery/nf-ntquery-citexttofulltree.md)

[CITextToSelectTree](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/ntquery/nf-ntquery-citexttoselecttree.md)

[DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree)

[DBID](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbid)