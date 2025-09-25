# UnregisterHotKey function

## Description

Frees a hot key previously registered by the calling thread.

## Parameters

### `hWnd` [in, optional]

Type: **HWND**

A handle to the window associated with the hot key to be freed. This parameter should be **NULL** if the hot key is not associated with a window.

### `id` [in]

Type: **int**

The identifier of the hot key to be freed.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

**Conceptual**

[Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)

**Reference**

[RegisterHotKey](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerhotkey)

[WM_HOTKEY](https://learn.microsoft.com/windows/desktop/inputdev/wm-hotkey)