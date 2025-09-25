# IMetaDataImport::GetParamForMethodIndex

## Description

Gets the token that represents a specified parameter of the method represented by the specified MethodDef token.

## Parameters

### `tkMethodDef` [in]

A token that represents the method to return the parameter token for.

### `ulParamSeq` [in]

The ordinal position in the parameter list where the requested parameter occurs. Parameters are numbered starting from one, with the method's return value in position zero.

### `ptkParamDef` [out]

A pointer to a ParamDef token that represents the requested parameter.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)