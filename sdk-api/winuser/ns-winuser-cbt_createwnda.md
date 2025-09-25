# CBT_CREATEWNDA structure

## Description

Contains information passed to a **WH_CBT** hook procedure, [CBTProc](https://learn.microsoft.com/windows/win32/winmsg/cbtproc), before a window is created.

## Members

### `lpcs`

Type: **LPCREATESTRUCT**

A pointer to a [CREATESTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-createstructa) structure that contains initialization parameters for the window about to be created.

### `hwndInsertAfter`

Type: **HWND**

A handle to the window whose position in the Z order precedes that of the window being created. This member can also be **NULL**.

## See also

[CBTProc](https://learn.microsoft.com/windows/win32/winmsg/cbtproc)

[CREATESTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-createstructa)

**Conceptual**

[Hooks](https://learn.microsoft.com/windows/desktop/winmsg/hooks)

**Reference**

[SetWindowsHookEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowshookexa)

## Remarks

> [!NOTE]
> The winuser.h header defines CBT_CREATEWND as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).