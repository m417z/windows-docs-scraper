# IMetaDataImport::GetRVA

## Description

Gets the relative virtual address (RVA) and the implementation flags of the method or field represented by the specified token.

## Parameters

### `tk` [in]

A MethodDef or FieldDef metadata token that represents the code object to return the RVA for. If the token is a FieldDef, the field must be a global variable.

### `pulCodeRVA` [out]

 A pointer to the relative virtual address of the code object represented by the token.

### `pdwImplFlags` [out]

A pointer to the implementation flags for the method. This value is a bitmask from the [CorMethodImpl](https://learn.microsoft.com/dotnet/framework/unmanaged-api/metadata/cormethodimpl-enumeration) enumeration. The value of *pdwImplFlags* is valid only if *tk* is a MethodDef token.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)