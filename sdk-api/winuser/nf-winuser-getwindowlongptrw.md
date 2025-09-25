# GetWindowLongPtrW function

## Description

Retrieves information about the specified window. The function also retrieves the value at a specified offset into the extra window memory.

**Note** To write code that is compatible with both 32-bit and 64-bit versions of Windows, use **GetWindowLongPtr**. When compiling for 32-bit Windows, **GetWindowLongPtr** is defined as a call to the [GetWindowLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowlonga) function.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window and, indirectly, the class to which the window belongs.

### `nIndex` [in]

Type: **int**

The zero-based offset to the value to be retrieved. Valid values are in the range zero through the number of bytes of extra window memory, minus the size of a **LONG_PTR**. To retrieve any other value, specify one of the following values.

| Value | Meaning |
| --- | --- |
| **GWL_EXSTYLE**<br><br>-20 | Retrieves the [extended window styles](https://learn.microsoft.com/windows/desktop/winmsg/extended-window-styles). |
| **GWLP_HINSTANCE**<br><br>-6 | Retrieves a handle to the application instance. |
| **GWLP_HWNDPARENT**<br><br>-8 | Retrieves a handle to the parent window, if there is one. |
| **GWLP_ID**<br><br>-12 | Retrieves the identifier of the window. |
| **GWL_STYLE**<br><br>-16 | Retrieves the [window styles](https://learn.microsoft.com/windows/desktop/winmsg/window-styles). |
| **GWLP_USERDATA**<br><br>-21 | Retrieves the user data associated with the window. This data is intended for use by the application that created the window. Its value is initially zero. |
| **GWLP_WNDPROC**<br><br>-4 | Retrieves the pointer to the window procedure, or a handle representing the pointer to the window procedure. You must use the [CallWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-callwindowproca) function to call the window procedure. |

The following values are also available when the *hWnd* parameter identifies a dialog box.

| Value | Meaning |
| --- | --- |
| **DWLP_DLGPROC**<br><br>DWLP_MSGRESULT + sizeof(LRESULT) | Retrieves the pointer to the dialog box procedure, or a handle representing the pointer to the dialog box procedure. You must use the [CallWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-callwindowproca) function to call the dialog box procedure. |
| **DWLP_MSGRESULT**<br><br>0 | Retrieves the return value of a message processed in the dialog box procedure. |
| **DWLP_USER**<br><br>DWLP_DLGPROC + sizeof(DLGPROC) | Retrieves extra information private to the application, such as handles or pointers. |

## Return value

Type: **LONG_PTR**

If the function succeeds, the return value is the requested value.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If [SetWindowLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowlonga) or [SetWindowLongPtr](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowlongptra) has not been called previously, **GetWindowLongPtr** returns zero for values in the extra window or class memory.

## Remarks

Reserve extra window memory by specifying a nonzero value in the
**cbWndExtra** member of the [WNDCLASSEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassexa) structure used with the [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa) function.

> [!NOTE]
> The winuser.h header defines GetWindowLongPtr as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CallWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-callwindowproca)

**Conceptual**

**Reference**

[RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa)

[SetParent](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setparent)

[SetWindowLongPtr](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowlongptra)

[WNDCLASSEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassexa)

[Window Classes](https://learn.microsoft.com/windows/desktop/winmsg/window-classes)