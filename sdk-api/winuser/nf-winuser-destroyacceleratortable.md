# DestroyAcceleratorTable function

## Description

Destroys an accelerator table.

## Parameters

### `hAccel` [in]

Type: **HACCEL**

A handle to the accelerator table to be destroyed. This handle must have been created by a call to the [CreateAcceleratorTable](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createacceleratortablea) or [LoadAccelerators](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadacceleratorsa) function.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero. However, if the table has been loaded more than one call to [LoadAccelerators](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadacceleratorsa), the function will return a nonzero value only when **DestroyAcceleratorTable** has been called an equal number of times.

If the function fails, the return value is zero.

## See also

**Conceptual**

[CopyAcceleratorTable](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-copyacceleratortablea)

[CreateAcceleratorTable](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createacceleratortablea)

[Keyboard Accelerators](https://learn.microsoft.com/windows/desktop/menurc/keyboard-accelerators)

[LoadAccelerators](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadacceleratorsa)

**Reference**

[TranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-translateacceleratora)