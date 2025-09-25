# IMetaDataImport::EnumUserStrings

## Description

Enumerates String tokens representing hard-coded strings in the current metadata scope.

## Parameters

### `phEnum` [in, out]

A pointer to the enumerator. This must be NULL for the first call of this method.

### `rgStrings` [out]

The array used to store the String tokens.

### `cMax` [in]

The maximum size of the *rgStrings* array.

### `pcStrings` [out]

The number of String tokens returned in *rgStrings*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumUserStrings** returned successfully. |
| **S_FALSE** | There are no tokens to enumerate. In this case, *pcStrings* is 0 (zero). |

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)