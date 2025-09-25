# GetWindowLongW function

## Description

Retrieves information about the specified window. The function also retrieves the 32-bit (**DWORD**) value at the specified offset into the extra window memory.

**Note** If you are retrieving a pointer or a handle, this function has been superseded by the [GetWindowLongPtr](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowlongptra) function. (Pointers and handles are 32 bits on 32-bit Windows and 64 bits on 64-bit Windows.) To write code that is compatible with both 32-bit and 64-bit versions of Windows, use **GetWindowLongPtr**.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window and, indirectly, the class to which the window belongs.

### `nIndex` [in]

Type: **int**

The zero-based offset to the value to be retrieved. Valid values are in the range zero through the number of bytes of extra window memory, minus four; for example, if you specified 12 or more bytes of extra memory, a value of 8 would be an index to the third 32-bit integer. To retrieve any other value, specify one of the following values.

| Value | Meaning |
| --- | --- |
| **GWL_EXSTYLE**<br><br>-20 | Retrieves the [extended window styles](https://learn.microsoft.com/windows/desktop/winmsg/extended-window-styles). |
| **GWL_HINSTANCE**<br><br>-6 | Retrieves a handle to the application instance. |
| **GWL_HWNDPARENT**<br><br>-8 | Retrieves a handle to the parent window, if any. |
| **GWL_ID**<br><br>-12 | Retrieves the identifier of the window. |
| **GWL_STYLE**<br><br>-16 | Retrieves the [window styles](https://learn.microsoft.com/windows/desktop/winmsg/window-styles). |
| **GWL_USERDATA**<br><br>-21 | Retrieves the user data associated with the window. This data is intended for use by the application that created the window. Its value is initially zero. |
| **GWL_WNDPROC**<br><br>-4 | Retrieves the address of the window procedure, or a handle representing the address of the window procedure. You must use the [CallWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-callwindowproca) function to call the window procedure. |

The following values are also available when the *hWnd* parameter identifies a dialog box.

| Value | Meaning |
| --- | --- |
| **DWL_DLGPROC**<br><br>DWLP_MSGRESULT + sizeof(LRESULT) | Retrieves the address of the dialog box procedure, or a handle representing the address of the dialog box procedure. You must use the [CallWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-callwindowproca) function to call the dialog box procedure. |
| **DWL_MSGRESULT**<br><br>0 | Retrieves the return value of a message processed in the dialog box procedure. |
| **DWL_USER**<br><br>DWLP_DLGPROC + sizeof(DLGPROC) | Retrieves extra information private to the application, such as handles or pointers. |

## Return value

Type: **LONG**

If the function succeeds, the return value is the requested value.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If [SetWindowLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowlonga) has not been called previously, **GetWindowLong** returns zero for values in the extra window or class memory.

## Remarks

Reserve extra window memory by specifying a nonzero value in the
**cbWndExtra** member of the [WNDCLASSEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassexa) structure used with the [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa) function.

#### Examples

For an example, see [Creating, Enumerating, and Sizing Child Windows](https://learn.microsoft.com/windows/desktop/winmsg/using-windows).

> [!NOTE]
> The winuser.h header defines GetWindowLong as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CallWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-callwindowproca)

**Conceptual**

[GetWindowLongPtr](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowlongptra)

**Reference**

[RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa)

[SetParent](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setparent)

[SetWindowLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowlonga)

[WNDCLASS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassa)

[Window Classes](https://learn.microsoft.com/windows/desktop/winmsg/window-classes)