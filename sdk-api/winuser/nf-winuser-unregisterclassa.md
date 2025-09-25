# UnregisterClassA function

## Description

Unregisters a window class, freeing the memory required for the class.

## Parameters

### `lpClassName` [in]

Type: **LPCTSTR**

A null-terminated string or a class atom. If *lpClassName* is a string, it specifies the window class name. This class name must have been registered by a previous call to the [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa) or [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa) function. System classes, such as dialog box controls, cannot be unregistered. If this parameter is an atom, it must be a class atom created by a previous call to the **RegisterClass** or **RegisterClassEx** function. The atom must be in the low-order word of *lpClassName*; the high-order word must be zero.

### `hInstance` [in, optional]

Type: **HINSTANCE**

A handle to the instance of the module that created the class.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the class could not be found or if a window still exists that was created with the class, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Before calling this function, an application must destroy all windows created with the specified class.

All window classes that an application registers are unregistered when it terminates.

Class atoms are special atoms returned only by [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa) and [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa).

No window classes registered by a DLL are unregistered when the .dll is unloaded.

> [!NOTE]
> The winuser.h header defines UnregisterClass as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

**Reference**

[RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa)

[RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa)

[Window Classes](https://learn.microsoft.com/windows/desktop/winmsg/window-classes)