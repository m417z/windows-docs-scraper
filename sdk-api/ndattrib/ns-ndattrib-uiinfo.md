# UiInfo structure

## Description

The **UiInfo** structure is used to display repair messages to the user.

## Members

### `type`

Type: **[UI_INFO_TYPE](https://learn.microsoft.com/windows/win32/api/ndattrib/ne-ndattrib-ui_info_type)**

The type of user interface (UI) to use. This can be one of the values shown in the following members.

### `pwzNull`

Type: **LPWSTR**

No additional UI is required. Used when **type** is set to UIT_NONE.

### `ShellInfo`

Type: **ShellCommandInfo**

Execute a shell command. Used when **type** is set to UIT_SHELL_COMMAND.

### `pwzHelpUrl`

Type: **LPWSTR**

Launches a help pane. Used when **type** is set to UIT_HELP_PANE.

### `pwzDui`

Type: **LPWSTR**

Use a direct user interface. Used when **type** is set to UIT_DUI.

## See also

[FreeUiInfo](https://learn.microsoft.com/windows/desktop/NDF/freeuiinfo)

[UI_INFO_TYPE](https://learn.microsoft.com/windows/win32/api/ndattrib/ne-ndattrib-ui_info_type)