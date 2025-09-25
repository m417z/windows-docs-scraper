# IMetaDataImport::EnumMethodImpls

## Description

Enumerates MethodBody and MethodDeclaration tokens representing methods of the specified type.

## Parameters

### `phEnum` [in, out]

 A pointer to the enumerator. This must be NULL for the first call of this method.

### `tkTypeDef` [in]

A TypeDef token for the type whose method implementations to enumerate.

### `rMethodBody` [out]

The array to store the MethodBody tokens.

### `rMethodDecl` [out]

The array to store the MethodDeclaration tokens.

### `cMax` [in]

The maximum size of the *rMethodBody* and *rMethodDecl* arrays.

### `pcTokens` [out]

The actual number of methods returned in *rMethodBody* and *rMethodDecl*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumMethodImpls** returned successfully. |
| **S_FALSE** | There are no method tokens to enumerate. In this case, *pcTokens* is 0 (zero). |

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)