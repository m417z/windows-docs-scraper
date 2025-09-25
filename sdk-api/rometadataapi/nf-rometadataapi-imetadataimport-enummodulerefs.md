# IMetaDataImport::EnumModuleRefs

## Description

Enumerates ModuleRef tokens that represent imported modules.

## Parameters

### `phEnum` [in, out]

A pointer to the enumerator. This must be NULL for the first call of this method.

### `rgModuleRefs` [out]

The array used to store the ModuleRef tokens.

### `cMax` [in]

The maximum size of the *rgModuleRefs* array.

### `pcModuleRefs` [out]

The number of ModuleRef tokens returned in *rgModuleRefs*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumModuleRefs** returned successfully. |
| **S_FALSE** | There are no tokens to enumerate. In this case, *pcModuleRefs* is 0 (zero). |

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)