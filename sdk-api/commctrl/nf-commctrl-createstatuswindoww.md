# CreateStatusWindowW function

## Description

Creates a status window, which is typically used to display the status of an application. The window generally appears at the bottom of the parent window, and it contains the specified text.

**Note** This function is obsolete. Use [CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa) instead.

## Parameters

### `style`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Window styles for the status window. This parameter must include the [WS_CHILD](https://learn.microsoft.com/windows/desktop/winmsg/window-styles) style and should also include the [WS_VISIBLE](https://learn.microsoft.com/windows/desktop/winmsg/window-styles) style.

### `lpszText`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a null-terminated string that specifies the status text for the first part.

### `hwndParent`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

handle to the parent window.

### `wID`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Control identifier for the status window. The window procedure uses this value to identify messages it sends to the parent window.

## Return value

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns the handle to the status window if successful, or **NULL** otherwise. To retrieve extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **CreateStatusWindow** function calls the [CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa) function to create the window. It passes the parameters to without modification and sets the position, width, and height parameters to **CreateWindow** default values.

> [!NOTE]
> The commctrl.h header defines CreateStatusWindow as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).