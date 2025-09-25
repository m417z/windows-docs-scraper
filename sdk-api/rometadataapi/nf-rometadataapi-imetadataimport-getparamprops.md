# IMetaDataImport::GetParamProps

## Description

Gets metadata values for the parameter referenced by the specified ParamDef token.

## Parameters

### `tkParamDef` [in]

A ParamDef token that represents the parameter to return metadata for.

### `ptkMethodDef` [out]

A pointer to a MethodDef token representing the method that takes the parameter.

### `pulSequence` [out]

The ordinal position of the parameter in the method argument list.

### `szName` [out]

A buffer to hold the name of the parameter.

### `cchName` [in]

The requested size in wide characters of *szName*.

### `pchName` [out]

The returned size in wide characters of *szName*.

### `pdwAttr` [out]

A pointer to any attribute flags associated with the parameter.

### `pdwCPlusTypeFlag` [out]

A pointer to a flag specifying that the parameter is a ValueType.

### `ppValue` [out]

A pointer to a constant string returned by the parameter.

### `pcchValue` [out]

The size of *ppValue* in wide characters, or zero if *ppValue* does not hold a string.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)