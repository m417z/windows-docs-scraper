# LoadMenuIndirectW function

## Description

Loads the specified menu template in memory.

## Parameters

### `lpMenuTemplate` [in]

Type: **const MENUTEMPLATE***

A pointer to a menu template or an extended menu template. A menu template consists of a [MENUITEMTEMPLATEHEADER](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-menuitemtemplateheader) structure followed by one or more contiguous [MENUITEMTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-menuitemtemplate) structures. An extended menu template consists of a [MENUEX_TEMPLATE_HEADER](https://learn.microsoft.com/windows/desktop/menurc/menuex-template-header) structure followed by one or more contiguous [MENUEX_TEMPLATE_ITEM](https://learn.microsoft.com/windows/desktop/menurc/menuex-template-item) structures.

## Return value

Type: **HMENU**

If the function succeeds, the return value is a handle to the menu.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

For both the ANSI and the Unicode version of this function, the strings in the [MENUITEMTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-menuitemtemplate) structure must be Unicode strings.

> [!NOTE]
> The winuser.h header defines LoadMenuIndirect as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[LoadMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadmenua)

[MENUEX_TEMPLATE_HEADER](https://learn.microsoft.com/windows/desktop/menurc/menuex-template-header)

[MENUEX_TEMPLATE_ITEM](https://learn.microsoft.com/windows/desktop/menurc/menuex-template-item)

[MENUITEMTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-menuitemtemplate)

[MENUITEMTEMPLATEHEADER](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-menuitemtemplateheader)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**