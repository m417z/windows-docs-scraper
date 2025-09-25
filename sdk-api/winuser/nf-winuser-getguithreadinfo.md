# GetGUIThreadInfo function

## Description

Retrieves information about the active window or a specified GUI thread.

## Parameters

### `idThread` [in]

Type: **DWORD**

The identifier for the thread for which information is to be retrieved. To retrieve this value, use the [GetWindowThreadProcessId](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowthreadprocessid) function. If this parameter is **NULL**, the function returns information for the foreground thread.

### `pgui` [in, out]

Type: **LPGUITHREADINFO**

A pointer to a [GUITHREADINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-guithreadinfo) structure that receives information describing the thread. Note that you must set the **cbSize** member to `sizeof(GUITHREADINFO)` before calling this function.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function succeeds even if the active window is not owned by the calling process. If the specified thread does not exist or have an input queue, the function will fail.

This function is useful for retrieving out-of-context information about a thread. The information retrieved is the same as if an application retrieved the information about itself.

For an edit control, the returned **rcCaret** rectangle contains the caret plus information on text direction and padding. Thus, it may not give the correct position of the cursor. The Sans Serif font uses four characters for the cursor:

| Cursor character | Unicode code point |
| --- | --- |
| **CURSOR_LTR** | 0xf00c |
| **CURSOR_RTL** | 0xf00d |
| **CURSOR_THAI** | 0xf00e |
| **CURSOR_USA** | 0xfff (this is a marker value with no associated glyph) |

 To get the actual insertion point in the **rcCaret** rectangle, perform the following steps.

1. Call [GetKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeyboardlayout) to retrieve the current input language.
2. Determine the character used for the cursor, based on the current input language.
3. Call [CreateFont](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfonta) using Sans Serif for the font, the height given by **rcCaret**, and a width of `zero`. For *fnWeight*, call `SystemParametersInfo(SPI_GETCARETWIDTH, 0, pvParam, 0)`. If *pvParam* is greater than 1, set *fnWeight* to 700, otherwise set *fnWeight* to 400.
4. Select the font into a device context (DC) and use [GetCharABCWidths](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharabcwidthsa) to get the `B` width of the appropriate cursor character.
5. Add the `B` width to **rcCaret**.**left** to obtain the actual insertion point.

The function may not return valid window handles in the [GUITHREADINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-guithreadinfo) structure when called to retrieve information for the foreground thread, such as when a window is losing activation.

### DPI Virtualization

The coordinates returned in the **rcCaret** rect of the [GUITHREADINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-guithreadinfo) struct are logical coordinates in terms of the window associated with the caret. They are not virtualized into the mode of the calling thread.

## See also

**Conceptual**

[GUITHREADINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-guithreadinfo)

[GetCursorInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcursorinfo)

[GetWindowThreadProcessId](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowthreadprocessid)

**Reference**

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)