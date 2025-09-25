# SetMenuContextHelpId function

## Description

Associates a Help context identifier with a menu.

## Parameters

### `unnamedParam1`

Type: **HMENU**

A handle to the menu with which to associate the Help context identifier.

### `unnamedParam2`

Type: **DWORD**

The help context identifier.

## Return value

Type: **BOOL**

Returns nonzero if successful, or zero otherwise.

To retrieve extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All items in the menu share this identifier. Help context identifiers can't be attached to individual menu items.

## See also

[GetMenuContextHelpId](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenucontexthelpid)