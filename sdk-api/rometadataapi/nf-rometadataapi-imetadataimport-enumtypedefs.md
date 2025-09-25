# IMetaDataImport::EnumTypeDefs

## Description

Enumerates TypeDef tokens representing all types within the current scope.

## Parameters

### `phEnum` [in, out]

A pointer to the new enumerator. This must be NULL for the first call of this method.

### `rgTypeDefs` [out]

The array used to store the TypeDef tokens.

### `cMax` [in]

The maximum size of the *rgTypeDefs* array.

### `pcTypeDefs` [out, retval]

The number of TypeDef tokens returned in *rgTypeDefs*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumTypeDefs** returned successfully. |
| **S_FALSE** | There are no tokens to enumerate. In this case, *pcTypeDefs* is 0 (zero). |

## Remarks

The TypeDef token represents a type such as a class or an interface, as well as any type added via an extensibility mechanism.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)