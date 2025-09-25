# IMetaDataImport::GetUserString

## Description

Gets the literal string represented by the specified metadata token.

## Parameters

### `tkString` [in]

The String token to return the associated string for.

### `szString` [out]

A copy of the requested string.

### `cchString` [in]

The maximum size in wide characters of the requested *szString*.

### `pchString` [out]

The size in wide characters of the returned *szString*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)