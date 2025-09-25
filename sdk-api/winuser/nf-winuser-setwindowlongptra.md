# SetWindowLongPtrA function

## Description

Changes an attribute of the specified window. The function also sets a value at the specified offset in the extra window memory.

**Note** To write code that is compatible with both 32-bit and 64-bit versions of Windows, use **SetWindowLongPtr**. When compiling for 32-bit Windows, **SetWindowLongPtr** is defined as a call to the [SetWindowLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowlonga) function.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window and, indirectly, the class to which the window belongs. The **SetWindowLongPtr** function fails if the process that owns the window specified by the *hWnd* parameter is at a higher process privilege in the UIPI hierarchy than the process the calling thread resides in.

**Windows XP/2000:**  The **SetWindowLongPtr** function fails if the window specified by the *hWnd* parameter does not belong to the same process as the calling thread.

### `nIndex` [in]

Type: **int**

The zero-based offset to the value to be set. Valid values are in the range zero through the number of bytes of extra window memory, minus the size of a **LONG_PTR**. To set any other value, specify one of the following values.

| Value | Meaning |
| --- | --- |
| **GWL_EXSTYLE**<br><br>-20 | Sets a new [extended window style](https://learn.microsoft.com/windows/desktop/winmsg/extended-window-styles). |
| **GWLP_HINSTANCE**<br><br>-6 | Sets a new application instance handle. |
| **GWLP_HWNDPARENT**<br><br>-8 | Sets a new owner for a top-level window. |
| **GWLP_ID**<br><br>-12 | Sets a new identifier of the child window. The window cannot be a top-level window. |
| **GWL_STYLE**<br><br>-16 | Sets a new [window style](https://learn.microsoft.com/windows/desktop/winmsg/window-styles). |
| **GWLP_USERDATA**<br><br>-21 | Sets the user data associated with the window. This data is intended for use by the application that created the window. Its value is initially zero. |
| **GWLP_WNDPROC**<br><br>-4 | Sets a new address for the window procedure. |

The following values are also available when the *hWnd* parameter identifies a dialog box.

| Value | Meaning |
| --- | --- |
| **DWLP_DLGPROC**<br><br>DWLP_MSGRESULT + sizeof(LRESULT) | Sets the new pointer to the dialog box procedure. |
| **DWLP_MSGRESULT**<br><br>0 | Sets the return value of a message processed in the dialog box procedure. |
| **DWLP_USER**<br><br>DWLP_DLGPROC + sizeof(DLGPROC) | Sets new extra information that is private to the application, such as handles or pointers. |

### `dwNewLong` [in]

Type: **LONG_PTR**

The replacement value.

## Return value

Type: **LONG_PTR**

If the function succeeds, the return value is the previous value of the specified offset.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the previous value is zero and the function succeeds, the return value is zero, but the function does not clear the last error information. To determine success or failure, clear the last error information by calling [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) with 0, then call **SetWindowLongPtr**. Function failure will be indicated by a return value of zero and a [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) result that is nonzero.

## Remarks

Certain window data is cached, so changes you make using **SetWindowLongPtr** will not take effect until you call the [SetWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowpos) function.

If you use **SetWindowLongPtr** with the **GWLP_WNDPROC** index to replace the window procedure, the window procedure must conform to the guidelines specified in the description of the [WindowProc](https://learn.microsoft.com/windows/win32/api/winuser/nc-winuser-wndproc) callback function.

If you use **SetWindowLongPtr** with the **DWLP_MSGRESULT** index to set the return value for a message processed by a dialog box procedure, the dialog box procedure should return **TRUE** directly afterward. Otherwise, if you call any function that results in your dialog box procedure receiving a window message, the nested window message could overwrite the return value you set by using **DWLP_MSGRESULT**.

Calling **SetWindowLongPtr** with the **GWLP_WNDPROC** index creates a subclass of the window class used to create the window. An application can subclass a system class, but should not subclass a window class created by another process. The **SetWindowLongPtr** function creates the window subclass by changing the window procedure associated with a particular window class, causing the system to call the new window procedure instead of the previous one. An application must pass any messages not processed by the new window procedure to the previous window procedure by calling [CallWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-callwindowproca). This allows the application to create a chain of window procedures.

Reserve extra window memory by specifying a nonzero value in the
**cbWndExtra** member of the [WNDCLASSEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassexa) structure used with the [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa) function.

Do not call **SetWindowLongPtr** with the **GWLP_HWNDPARENT** index to change the parent of a child window. Instead, use the [SetParent](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setparent) function.

**GWLP_HWNDPARENT** is used to change the owner of a top-level window, not the parent of a child window.

A window can have either a parent or an owner, or neither, but never both simultaneously.

If the window has a class style of **CS_CLASSDC** or **CS_PARENTDC**, do not set the extended window styles **WS_EX_COMPOSITED** or **WS_EX_LAYERED**.

 Calling **SetWindowLongPtr** to set the style on a progressbar will reset its position.

> [!NOTE]
> The winuser.h header defines SetWindowLongPtr as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CallWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-callwindowproca)

**Conceptual**

[GetWindowLongPtr](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowlongptra)

**Reference**

[RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa)

[SetParent](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setparent)

[WNDCLASSEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassexa)

[Window Classes](https://learn.microsoft.com/windows/desktop/winmsg/window-classes)

[WindowProc](https://learn.microsoft.com/windows/win32/api/winuser/nc-winuser-wndproc)