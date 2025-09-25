# IApplicationAssociationRegistration::SetAppAsDefaultAll

## Description

Sets an application as the default for all of the registered associations of any [type](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-associationtype) for that application. Not intended for use in Windows 8.

## Parameters

### `pszAppRegistryName` [in]

Type: **LPCWSTR**

A pointer to a null-terminated Unicode string that specifies the registered name of the application.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Default Programs](https://learn.microsoft.com/windows/desktop/shell/default-programs)

[IApplicationAssociationRegistration](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationassociationregistration)