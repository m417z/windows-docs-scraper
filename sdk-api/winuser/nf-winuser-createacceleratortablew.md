# CreateAcceleratorTableW function

## Description

Creates an accelerator table.

## Parameters

### `paccel` [in]

Type: **LPACCEL**

An array of [ACCEL](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-accel) structures that describes the accelerator table.

### `cAccel` [in]

Type: **int**

The number of [ACCEL](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-accel) structures in the array. This must be within the range 1 to 32767 or the function will fail.

## Return value

Type: **HACCEL**

If the function succeeds, the return value is the handle to the created accelerator table; otherwise, it is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Before an application closes, it can use the [DestroyAcceleratorTable](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyacceleratortable) function to destroy any accelerator tables that it created by using the **CreateAcceleratorTable** function.

#### Examples

For an example, see [Creating User Editable Accelerators](https://learn.microsoft.com/windows/desktop/menurc/using-keyboard-accelerators).

> [!NOTE]
> The winuser.h header defines CreateAcceleratorTable as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ACCEL](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-accel)

**Conceptual**

[CopyAcceleratorTable](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-copyacceleratortablea)

[DestroyAcceleratorTable](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyacceleratortable)

[Keyboard Accelerators](https://learn.microsoft.com/windows/desktop/menurc/keyboard-accelerators)

[LoadAccelerators](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadacceleratorsa)

**Reference**

[TranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-translateacceleratora)