# IApplicationAssociationRegistration::QueryAppIsDefaultAll

## Description

Determines whether an application owns all of the registered default associations for a given application level. Not intended for use in Windows 8.

## Parameters

### `alQueryLevel` [in]

Type: **[ASSOCIATIONLEVEL](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-associationlevel)**

One of the [ASSOCIATIONLEVEL](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-associationlevel) enumeration values that specifies the level of association, such as per-user or machine. This is typically [AL_EFFECTIVE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-associationlevel).

### `pszAppRegistryName` [in]

Type: **LPCWSTR**

A pointer to a **null**-terminated Unicode string that specifies the registered name of the application.

### `pfDefault` [out]

Type: **BOOL***

When this method returns, contains **TRUE** if the application is the default for all  [association types](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-associationtype) at the specified [ASSOCIATIONLEVEL](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-associationlevel);
or **FALSE** otherwise.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Default Programs](https://learn.microsoft.com/windows/desktop/shell/default-programs)

[IApplicationAssociationRegistration](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationassociationregistration)