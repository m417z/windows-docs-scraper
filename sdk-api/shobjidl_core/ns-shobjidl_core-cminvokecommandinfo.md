# CMINVOKECOMMANDINFO structure

## Description

Contains information needed by [IContextMenu::InvokeCommand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icontextmenu-invokecommand) to invoke a shortcut menu command.

## Members

### `cbSize`

Type: **DWORD**

The size of this structure, in bytes.

### `fMask`

Type: **DWORD**

Zero, or one or more of the following flags.

#### CMIC_MASK_HOTKEY

The **dwHotKey** member is valid.

#### CMIC_MASK_ICON

The **hIcon** member is valid. As of Windows Vista this flag is not used.

#### CMIC_MASK_FLAG_NO_UI

The system is prevented from displaying user interface elements (for example, error messages) while carrying out a command.

#### CMIC_MASK_NO_CONSOLE

If a shortcut menu handler needs to create a new process, it will normally create a new console. Setting the **CMIC_MASK_NO_CONSOLE** flag suppresses the creation of a new console.

#### CMIC_MASK_FLAG_SEP_VDM

This flag is valid only when referring to a 16-bit Windows-based application. If set, the application that the shortcut points to runs in a private Virtual DOS Machine (VDM). See Remarks.

#### CMIC_MASK_ASYNCOK

Wait for the DDE conversation to terminate before returning.

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

### `hwnd`

Type: **HWND**

A handle to the window that is the owner of the shortcut menu. An extension can also use this handle as the owner of any message boxes or dialog boxes it displays.

### `lpVerb`

Type: **LPCSTR**

The address of a null-terminated string that specifies the language-independent name of the command to carry out. This member is typically a string when a command is being activated by an application. The system provides predefined constant values for the following command strings.

| Constant | Command string |
| --- | --- |
| CMDSTR_RUNAS | "RunAs" |
| CMDSTR_PRINT | "Print" |
| CMDSTR_PREVIEW | "Preview" |
| CMDSTR_OPEN | "Open" |

This is not a fixed set; new canonical verbs can be invented by context menu handlers and applications can invoke them.

If a canonical verb exists and a menu handler does not implement the canonical verb, it must return a failure code to enable the next handler to be able to handle this verb. Failing to do this will break functionality in the system including [ShellExecute](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecutea).

Alternatively, rather than a pointer, this parameter can be [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea)(offset) where *offset* is the menu-identifier offset of the command to carry out. Implementations can use the [IS_INTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-is_intresource) macro to detect that this alternative is being employed. The Shell uses this alternative when the user chooses a menu command.

### `lpParameters`

Type: **LPCSTR**

An optional string containing parameters that are passed to the command. The format of this string is determined by the command that is to be invoked. This member is always **NULL** for menu items inserted by a Shell extension.

### `lpDirectory`

Type: **LPCSTR**

An optional working directory name. This member is always **NULL** for menu items inserted by a Shell extension.

### `nShow`

Type: **int**

A set of SW_ values to pass to the [ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow) function if the command displays a window or starts an application.

### `dwHotKey`

Type: **DWORD**

An optional keyboard shortcut to assign to any application activated by the command. If the **fMask** parameter does not specify **CMIC_MASK_HOTKEY**, this member is ignored.

### `hIcon`

Type: **HANDLE**

An icon to use for any application activated by the command. If the **fMask** member does not specify **CMIC_MASK_ICON**, this member is ignored.

## Remarks

Although the [IContextMenu::InvokeCommand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icontextmenu-invokecommand) declaration specifies a **CMINVOKECOMMANDINFO** structure for the *pici* parameter, it can also accept a [CMINVOKECOMMANDINFOEX](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-cminvokecommandinfoex) structure. If you are implementing this method, you must inspect **cbSize** to determine which structure has been passed.