# IMetaDataTables::GetTableIndex

## Description

Gets the index for the table referenced by the specified token.

## Parameters

### `token` [in]

The token that references the table.

### `pixTbl` [out]

A pointer to the returned index for the referenced table.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

We do not recommend the use of this method, because it does not return consistent results. For information about the GUID table, see the Common Language Infrastructure (CLI) documentation, especially "Partition II: Metadata Definition and Semantics". For more info, see [ECMA C# and Common Language Infrastructure Standards](https://learn.microsoft.com/dotnet/standard/components#applicable-standards) and [Standard ECMA-335 - Common Language Infrastructure (CLI)](https://ecma-international.org/publications-and-standards/standards/ecma-335/) on the Ecma International Web site.

## See also

[IMetaDataTables](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadatatables)