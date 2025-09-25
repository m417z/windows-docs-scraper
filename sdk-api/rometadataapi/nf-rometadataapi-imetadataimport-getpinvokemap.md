# IMetaDataImport::GetPinvokeMap

## Description

Gets a ModuleRef token to represent the target assembly of a PInvoke call.

## Parameters

### `tk` [in]

A FieldDef or MethodDef token to get the PInvoke mapping metadata for.

### `pdwMappingFlags` [out]

A pointer to flags used for mapping. This value is a bitmask from the [CorPinvokeMap](https://learn.microsoft.com/dotnet/framework/unmanaged-api/metadata/corpinvokemap-enumeration) enumeration.

### `szImportName` [out]

The name of the unmanaged target DLL.

### `cchImportName` [in]

The size in wide characters of *szImportName*.

### `pchImportName` [out]

The number of wide characters returned in *szImportName*.

### `ptkImportDLL` [out]

A pointer to a ModuleRef token that represents the unmanaged target object library.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)