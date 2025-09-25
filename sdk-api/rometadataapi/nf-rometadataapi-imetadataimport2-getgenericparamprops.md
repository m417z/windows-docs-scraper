# IMetaDataImport2::GetGenericParamProps

## Description

Gets the metadata associated with the generic parameter represented by the specified token.

## Parameters

### `gp` [in]

The token that represents the generic parameter for which to return metadata.

### `pulParamSeq` [out]

The ordinal position of the Type parameter in the parent constructor or method.

### `pdwParamFlags` [out]

 A value of the [CorGenericParamAttr](https://learn.microsoft.com/dotnet/framework/unmanaged-api/metadata/corgenericparamattr-enumeration) enumeration that describes the Type for the generic parameter.

### `ptOwner` [out]

A **TypeDef** or **MethodDef** token that represents the owner of the parameter.

### `reserved` [out]

Reserved for future extensibility.

### `wzname` [out]

The name of the generic parameter.

### `cchName` [in]

The size of the *wzName* buffer.

### `pchName` [out]

The returned size of the name, in wide characters.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport2](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport2)