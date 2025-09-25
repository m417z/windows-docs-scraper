# Animate_Close macro

## Syntax

```cpp
BOOL Animate_Close(
   HWND hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Always returns **FALSE**.

## Description

Closes an AVI clip. You can use this macro or send the [ACM_OPEN](https://learn.microsoft.com/windows/desktop/Controls/acm-open) message explicitly, passing in **NULL** parameters.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the animation control.

## Remarks

You can use **Animate_Close** to close an AVI file or AVI resource that was previously opened for the specified animation control.

## See also

[Animate_Open](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-animate_open)