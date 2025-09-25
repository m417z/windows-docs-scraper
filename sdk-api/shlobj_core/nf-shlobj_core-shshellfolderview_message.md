# SHShellFolderView_Message function

## Description

[**SHShellFolderView_Message** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Sends a message to the shell's default [IFolderView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderview) implementation (DefView).

## Parameters

### `hwndMain` [in]

Type: **HWND**

A handle to the window that receives the message.

### `uMsg`

Type: **UINT**

The message to send. The following is a list of possible messages.

| Message | Description |
| --- | --- |
| [SFVM_ADDOBJECT](https://learn.microsoft.com/windows/desktop/shell/samples-usingimagefactory) | Adds an object to the shell view. |
| [SFVM_GETSELECTEDOBJECTS](https://learn.microsoft.com/windows/desktop/shell/sfvm-getselectedobjects) | Retrieves an array of PIDLs for all selected objects. |
| [SFVM_REARRANGE](https://learn.microsoft.com/windows/desktop/shell/sfvm-rearrange) | Notifies the [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) to rearrange its items. |
| [SFVM_REMOVEOBJECT](https://learn.microsoft.com/windows/desktop/shell/sfvm-removeobject) | Removes an object from the shell view. |
| [SFVM_SETCLIPBOARD](https://learn.microsoft.com/windows/desktop/shell/sfvm-setclipboard) | Notifies the [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) when one of its objects is placed on the clipboard as a result of a menu command. |
| [SFVM_SETITEMPOS](https://learn.microsoft.com/windows/desktop/shell/sfvm-setitempos) | Sets the position of an item in the shell view. |
| [SFVM_SETPOINTS](https://learn.microsoft.com/windows/desktop/shell/sfvm-setpoints) | Sets the points of the currently selected objects to the data object on **copy** and **cut** commands. |
| [SFVM_UPDATEOBJECT](https://learn.microsoft.com/windows/desktop/shell/sfvm-updateobject) | Updates an object by passing a pointer to an array of two PIDLs. |

### `lParam`

Type: **LPARAM**

Contents of this value depend on the message passed in *uMsg*. See individual message topics for more information.

## Return value

Type: **LRESULT**

The return value depends on the message passed in *uMsg*. See individual message topics for more information.

## See also

[SHCreateShellFolderView](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shcreateshellfolderview)