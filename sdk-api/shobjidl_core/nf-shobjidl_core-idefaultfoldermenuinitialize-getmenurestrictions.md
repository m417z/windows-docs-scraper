# IDefaultFolderMenuInitialize::GetMenuRestrictions

## Description

Gets shortcut menu restrictions that are currently set for the [IDefaultFolderMenuInitialize](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nn-shobjidl_core-idefaultfoldermenuinitialize) object.

## Parameters

### `dfmrMask` [in]

A bitwise combination of the [DEFAULT_FOLDER_MENU_RESTRICTIONS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-default_folder_menu_restrictions) values that specify the mask of the restrictions to get.

### `pdfmrValues` [out]

A bitwise combination of the [DEFAULT_FOLDER_MENU_RESTRICTIONS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-default_folder_menu_restrictions) values that specify the restrictions.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDefaultFolderMenuInitialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idefaultfoldermenuinitialize)

[IDefaultFolderMenuInitialize::SetMenuRestrictions](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idefaultfoldermenuinitialize-setmenurestrictions)