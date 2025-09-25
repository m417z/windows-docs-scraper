# GetClassLongPtrW function

## Description

Retrieves the specified value from the [WNDCLASSEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassexa) structure associated with the specified window.

**Note** To write code that is compatible with both 32-bit and 64-bit versions of Windows, use **GetClassLongPtr**. When compiling for 32-bit Windows, **GetClassLongPtr** is defined as a call to the [GetClassLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclasslonga) function.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window and, indirectly, the class to which the window belongs.

### `nIndex` [in]

Type: **int**

The value to be retrieved. To retrieve a value from the extra class memory, specify the positive, zero-based byte offset of the value to be retrieved. Valid values are in the range zero through the number of bytes of extra class memory, minus eight; for example, if you specified 24 or more bytes of extra class memory, a value of 16 would be an index to the third integer. To retrieve any other value from the [WNDCLASSEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassexa) structure, specify one of the following values.

| Value | Meaning |
| --- | --- |
| **GCW_ATOM**<br><br>-32 | Retrieves an **ATOM** value that uniquely identifies the window class. This is the same atom that the [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa) function returns. |
| **GCL_CBCLSEXTRA**<br><br>-20 | Retrieves the size, in bytes, of the extra memory associated with the class. |
| **GCL_CBWNDEXTRA**<br><br>-18 | Retrieves the size, in bytes, of the extra window memory associated with each window in the class. For information on how to access this memory, see [GetWindowLongPtr](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowlongptra). |
| **GCLP_HBRBACKGROUND**<br><br>-10 | Retrieves a handle to the background brush associated with the class. |
| **GCLP_HCURSOR**<br><br>-12 | Retrieves a handle to the cursor associated with the class. |
| **GCLP_HICON**<br><br>-14 | Retrieves a handle to the icon associated with the class. |
| **GCLP_HICONSM**<br><br>-34 | Retrieves a handle to the small icon associated with the class. |
| **GCLP_HMODULE**<br><br>-16 | Retrieves a handle to the module that registered the class. |
| **GCLP_MENUNAME**<br><br>-8 | Retrieves the pointer to the menu name string. The string identifies the menu resource associated with the class. |
| **GCL_STYLE**<br><br>-26 | Retrieves the window-class style bits. |
| **GCLP_WNDPROC**<br><br>-24 | Retrieves the address of the window procedure, or a handle representing the address of the window procedure. You must use the [CallWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-callwindowproca) function to call the window procedure. |

## Return value

Type: **ULONG_PTR**

If the function succeeds, the return value is the requested value.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Reserve extra class memory by specifying a nonzero value in the
**cbClsExtra** member of the [WNDCLASSEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassexa) structure used with the [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa) function.

> [!NOTE]
> The winuser.h header defines GetClassLongPtr as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[GetWindowLongPtr](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowlongptra)

**Reference**

[RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa)

[SetClassLongPtr](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setclasslongptra)

[WNDCLASSEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassexa)

[Window Classes](https://learn.microsoft.com/windows/desktop/winmsg/window-classes)