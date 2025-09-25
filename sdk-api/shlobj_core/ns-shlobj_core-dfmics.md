# DFMICS structure

## Description

Contains additional arguments used by [DFM_INVOKECOMMANDEX](https://learn.microsoft.com/windows/desktop/shell/prophand-content-view).

## Members

### `cbSize`

Type: **DWORD**

The size of this structure, in bytes.

### `fMask`

Type: **DWORD**

Zero, or one or more of the following flags that specify how to handle the data in the [CMINVOKECOMMANDINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-cminvokecommandinfo) or [CMINVOKECOMMANDINFOEX](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-cminvokecommandinfoex) structure pointed to by **pici**.

#### CMIC_MASK_HOTKEY

The **dwHotKey** member is valid.

#### CMIC_MASK_ICON

Not used.

#### CMIC_MASK_FLAG_NO_UI

The implementation of [IContextMenu::InvokeCommand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icontextmenu-invokecommand) is prevented from displaying user interface elements (for example, error messages) while carrying out a command.

#### CMIC_MASK_UNICODE

Used only when **pici** points to a [CMINVOKECOMMANDINFOEX](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-cminvokecommandinfoex) structure. Indicates that the shortcut menu handler should use **lpVerbW**, **lpParametersW**, **lpTitleW**, and **lpDirectoryW** members instead of their ANSI equivalents. Because some shortcut menu handlers may not support Unicode, you should also pass valid ANSI strings in the **lpVerb**, **lpParameters**, **lpTitleW**, and **lpDirectory** members.

#### CMIC_MASK_NO_CONSOLE

If a shortcut menu handler needs to create a new process, it normally creates a new console. Setting the **CMIC_MASK_NO_CONSOLE** flag suppresses the creation of a new console.

#### CMIC_MASK_FLAG_SEP_VDM

This flag is valid only when referring to a 16-bit Windows-based application. If set, the application that the shortcut points to runs in a private Virtual DOS Machine (VDM). See Remarks.

#### CMIC_MASK_ASYNCOK

The implementation of [IContextMenu::InvokeCommand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icontextmenu-invokecommand) can spin off a new thread or process to handle the call and does not need to block on completion of the function being invoked. For example, if the verb is "delete" the **IContextMenu::InvokeCommand** call may return before all of the items have been deleted. Since this is advisory, calling applications that specify this flag cannot guarantee that this request will be honored if they are not familiar with the implementation of the verb that they are invoking.

#### CMIC_MASK_NOASYNC

**Windows Vista and later.** The implementation of [IContextMenu::InvokeCommand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icontextmenu-invokecommand) should be synchronous, not returning before it is complete. Since this is recommended, calling applications that specify this flag cannot guarantee that this request will be honored if they are not familiar with the implementation of the verb that they are invoking.

#### CMIC_MASK_SHIFT_DOWN

The SHIFT key is pressed. Use this instead of polling the current state of the keyboard that may have changed since the verb was invoked.

#### CMIC_MASK_CONTROL_DOWN

The CTRL key is pressed. Use this instead of polling the current state of the keyboard that may have changed since the verb was invoked.

#### CMIC_MASK_FLAG_LOG_USAGE

Indicates that the implementation of [IContextMenu::InvokeCommand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icontextmenu-invokecommand) might want to keep track of the item being invoked for features like the "Recent documents" menu.

#### CMIC_MASK_NOZONECHECKS

Do not perform a zone check. This flag allows [ShellExecuteEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecuteexa) to bypass zone checking put into place by [IAttachmentExecute](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iattachmentexecute).

#### CMIC_MASK_PTINVOKE

Used only when **pici** points to a [CMINVOKECOMMANDINFOEX](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-cminvokecommandinfoex) structure. The **ptInvoke** member is valid.

### `lParam`

Type: **LPARAM**

A pointer to a null-terminated string that contains additional arguments to the selected menu command. This member can be **NULL**.

### `idCmdFirst`

Type: **UINT**

The minimum value that the handler can specify for a menu item identifier.

### `idDefMax`

Type: **UINT**

The maximum value that the handler can specify for a menu item identifier.

### `pici`

Type: **LPCMINVOKECOMMANDINFO**

A pointer to a [CMINVOKECOMMANDINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-cminvokecommandinfo) or **CMINVOKECOMMANDINFO** structure.

### `punkSite`

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the site of the context menu handler.