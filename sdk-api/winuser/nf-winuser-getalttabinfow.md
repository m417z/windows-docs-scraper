# GetAltTabInfoW function

## Description

Retrieves status information for the specified window if it is the application-switching (ALT+TAB) window.

## Parameters

### `hwnd` [in, optional]

Type: **HWND**

A handle to the window for which status information will be retrieved. This window must be the application-switching window.

### `iItem` [in]

Type: **int**

The index of the icon in the application-switching window. If the *pszItemText* parameter is not **NULL**, the name of the item is copied to the *pszItemText* string. If this parameter is –1, the name of the item is not copied.

### `pati` [in, out]

Type: **PALTTABINFO**

A pointer to an [ALTTABINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-alttabinfo) structure to receive the status information. Note that you must set the **csSize** member to `sizeof(ALTTABINFO)` before calling this function.

### `pszItemText` [out, optional]

Type: **LPTSTR**

The name of the item. If this parameter is **NULL**, the name of the item is not copied.

### `cchItemText` [in]

Type: **UINT**

The size, in characters, of the *pszItemText* buffer.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The application-switching window enables you to switch to the most recently used application window. To display the application-switching window, press ALT+TAB. To select an application from the list, continue to hold ALT down and press TAB to move through the list. Add SHIFT to reverse direction through the list.

> [!NOTE]
> The winuser.h header defines GetAltTabInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ALTTABINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-alttabinfo)

**Conceptual**

**Reference**

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)