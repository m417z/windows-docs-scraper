# IContextMenu::InvokeCommand

## Description

Carries out the command associated with a shortcut menu item.

## Parameters

### `pici`

Type: **LPCMINVOKECOMMANDINFO**

A pointer to a [CMINVOKECOMMANDINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-cminvokecommandinfo) or [CMINVOKECOMMANDINFOEX](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-cminvokecommandinfoex) structure that contains specifics about the command.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [IContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu) interface is exported by several Shell extension handlers and namespace extensions. It is used to add commands to shortcut menus. When the user selects one of the commands that the handler or namespace extension added to a shortcut menu, the Shell calls that command's **InvokeCommand** method. The command can be specified by its menu identifier offset, defined when [IContextMenu::QueryContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icontextmenu-querycontextmenu) was called, or by its associated verb. An application can invoke this method directly by obtaining a pointer to an object's **IContextMenu** interface. An application can also invoke this method indirectly by calling [ShellExecute](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecutea) or [ShellExecuteEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecuteexa) and specifying a verb that is supported by the namespace extension or handler.

### Note to Users

Although the *pici* parameter is declared in Shlobj.h as a [CMINVOKECOMMANDINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-cminvokecommandinfo) structure, you can use either **CMINVOKECOMMANDINFO** or [CMINVOKECOMMANDINFOEX](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-cminvokecommandinfoex). Either will work for ANSI strings, but you must use a **CMINVOKECOMMANDINFOEX** structure for Unicode strings.

### Notes to Implementers

Check the **cbSize** member of *pici* to determine which structure ([CMINVOKECOMMANDINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-cminvokecommandinfo) or [CMINVOKECOMMANDINFOEX](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-cminvokecommandinfoex)) was passed in. If it is a **CMINVOKECOMMANDINFOEX** structure and the **fMask** member has the **CMIC_MASK_UNICODE** flag set, you must cast *pici* to **CMINVOKECOMMANDINFOEX** to use the Unicode information contained in the last five members of the structure.

If the verb, specified either by a canonical verb name or the command ID is not recognized by the context menu handler, it must return a failure (E_FAIL) so that the verb can be passed on to other context menu handlers that might implement it.

As of Windows Vista, it is not sufficient invoke the command asynchronously simply by setting the CMIC_MASK_ASYNCOK flag in the **fMask** member of the [CMINVOKECOMMANDINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-cminvokecommandinfo) or [CMINVOKECOMMANDINFOEX](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-cminvokecommandinfoex) structure. You must also set a thread reference on the calling thread as explained in [Managing Thread References](https://learn.microsoft.com/windows/desktop/shell/managing-thread-references).

## See also

[IContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu)