# IMetaDataImport::EnumPermissionSets

## Description

Enumerates permissions for the objects in a specified metadata scope.

## Parameters

### `phEnum` [in, out]

A pointer to the enumerator. This must be NULL for the first call of this method.

### `tk` [in]

A metadata token that limits the scope of the search, or NULL to search the widest scope possible.

### `dwActions` [in]

 Flags representing the [SecurityAction](https://learn.microsoft.com/dotnet/api/system.security.permissions.securityaction) values to include in *rPermission*, or zero to return all actions.

### `rPermission` [out]

The array used to store the Permission tokens.

### `cMax` [in]

The maximum size of the *rPermission* array.

### `pcTokens` [out]

The number of Permission tokens returned in *rPermission*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumPermissionSets** returned successfully. |
| **S_FALSE** | There are no tokens to enumerate. In this case, *pcTokens* is 0 (zero). |

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)