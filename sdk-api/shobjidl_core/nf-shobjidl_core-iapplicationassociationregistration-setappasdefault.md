# IApplicationAssociationRegistration::SetAppAsDefault

## Description

Sets an application as the default for a given extension or protocol, provided that the application's publisher matches the current default's. For more information, see [Default Programs](https://learn.microsoft.com/windows/desktop/shell/default-programs). Not intended for use in Windows 8.

## Parameters

### `progId` [in]

Type: **LPCWSTR**

A pointer to a **null**-terminated Unicode string that specifies the application's ProgID.

### `extOrUriScheme` [in]

Type: **LPCWSTR**

A pointer to a **null**-terminated Unicode string that contains the file name extension or protocol of the application, such as .mp3 or http.

### `atSetType` [in]

Type: **[ASSOCIATIONTYPE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-associationtype)**

One of the [ASSOCIATIONTYPE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-associationtype) enumeration values that specifies the type of the application named in *extOrUriScheme*, such as file name extension or MIME type.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code. In particular, if the application's publisher doesn't match the default's, this method returns **E_ACCESSDENIED**.

## See also

[Default Programs](https://learn.microsoft.com/windows/desktop/shell/default-programs)

[IApplicationAssociationRegistration](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationassociationregistration)