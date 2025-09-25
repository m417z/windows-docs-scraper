# IApplicationAssociationRegistration::QueryAppIsDefault

## Description

Determines whether an application owns the registered default association for a given application level and type. Not intended for use in Windows 8.

## Parameters

### `pszQuery` [in]

Type: **LPCWSTR**

A pointer to a **null**-terminated Unicode string that contains the file name extension or protocol of the application, such as .mp3 or http.

### `atQueryType` [in]

Type: **[ASSOCIATIONTYPE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-associationtype)**

One of the [ASSOCIATIONTYPE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-associationtype) enumeration values that specifies the type of the application named in *pszQuery*, such as file name extension or MIME type.

### `alQueryLevel` [in]

Type: **[ASSOCIATIONLEVEL](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-associationlevel)**

One of the [ASSOCIATIONLEVEL](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-associationlevel) enumeration values that specifies the level of association, such as per-user or machine. This is typically [AL_EFFECTIVE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-associationlevel).

### `pszAppRegistryName` [in]

Type: **LPCWSTR**

A pointer to a **null**-terminated Unicode string that specifies the registered name of the application.

### `pfDefault` [out]

Type: **BOOL***

 When this method returns, contains **TRUE** if the application is the default; or **FALSE** otherwise.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Default Programs](https://learn.microsoft.com/windows/desktop/shell/default-programs)

[IApplicationAssociationRegistration](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationassociationregistration)