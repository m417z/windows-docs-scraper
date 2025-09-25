# SetClassLongW function

## Description

Replaces the specified 32-bit (**long**) value at the specified offset into the extra class memory or the [WNDCLASSEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassexa) structure for the class to which the specified window belongs.

**Note** This function has been superseded by the [SetClassLongPtr](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setclasslongptra) function. To write code that is compatible with both 32-bit and 64-bit versions of Windows, use **SetClassLongPtr**.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window and, indirectly, the class to which the window belongs.

### `nIndex` [in]

Type: **int**

The value to be replaced. To set a 32-bit value in the extra class memory, specify the positive, zero-based byte offset of the value to be set. Valid values are in the range zero through the number of bytes of extra class memory, minus four; for example, if you specified 12 or more bytes of extra class memory, a value of 8 would be an index to the third 32-bit integer. To set any other value from the [WNDCLASSEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassexa) structure, specify one of the following values.

| Value | Meaning |
| --- | --- |
| **GCL_CBCLSEXTRA**<br><br>-20 | Sets the size, in bytes, of the extra memory associated with the class. Setting this value does not change the number of extra bytes already allocated. |
| **GCL_CBWNDEXTRA**<br><br>-18 | Sets the size, in bytes, of the extra window memory associated with each window in the class. Setting this value does not change the number of extra bytes already allocated. For information on how to access this memory, see [SetWindowLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowlonga). |
| **GCL_HBRBACKGROUND**<br><br>-10 | Replaces a handle to the background brush associated with the class. |
| **GCL_HCURSOR**<br><br>-12 | Replaces a handle to the cursor associated with the class. |
| **GCL_HICON**<br><br>-14 | Replaces a handle to the icon associated with the class. |
| **GCL_HICONSM**<br><br>-34 | Replace a handle to the small icon associated with the class. |
| **GCL_HMODULE**<br><br>-16 | Replaces a handle to the module that registered the class. |
| **GCL_MENUNAME**<br><br>-8 | Replaces the address of the menu name string. The string identifies the menu resource associated with the class. |
| **GCL_STYLE**<br><br>-26 | Replaces the window-class style bits. |
| **GCL_WNDPROC**<br><br>-24 | Replaces the address of the window procedure associated with the class. |

### `dwNewLong` [in]

Type: **LONG**

The replacement value.

## Return value

Type: **DWORD**

If the function succeeds, the return value is the previous value of the specified 32-bit integer. If the value was not previously set, the return value is zero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If you use the **SetClassLong** function and the **GCL_WNDPROC** index to replace the window procedure, the window procedure must conform to the guidelines specified in the description of the [WindowProc](https://learn.microsoft.com/windows/win32/api/winuser/nc-winuser-wndproc) callback function.

Calling **SetClassLong** with the **GCL_WNDPROC** index creates a subclass of the window class that affects all windows subsequently created with the class. An application can subclass a system class, but should not subclass a window class created by another process.

Reserve extra class memory by specifying a nonzero value in the **cbClsExtra** member of the [WNDCLASSEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassexa) structure used with the [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa) function.

Use the **SetClassLong** function with care. For example, it is possible to change the background color for a class by using **SetClassLong**, but this change does not immediately repaint all windows belonging to the class.

#### Examples

For an example, see [Displaying an Icon](https://learn.microsoft.com/windows/desktop/menurc/using-icons).

> [!NOTE]
> The winuser.h header defines SetClassLong as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[GetClassLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclasslonga)

**Reference**

[RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa)

[SetClassLongPtr](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setclasslongptra)

[SetWindowLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowlonga)

[WNDCLASSEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassexa)

[Window Classes](https://learn.microsoft.com/windows/desktop/winmsg/window-classes)

[WindowProc](https://learn.microsoft.com/windows/win32/api/winuser/nc-winuser-wndproc)