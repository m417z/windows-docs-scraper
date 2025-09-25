# CopyAcceleratorTableA function

## Description

Copies the specified accelerator table. This function is used to obtain the accelerator-table data that corresponds to an accelerator-table handle, or to determine the size of the accelerator-table data.

## Parameters

### `hAccelSrc` [in]

Type: **HACCEL**

A handle to the accelerator table to copy.

### `lpAccelDst` [out, optional]

Type: **LPACCEL**

An array of [ACCEL](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-accel) structures that receives the accelerator-table information.

### `cAccelEntries` [in]

Type: **int**

The number of [ACCEL](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-accel) structures to copy to the buffer pointed to by the
*lpAccelDst* parameter.

## Return value

Type: **int**

If
*lpAccelDst* is **NULL**, the return value specifies the number of accelerator-table entries in the original table. Otherwise, it specifies the number of accelerator-table entries that were copied.

## See also

[ACCEL](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-accel)

**Conceptual**

[CreateAcceleratorTable](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createacceleratortablea)

[DestroyAcceleratorTable](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyacceleratortable)

[Keyboard Accelerators](https://learn.microsoft.com/windows/desktop/menurc/keyboard-accelerators)

[LoadAccelerators](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadacceleratorsa)

**Reference**

[TranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-translateacceleratora)

## Remarks

> [!NOTE]
> The winuser.h header defines CopyAcceleratorTable as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).