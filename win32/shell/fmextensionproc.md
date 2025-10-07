# FMExtensionProc callback function

Specifies an application-defined callback function called by File Manager to communicate with a File Manager extension.

## Parameters

*hwnd*

Type: **HWND**

A window handle to File Manager. An extension uses this handle to specify the parent window for any dialog box or message box it must display, and to send query messages to File Manager.

*wMsg*

Type: **WORD**

One of the following File Manager messages.

**1 through 99**

User selected an item from the extension-supplied menu. The value is the identifier of the selected menu item.

**FMEVENT\_HELPMENUITEM**

User pressed F1 while selecting an extension menu or toolbar command item. Indicates that the extension should call **WinHelp** appropriately for the command item.

**FMEVENT\_HELPSTRING**

User selected an extension menu or toolbar command item. Indicates that the extension should supply a Help string.

**FMEVENT\_INITMENU**

User selected the extension's menu. The extension should initialize items in the menu.

**FMEVENT\_LOAD**

File Manager is loading the extension DLL and prompts the DLL for information about the menu that the DLL supplies.

**FMEVENT\_SELCHANGE**

Selection in the **File Manager** directory window or **Search Results** window has changed.

**FMEVENT\_TOOLBARLOAD**

File Manager is creating the toolbar and prompts the extension DLL for information about any buttons the DLL adds to the toolbar.

**FMEVENT\_UNLOAD**

File Manager is unloading the extension DLL.

**FMEVENT\_USER\_REFRESH**

User selected the **Refresh** command from the **Window** menu. The extension should update items in the menu, if necessary.

*lParam*

Type: **LONG**

Message-specific value.

## Return value

Type: **LONG**

Returns a value dependent upon the *wMsg* parameter message.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Wfext.h |
| Unicode and ANSI names<br> | **FMExtensionProcW** (Unicode)<br> |

