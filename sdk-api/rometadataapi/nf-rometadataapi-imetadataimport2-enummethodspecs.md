# IMetaDataImport2::EnumMethodSpecs

## Description

Gets an enumerator for an array of MethodSpec tokens associated with the specified MethodDef or MemberRef token.

## Parameters

### `phEnum` [in, out]

 pointer to the enumerator for *rMethodSpecs*.

### `tk` [in]

The **MemberRef** or **MethodDef** token that represents the method whose **MethodSpec** tokens are to be enumerated. If the value of *tk* is 0 (zero), all **MethodSpec** tokens in the scope will be enumerated.

### `rMethodSpecs` [out]

The array of **MethodSpec** tokens to enumerate.

### `cMax` [in]

The requested maximum number of tokens to place in *rMethodSpecs*.

### `pcMethodSpecs` [out]

The returned number of tokens placed in *rMethodSpecs*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumMethodSpecs** returned successfully. |
| **S_FALSE** | *phEnum* has no member elements. In this case, *pcMethodSpecs* is set to 0 (zero). |

## See also

[IMetaDataImport2](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport2)