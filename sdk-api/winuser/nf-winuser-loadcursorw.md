# LoadCursorW function

## Description

Loads the specified cursor resource from the executable (.exe) file associated with an application instance.

> [!NOTE]
> This function has been superseded by the [LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagew) function (with **LR_DEFAULTSIZE** and **LR_SHARED** flags set).

## Parameters

### `hInstance` [in, optional]

Type: **HINSTANCE**

A handle to the module of either a DLL or executable (.exe) file that contains the cursor to be loaded. For more information, see [GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea).

To load a predefined system cursor, set this parameter to **NULL**.
### `lpCursorName` [in]

Type: **LPCTSTR**

If *hInstance* is non-**NULL**, *lpCursorName* specifies the cursor resource either by name or ordinal. This ordinal must be packaged by using the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcew) macro.

If *hInstance* is **NULL**, *lpCursorName* specifies the identifier that begins with the [IDC\_ prefix](https://learn.microsoft.com/windows/win32/menurc/about-cursors) of a predefined system cursor to load.

## Return value

Type: **HCURSOR**

If the function succeeds, the return value is the handle to the newly loaded cursor.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **LoadCursor** function loads the cursor resource only if it has not been loaded; otherwise, it retrieves the handle to the existing resource. This function returns a valid cursor handle only if the *lpCursorName* parameter is a pointer to a cursor resource. If *lpCursorName* is a pointer to any type of resource other than a cursor (such as an icon), the return value is not **NULL**, even though it is not a valid cursor handle.

The **LoadCursor** function searches the cursor resource most appropriate for the cursor for the current display device. The cursor resource can be a color or monochrome bitmap.

### DPI Virtualization

This API does not participate in DPI virtualization. The output returned is not affected by the DPI of the calling thread.

#### Examples

For an example, see [Creating a Cursor](https://learn.microsoft.com/windows/desktop/menurc/using-cursors).

> [!NOTE]
> The winuser.h header defines LoadCursor as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[Cursors](https://learn.microsoft.com/windows/desktop/menurc/cursors)

[LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagea)

[MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea)

[IS_INTRESOURCE](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-is_intresource)

**Reference**

[SetCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcursor)

[SetCursorPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcursorpos)

[ShowCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showcursor)