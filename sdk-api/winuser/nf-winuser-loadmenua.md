# LoadMenuA function

## Description

Loads the specified menu resource from the executable (.exe) file associated with an application instance.

## Parameters

### `hInstance` [in, optional]

Type: **HINSTANCE**

A handle to the module containing the menu resource to be loaded.

### `lpMenuName` [in]

Type: **LPCTSTR**

The name of the menu resource. Alternatively, this parameter can consist of the resource identifier in the low-order word and zero in the high-order word. To create this value, use the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro.

## Return value

Type: **HMENU**

If the function succeeds, the return value is a handle to the menu resource.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The [DestroyMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroymenu) function is used, before an application closes, to destroy the menu and free memory that the loaded menu occupied.

#### Examples

For an example, see [Displaying a Shortcut Menu](https://learn.microsoft.com/windows/desktop/menurc/using-menus)

> [!NOTE]
> The winuser.h header defines LoadMenu as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[LoadMenuIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadmenuindirecta)

[MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**