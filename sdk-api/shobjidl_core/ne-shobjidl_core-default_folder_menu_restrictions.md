# DEFAULT_FOLDER_MENU_RESTRICTIONS enumeration

## Description

Defines shortcut menu restrictions used by [IDefaultFolderMenuInitialize::GetMenuRestrictions](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nf-shobjidl_core-idefaultfoldermenuinitialize-getmenurestrictions) and [IDefaultFolderMenuInitialize::SetMenuRestrictions](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nf-shobjidl_core-idefaultfoldermenuinitialize-setmenurestrictions).

## Constants

### `DFMR_DEFAULT:0`

0x0000. No restrictions.

### `DFMR_NO_STATIC_VERBS:0x8`

0x0008. Don't use the handler for static verbs.

### `DFMR_STATIC_VERBS_ONLY:0x10`

0x0010. Static verbs only. No dynamic **IContextMenu** verbs allowed.

### `DFMR_NO_RESOURCE_VERBS:0x20`

0x0020. Don't add verbs for cut, copy, paste, link, delete, rename, or properties.

### `DFMR_OPTIN_HANDLERS_ONLY:0x40`

0x0040. Opt-in to load handler for partial cloud files. Only used for handlers that will not cause implicit hydration. Opt-in handlers must have the registry value "ContextMenuOptIn" under HKCR\CLSID\

### `DFMR_RESOURCE_AND_FOLDER_VERBS_ONLY:0x80`

0x0080. Only load resource verbs (cut, copy, paste, link, delete, rename, and properties) and folder verbs added by [IContextMenuCB](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nn-shobjidl_core-icontextmenucb).

### `DFMR_USE_SPECIFIED_HANDLERS:0x100`

0x0100. Use handlers with CLSID values that were added through [IDefaultFolderMenuInitialize::SetHandlerClsid](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nf-shobjidl_core-idefaultfoldermenuinitialize-sethandlerclsid)

### `DFMR_USE_SPECIFIED_VERBS:0x200`

0x0200. Only load handlers that support the specified verbs.

### `DFMR_NO_ASYNC_VERBS:0x400`

0x0400. Ignore async verbs.

### `DFMR_NO_NATIVECPU_VERBS:0x800`

0x0800. Ignore verbs that are registered for the native CPU architecture.

## See also

[IDefaultFolderMenuInitialize::GetMenuRestrictions](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idefaultfoldermenuinitialize-getmenurestrictions)

[IDefaultFolderMenuInitialize::SetMenuRestrictions](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idefaultfoldermenuinitialize-setmenurestrictions)