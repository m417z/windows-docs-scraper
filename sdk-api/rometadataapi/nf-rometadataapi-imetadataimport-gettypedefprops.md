# IMetaDataImport::GetTypeDefProps

## Description

Returns metadata information for the Type represented by the specified TypeDef token.

## Parameters

### `tkTypeDef` [in]

The TypeDef token that represents the type to return metadata for.

### `szTypeDef` [out]

A buffer containing the type name.

### `cchTypeDef` [in]

The size in wide characters of *szTypeDef*.

### `pchTypeDef` [out]

The number of wide characters returned in *szTypeDef*.

### `pdwTypeDefFlags` [out]

A pointer to any flags that modify the type definition. This value is a bitmask from the [CorTypeAttr](https://learn.microsoft.com/dotnet/framework/unmanaged-api/metadata/cortypeattr-enumeration) enumeration.

### `ptkExtends` [out]

A TypeDef or TypeRef metadata token that represents the base type of the requested type.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)