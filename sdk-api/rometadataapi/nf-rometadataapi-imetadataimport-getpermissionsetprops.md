# IMetaDataImport::GetPermissionSetProps

## Description

Gets the metadata associated with the [System.Security.PermissionSet](https://learn.microsoft.com/dotnet/api/system.security.permissionset) represented by the specified Permission token.

## Parameters

### `tk` [in]

The Permission metadata token that represents the permission set to get the metadata properties for.

### `pdwAction` [out]

A pointer to the permission set.

### `ppvPermission` [out]

A pointer to the binary metadata signature of the permission set.

### `pcbPermission` [out]

The size in bytes of *const*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)