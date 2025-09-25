# IMetaDataImport::EnumSignatures

## Description

Enumerates Signature tokens representing stand-alone signatures in the current scope.

## Parameters

### `phEnum` [in, out]

 A pointer to the enumerator. This must be NULL for the first call of this method.

### `rgSignatures` [out]

The array used to store the Signature tokens.

### `cMax` [in]

The maximum size of the *rgSignatures* array.

### `pcSignatures` [out]

The number of Signature tokens returned in *rgSignatures*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumSignatures** returned successfully. |
| **S_FALSE** | There are no tokens to enumerate. In this case, *pcSignatures* is 0 (zero). |

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)