# LoadAcceleratorsA function

## Description

Loads the specified accelerator table.

## Parameters

### `hInstance` [in, optional]

Type: **HINSTANCE**

A handle to the module whose executable file contains the accelerator table to be loaded.

### `lpTableName` [in]

Type: **LPCTSTR**

The name of the accelerator table to be loaded. Alternatively, this parameter can specify the resource identifier of an accelerator-table resource in the low-order word and zero in the high-order word. To create this value, use the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro.

## Return value

Type: **HACCEL**

If the function succeeds, the return value is a handle to the loaded accelerator table.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the accelerator table has not yet been loaded, the function loads it from the specified executable file.

Accelerator tables loaded from resources are freed automatically when the application terminates.

#### Examples

For an example, see [Creating Accelerators for Font Attributes](https://learn.microsoft.com/windows/desktop/menurc/using-keyboard-accelerators).

> [!NOTE]
> The winuser.h header defines LoadAccelerators as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[CopyAcceleratorTable](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-copyacceleratortablea)

[CreateAcceleratorTable](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createacceleratortablea)

[DestroyAcceleratorTable](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyacceleratortable)

[Keyboard Accelerators](https://learn.microsoft.com/windows/desktop/menurc/keyboard-accelerators)

[MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea)

**Reference**