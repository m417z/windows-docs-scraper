# LoadIconA function

## Description

Loads the specified icon resource from the executable (.exe) file associated with an application instance.

> [!NOTE]
> This function has been superseded by the [LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagea) function (with **LR_DEFAULTSIZE** and **LR_SHARED** flags set).

## Parameters

### `hInstance` [in, optional]

Type: **HINSTANCE**

A handle to the module of either a DLL or executable (.exe) file that contains the icon to be loaded. For more information, see [GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea).

To load a predefined system icon, set this parameter to **NULL**.

### `lpIconName` [in]

Type: **LPCTSTR**

If *hInstance* is non-**NULL**, *lpIconName* specifies the icon resource either by name or ordinal. This ordinal must be packaged by using the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcew) macro.

If *hInstance* is **NULL**, *lpIconName* specifies the [identifier (beginning with the IDI\_ prefix)](https://learn.microsoft.com/windows/win32/menurc/about-icons) of a predefined system icon to load.

## Return value

Type: **HICON**

If the function succeeds, the return value is a handle to the newly loaded icon.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**LoadIcon** loads the icon resource only if it has not been loaded; otherwise, it retrieves a handle to the existing resource. The function searches the icon resource for the icon most appropriate for the current display. The icon resource can be a color or monochrome bitmap.

**LoadIcon** can only load an icon whose size conforms to the **SM_CXICON** and **SM_CYICON** system metric values. Use the [LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagea) function to load icons of other sizes.

> [!NOTE]
> The winuser.h header defines LoadIcon as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[CreateIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createicon)

[Icons](https://learn.microsoft.com/windows/desktop/menurc/icons)

[LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagea)

[MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea)

[IS_INTRESOURCE](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-is_intresource)