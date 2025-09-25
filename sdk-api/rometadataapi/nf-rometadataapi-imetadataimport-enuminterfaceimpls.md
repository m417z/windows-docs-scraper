# IMetaDataImport::EnumInterfaceImpls

## Description

Enumerates MethodDef tokens representing interface implementations.

## Parameters

### `phEnum` [in, out]

A pointer to the enumerator.

### `td` [in]

The token of the TypeDef whose MethodDef tokens representing interface implementations are to be enumerated.

### `rImpls` [out]

The array used to store the MethodDef tokens.

### `cMax` [in]

The maximum size of the *rImpls* array.

### `pcImpls` [out, retval]

The actual number of tokens returned in *rImpls*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumInterfaceImpls** returned successfully. |
| **S_FALSE** | There are no MethodDef tokens to enumerate. In this case, *pcImpls* is 0 (zero). |

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)