# IMetaDataTables::GetCodedTokenInfo

## Description

Gets a pointer to an array of tokens associated with the specified row index.

## Parameters

### `ixCdTkn` [in]

The kind of coded token to return.

### `pcTokens` [out]

A pointer to the length of *ppTokens*.

### `ppTokens` [out]

A pointer to a pointer to an array that contains the list of returned tokens.

### `ppName` [out]

A pointer to a pointer to the name of the token at *ixCdTkn*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataTables](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadatatables)