# IMetaDataAssemblyImport::EnumAssemblyRefs

## Description

Enumerates the mdAssemblyRef instances that are defined in the assembly manifest.

## Parameters

### `phEnum` [in, out]

A pointer to the enumerator. This must be a null value when the **EnumAssemblyRefs** method is called for the first time.

### `rAssemblyRefs` [out]

The enumeration of **mdAssemblyRef** metadata tokens.

### `cMax` [in]

The maximum number of tokens that can be placed in the rAssemblyRefs array.

### `pcTokens` [out]

The number of tokens actually placed in *rAssemblyRefs*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumAssemblyRefs** returned successfully. |
| **S_FALSE** | There are no tokens to enumerate. In this case, *pcTokens* is set to zero. |

## See also

[IMetaDataAssemblyImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataassemblyimport)