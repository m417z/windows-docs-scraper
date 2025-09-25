## Description

Determines whether the Shell will be allowed to move, copy, delete, or rename a folder or printer object.

## Parameters

### `hwnd`

A handle to the window that the copy hook handler should use as the parent for any user interface elements the handler may need to display. If **FOF_SILENT** is specified in *wFunc*, the method should ignore this parameter.

### `wFunc`

The operation to perform. This parameter can be one of the values listed under the **wFunc** member of the [SHFILEOPSTRUCT](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-shfileopstructa) structure.

### `wFlags`

The flags that control the operation. This parameter can be one or more of the values listed under the *fFlags* member of the [SHFILEOPSTRUCT](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-shfileopstructa) structure.
For printer copy hooks, this value is one of the following values defined in Shellapi.h.

| Value | Description |
|-------------|------------|
| **PO_DELETE** | A printer is being deleted. *pszSrcFile* points to the full path to the specified printer. |
| **PO_RENAME** | A printer is being renamed. The *pszSrcFile* parameter points to the printer's new name. The *pszDestFile* parameter points to the old name. |
| **PO_PORTCHANGE** | Not supported. Do not use. |
| **PO_REN_PORT** | Not supported. Do not use. |

### `pszSrcFile`

A pointer to a string that contains the name of the source folder.

### `dwSrcAttribs`

The attributes of the source folder. This parameter can be a combination of any of the file attribute flags (FILE_ATTRIBUTE_*) defined in the header files. See [File Attribute Constants](https://learn.microsoft.com/windows/desktop/FileIO/file-attribute-constants).

### `pszDestFile`

A pointer to a string that contains the name of the destination folder.

### `dwDestAttribs`

The attributes of the destination folder. This parameter can be a combination of any of the file attribute flags (FILE_ATTRIBUTE_*) defined in the header files. See [File Attribute Constants](https://learn.microsoft.com/windows/desktop/FileIO/file-attribute-constants).

## Return value

Returns an integer value that indicates whether the Shell should perform the operation. One of the following:

| Value | Description |
|-------------|------------|
| **IDYES** | Allows the operation. |
| **IDNO** | Prevents the operation on this folder but continues with any other operations that have been approved (for example, a batch copy operation). |
| **IDCANCEL** | Prevents the current operation and cancels any pending operations. |

## Remarks

The Shell calls each copy hook handler registered for a folder or printer object until all the handlers have been called, or until one of them returns IDNO or IDCANCEL.

Copy hook handlers for folders are registered under the following key:

**HKEY_CLASSES_ROOT/Directory/Shellex/CopyHookHandlers/your_copyhook/{copyhook CLSID value}**

Copy hook handlers for printers are registered under the following key.

**HKEY_CLASSES_ROOT/Printers/Shellex/CopyHookHandlers/your_copyhook/{copyhook CLSID value}**
When this method is called, the Shell initializes the [ICopyHookW](https://learn.microsoft.com/windows/win32/api/shlobj/nn-shlobj-icopyhookw) interface directly without using an [IShellExtInit](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellextinit) interface first.

## See also