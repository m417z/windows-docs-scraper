# SHShowManageLibraryUI function

## Description

Shows the library management dialog box, which enables users to manage the library folders and default save location.

## Parameters

### `psiLibrary` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object that represents the library that is to be managed.

### `hwndOwner` [in, optional]

Type: **HWND**

The handle for the window that owns the library management dialog box. The value of this parameter can be **NULL**.

### `pszTitle` [in, optional]

Type: **LPCWSTR**

A pointer to the title for the library management dialog. To display the generic title string, set the value of this parameter to **NULL**.

### `pszInstruction` [in, optional]

Type: **LPCWSTR**

A pointer to a help string to display below the title string in the library management dialog box. To display the generic help string, set the value of this parameter to **NULL**.

### `lmdOptions` [in]

Type: **[LIBRARYMANAGEDIALOGOPTIONS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-librarymanagedialogoptions)**

A value from the [LIBRARYMANAGEDIALOGOPTIONS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-librarymanagedialogoptions) enumeration that specifies the behavior of the management dialog box.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[LIBRARYMANAGEDIALOGOPTIONS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-librarymanagedialogoptions)